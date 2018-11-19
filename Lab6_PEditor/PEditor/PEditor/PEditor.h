#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

string const Nu = "0";

class TEditor
{
//private:
	string CEdit; // ������
	string Editor; //  ����� ��? 

public:
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
	__declspec(property(get = GetStore, put = SetStore)) string Editor; 
};

bool TEditor::NumberIsNull()
{
	if (Editor == Nu) {
		return true;
	}
	else {
		return false;
	}
}

string TEditor::AddSign() 
{
	string ts;
	ts = Editor;
	if (ts[1] == '-') {
		ts.erase(ts.find('-'), 1);
	}
	else {
		ts.insert(1, "-");
	}
}

string  TEditor::AddPNumber(int a) // ���������� ���������
{
	string d;
	string ts;
	ts = Editor;
	if (ts == "0") {
		ts = "";
	}
	if (ts == "-0") {
		ts = "-";
	}
	switch (a)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		d = toString(a);
		break;
	case 10: 
		d = "A"; 
		break; 
	case 11: 
		d = "B"; 
		break; 
	case 12: 
		d = "C"; 
		break; 
	case 13: 
		d = "D";
		break; 
	case 14: 
		d = "E";
		break; 
	case 15: 
		d = "F";
		break; 

	default:
		cout << "������� �������� �������� ���" << toString(a) << " ������ �� ����������" << endl;
		break;
	}
	ts.insert(ts.length() + 1, d);
	Editor = ts;
	return Editor;
	
}

string TEditor::AddNull() 
{
	if (!NumberIsNull()) {
		string ts;
		ts = Editor;
		ts.insert(ts.length() + 1, "0");
	}
	return Editor;
}
string TEditor::BackSpace() 
{
	int n;
	string ts;
	ts = Editor;
	n = ts.length();
	if (ts[n] == ',') {
		ts.erase(ts.length() - 1, 1);
	}
	else {
		ts.erase(ts.length(), 1);
	}
	if ((ts == "") || (ts == "-") || (ts == "-,") || (ts == "-.") || (ts == ",")) {
		ts = Nu;
	}
}
string TEditor::Clear()
{
	Editor = Nu;
	return Editor;

 }

TEditor::TEditor(string Cr)
{
	CEdit = Cr;
}
string TEditor::GetStore() {
	return CEdit;
}
void TEditor::SetStore(string a) {
	CEdit = a;
}

string TEditor::Edit(int a) 
{
	string Result;
	switch (a) {
	case 0:
		Result = AddNull();
		break;
	case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:
	case 9:case 10:case 11:case 12:case 13:case 14:case 15: // some shit again
		Result = AddPNumber(a);
		break;
	case 20: // + or -
		Result = AddSign();
		break;
	case 21: // backSpace
		Result = BackSpace();
		break;
	case 22: //clear
		Result = Clear();
		break;
	default:
		cout << "������ �� ���������� �������" << endl;
		Result = Editor;
		break;

	}
	return Result;

}



string toString( int a) { // ???  some shit
	stringstream ss;
	ss << a;
	return ss.str();
}

