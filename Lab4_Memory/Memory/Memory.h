#pragma once
#include <string>

using namespace std;

template <class C>
class Memory
{
private:
	C Fnumber;
	bool Fstate;
public:
	Memory();
	~Memory();

	void write(C);

	C get();

	void add(C);

	void erase();

	string getState();

	//get == getNumber

	__declspec(property(get = get, put = write)) C Fnumber;
	__declspec(property(get = getState)) bool Fstate;
};
