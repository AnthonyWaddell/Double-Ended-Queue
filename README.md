# Double-Ended-Queue

Purpose 

To review the use in design and implementation of a recursive solution to solve a problem.  Analyze the complexity of a recursive algorithm and practice the use of recurrences. 

 

Problem Description 

Write a recursive program to solve the problem of the Fiji Explorers: three explorers and three cannibals come to a river and find a boat that holds two individuals.  If the cannibals ever outnumber the explorers on either bank, the explorers will be eaten.  How might they cross safely? Your task is  to write a program that will show the sequence in which all the individuals are transported from one side of the river to the other side, well and alive. 

Before starting to code, design and analyze your algorithm.    

This is typically a backtracking problem (like the 8 queens).   Understand what your search space looks like and identify valid/invalid states.   

The difference b/w Deque and a FIFO queue is that Deque has three additional methods: 

getBack( ): retrieves the tail object. 

removeBack( ): removes the tail object. 

addFront( object ): enqueues a new object to the front. 

All the other methods are functionally identical to those of the FIFO queues. 
