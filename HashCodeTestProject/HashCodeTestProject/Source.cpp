#include <iostream>
#include "Scanner.h"
#include "Table.h"

using namespace std;


int main()
{
	Table *table = new Table();


	Scanner* scanner = new Scanner(table);
	scanner->scan_input();
	scanner->scan_table();
	scanner->print_commands();
	scanner->table_test();
	system("PAUSE");
	return 0;
}