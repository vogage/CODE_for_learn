# -*- coding: utf-8 -*-
"""
Created on Mon Jul 29 18:19:10 2019

@author: HP
"""

#Neutral networks can be constructed using the torch.nn package
#Now that you had a glimpse of autograd,nn depends on autograd to define models and differentiate them. 
#An nn.Module contains layers and a method forward(input) that returns the output.

#A typical training procedure for a neural network is as follows:
# 1. Define the neural network that has some learnable parameters(or weights)
# 2. Iterate over a dataset of inputs
# 3. Process input through the network
# 4. Compute the loss(how far is the output from being correct)
# 5. propagate gradients back into the network's parameters
# 6. Update the weights of the network,typically using a simple update rule: 
# weight=weight-learning_rate*gradient


#Define the network

import torch
import torch.nn as nn
import torch.nn.functional as F

class Net(nn.Module):
    def __init__(self):
        super(Net,self).__init__()
        #1 input image channel, 6 out put channels ,3*3 square convolution kenel
        self.conv1=nn.Conv2d(1,6,3)
        self.conv2=nn.Conv2d(6,16,3)
        #an affine operation: y=Wx+b
        self.fc1=nn.Linear(16*6*6,120)  #6*6 from image dimension
        
        #why not 5*5 ??????????
        
        self.fc2=nn.Linear(120,84)
        self.fc3=nn.Linear(84,10)
        
    def forward(self,x):
        #Max pooling over a (2,2) window
        x=F.max_pool2d(F.relu(self.conv1(x)),(2,2))
        #If the size is a square you can only specify a single number
        x=F.max_pool2d(F.relu(self.conv2(x)),2)
        x=x.view(-1,self.num_flat_features(x))
        x=F.relu(self.fc1(x))
        x=F.relu(self.fc2(x))
        x=self.fc3(x)
        return x
    
    def num_flat_features(self,x):
        size=x.size()[1:]#all dimensions except the batch dimension
        num_features=1
        for s in size:
            num_features*=s;
        return num_features
    
    
net=Net()
print(net)

params=list(net.parameters())
print(len(params))
print(params[0].size())  #conv1's weight

print(params[1].size()) 

input=torch.randn(1,1,32,32)
out=net(input)
print(out)

#Zero the gradient buffers of all parameters and backprops with random gradients:
net.zero_grad()
out.backward(torch.randn(1,10))

#Note
# torch.nn only supports mini-batches. The entire torch.nn package only supports inputs that are
# a mini-batch of samples,and not a single sample

#For example,nn.Conv2d will take in a 4D Tensor of nSamples x nChannels x Height x Width.
#If you have a single sample, just use input.unsqueeze(0) to add a fake batch dimension

#before proceeding further,let's recap all the class you've seen so far

#Recap:
# 1. torch.Tensor - A multi-dimensional array with support for autograd operations like 
#backward(). Also holds the gradient w.r.t the tensor
# 2. nn.Module - Neural networks module.Convenient way of encapsulating（压缩） parameters, with
# helpers for moving them to GPU,exporting,loading,etc.
# 3. nn.Parameter - A kind of Tensor, that is automatically registered as a parameter
# when assigned as an attribute to a Module.
# 4. autograd.Function - Implements forward and backward definitions of an augograd operation.Every
# Tensor operation creates at least a single Function node that connects to functions that created a 
# Tensor and encodes its history.

#Loss function
# A loss function takes the (output, target)pair of inputs,and computes a value that estimates how
# far away the output is from the target.
# There are several different loss functions under the nn package.A simple loss is:nn.MSELoss which
# computes the mean-squared error between the input and the target.

#for example:
output=net(input)
target=torch.randn(10)# a dummy target , for example
print("iiiiiiiiiiii")
print(target)
print("oooooo")
target=target.view(1,-1)  #make it the same shape as output
print(target)
criterion=nn.MSELoss()

loss=criterion(output,target)
print(loss)


#Now,If you follow loss in the backward direction,using its .grad_fn attribute,you will see a 
#graph of computions that looks like this
print(loss.grad_fn) #MSELoss
print(loss.grad_fn.next_functions[0][0])#Linear
print(loss.grad_fn.next_functions[0][0].next_functions[0][0])#ReLU

#Backprop
#To backpropagate the error all we have to do is to loss.backward(). you need to clear the existing 
#gradients though,else gradients will be accumulated to existing gradients

#Now we shall call loss.backward(), and have a look at conv1's bias gradients before and after the backward

net.zero_grad()# zeros the gradient buffers of all parameters

print('conv1.bias.grad before backward')
print(net.conv1.bias.grad)

loss.backward()

print('conv1.bias.grad after backward')
print(net.conv1.bias.grad)

#Update the weights

#The simplest update rule used in practice is the Stochastic Gradient Descent(SGD):
#       weight=weight-learning_rate*gradient

#we can implement this using simple python code:
learning_rate=0.01
for f in net.parameters():
    f.data.sub_(f.grad.data*learning_rate)

#However, as you use neural networks, you want to use various different rules such as
# SGD, Nesterov-SGD,Adam,RMSProp,etc.To enable this ,we built a small package:
# torch.optim that implements all these methods.Using it is very simple:


import torch.optim as optim
optimizer=optim.SGD(net.parameters(),lr=0.01)
#create your optimizer
optimizer.zero_grad()
output=net(input)
loss=criterion(output,target)
loss.backward()
optimizer.step() #Does the update

















































































































































