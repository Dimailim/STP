#include "stdafx.h"
#include "Poly.h"


Poly::Poly()
{
	vec.push_back(Member());
}

Poly::Poly(int c, int n)
{
	if(c > 0)
		vec.push_back(Member(c, n));
	else
		vec.push_back(Member());
}

Poly::Poly(vector<Member> v)
{
	if (v.size() > 0)
		vec = v;
	else
		vec.push_back(Member());
}

Poly::~Poly()
{
}

int Poly::deg()
{
	int n = 0;
	if (vec.size()) {
		for (int i = 0; i < vec.size(); ++i) {
			n = max(n, vec[i].getDeg());
		}
	}
	return n;
}

int Poly::coef(int n)
{
	int c = 0;
	if (vec.size()) {
		for (int i = 0; i < vec.size(); ++i) {
			if (n == vec[i].getDeg()) {
				c = vec[i].getCoef();
				break;
			}
		}
	}
	return c;
}

void Poly::clear()
{
	vec.clear();
}

Poly Poly::operator+(const Poly & q)
{
	vector<Member> v;

	for (int i = 0; i < vec.size(); ++i) {
		for (int j = 0; j < q.vec.size(); ++j) {
			Member tmp = vec[i] + q.vec[j];
			if (!tmp.isNull()) {
				v.push_back(tmp);
			}
		}
	}
	return Poly(v);
}

Poly Poly::operator-(const Poly & q)
{
	vector<Member> v;

	for (int i = 0; i < vec.size(); ++i) {
		for (int j = 0; j < q.vec.size(); ++j) {
			Member tmp = vec[i] - q.vec[j];
			if (!tmp.isNull()) {
				v.push_back(tmp);
			}
		}
	}
	return Poly(v);
}

Poly Poly::operator*(const Poly & q)
{
	vector<Member> v;

	for (int i = 0; i < vec.size(); ++i) {
		for (int j = 0; j < q.vec.size(); ++j) {
			Member tmp = vec[i] * q.vec[j];
			if (!tmp.isNull()) {
				v.push_back(tmp);
			}
		}
	}
	return Poly(v);
}

Poly Poly::operator-()
{
	vector<Member> v;

	for (int i = vec.size() - 1; i > 0; --i) {
		v.push_back(-vec[i]);
	}
	return Poly(v);
}

bool Poly::operator==(const Poly & q)
{
	if (vec.size() == q.vec.size()) {
		for (int i = 0; i < vec.size(); ++i) {
			if (vec[i] != q.vec[i]) return false;
		}
	}
	return true;
}

Poly Poly::diff()
{
	vector<Member> v;

	for (int i = vec.size() - 1; i > 0; --i) {
		v.push_back(vec[i].diff());
	}
	return Poly(v);
}

double Poly::calculate(int x)
{
	double res = 0.0;

	for (int i = vec.size() - 1; i > 0; --i) {
		res += vec[i].calculate(x);
	}
	return res;
}

Member Poly::at(int i)
{
	if (i >= 0 && i < vec.size()) {
		return vec.at(i);
	}
	return Member();
}

string Poly::toString()
{
	string str;
	if (vec[0].isNegative()) str += "-";
	for (int i = 0; i < vec.size(); ++i) {
		if (vec[i].isNegative() && i > 0) str += "-";
		else if (i > 0) str += "+";
		str += vec[i].getCoef();
		str += "*x^";
		str += vec[i].getDeg();
	}
	return str;
}

