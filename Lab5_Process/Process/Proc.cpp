#include "Proc.h"

template<class C>
Proc<C>::Proc()
{
	Lop_Res = new C;
	Rop = new C;
	Operation = None;
}

template<class C>
Proc<C>::~Proc()
{
}

template<class C>
void Proc<C>::reset()
{
	Lop_Res = new C;
	Rop = new C;
	Operation = None;
}

template<class C>
void Proc<C>::OptnClear()
{
	Operation = None;
}

template<class C>
void Proc<C>::OptnRun()
{
	switch (Operation)
	{
	case Add: {
		Lop_Res = Lop_Res + Rop;
		break;
	}
	case Sub: {
		Lop_Res = Lop_Res - Rop;
		break;
	}
	case Mul: {
		Lop_Res = Lop_Res * Rop;
		break;
	}
	case Dvd: {
		Lop_Res = Lop_Res / Rop;
		break;
	}
	default:
		break;
	}
}

template<class C>
void Proc<C>::FuncRun()
{
	switch (Operation)
	{
	case Rev: {
		Rop = Rop.reverse();
		break;
	}
	case Sqr: {
		Rop = sqrt(Rop);
		break;
	}
	default:
		break;
	}
}

template<class C>
C Proc<C>::getLeft()
{
	return Lop_Res;
}

template<class C>
void Proc<C>::setLeft(C Operand)
{
	Lop_Res = Operand;
}

template<class C>
C Proc<C>::getRight()
{
	return Rop;
}

template<class C>
void Proc<C>::setRight(C Operand)
{
	Rop = Operand;
}

template<class C>
int Proc<C>::getOptn()
{
	return Option;
}

template<class C>
void Proc<C>::setOptn(int Oprtn)
{
	Option = Oprtn;
}
