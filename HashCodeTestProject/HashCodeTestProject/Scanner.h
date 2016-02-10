#pragma once
#include "Table.h"
#include<vector>
#include<string>

using namespace std;

class Scanner
{
public:
	Scanner(Table* t);
	~Scanner();

	

	void scan_input();
	void scan_table();
	void print_commands();

private:
	Table *table;
	vector<string> commands;
	vector<int*> line_vertical;
	vector<int*> line_horizontal;
	int r; int c;
};

