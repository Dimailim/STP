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

	bool FracIsNull(); // дробь≈стьЌоль
	string AddSign(); // добавить«нак
	string AddFracNumber(int a); //добавить÷ифру
	string AddNull(); // добавитьЌоль
	string Backspace(); //забой—имвлоа
	string Clear(); // очистить
	FEditor(string Cr = Nu); //конструктор
	string GetStore(); // читать—трока¬формате—троки
	void SetStore(string a); // писать—трока¬формате—троки
	string Edit(int a); //  редактировать
	string AddSeparator();
};
string toString(int a) { 
	string str = to_string(a);
	return str;
}



