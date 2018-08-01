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

the second argument is the size (type: integer)

details are in the following

### Sudoku (class)
This created for solving a sudoku by load a txt file which store a sudoku question

The txt file format will like:
 ```
 5_89_6_42
 _97_341_5
 __42_7__3
 3715_9_24
 __21_____
 _6_7__351
 __5392_1_
 ___6__279
 _26_71__8
 ```
