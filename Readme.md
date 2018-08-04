# Caesar Cipher
Author: Ting-Kai Hu

Today Date: 2018-08-01

## Abstract
This is a simple practice for understand how to solve a sudoku.

To understand more about Sudoku: https://en.wikipedia.org/wiki/Sudoku

## Usage
### Instructions (in your main.cpp or any where else)
1. first include the header file
 ```
 include "Sudoku.h"
 ```
2. then load a Sudoku object
 ```
 Sudoku s(filename, size);
 ```
the first argument is the filename (type: string)

the second argument is the size (type: integer), default is 3

details are in the following

### Sudoku (class)
This created for solving a sudoku by load a txt file which store a sudoku question

The txt file format will like:
 ```
 // resources/map2.txt
 4 _ 6 _ _ 8 _ 2 _
 5 2 9 _ _ _ _ 7 3
 3 _ 1 _ 2 7 6 5 4
 2 3 5 4 _ 9 1 _ _
 6 1 8 5 _ 2 _ _ 9
 7 _ _ 1 8 6 _ _ _
 _ _ _ _ _ 3 5 1 8
 8 _ _ 7 6 1 4 9 _
 _ _ _ _ _ 5 3 6 7
 ```
just like the txt files in resources folder.

And the size means:

if you want to solve a 9*9 sudoku

then the size will be root(9) = 3

