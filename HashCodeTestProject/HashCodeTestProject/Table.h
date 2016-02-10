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
	int get(int, int);
	void print_table();
	int r; int c;
private:

	
	
	int ** tab;
};

