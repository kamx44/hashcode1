#pragma once
class Table
{
public:
	Table();
	~Table();
	void init_table(int, int );
	void set(int, int, int);
	void print_table();
private:
	int r; int c;
	int ** tab;
};

