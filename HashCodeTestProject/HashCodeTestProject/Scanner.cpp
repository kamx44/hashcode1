#include "Scanner.h"
#include "Table.h"
#include <iostream>
#include <fstream>
#include <string>

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
	while (i<table->r&&j<table->c) {
		if (table->get(i,j) == 1) {
			check = true;
			 position = new int[2];
			 position[0] = i;
			 position[1] = j;
			 line_horizontal.push_back(position);
		}
		else if(table->get(i, j) != 1 && check==false){
			
		}
		else {
			check = false;
			int *pos = line_horizontal[0];
			j = pos[1];
			int jj = pos[1];
			int ii = pos[0];
			while (table->get(ii, jj) == 1) {
				position = new int[2];
				position[0] = ii;
				position[1] = jj;
				line_vertical.push_back(position);
				ii++;
			}
			if (line_horizontal.size() >= line_vertical.size()) {
				string line("kupa");
				int *pos1 = line_horizontal[0];
				int *pos2 = line_horizontal[line_horizontal.size()-1];
				line = "PAINT_LINE " + to_string(pos1[0]) + ' ' + to_string(pos1[1]) + ' ' + to_string(pos2[0]) + ' ' + to_string(pos2[1]);
				cout << line<<endl;
				commands.push_back(line);
				for (int i = 0; i < line_horizontal.size(); i++) {
					int *p = line_horizontal[i];
					table->set(p[0], p[1], 2);
				}
			}
			else {
				string line;
				int *pos1 = line_vertical[0];
				int *pos2 = line_vertical[line_vertical.size()-1];
				line = "PAINT_LINE " + to_string(pos1[0]) + ' ' + to_string(pos1[1]) + ' ' + to_string(pos2[0]) + ' ' + to_string(pos2[1]);
				cout << line << endl;
				commands.push_back(line);
				for (int i = 0; i < line_vertical.size(); i++) {
					int *p = line_vertical[i];
					table->set(p[0], p[1], 2);
				}
			}
			line_vertical.clear();
			line_horizontal.clear();
		}
		if (++j == table->c) {
			i++;
			j = 0;
		}
	}
}

void Scanner::print_commands() {
	for (int i = 0; i < commands.size(); i++) {
		cout << commands[i] << endl;
	}
	if (commands.size() == 0)
		cout << "no commands" << endl;
	else
		cout << commands.size() << endl;
}