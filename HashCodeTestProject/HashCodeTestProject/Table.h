#pragma once
#include<vector>
#include<string>

class Table
{
public:
	Table();
	~Table();
	void init_table(int, int );
	void set(int, int, int);
	void print_table();
private:

	vector<string> commands;
	int r; int c;
	int ** tab;
};

