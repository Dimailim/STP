#include "pch.h"
#include <iostream>
#include "PEditor.h"
#include <string>

using namespace std;

bool TEditor::NumberIsNull()
{
	if (CEdit == Nu || CEdit == ("-"+ Nu)) {
		return true;
	}
	else {
		return false;
	}
}

string TEditor::AddSign()
{

	if (CEdit[0] == '-') {
		CEdit.erase(CEdit.find('-'), 1);
	}
	else {
		CEdit = "-" + CEdit;
	}
	return CEdit; // ???
}

string  TEditor::AddPNumber(int a) // реализацию подглянул
{
	string d;
	string ts;
	ts = CEdit;
	if (ts == "0") {
		ts = "";
	}
	if (ts == "-0") {
		ts = "-";
	}
	switch (a)
	{
	case 1: case 2: case 3: 
	case 4: case 5: case 6: 
	case 7: case 8: case 9:
		d =  toString(a);
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
		cout << "Передан неверный числовой код" << toString(a) << " строка не изменилась" << endl;
		break;
	}
	ts.insert(ts.length() + 1, d);
	CEdit = d;
	return CEdit;

}

string TEditor::AddNull()
{
	if (!NumberIsNull()) {
		CEdit = '0' + CEdit;
		return CEdit;
	}
	
	
}
string TEditor::BackSpace()
{
	int n;
	n = CEdit.length();
	if (CEdit[n] == ',') {
		CEdit.erase(CEdit.length() - 1, 1);
	}
	else {
		CEdit.erase(CEdit.length(), 1);
	}
	if ((CEdit == "") || (CEdit == "-") || (CEdit == "-,") || (CEdit == "-.") || (CEdit == ",")) {
		CEdit = Nu;
	}
	
	return CEdit;
}
string TEditor::Clear()
{
	CEdit = Nu;
	return CEdit;

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
	case Add: // + or -
		Result = AddSign();
		break;
	case Erase: // backSpace
		Result = BackSpace();
		break;
	case Remove: //clear
		Result = Clear();
		break;
	default:
		cout << "Задана не корректная команда" << endl;
		Result = CEdit;
		break;

	}
	return Result;

}





int main()
{
  
}
