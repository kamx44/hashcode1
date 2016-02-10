#pragma once
#include "Table.h"
#include<vector>

class Scanner
{
public:
	Scanner(Table* t);
	~Scanner();

	

	void scan_input();
	void scan_table();

private:
	Table *table;
	vector<int*> line_vertical;
	vector<int*> line_horizontal;
	int r; int c;
};

