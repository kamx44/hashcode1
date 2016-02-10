#pragma once
class Table
{
public:
	Table();
	~Table();
	void init_table(int, int );
private:
	int ** tab;
};

