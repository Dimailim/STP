#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

string const Nu = "0,";

class TEditor
{
private:
	string CEdit; // ������

public:
	enum
	{
		Add = 20,
		Erase = 21,
		Remove = 22
		
	}; // ???
	bool  NumberIsNull(); // �������������
	string AddSign(); // ������������
	string AddPNumber(int a); //���������-����� �����
	string AddNull(); // ������������
	string BackSpace(); // ������������
	string Clear(); // ��������
	TEditor(string Cr = Nu); // ����������
	string GetStore(); // ��������������������������
	void SetStore(string a); //��������������������������
	string Edit(int a); // �������������
	
};
string toString(int a) { // ???  some shit  how fix?
	string str = to_string(a);
	return str;
}



