# -*- coding: utf-8 -*-
"""
Created on Tue Dec 22 08:48:53 2020

@author: Qiandehou
"""
#
#
#"""
#词向量
#"""
##Embedding(num_embeddings,embedding_dim)
##embedding=nn.Embedding(10,2)    #10个词，每个词2维
##input=t.arange(0,6).view(3,2).long()    #三个句子，每个句子有两个词
## 
###input=t.autograd.Variable(input)
##output=embedding(input)
##print(output.size())
##print(input)
##print(output)
##
##ts=t.sum(output,dim=2)
##print(ts)
#
##tsoft=F.softmax(ts,dim=0)
##print(tsoft)
##
##tsoft=F.softmax(ts,dim=1)
##print(tsoft)
#
#
##print(output)
##print(output[:,:,:1])
#import torch
#from torch import nn
#
#
#def rnn_forwarder(rnn, inputs, seq_lengths):
#    """
#    :param rnn: RNN instance
#    :param inputs: FloatTensor, shape [batch, time, dim] if rnn.batch_first else [time, batch, dim]
#    :param seq_lengths: LongTensor shape [batch]
#    :return: the result of rnn layer,
#    """
#    batch_first = rnn.batch_first
#    # assume seq_lengths = [3, 5, 2]
#    # 对序列长度进行排序(降序), sorted_seq_lengths = [5, 3, 2]
#    # indices 为 [1, 0, 2], indices 的值可以这么用语言表述
#    # 原来 batch 中在 0 位置的值, 现在在位置 1 上.
#    # 原来 batch 中在 1 位置的值, 现在在位置 0 上.
#    # 原来 batch 中在 2 位置的值, 现在在位置 2 上.
#    sorted_seq_lengths, indices = torch.sort(seq_lengths, descending=True)
#
#    # 如果我们想要将计算的结果恢复排序前的顺序的话,
#    # 只需要对 indices 再次排序(升序),会得到 [0, 1, 2],
#    # desorted_indices 的结果就是 [1, 0, 2]
#    # 使用 desorted_indices 对计算结果进行索引就可以了.
#    _, desorted_indices = torch.sort(indices, descending=False)
#
#    # 对原始序列进行排序
#    if batch_first:
#        inputs = inputs[indices]
#        
#    else:
#        inputs = inputs[:, indices]
#    packed_inputs = nn.utils.rnn.pack_padded_sequence(inputs,
#                                                      sorted_seq_lengths.cpu().numpy(),
#                                                      batch_first=batch_first)
#    print(packed_inputs)
#
#    print(inputs)
#    res, state = rnn(packed_inputs)
#
#    padded_res, _ = nn.utils.rnn.pad_packed_sequence(res, batch_first=batch_first)
#
#    # 恢复排序前的样本顺序
#    if batch_first:
#        desorted_res = padded_res[desorted_indices]
#    else:
#        desorted_res = padded_res[:, desorted_indices]
#    return desorted_res
#
#
#if __name__ == "__main__":
#    bs = 3
#    max_time_step = 5
#    feat_size = 15
#    hidden_size = 2
#    seq_lengths = torch.tensor([3, 5, 2], dtype=torch.long)
#
#    rnn = nn.GRU(input_size=feat_size,
#                 hidden_size=hidden_size, batch_first=True, bidirectional=True)
#    x = torch.randn([bs, max_time_step, feat_size])
#
#    using_packed_res = rnn_forwarder(rnn, x, seq_lengths)
#    print(using_packed_res)
#
#    # 不使用 pack_paded, 用来和上面的结果对比一下.
#    not_packed_res, _ = rnn(x)
#    print(not_packed_res)
#
#
#
#
#
#
#
#

#batch1 = torch.randn(2, 2, 1)
#batch2 = torch.randn(3, 3, 1)
##res = torch.bmm(batch1, batch2)
##print(res.size())
##res2=batch1.bmm(batch2)
##print(res2.size())
#
#print(batch1.size())
#batch1=batch1.squeeze(1)
#print(batch1.size())
#
##b=torch.cat((batch1,batch2),2)
##print(b.size())
#print(batch1)
#print("batch1.sum():",batch1.sum())
#
#input = [
#    [2, 3, 4, 5, 0, 0],
#    [1, 4, 3, 0, 0, 0],
#    [4, 2, 2, 5, 7, 0],
#    [1, 0, 0, 0, 0, 0]
#]
#input = torch.tensor(input)
##注意index的类型
#length = torch.LongTensor([[4],[3],[5],[1]])
##index之所以减1,是因为序列维度是从0开始计算的
#out = torch.gather(input, 1, length-1)
#print(out)
#
#
#
#

#x = torch.randn(3,3, 4)
#print(x.size())
#x.squeeze(1)
#print(x.size())

# import random

# list = [20, 16, 10, 5]
# random.shuffle(list)
# print( "随机排序列表 : ",  list)

# random.shuffle(list)
# print( "随机排序列表 : ",  list)
# import torch
# import torch.nn as nn
# w = torch.empty(3, 5)
# print(w)
# nn.init.uniform_(-initrange, initrange)
# print(w)
import torch

# a=torch.Tensor([[1, 2, 3],[4, 5 ,6],[7, 8, 9],[10 ,11 ,12]])
# print(a)
# print(torch.triu(a))

# sz=5
# mask = (torch.triu(torch.ones(sz, sz)) == 1).transpose(0, 1)
# print(mask)
# mask = mask.float().masked_fill(mask == 0, float('-inf')).masked_fill(mask == 1, float(0.0))
# print(mask)
# a = torch.rand(5,6)
# print(a)
# b = a.narrow(0,2,3)
# print(b)

# data=torch.tensor([[1,2],[3,4],[5,6]])
# print(data)
# m=data.narrow(1,0,2)
# print(m)


# from transformers import pipeline
# classifier = pipeline('sentiment-analysis')
# pr=classifier('We are very happy to show you the Transformers library.')
# print(pr)
# results = classifier(["We are very happy to show you the Transformers library.","We hope you don't hate it."])
# for result in results:
#     print(f"label: {result['label']}, with score: {round(result['score'], 4)}")

import torch
import torch.nn as nn

# x = torch.Tensor([[1, 2], [3, 4]])
# pad = nn.ZeroPad2d(padding=(1, 2, 3, 4))
# y = pad(x)
# print(y)


# l = [torch.tensor([1,2,3]), torch.tensor([4,5]),torch.tensor([6,7,8,9])]
# emb_len=4
# # this is what you want:
# lp = torch.stack([torch.cat([i, i.new_zeros(emb_len - i.size(0))], 0) for i in l],1)

# print(l)
# print(lp)


# targets=torch.tensor([[20, 8, 12, 16, 13, 16,  4,  4, 16,  8, 16, 21, 16, 16,  8, 12, 22,  8,
#          10, 17],
#         [ 5,  4, 18, 10,  6,  5,  5, 17, 10,  4,  5, 17,  5,  5,  4,  4, 10,  4,
#          14, 12],
#         [15, 15,  5, 23,  5, 15,  6,  7, 23, 10, 12, 22, 15, 15, 16, 10,  7, 15,
#          15,  4],
#         [22,  3, 22, 24, 15,  4,  5,  2, 25, 17,  7,  5,  4,  4,  9,  8,  2,  3,
#          16,  5],
#         [17,  9, 26, 17,  3,  9,  9,  0,  5, 12,  2,  7,  7, 28,  2,  4,  0,  9,
#           7, 13],
#         [22,  2,  5, 24,  7,  2,  2,  0,  3, 17,  0,  2,  2,  2,  0,  5,  0,  2,
#           2, 15],
#         [13,  0,  6, 28,  2,  0,  0,  0,  7,  3,  0,  0,  0,  0,  0,  6,  0,  0,
#           0, 16],
#         [ 9,  0,  7,  2,  0,  0,  0,  0,  2,  9,  0,  0,  0,  0,  0,  7,  0,  0,
#           0,  9],
#         [ 2,  0,  2,  0,  0,  0,  0,  0,  0,  2,  0,  0,  0,  0,  0,  2,  0,  0,
#           0,  2]])
# targets.long()
# print(targets.dtype)
# yy=torch.cat((targets,torch.zeros(10-targets.size(0)-1,20,dtype=torch.long)),0)
# print(yy.size())
# print(yy.dtype)

# m = nn.Softmax(dim=0)
# input = torch.randn(2, 3)
# output = m(input)
# print(input)
# print(output)

# import unicodedata

# def unicodeToAscii(s):
#     return ''.join(
#              c for c in unicodedata.normalize('NFD',s)
#              if unicodedata.category(c)!='Mn'
#              )

# t="dfjladsjfaldfj dkafhaldkjf ASDADSADSAfdsgsdg@@@@@@@@@@@."
# print(unicodeToAscii(t))

# print(torch.cuda.is_available())
# # Python code to demonstrate copy operations 
  
# # importing "copy" for copy operations 
# import copy 
  
# # initializing list 1 
# li1 = [1, 2, [3,5], 4] 
  
# # using deepcopy to deep copy  
# li2 = copy.deepcopy(li1) 
  
# # original elements of list 
# print ("The original elements before deep copying") 
# for i in range(0,len(li1)): 
#     print (li1[i],end=" ") 
  
# print("\r") 
  
# # adding and element to new list 
# li2[2][0] = 7
  
# # Change is reflected in l2  
# print ("The new list of elements after deep copying ") 
# for i in range(0,len( li1)): 
#     print (li2[i],end=" ") 
  
# print("\r") 
  
# # Change is NOT reflected in original list 
# # as it is a deep copy 
# print ("The original elements after deep copying") 
# for i in range(0,len( li1)): 
#     print (li1[i],end=" ") 
    
    
# # Python code to demonstrate copy operations 
  
# # importing "copy" for copy operations 
# import copy 
  
# # initializing list 1 
# li1 = [1, 2, [3,5], 4] 
  
# # using copy to shallow copy  
# li2 = copy.copy(li1) 
  
# # original elements of list 
# print ("The original elements before shallow copying") 
# for i in range(0,len(li1)): 
#     print (li1[i],end=" ") 
  
# print("\r") 
  
# # adding and element to new list 
# li2[2][0] = 7
  
# # checking if change is reflected 
# print ("The original elements after shallow copying") 
# for i in range(0,len( li1)): 
#     print (li1[i],end=" ") 
    
assert 2 > 5
