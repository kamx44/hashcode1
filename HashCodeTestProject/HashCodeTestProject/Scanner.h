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
	void init_test_table();
	void table_test();
private:
	Table *table;
	vector<string> commands;
	vector<int*> line_vertical;
	vector<int*> line_horizontal;
	Table *test;
	int r; int c;
};

