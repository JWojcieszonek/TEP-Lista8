#include "CTable.h"
#include <iostream>
#include <ctype.h>
using namespace std;

const string CTable::DEFAULT_NAME="Name";
const int CTable::DEFAULT_TABLE_SIZE = 5;
const int CTable::MAX_TABLE_SIZE = 10000;

CTable::CTable()
{
	s_name = DEFAULT_NAME;
	cout << "bezp: " << s_name << endl;
	i_table_size = DEFAULT_TABLE_SIZE;
	pi_table = new int[i_table_size];
	for (int ii = 0; ii < i_table_size; ii++) 
	{
		pi_table[ii] = 0;
	}
}

CTable::CTable(string sName, int iTableLen)
{
	s_name = sName;
	cout << "parametr: " << s_name << endl;
	if (iTableLen > 0 && iTableLen < MAX_TABLE_SIZE)
		i_table_size = iTableLen;
	else
		i_table_size = DEFAULT_TABLE_SIZE;
	pi_table = new int[i_table_size];
	for (int ii = 0; ii < i_table_size; ii++)
	{
		pi_table[ii] = 0;
	}
}

CTable::CTable(const CTable &pcOther)
{
	s_name = pcOther.s_name + "_copy";
	cout << "kopiuj: " << s_name << endl;
	v_copy(pcOther);
}

CTable::CTable(CTable && cOther)
{
	pi_table = cOther.pi_table;
	i_table_size = cOther.i_table_size;
	s_name = cOther.s_name;
	cOther.pi_table = NULL;
	cOther.i_table_size = 0;
	std::cout << "MOVE" << endl;
}

CTable::~CTable()
{
	if(pi_table!=NULL)
	{
		cout << "usuwam: " << s_name << endl;
		delete[] pi_table;
	}
	
}

CTable CTable::operator=(const CTable & cOther)
{
	if (pi_table != NULL)
		delete pi_table;
	v_copy(cOther);
	std::cout << "op=" << endl;
	return *this;
}

CTable& CTable::operator=(CTable && cOther)
{
	if (this != &cOther)
	{
		if (pi_table != NULL)
			delete pi_table;
		pi_table = cOther.pi_table;
		i_table_size = cOther.i_table_size;
		s_name = cOther.s_name;
		cOther.pi_table = NULL;
		cOther.i_table_size = 0;
		std::cout << "MOVE" << endl;
	}
	return *this;
}

CTable&  CTable::operator+(CTable && cOther)
{
	int old_size= i_table_size;
	bSetNewSize(i_table_size + cOther.i_table_size);
	for (int ii=old_size; ii < i_table_size; ii++)
	{
		pi_table[ii] = cOther.pi_table[ii - old_size];
		
	}
	cOther.pi_table = NULL;
	cOther.i_table_size = 0;
	return *this;
}

void CTable::vSetName(string sName)
{
	s_name = sName;
}

bool CTable::bSetNewSize(int iTableLen)
{
	if (iTableLen <= 0 || iTableLen > MAX_TABLE_SIZE) return(false);
	int *pt_new_table;
	pt_new_table = new int[iTableLen];
	if (pi_table != NULL)
	{
		int i_min_len;
		if (iTableLen < i_table_size)
			i_min_len = iTableLen;
		else
			i_min_len = i_table_size;
		for (int ii = 0; ii < i_min_len; ii++)
			pt_new_table[ii] = pi_table[ii];
		delete[] pi_table;
	}
	pi_table = pt_new_table;
	i_table_size = iTableLen;
	return(true);
	
}

void CTable::vPrint()
{
	if (pi_table != NULL)
	{
		for (int ii = 0; ii < i_table_size; ii++)
		{
			cout << pi_table[ii]<<endl;
		}
	}
}

void CTable::v_copy(const CTable & cOther)
{
	pi_table = new int[cOther.i_table_size];
	i_table_size = cOther.i_table_size;
	s_name = cOther.s_name;

	for (int ii = 0; ii < cOther.i_table_size; ii++)
	{
		pi_table[ii] = cOther.pi_table[ii];
	}
}

CTable * CTable::pcClone()
{	
	return new CTable(this->s_name,this->i_table_size);
}

void CTable::v_mod_tab(CTable *pcTab, int iNewSize)
{
	if(iNewSize>0 && iNewSize< MAX_TABLE_SIZE)
		pcTab->bSetNewSize(iNewSize);
}
void CTable:: v_mod_tab(CTable cTab, int iNewSize)
{
	if (iNewSize > 0 && iNewSize < MAX_TABLE_SIZE)
		cTab.bSetNewSize(iNewSize);
}



