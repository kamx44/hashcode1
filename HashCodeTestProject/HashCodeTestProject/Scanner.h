#pragma once
#include "Table.h"

class Scanner
{
public:
	Scanner(Table* t);
	~Scanner();

	

	void scan_input();

private:
	Table *table;
	int r; int c;
};

