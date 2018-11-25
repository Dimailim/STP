#include "TEditor.h"
#include <regex>
#include <string>

bool FEditor::FracIsNull()
{
	regex fNumreg("-?0/?1*"); //  или  после 1 "+" - один или более раз ? 
	if (regex_match(FEdit, fNumreg)) {
		return true;
	}
	else {
		return false;
	}
}

string FEditor::AddSign()
{
	if (FEdit[0] == '-') {
		FEdit.erase(FEdit.find('-'), 1);
	}
	else {
		FEdit = "-" + FEdit;
	}
	return FEdit;
}

string FEditor::AddFracNumber(int a)
{
	string d;
		d = toString(a);
	FEdit.append(d);
	//FEdit = d;
	return FEdit;
}

string FEditor::AddNull()
{
	return AddFracNumber(0);
}

string FEditor::Backspace()
{
	int n;
	n = FEdit.length();
	FEdit.erase(n - 1, 1);
	if ((FEdit == "") || (FEdit == "-")) { // work
		FEdit = Nu;
	}
	return FEdit;
}

string FEditor::Clear()
{
	FEdit = Nu;
	return FEdit;
}

FEditor::FEditor(string Cr)
{
	regex fNumreg("-?(0|[1-9][0-9]*)/?[1-9][0-9]*");
	if (regex_match(Cr, fNumreg))
		FEdit = Cr;
}

string FEditor::GetStore()
{
	return FEdit;
}

void FEditor::SetStore(string a)
{
	regex fNumreg("-?(0|[1-9][0-9]*)/[1-9][0-9]*");
	if (regex_match(a, fNumreg))
		FEdit = a;
}

string FEditor::Edit(int a)
{
	string Result;
		
		if (a < 0 || a > 0) {
			Result = AddFracNumber(a);
		}
		if (a == 0) {
			Result = AddNull();
		}
		else{ 
			Result = FEdit;
		}
		switch (a)
		{
		case Sign: //  + or -
			Result = AddSign();
			break;
		case Erase: // backSpace
			Result = Backspace();
			break;
		case RemoveAll:
			Result = Clear();
			break;
		case Separator:
			Result = AddSeparator();
		default:
			break;
		}

	return Result;
}

string FEditor::AddSeparator()
{
	if (FEdit.find('/') == -1) {
		FEdit += "/";
	}
	return FEdit;
}



int main() {

 }