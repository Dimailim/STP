#pragma once
#include <string>
#include <vector>

using namespace std;

class Pnumber {
private:
	//int a, b, c;
public:
	double a;
	int b, c;

	Pnumber(double x, int y, int z) {
		a = x;
		b = y;
		c = z;
	}

	Pnumber(string sa, string sb, string sc) {
		stringstream ssa{ sa };
		ssa >> a;
		stringstream ssb{ sb };
		ssb >> b;
		stringstream ssc{ sc };
		ssc >> c;
	};

	Pnumber operator + (const Pnumber &p2) {
		if (b == p2.b && c == p2.c)
			return Pnumber(a + p2.a, b, c);
		else
			return Pnumber(0, 10, 0);
	};

	Pnumber operator * (const Pnumber &p2) {
		return Pnumber(a * p2.a, b, c);
	};

	Pnumber operator - (const Pnumber &p2) {
		return Pnumber(a - p2.a, b, c);
	};

	Pnumber operator / (const Pnumber &p2) {
		return Pnumber(a / p2.a, b, c);
	};

	Pnumber reverse() {
		return Pnumber(1/a, b, c);
	};

	Pnumber square() {
		return Pnumber(a * a, b, c);
	};

	double getA() {
		return a;
	}

	string getAstring() {
		vector<int> top, bot;
		int i = (int)a;
		double f = (a - (int)a);
		for (int q = 0; q < c && f - (int)f; ++q)
			f *= 10;
		int frac = f;

		while (i) {
			int d = i % b;
			top.push_back(d);
			i /= b;
		}

		while (frac) {
			int d = frac % b;
			bot.push_back(d);
			frac /= b;
		}
		
		stringstream ss;
		while (!top.empty()) {
			if (top.back() < 10) {
				ss << top.back();
			}
			else {
				char c = 55;
				ss << (char)(c + top.back());
			}
			top.pop_back();
		}
		

		if (c) {
			ss << ".";
			int count = 0;

			while (count < c && !bot.empty()) {
				if (bot.back() < 10) {
					ss << bot.back();
				}
				else {
					char c = 55;
					ss << (char)(c + bot.back());
				}
				++count;
				bot.pop_back();
			}

			while (count < c) {
				ss << "0";
				++count;
			}
		}
		return ss.str();
	}

	int getB(){
		return b;
	}

	string getBstring() {
		stringstream ss;
		ss << b;
		return ss.str();
	}

	int getC() {
		return c;
	}

	string getCstring() {
		stringstream ss;
		ss << c;
		return ss.str();
	}
	void setB(int x) {
		b = x;
	 }

	void setBstring(string str) {
		stringstream ss{ str };
		ss >> b;
	}

	void setC(int y) {
		c = y;
	}

	void setCstring(string str) {
		stringstream ss{ str };
		ss >> c;
	}
};