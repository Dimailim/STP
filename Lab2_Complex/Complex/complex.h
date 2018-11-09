#pragma once
#include <string>
#include <cmath>

#define M_PI 3.14159265358979323846

using namespace std;

class Complex{
private: 
	//double a, b;
public:
	double a, b;

	Complex(double x, double y){
		a = x;
		b = y;
	}

	Complex(string str) {
		stringstream ss{ str };
		ss >> a;
		char c;
		ss >> c >> c >> c;
		ss >> b; //numeric_limits<streamsize>::max(), "+i*"
	};

	Complex copy() {
		return Complex(a, b);
	}

	Complex operator + (const Complex &c2) {
		return Complex(a + c2.a, b + c2.b);
	};

	Complex operator * (const Complex &c2) {
		return Complex(a * c2.a - b * c2.b, a * c2.b + c2.a * b);
	};

	Complex square() {
		return Complex(a * a - b * b, a * b + a * b);
	}

	Complex reverse() {
		return Complex(a / (a * a + b * b), b / (a * a + b * b));
	}

	Complex operator - (const Complex &c2) {
		return Complex(a - c2.a, b - c2.b);
	};

	Complex operator / (const Complex &c2) {
		return Complex((a * c2.a + b * c2.b) / ( c2.a * c2.a + c2.b * c2.b),
			(c2.a * b - a * c2.b) / (c2.a * c2.a + c2.b * c2.b));
	};

	Complex operator - ()
	{
		return Complex(0, 0) - *this;
	};
	
	double cmod() {
		return sqrt(a * a + b * b);
	}

	double crad() {
		if (a > 0) {
			return atan(b / a);
		}
		else if(a == 0 && b > 0) {
			return M_PI / 2;
		}
		else if (a < 0) {
			return atan(b / a) + M_PI;
		}
		else {
			return -M_PI / 2;
		}
	}

	double cdeg() {
		return crad() * 180 / M_PI;
	}

	Complex cpow(int n) {
		return Complex(pow(cmod(), n) * cos(n * crad()),
			pow(cmod(), n) * sin(n * crad()));
	}

	Complex csqrt(int n, int i) {
		return Complex(sqrt(cmod()) * (cos((crad() + 2 * i * M_PI) / n)),
			sqrt(cmod()) * (sin((crad() + 2 * i * M_PI) / n)));
	}
	
	const bool operator == (const Complex &c2)
	{
		if ((a == c2.a) && (b == c2.b))
			return true;
		return false;
	}

	const bool operator != (const Complex &c2) {
		return !(*this == c2);
	}

	double getRe() {
		return a;
	}

	string getReString() {
		stringstream ss;
		ss << a;
		return ss.str();
	}

	double getIm() {
		return b;
	}

	string getImString() {
		stringstream ss;
		ss << b;
		return ss.str();
	}

	string toString() {
		stringstream ss;
		ss << a << "+i*" << b;
		return ss.str();
	}
};
