#include "Table.h"
#include <iostream>

using namespace std;


Table::Table()
{
}


Table::~Table()
{
}

void Table::init_table(int r, int c)
{
	tab = new int*[r];
	for (int i = 0; i < r; i++)
	{
		tab[i] = new int[c];
	}
	this->r = r; this->c = c;
}

void Table::set(int i, int j, int value)
{
	this->tab[i][j] = value;
}

void Table::print_table()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << tab[i][i] << " ";

		}
		cout << endl;
	}
}
