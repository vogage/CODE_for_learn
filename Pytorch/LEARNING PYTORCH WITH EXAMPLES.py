# -*- coding: utf-8 -*-
"""
Created on Fri Aug 23 10:10:34 2019

@author: Qiandehou
"""

import numpy as np

#N is batch size: D_in is input dimension;
#H is hidden dimension; D_out is output dimension.

N,D_in,H,D_out=64,1000,100,10

#Create random input and output data
x=np.random.randn(N,D_in)
y=np.random.randn(N,D_out)

#Randomly initialize weights
w1=np.random.randn(D_in,H)
w2=np.random.randn(H,D_out)


learning_rate=1e-6
for t in range(500):
    #Forward pass: compute predicted y
    h=x.dot(w1)
    h_relu=np.maximum(h,0)
    y_pred=h_relu.dot(w2)
    
    #Compute and print loss
    loss=np.square(y_pred-y).sum()
    print(t,loss)
    
    #Backprop to compute gradients of w1 and w2 with respect to loss
    grad_y_pred=2.0*(y_pred-y)
    grad_w2=h_relu.T.dot(grad_y_pred)
    grad_h_relu=grad_y_pred.dot(w2.T)
    grad_h=grad_h_relu.copy()
    grad_h[h<0]=0
    grad_w1=x.T.dot(grad_h)
    
    #Update weights
    w1-=learning_rate*grad_w1
    w2-=learning_rate*grad_w2
    
    if t==3:
        break
    
import torch

dtype=torch.float
device=torch.device("cpu")
#device=torch.device("cuda:0")#Uncomment this to run on GPu

#N is batch size;D_in is input dimension;
#H is hidden dimension; D_out is output dimension

N,D_in,H,D_out=64,1000,100,10

#Create random input and output data
x=torch.randn(N,D_in,device=device,dtype=dtype)
y=torch.randn(N,D_out,device=device,dtype=dtype)

#Randomly initialize weights
w1=torch.randn(D_in,H,device=device,dtype=dtype)
w2=torch.randn(H,D_out,device=device,dtype=dtype)

learning_rate=1e-6
for t in range(500):
    #Forward pass:compute predicted y
    h=x.mm(w1)
    h_relu=h.clamp(min=0)
    y_pred=h_relu.mm(w2)
    
    #Compute and print loss
    loss=(y_pred-y).pow(2).sum().item()
    if t%100==99:
        print(t,loss)
        
    #Backprop to compute gradients of w1 and w2 with respect to loss
    grad_y_pred=2.0*(y_pred-y)
    grad_w2=h_relu.t().mm(grad_y_pred)
    grad_h_relu=grad_y_pred.mm(w2.t())
    grad_h=grad_h_relu.clone()
    grad_h[h<0]=0
    grad_w1=x.t().mm(grad_h)
    
    #Update weights using gradient descent
    w1-=learning_rate*grad_w1
    w2-=learning_rate*grad_w2
    
    
dtype=torch.float
device=torch.device("cpu")
#device=torch.device("cuda:0")#Uncomment this to run on GPU

#N is batch size;D_in is input dimension
#H is hidden dimension;D_out is output dimension.
N,D_in,H,D_out=64,1000,100,10

#Create random Tensors to hold input and outputs.
#Setting requires_grad=False indicates that we do not need to compute gradients
#With respect to these Tensors during the backward pass.
x=torch.randn(N,D_in,device=device,dtype=dtype)
y=torch.randn(N,D_out,device=device,dtype=dtype)

#Create random Tensors for weights.
#Setting requires_grad=True indicates that we want to compute gradients with
#respect to these Tensors during the backward pass
w1=torch.randn(D_in,H,device=device,dtype=dtype,requires_grad=True)
w2=torch.randn(H,D_out,device=device,dtype=dtype,requires_grad=True)


learning_rate=1e-6
for t in range(500):
    #Forward pass : compute predicted y using operations on Tensors;these
    #are exactly the same operations we used to compute the forward pass using Tensors,
    #but we do not need to keep references to intermediate values since
    #we are not implementing the backward pass by hand
    y_pred=x.mm(w1).clamp(min=0).mm(w2)
    
    #Compute and print loss using operations on Tensors.
    #Now loss is a tensor of shape (1,)
    #loss.item() gets the scalar value held in the loss.
    loss=(y_pred-y).pow(2).sum()
    if t%100==99:
        print(t,loss.item())
        
    #Use autograd to compute the backward pass.This call will compute the 
    #gradient of loss with respect to all Tensors with requires_grad=True.
    #After this call w1.grad and w2.grad will be Tensors holding the gradient
    #of the loss with respect to w1 and w2 repectively
    loss.backward()
    
    #Manually update weights using gradient descent.Wrap in torch.no_grad()
    #because weights have requires_grad=True, but we don't need to track this
    #in autograd
    #An alternative way is to operate on weight.data and weight.grad.data.
    #Recall that tensor.data gives a tensor that shares the storage with
    #tensor, but doesn't track history
    #You can also use torch.optim.SGD to achieve this
    with torch.no_grad():
        w1-=learning_rate*w1.grad
        w2-=learning_rate*w2.grad
        
        #Manually zeros the gradients after updating weights
        w1.grad.zero_()
        w2.grad.zero_()
        
#PyTorch: Defining new autograd functions
#
#Under the hood, each primitive autograd operator is really two functions that operate on Tensors. 
#The forward function computes output Tensors from input Tensors. 
#The backward function receives the gradient of the output Tensors with respect to some scalar value, 
#and computes the gradient of the input Tensors with respect to that same scalar value.
#
#In PyTorch we can easily define our own autograd operator by defining a subclass of torch.
#autograd.Function and implementing the forward and backward functions. 
#We can then use our new autograd operator by constructing an instance and calling it like a function, 
#passing Tensors containing input data.
#
#In this example we define our own custom autograd function for performing the ReLU nonlinearity, 
#and use it to implement our two-layer network:      
#        

class MyReLU(torch.autograd.Function):
    """
    We can implement out own custom autograd Functions by subclassing 
    torch.autograd.Function and implementing the forward and backward passes
    which operate on Tensors.
    """
    
    @staticmethod
    def forward(ctx,input):
        """
        In the forward pass we receive a Tensor containing the input and return a
        Tensor containint the output.ctx is a contesxt object that can be used 
        to stach information for backward computation.You can cache arbitrary
        objects for use in the backward pass using the ctx.save_for_backward method
        """
        ctx.save_for_backward(input)
        return input.clamp(min=0)
    @staticmethod
    def backward(ctx,grad_output):
        """
        In the backward pass we receive a Tensor contain the gradient of the
        loss with respect to the output, and we need to compute the gradient of 
        the loss with respect to the input
        """
        input,=ctx.saved_tensors
        grad_input=grad_output.clone()
        grad_input[input<0]=0
        return grad_input
        
    
dtype=torch.float
device=torch.device("cpu")
#device=torch.device("cuda:0")#Uncomment this to run on GPU

#N is batch size; D_in is input dimension;
#H is hidden dimension;D_out is output dimension.
N,D_in,H,D_out=64,1000,100,10

#Create random Tensors to hold input and outputs.
x=torch.randn(N,D_in,device=device,dtype=dtype)
y=torch.randn(N,D_out,device=device,dtype=dtype)

#Create randomTensors for weights
w1=torch.randn(D_in,H,device=device,dtype=dtype,requires_grad=True)
w2=torch.randn(H,D_out,device=device,dtype=dtype,requires_grad=True)

learning_rate=1e-6
for t in range(500):
    #To apply out Function,we use Function.apply method.We alias this as 'relu'
    relu=MyReLU.apply
    
    #Forward pass:compute predicted y usint operations; we compute
    #ReLU using out custom autograd operation.
    y_pred=relu(x.mm(w1)).mm(w2)
    
    #Compute and print loss
    loss =(y_pred-y).pow(2).sum()
    if t%100==99:
        print(t,loss.item())
        
        
    #Use autograd to compute the backward pass.
    loss.backward()
    
    #Update weights using gradient descent
    with torch.no_grad():
        w1-=learning_rate*w1.grad
        w2-=learning_rate*w2.grad
        
        #Manually zero the gradients after updating weights
        w1.grad.zero_()
        w2.grad.zero_()

#---------------------------------------------------------------------------------------------------
import tensorflow as tf
import numpy as np

#First we set up thee computational graph:

#N is batch size; D_in is input dimension
#H is hidden dimension; D_out is output dimension
N,D_in,H,D_out=64,1000,100,10

#Create placeholders for the input and target data; these will be filled
#with real data when we execute the graph
x=tf.placeholder(tf.float32,shape=(None,D_in))
y=tf.placeholder(tf.float32,shape=(None,D_out))

#Create Variable for the weights and initialize them with random data.
#A TensorFlow Variable persists its value across executions of the graph
w1=tf.Variable(tf.random_normal((D_in,H)))
w2=tf.Variable(tf.random_normal((H,D_out)))

#Forward pass:Compute the predicted y using operations on Tensorflow Tensors
#Note that this code does not actually perform any numeric operations;
#it merely sets up the computational graph that we will later execute.
h=tf.matmul(x,w1)
h_relu=tf.maximum(h,tf.zeros(1))
y_pred=tf.matmul(h_relu,w2)

#Compute loss using operations on Tensorflow Tensors
loss = tf.reduce_sum((y-y_pred)**2.0)

#Compute gradient of the loss with respect to w1 and w2.
grad_w1,grad_w2=tf.gradients(loss,[w1,w2])

#Update the weights using gradient descent.To actually update the weights
#we need to evaluate new_w1 and new_2 when executing the graph.Note that
#in TensorFlow the act of updating the value of the weight is part of 
#the computational graph; in Pytorch this happens outside the computational graph
learning_rate=1e-6
new_w1=w1.assign(w1-learning_rate*grad_w1)
new_w2=w2.assign(w2-learning_rate*grad_w2)

#Now we have built out computational graph,so we enter a TensorFlow session to actually execute the graph
with tf.Session() as sess:
    #Run the graph once to initialize the Variables w1 and w2.
    sess.run(tf.global_variables_initializer())
    
    #Create numpy arrays holding the actual data for the inputs x and targets y
    x_value=np.random.randn(N,D_in)
    y_value=np.random.randn(N,D_out)
    for t in range(500):
        #Execute the graph many times.Each time it executes we want to bind x_value to x and 
        #y_value to y,specified with the feed_dict argument.
        #Each time we excute the graph we want to compute the values for loss
        #new_w1,and new_w2; the values of these Tensors are returned as numpy arrays
        loss_value, _, _=sess.run([loss,new_w1,new_w2],
                                  feed_dict={x:x_value,y:y_value})
        
        if t%100==99:
            print(t,loss_value)
            
#----------------------------------------------------------------------------------------------------------            
            
#nn module
#PyTorch: nn
#Computational graphs and autograd are a very powerful paradigm for defining complex operators 
#and automatically taking derivatives; however for large neural networks raw autograd can be a bit too low-level.
#
#When building neural networks we frequently think of arranging the computation into layers, 
#some of which have learnable parameters which will be optimized during learning.
#
#In TensorFlow, packages like Keras, TensorFlow-Slim, 
#and TFLearn provide higher-level abstractions over raw computational graphs that are useful for building neural networks.
#
#In PyTorch, the nn package serves this same purpose. 
#The nn package defines a set of Modules, which are roughly equivalent to neural network layers. 
#A Module receives input Tensors and computes output Tensors, 
#but may also hold internal state such as Tensors containing learnable parameters. 
#The nn package also defines a set of useful loss functions that are commonly used when training neural networks.
#
#In this example we use the nn package to implement our two-layer network:


#N is batch size; D_in is input dimension;
#H is hidden dimension; D_out is output dimension.
N,D_in,H,D_out=64,1000,100,10

#Create random Tensors to hold inputs and outputs
x=torch.randn(N,D_in)
y=torch.randn(N,D_out)

#Use the nn package to define our model as a sequence of layers.nn.Sequential
#is a Module which contains other Modules, and applies them in sequence to 
#produce its output.Each Linear Module computes output from input using a 
#linear function, and holds internal Tensors for its weight and bias.
model=torch.nn.Sequential(
        torch.nn.Linear(D_in,H),
        torch.nn.ReLU(),
        torch.nn.Linear(H,D_out),
)

#The nn package also contains defintions of popular loss functions; in this
#case we will use Mean Squared Error(MSE) as our loss funtion.
loss_fn=torch.nn.MSELoss(reduction='sum')

learning_rate=1e-4
for t in range(500):
    #Forward pass: compute predicted y by passing x to the model.Model objects override the __call__
    #operator so you can call them like functions. When doing so you pass a Tensor of input data to 
    #the Module and it produces a Tensor of output data.
    y_pred=model(x)
    
    #Compute and print loss.We pass Tensors containint the predicted and true
    #values of y.and the loss function returns a Tensor containing the loss.
    loss=loss_fn(y_pred,y)
    if t%100==99:
        print(t,loss.item())
        
    #Zero the gradients before running the backward pass.
    model.zero_grad()
    
    #Backward pass: compute gradient of the loss with respect to all the learnable 
    #parameters of the model.Internally, the parameters of each Module are stored in Tensors
    #with requires_grad=True ,so this call will compute gradients for all learnable paramters in
    #the model.
    loss.backward()
    
    #update the weights using gradient descent . Each parameter is a Tensor, so 
    #we can access its gradients like we did before
    with torch.no_grad():
        for param in model.parameters():
            param-=learning_rate*param.grad
            
#PyTorch: optim
#Up to this point we have updated the weights of our models by manually mutating the Tensors holding 
#learnable parameters (with torch.no_grad() or .data to avoid tracking history in autograd). 
#This is not a huge burden for simple optimization algorithms like stochastic gradient descent, 
#but in practice we often train neural networks using more sophisticated optimizers like AdaGrad, RMSProp, Adam, etc.

#The optim package in PyTorch abstracts the idea of an optimization algorithm and 
#provides implementations of commonly used optimization algorithms.

#In this example we will use the nn package to define our model as before, 
#but we will optimize the model using the Adam algorithm provided by the optim package:






    





























