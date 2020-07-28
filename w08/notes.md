# Week 8 Tutorial: Hashing, Heaps, Tries

## Two sum problem
Given an array of integers A and a value V, can we find two numbers in A that add up to V in time:
- O(n^2) : two loops, look through every possible combination of pairs
- O(nlogn) : sort (nlogn) + two pointers at start & end (n)
- O(n) : use hashtable

A = [ 5 8 6 4 3 7 9 ]
A = [ 3 4 5 6 7 8 9 ]
      ^       ^
V = 10

Hash table:
key: int
value: int -> inverse of the key (V - key)

hashtable: 5, 2, 4, 

## Hash tables
- hash table: key value store
- hash function
- collision resolution
    - linked lists
    - linear probing
    - double hash
- trivia: birthday problem
- resizing

## Heaps
- max heap (parent > child)
- min heap (parent < child)
- array representation
- fix up, fix down
- used in a priority queue

## Tries
- dictionary data structure
- insertion and lookup

## Assignment
- Poll
- Must use your private group Wiki

## Lab
- Please move into assignment groups.
- Nanway and I will first move through each group, please show us your Wiki + GitHub repo
- Marking as normal
