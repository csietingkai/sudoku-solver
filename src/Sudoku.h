#ifndef SUDOKU_H_
#define SUDOKU_H_

using namespace std;

class Sudoku
{
	public:
		// constructor
		Sudoku(const string filename, const int size = 3);
		~Sudoku();
		
		// getters
		const string get_filename() const;
		const int get_size() const;
		const char get_element(const int row, const int col) const;
		const string to_string() const;
		
		// operators
		const Sudoku& operator =(const Sudoku& other);
		const bool operator ==(const Sudoku& other);
		friend ostream& operator <<(ostream& strm, const Sudoku& other);
		
		// functions
		const bool solve();
	
	private:
		string filename;
		int size;
		int square;
		int **elements;
		
		void load_file();
		
		const bool find_unsign(int& row, int& col);
		const bool is_safe(const int row, const int col, const int num);
		const bool used_in_box(const int row, const int col, const int num);
		const bool used_in_row(const int row, const int num);
		const bool used_in_col(const int col, const int num);
};

void error(const string err_msg);

#endif //SUDOKU_H_
