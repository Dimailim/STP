#pragma once
#include <string>

using namespace std;
string const Nu = "0/1";

class FEditor
{
private:

	string FEdit;
	string const separator = "/";

public:

	enum 
	{
		Sign = 100,
		Erase,
		RemoveAll,
		Separator
	};

	bool FracIsNull(); // �������������
	string AddSign(); // ������������
	string AddFracNumber(int a); //�������������
	string AddNull(); // ������������
	string Backspace(); //������������
	string Clear(); // ��������
	FEditor(string Cr = Nu); //�����������
	string GetStore(); // ��������������������������
	void SetStore(string a); // ��������������������������
	string Edit(int a); //  �������������
	string AddSeparator();
};
string toString(int a) { 
	string str = to_string(a);
	return str;
}



