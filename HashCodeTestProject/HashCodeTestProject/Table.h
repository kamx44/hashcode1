#pragma once
#include<vector>
#include<string>

class Table
{
public:
	Table();
	~Table();
	void init_table(int, int );
private:
	vector<string> commands;
	int ** tab;
};

