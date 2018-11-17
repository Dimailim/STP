#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Memory/Memory.h"
#include "../Memory/Memory.cpp"
#include "../../Lab1_Fraction/Fraction/fraction.h"
#include "../../Lab2_Complex/Complex/complex.h"
#include "../../Lab3_Pnumber/PNumber/Pnumber.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Memory_Test
{		
	TEST_CLASS(UnitTestMemory)
	{
	public:
		
		TEST_METHOD(Construct)
		{
			Memory<Fraction> f;
			Assert::AreEqual(string("0/1"), f.get().toString());

			Memory<Complex> c;
			Assert::AreEqual(string("0+i*0"), c.get().toString());

			Memory<Pnumber> p;
			Assert::AreEqual(string("0"), p.get().getAstring());
		}

	};
}