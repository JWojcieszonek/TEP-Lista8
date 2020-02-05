#include "CTable.h"
#include <iostream>
using namespace std;

int main()
{
	CTable tab1 = CTable("tab1", 5);
	CTable tab2 = CTable("tab2", 10);
	//CTable tab3 = CTable(std::move(tab1));
	//tab2 =std::move(tab3);
	tab1 +std::move( tab2);
	tab1.vPrint();
	return 0;
}