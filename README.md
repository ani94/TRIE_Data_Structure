Problem Statement 
------------------
Given ten million words (unsorted) with an average length of 8 characters. The task is to
search for a word from these ten million words.
Give your
a) Data structure with justification
b) Efficient algorithm
c) Complexity analysis to accomplish this task.


TRIE_Data_Structure
===================

A trie, also called digital tree or sometimes radix tree or prefix tree (as they can be searched by prefixes),
is an ordered tree data structure that is used to store a dynamic set or associative array where the keys are 
usually strings. Unlike a binary search tree, no node in the tree stores the key associated with that node;
instead, its position in the tree defines the key with which it is associated. All the descendants of a node
have a common prefix of the string associated with that node, and the root is associated with the empty string.
Values are normally not associated with every node, only with leaves and some inner nodes that correspond to 
keys of interest.

**I have implemented Trie in C++ and Python**

File Structure
===============

* main.cpp - User Interface code File  - Trie Implemented
* code_for_inp.cpp - File Oriented Main code File - Trie + Cache Implemented
* serialize.py - Code for serializing the data for fast processing 
* 11million.txt - Text file which contains 11 million data words .
* result.txt - File Containing Serialized Data 
* medium_in_58110 - File containing 58110 words

Prerequisites of System 
========================

* Python Interpreter
* G++ compiler
* CPickle Python Library

Instructions on running the code 
================================

* For running `main.cpp` 
..* `g++ main.cpp`
..* `./a.out`

* For running `code_for_inp.cpp` 
..* `g++ code_for_inp.cpp`
..* `./a.out < medium_in_58110`

* For running `serialize.py` 
..* `python serialize.py`
