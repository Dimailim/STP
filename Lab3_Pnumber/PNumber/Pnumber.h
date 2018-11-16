#pragma once
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

class Pnumber {
private:
	//int a, b, c;
public:
	double a;
	int b, c;

	Pnumber(double x, int y, int z) {
		b = y;
		if (b == 2 || b == 8 || b == 10 || b == 16) {
			a = x;
			c = z;
		}
		else {
			a = 0;
			b = 0;
			c = 0;
		}
	}

	Pnumber(string sa, string sb, string sc) {
		std::istringstream(sb) >> b;
		std::istringstream(sc) >> c;
		if (b == 8 || b == 16) {
			int top;
			stringstream ss(sa);
			ss >> std::setbase(b) >> top;

			if (c > 0) {
				int bot;
				char ch;
				ss >> ch >> bot;
				double tmp = bot;
				while(tmp > 1)
					tmp /= 10;
				a = top + tmp;
			}
			else {
				a = top;
			}
		}
		else if (b == 10) {
			a = stod(sa);
		}
		else if (b == 2) {
			a = fromBin(sa);
		}
		else{
			a = 0;
			b = 0; 
			c = 0;
		}
	};

	double fromBin(string str) {
		int top = 0, tmp = 0, dot;
		double bot = 0;
		

		if (dot = str.find('.')) {
			if (dot > 0) {
				string t = str.substr(0, dot);
				string b = str.substr(dot + 1);
				while (!t.empty()) {
					top = top << 1;
					top += (t.front() == '1') ? 1 : 0;
					t = t.substr(1);
				}

				while (!b.empty()) {
					tmp = tmp << 1;
					tmp += (b.front() == '1') ? 1 : 0;
					b = b.substr(1);
				}

				bot = tmp;
				while (bot > 1)
					bot /= 10;
			}
		}
		else {
			stringstream ss(str);
			ss >> tmp;
			vector<int> v;
			while (tmp > 0) {
				v.push_back(tmp % 2);
				tmp /= 10;
			}

			while (!v.empty()) {
				top = top << 1;
				top += v.back();
				v.pop_back();
			}
		}
		
		return (double)top + bot;
	}

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
		stringstream ss;
		int top, bot;
		float ttop, tbot;
		int bs;
		tbot = modf((float)a, &ttop);
		top = ttop;

		for (bs = 0; bs < c && modf(tbot, &ttop); ++bs) {
			tbot *= 10;
		}
		bot = tbot;

		if (b == 2) {
			string str;
			while (top) {
				str.insert(0, (top % 2) ? "1" : "0");
				top /= 2;
			}
			ss << str;

			if (c) {
				ss << '.';
				str.clear();

				while (bot) {
					str.insert(0, (bot % 2) ? "1" : "0");
					bot /= 2;
				}

				while (str.length() < c) {
					str.insert(0, "0");
				}
				while (str.length() > c) {
					str.pop_back();
				}

				ss << str;
			}
		}
		else if (b == 8 || b == 16) {
			ss << std::setbase(b) << top;
			if (c) {
				ss << '.';

				stringstream tss;
				tss << std::setbase(b) << bot;
				string tstr = tss.str();
				while(tstr.length() < c) {
					tstr.insert(0, "0");
				}
				while (tstr.length() > c) {
					tstr.pop_back();
				}

				ss << tstr;
			}
		}
		else if (b == 10) {
			ss << fixed << setprecision(c) << a; // << fixed << setprecision(4)
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
		if (x == 2 || x == 8 || x == 10 || x == 16)
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