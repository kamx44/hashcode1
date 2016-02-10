#include "Scanner.h"
#include "Table.h"
#include <iostream>
#include <fstream>
#include <String>

using namespace std;

Scanner::Scanner(Table *t)
{
	this->table = t;

}


Scanner::~Scanner()
{
	
}

void Scanner::scan_input()
{
	fstream file;
	file.open("right_angle.in", ios::in);
	if (file.good() == true)
	{
		r = 0; c = 0;
		string sample_string;
		getline(file, sample_string);
		getline(file, sample_string);
		c = sample_string.size();
		while (!file.eof())
		{
			getline(file,sample_string);
			r++;


		}

		cout << "Rows: " << r;
		cout << "Columns: " << c;

	}
	cout << endl << "Error reading a file" << endl;

}
