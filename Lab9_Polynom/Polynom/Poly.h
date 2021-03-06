#pragma once
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Member.h"

class Poly
{
private:
	vector<Member> vec;
public:
	Poly();
	Poly(int c, int n);
	Poly(vector<Member> v); //myself
	Poly(const Poly &q); //myself
	~Poly();

	int deg();
	int coef(int n);

	void clear();

	Poly operator + (const Poly &q);
	Poly operator - (const Poly &q);
	Poly operator * (const Poly &q);

	Poly operator - ();

	bool operator == (const Poly &q);

	Poly diff();

	double calculate(int x);

	Member at(int i);
	//myself

	string toString();
};

