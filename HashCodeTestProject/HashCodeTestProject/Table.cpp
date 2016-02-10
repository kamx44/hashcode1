#include "Table.h"



Table::Table()
{
}


Table::~Table()
{
}

void Table::init_table(int r, int c)
{
	tab = new int*[r];
	for (int i = 0; i < c; i++)
	{
		tab[i] = new int[c];
	}
	
}