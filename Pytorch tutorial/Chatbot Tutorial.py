# -*- coding: utf-8 -*-
"""
Created on Mon Sep  9 09:14:16 2019

@author: Qiandehou
"""
from __future__ import absolute_import
from __future__ import division
from __future__ import print_function
from __future__ import unicode_literals

import torch
from torch.jit import script,trace
import torch.nn as nn
from torch import optim
import torch.nn.functional as F
import csv
import random
import re
import os
import unicodedata
import codecs
from io import open
import itertools
import math

USE_CUDA=torch.cuda.is_available()
device=torch.device("cuda" if USE_CUDA else "cpu")

#Load&Preprocess Data

# The next step is to reformat our data file and load the data into structures that we can work with
# The cornel Movie_Dialogs Corpus is a rich dataset of movie character dialog
# 1. 220579 conversational exchanges between 10292 pairs of movie characters
# 2. 9035 characters from 617 movies
# 3. 304713 total utterances

#This dataset is large and diverse , and there is a great variation of language formality, time periods,sentiment etc.
#Our hope is that this diversity makes our model robust to many forms of inputs and quiries

#First, we'll take a look at some lines of our datafile to see the original format

corpus_name="cornell movie-dialogs corpus"
corpus=os.path.join("data\cornell_movie_dialogs_corpus",corpus_name)

def printLines(file,n=10):
    with open(file,'rb')as datafile:# 读取二进制文件,例如图片,视频等,使用'rb'模式打开文件
        lines=datafile.readlines()
    for line in lines[:n]:
        print(line)

printLines(os.path.join(corpus,"movie_lines.txt"))

#Create formatted data file
#For convenicence, we'll create a nicely formatted data file in which each line contains a tab-seperated
#query sentence and a response sentence pair

# The following functions facilitate the parsing of the raw movie_lines.txt data file.
# 1. loadLines splits each line of the file into a dictionary of fields(lineID,characterID,movieID,character,text)
# 2. loadConversations groups fields of lines from loadLines into conversations based on movie_conversations.txt
# 3. extractSentencePairs extracts pairs of sentences from conversations

# Splits each line of the file into a dictionary of fields
def loadLines(fileName, fields):
    lines={}
    with open(fileName,'r',encoding='iso-8859-1')as f:
        for line in f:
            values=line.split(" +++$+++ ")
            # Extract fields
            lineObj={}
            for i,field in enumerate(fields):
                lineObj[field]=values[i]
            lines[lineObj['lineID']]=lineObj
    return lines

 #Groups fields of lines from 'loadLines' into conversations based on *movie_conversations.txt*
def loadConversations(fileName,lines,fields):
    conversations=[]
    with open(fileName,'r',encoding='iso-8859-1')as f:
        for line in f:
            values=line.split(" +++$+++ ")
             #Extract fields
            convObj={}
            for i,field in enumerate(fields):
                convObj[field]=values[i]
                 #Convert string list (convObj["utteranceIDs"]=="['L598485','L598486',]")
            
            #debug: pay attention to the for circle layout
            utterance_id_pattern=re.compile('L[0-9]+')
            #print(utterance_id_pattern)
            
            lineIds=utterance_id_pattern.findall(convObj["utteranceIDs"])
                 #Reassemble lines
            convObj["lines"]=[]
            for lineId in lineIds:
                convObj["lines"].append(lines[lineId])
            conversations.append(convObj)
    return conversations



#Extracts pairs of sentences from conversations
def extractSentencePairs(conversations):
    qa_pairs=[]
    for conversation in conversations:
        #Iterate over all the lines of the conversation
        for i in range(len(conversation["lines"])-1): #We ignore the last line(no answer for it)
            inputLine=conversation["lines"][i]["text"].strip()
            targetLine=conversation["lines"][i+1]["text"].strip()
            #fileter wrong samples (if one of the lists is empty)
            if inputLine and targetLine:
                qa_pairs.append([inputLine,targetLine])
    return qa_pairs

# Now we'll call these functions and create the file. We'll call it formatted_movie_lines.txt

#Define path to new file
datafile=os.path.join(corpus,"formatted_movie_lines.txt")

delimiter='\t'
# Unescape the delimiter
delimiter=str(codecs.decode(delimiter,"unicode_escape"))

# Initialize lines dict, conversations list, and field ids
lines={}
conversations=[]
MOVIE_LINES_FIELDS=["lineID","characterID","movieID","character","text"]
MOVIE_CONVERSATIONS_FIELDS=["character1ID","character2ID","movieID","utteranceIDs"]

#Load lines and process conversations
print("\nProcessing corpus...")
lines=loadLines(os.path.join(corpus,"movie_lines.txt"),MOVIE_LINES_FIELDS)
#Load lines and process conversations
print("\nProcessing conversations...")
conversations=loadConversations(os.path.join(corpus,"movie_conversations.txt"),
                lines,MOVIE_CONVERSATIONS_FIELDS)

#Write new csv file
print("\nWriting newly formatted file...")
with open(datafile,'w',encoding='utf-8')as outputfile:
    writer=csv.writer(outputfile,delimiter=delimiter,lineterminator='\n')
    for pair in extractSentencePairs(conversations):
        writer.writerow(pair)

#Print a sample of lines
print("\nSample lines from file:")
printLines(datafile)

# Load and trim data

# Our next order of business is to create a vocabulary and load query/response sentence
# pairs into memory.

# Note that we are dealing with sequence of words, which do not have an implicit
# mapping to a discrete numerical space.Thus, we must create one by mapping each
# unique word that we encounter in our dataset to an index value.

# For this we define a Voc class, which keeps a mapping from words to indexes. a
# reverse mapping of indexes to words, a count of each word and a total word count.
# The class provides methods for adding a word to the vocabulary(addWord), adding
# all words in a sentence(addSentence) and trimming infrequently Seen words(trim).
# More on trimming later.

# Default word tokens
PAD_token=0 #Used for padding short sentences
SOS_token=1 #Start-of-sentence token
EOS_token=2 #End-of-sentence token

class Voc:
    def __init__(self,name):
        self.name=name
        self.trimmed=False
        self.word2index={}
        self.word2count={}
        self.index2word={PAD_token:"PAD",SOS_token:"SOS",EOS_token:"EOS"}
        self.num_words=3 #Count SOS,EOS,PAD
        
    def addSentence(self,sentence):
        for word in sentence.split(' '):
            self.addWord(word)
            
    def addWord(self.word):
        if word not in self.word2index:
            self.word2index[word]=self.num_words
            self.word2count[word]=1;
            self.index2word[self.num_words]=word
            self.num_words+=1
        else:
            self.word2count[word]+=1
    
    #Remove words below a certain count threshold
    def trim(self,min_count):
        if self.trimmed:
            return 
        self.trimmed=True
        
        keep_words=[]
        
        for k,v in self.word2count.items():
            if v>=min_count:
                keep_words.append(k)
                
        print('keep_words {}/{}={:.4f}'.format(
                len(keep_words),len(self.word2index),len(keep_words)
                /len(self.word2index)))
        
        #Reinitialize dictionaries
        self.word2index={}
        self.word2count={}
        self.index2word={PAD_token:"PAD",SOS_token:"SOS",EOS_token:"EOS"}
        self.num_words=3 #Count default tokens
        
        for word in keep_words:
            self.addWord(word)
            





























