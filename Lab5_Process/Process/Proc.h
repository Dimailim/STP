#pragma once
#include <cmath>

template<class C>
class Proc
{
private:
	C Lop_Res, Rop;
	int Operation;
public:

	enum {
		None = 0,
		Add,
		Sub,
		Mul,
		Dvd,
		Rev,
		Sqr
	};

	Proc();
	~Proc();

	void reset();

	void OptnClear();

	void OptnRun();

	void FuncRun();

	C getLeft();

	void setLeft(C);

	C getRight();

	void setRight(C);

	int getOptn();

	void setOptn(int);
};

