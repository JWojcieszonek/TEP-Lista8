#pragma once
#include <string>
using namespace std;


class CTable
{
public:
	CTable();
	CTable(string sName, int iTableLen);
	CTable(const CTable &pcOther);
	CTable(CTable &&cOther);
	~CTable();

	CTable operator=(const CTable &cOther);
	CTable& operator=(CTable &&cOther);
	CTable& operator+(CTable &&cOther);

	void vSetName(string sName);
	bool bSetNewSize(int iTableLen);
	void vPrint();
	void v_copy(const CTable &cOther);
	
	CTable *pcClone();
	static void v_mod_tab(CTable *pcTab, int iNewSize);
	static void v_mod_tab(CTable cTab, int iNewSize);

	static const string DEFAULT_NAME;
	static const int DEFAULT_TABLE_SIZE;
	static const int MAX_TABLE_SIZE;
private:
	string s_name;
	int i_table_size;
	int *pi_table;
};

