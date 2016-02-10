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

		//cout << "Rows: " << r;
		//cout << "Columns: " << c;
		table->init_table(r, c); // Initializes a table representing input
		file.close();
		file.open("right_angle.in", ios::in);
		if (file.good() == true)
		{
			getline(file, sample_string);
			//int i = 0;
			for (int i = 0; i < r;i++)
			{
				getline(file, sample_string);
				for (int j = 0; j < c; j++)
				{
					if (sample_string[j] == '#')
						table->set(i, j, 1);				
					else
						table->set(i, j, 0);
				}

				
				
				i++;
			}
			table->print_table();

		}
		else
			cout << endl << "Error reading a file" << endl;


	}
	else
		cout << endl << "Error reading a file" << endl;

}
