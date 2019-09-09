# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

from __future__ import print_function
import torch

x=torch.empty(5,3)
print(x)

#construct a randomly initialized matrix

x=torch.rand(5,3)
print(x)

#construct a matrix filled zeros and of dtype long:
x=torch.zeros(5,3,dtype=torch.long)
print(x)
# what is the meaning of dtype long????
# is the type of data

#construct a tensor directly from data:
x=torch.tensor([5.5,3])
print(x)

#or create a tensor based on an existing tensor.These method will reuse properties of
#the input tensor, e.g. dtype,unless new values are provided by user
x=x.new_ones(5,3,dtype=torch.double)# new_* methods take in sizes
print(x)

x=torch.randn_like(x,dtype=torch.float)#override dtype!
print(x)                                #result has the same size

#Get its size:
print(x.size())

#Note:
#torch.size() is in fact a tuple,so it supports all tuple operations
#tuple n. 元组；数据

#Operations:
#There are multiple syntaxes for operations. In the following example, we will take a\
#look at the addition operation.

#Addition:syntax 1
y=torch.rand(5,3)
print(x+y)

#Addition:syntax2
print(torch.add(x,y))

#Addition:providing an output tensor as argument
result=torch.empty(5,3)
torch.add(x,y,out=result)
print(result)

#Addition:in-place
#adds x to y
y.add_(x)
print(y)

#Note :\
#Any operation that mutates a tensor in-place is post-fixed with an _ ,For example:
#x.copy_(y),x.t_(),will change x.

#You can use standard NUMPY-like indexing with all bells and whistles!
print(x[:,1])
# just like matlab

#Resizing: If you want to resize/reshpe tensor, you can use torch.view:
x=torch.randn(4,4)
y=x.view(16)
z=x.view(-1,8)#the size -1 is inferred from other dimensions
print(x.size(),y.size(),z.size())

#If you have a one element tensor, use .item() to get the value as a Python number
x=torch.randn(1)
print(x)
print(x.item())

# NumPy Bridge
# Converting a Torch tensor to a NumPy array and vice versa is a breeze
#The Torch Tensor and NumPy array will share their underlying memory locations(if the 
#Torch Tensor is on CPU),and changeing one will change the other.

#Converting a Torch Tensor to NumPy Array
a=torch.ones(5)
print(a)
b=a.numpy()
print(b)

#See how the numpy array change in value
a.add_(1)
print(a)
print(b)

#Converting NumPy Array to Torch Tensor
#see how changing the np array changed the Torch Tensor automatically
import numpy as np
a=np.ones(5)
b=torch.from_numpy(a)
np.add(a,1,out=a)
print(a)
print(b)


















































