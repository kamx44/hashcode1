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
					if (sample_string.at(j) == '#')
						table->set(i, j, 1);				
					else
						table->set(i, j, 0);
				}			
			}

			table->print_table();

		}
		else
			cout << endl << "Error reading a file" << endl;


	}
	else
		cout << endl << "Error reading a file" << endl;

}


void Scanner::scan_table() {
	int taby = 10;
	int tabx = 10;
	int *position;
	bool check = false;
	bool exit = false;
	int i = 0;
	int j = 0;
	while (i<taby&&j<tabx) {
		if (table[i][j] == 1) {
			check == true;
			 position = new int[2];
			 position[0] = i;
			 position[1] = j;
			 line_horizontal.push_back(position);
		}
		else if(table[i][j] != 1 && check==false){
			j++;
			continue;
		}
		else {
			int *pos = line_horizontal[0];
			int j = pos[1];



		}
	}
}
