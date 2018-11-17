#pragma once
#include <string>
#include <cmath>

using namespace std;

class Fraction {
private:
	int x, y;
public:
<<<<<<< HEAD

	Fraction() {
			x = 0;
			y = 1;
		};
=======
	Fraction() {
		x = 0;
		y = 1;
	};
>>>>>>> 164653ded26e22ba8d4345b20b786dd24505a921

	Fraction(int a, int b){
		if (y == 0) {
			x = 0;
			y = 1;
		}
		else {
			y = b;
			x = a;
		}
		toShorten();
	};
	
	Fraction(double d){
        x = d * 100000;
        y = 100000;
        toShorten();
    }

	Fraction(string str) {
		stringstream ss{ str };
		(ss >> x).ignore(numeric_limits<streamsize>::max(), '/') >> y;
		if (y == 0) {
			x = 0;
			y = 1;
		}
		toShorten();
	};

	int GCD(int a, int b) {
		return b ? GCD(b, a%b) : a;
	};

	void toShorten() {
		int k = GCD(x, y);
		x /= k;
		y /= k;
		if (y < 0) {
			y *= -1;
			x *= -1;
		}
	};

	int getA() {
		return x;
	};
	int getB() {
		return y;
	};

	Fraction copy() {
		return Fraction(x, y);
	};

	Fraction operator + (const Fraction &f2) {
		return Fraction(x * f2.y + f2.x * y, y * f2.y);
	};

	Fraction operator * (const Fraction &f2) {
		return Fraction(x * f2.x, y * f2.y);
	};

	Fraction operator - (const Fraction &f2) {
		return Fraction(x * f2.y - f2.x * y, y * f2.y);
	};

	Fraction operator / (const Fraction &f2) {
		return Fraction(x * f2.y, y * f2.x);
	};
	
	Fraction square() {
		return Fraction(x * x, y * y);
	};

	Fraction reverse() {
		return Fraction(y, x);
	};

	Fraction operator - ()
	{
		return Fraction(x * -1, y);
	};

	const bool operator == (const Fraction &f2)
	{
		if ((x == f2.x) && (y == f2.y))
			return true;
		return false;
	}

	const bool operator > (const Fraction &f2)
	{
		double d1 = x / y;
		double d2 = f2.x / f2.y;

		return d1 > d2;
	}

	string getAstring() {
		stringstream ss;
		ss << x;
		return ss.str();
	}

	string getBstring() {
		stringstream ss;
		ss << y;
		return ss.str();
	}

	string toString() {
		stringstream ss;
		ss << x << "/" << y;
		return ss.str();
	}

	operator double() const
	{
		return double(this->x / this->y);
	}

	Fraction operator = (const double &d)
	{
		/*
		if (&f == this)
			return *this;
		return Fraction(this->x = f.x, this->y = f.y);
		*/
		this->x = d * 100000;
		this->y = 100000;
		toShorten();
		return *this;
	}
};