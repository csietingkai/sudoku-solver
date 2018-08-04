#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Sudoku.h"

using namespace std;

// constructor
Sudoku::Sudoku(const string filename, const int size)
{
	this->filename = filename;
	this->size = size;
	this->square = size * size;
	
	this->elements = new int*[size*size];
	for(int i = 0; i < size*size; i++)
	{
		this->elements[i] = new int[size*size];
		for(int j = 0; j < size*size; j++)
		{
			this->elements[i][j] = 0;
		}
	}
	
	load_file();
}

Sudoku::~Sudoku()
{
	for(int i = 0; i < this->square; i++)
	{
		delete[] this->elements[i];
	}
	delete[] this->elements;
}

// getters
const string Sudoku::get_filename() const
{
	return this->filename;
}

const int Sudoku::get_size() const
{
	return this->size;
}

const char Sudoku::get_element(const int row, const int col) const
{
	if(row < 0 || row >= square || col < 0 || col >= square)
	{
		error("Index out of bound");
	}
	return this->elements[row][col];
}

const string Sudoku::to_string() const
{
	string re = "";
	
	for(int i = 0; i < square; i++)
	{
		for(int j = 0; j < square; j++)
		{
			if(j%size == 0)
			{
				re += " ";
			}
			if(elements[i][j]/10 == 0)
			{
				re += " ";
			}
			re += " ";
			re += std::to_string(elements[i][j]);
		}
		if((i+1)%size == 0)
		{
			re += '\n';
		}
		if(i != square-1)
		{
			re += '\n';
		}
	}
	
	return re;
}

// oparators
const Sudoku& Sudoku::operator =(const Sudoku& other)
{
	if(this == &other)
	{
		return *this;
	}
	
	this->filename = other.get_filename();
	this->size = other.get_size();
	this->square = other.get_size()*other.get_size();
	for(int i = 0; i < square; i++)
	{
		for(int j = 0; j < square; j++)
		{
			this->elements[i][j] = other.get_element(i, j);
		}
	}
	
	return *this;
}

const bool Sudoku::operator ==(const Sudoku& other)
{
	if(this->filename.compare(other.get_filename()) == 0 && 
	   this->to_string().compare(other.to_string()) == 0)
	{
		return true;
	}
	return false;
}

ostream& operator <<(ostream& strm, const Sudoku& other)
{
	strm << other.to_string();
	return strm;
}

// functions
const bool Sudoku::solve()
{
	int row = 0;
	int col = 0;
	if(find_unsign(row, col) == false)
	{
		return true;
	}
	else
	{
		for(int num = 1; num <= square; num++)
		{
			if (is_safe(row, col, num))
			{
				elements[row][col] = num;
				//cout << "solving (" << row << ", " << col << ") ";
				//cout << "with value: " << num << endl;
				//cout << *this << endl;

				if (solve() == true)
				{
					return true;
				}

				elements[row][col] = 0;
			}
		}
		return false;
	}
}

// private function
void Sudoku::load_file()
{
	ifstream fin("resources/"+filename+".txt");
	
	if(fin.is_open() == false)
	{
		error("can not open input file");
	}
	
	string strin;
	int row = 0;
	while(getline(fin, strin))
	{
		istringstream iss(strin);
		vector<string> tokens;
		tokens.resize(square);
		for(int col = 0; col < square; col++)
		{
			getline(iss, tokens[col], ' ');
			cout << tokens[col] << " ";
			if(tokens[col].compare("_") == 0)
			{
				tokens[col] = "0";
			}
			elements[row][col] = stoi(tokens[col]);
		}
		cout << endl;
		row++;
	}
	
	fin.close();
}

const bool Sudoku::find_unsign(int& row, int& col)
{
	for(row = 0; row < square; row++)
	{
		for(col = 0; col < square; col++)
		{
			if(elements[row][col] == 0)
			{
				return true;
			}
		}
	}
	return false;
}

const bool Sudoku::is_safe(const int row, const int col, const int num)
{
	return !used_in_row(row, num) && !used_in_col(col, num) && !used_in_box(row - row%size , col - col%size, num);
}

const bool Sudoku::used_in_box(const int row, const int col, const int num)
{
	for(int r = 0; r < size; r++)
	{
		for(int c = 0; c < size; c++)
		{
			if(elements[r+row][c+col] == num)
			{
				return true;
			}
		}
	}
    return false;
}

const bool Sudoku::used_in_row(const int row, const int num)
{
	for(int col = 0; col < square; col++)
    {
		if(elements[row][col] == num)
		{
			return true;
		}
	}
	return false;
}

const bool Sudoku::used_in_col(const int col, const int num)
{
	for(int row = 0; row < square; row++)
    {
		if(elements[row][col] == num)
		{
			return true;
		}
	}
	return false;
}

void error(const string err_msg)
{
	throw std::invalid_argument(err_msg);
}
