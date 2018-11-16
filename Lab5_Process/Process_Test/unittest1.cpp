#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Process/Proc.h"
#include "../Process/Proc.cpp"
#include "../../Lab1_Fraction/Fraction/fraction.h"
#include "../../Lab2_Complex/Complex/complex.h"
#include "../../Lab3_Pnumber/PNumber/Pnumber.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Process_Test
{		
	TEST_CLASS(UnitTestProcess)
	{
	public:
		
		TEST_METHOD(TestConstructor)
		{
			Proc<Fraction> f;
			Assert::AreEqual(string("0/1"), f.getLeft().toString());
			Assert::AreEqual(string("0/1"), f.getRight().toString());
			Assert::AreEqual((int)f.None, f.getOptn());

			Proc<Complex> c;
			Assert::AreEqual(string("0+i*0"), c.getLeft().toString());
			Assert::AreEqual(string("0+i*0"), c.getRight().toString());
			Assert::AreEqual((int)c.None, c.getOptn());

			Proc<Pnumber> p;
			Assert::AreEqual(string("0"), p.getLeft().getAstring());
			Assert::AreEqual(string("0"), p.getRight().getAstring());
			Assert::AreEqual((int)p.None, p.getOptn());
		}

	};
}