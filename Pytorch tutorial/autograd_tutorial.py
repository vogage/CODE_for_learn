# -*- coding: utf-8 -*-
"""
Created on Sun Jul 28 14:36:25 2019

@author: HP
"""

#AUTOGRAD: AUTOMATIC DIFFERENTIATION
#Central to all neural networks in PyTorch is the autograd package.Let's first briefly visit this ,
#and we will then go to training our first neural network.
#The autograd package provides automatic differentation for all operations on Tensors.It is a define-
#by-run framework,which means that your backprop is defined by how your code is run,and that every single
#iteration can be different.

#Let us see this in more simple terms with some examples.

#Tensor

#torch.Tensor is the central class of the package.if you set its attribut .requires_grad as True,it
#starts to track all operations on it. when you finish your computation you can call .backward() and have 
#all the gradients computed automatically. The gradient for this tensor will accumulated int .grad attribute.

#There's one more class which is very important for autograd implementation -a Function.

#Tensor and Function are interconnected and build up an acyclic graph,that encodes a complete history of 
#computation.Each tensor has a .grad_fn attribute that references Function that has created the Tensor
#(except for Tensors created  by the user -their grad_fn is None).

#If you want to computee the derivatives, you can call .backward() on a Tensor. If Tensor is a scalar
#(i.e. it holds a one element data), you don't need to specify any arguments to backward(), however if
# if it has more elements, you need to specify a gradient argument that is a tensor of matching shape.

import torch

#Create a tensor and set requires_grad=True to track computation with it

x=torch.ones(2,2,requires_grad=True)
print(x)

#Do a tensor operation:
y=x+2
print(y)

#y was created as a result of an operation. so it has a grad_fn
print(y.grad_fn)

#Do more operations on y
z=y*y*3
out=z.mean()
print(z,out)

#.requiers_grad_(...) changes an existing Tensor's requirs_grad flag in-place.The
#input flag defaults to False if not given.
a=torch.randn(2,2)
a=((a*3)/(a-1))
print(a.requires_grad)
a.requires_grad_(True)
print(a.requires_grad)
b=(a*a).sum()
print(b.grad_fn)

#Gradients 
#Let's backprop now. Because out contains a single scalar, out.backward() is equivalent to 
#out.backward(torch.tensor(1.))
out.backward()

print(x.grad)

#This characteristic of vector-Jacobian product makes it very convenient to feed external gradients
#into a model that has non-scalar output.

#Now let's take a look at an example fo vector-Jacobian product:
x=torch.randn(3,requires_grad=True)
y=x*2
while y.data.norm()<1000:
    y=y*2
print(y)

v=torch.tensor([0.1,1.0,0.0001],dtype=torch.float)
y.backward(v)
print(x.grad)


#You can also stop autograd from tracking history on Tensors with .requires_grad=True by wrapping the code
#block in with torch.no_grad():
print(x.requires_grad)
print((x**2).requires_grad)

with torch.no_grad():
    print((x**2).requires_grad)





































































