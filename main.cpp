#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "src/Sudoku.h"

using namespace std;

int main()
{
	Sudoku sudoku("map1", 4);
	cout << sudoku << endl;
	sudoku.solve();
	cout << sudoku << endl;
	
	return 0;
}
