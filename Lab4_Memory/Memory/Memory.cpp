#include "stdafx.h"
#include "Memory.h"

template<class C>
Memory<C>::Memory()
{
	Fnumber = new C;
	Fstate = false;
}

template<class C>
Memory<C>::~Memory()
{
}

template<class C>
void Memory<C>::write(C other)
{
	Fnumber = other;
	Fstate = true;
}

template<class C>
C Memory<C>::get()
{
	C temp = Fnumber;
	return temp;
}

template<class C>
void Memory<C>::add(C other)
{
	Fnumber = Fnumber + other;
	Fstate = true;
}

template<class C>
void Memory<C>::erase()
{
	Fnumber = new C;
	Fstate = false;
}

template<class C>
string Memory<C>::getState()
{
	return Fstate ? str("_On") : str("_Off");
}
