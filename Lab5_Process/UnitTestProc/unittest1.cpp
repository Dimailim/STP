#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Process/Proc.h"
#include "../Process/Proc.cpp"
#include "../../Lab1_Fraction/Fraction/fraction.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestProc
{		
	TEST_CLASS(UnitTestProc)
	{
	public:
		
		TEST_METHOD(TestConstruct)
		{
			Proc<Fraction> f;
			Assert::AreEqual(string("0/1"), f.getLeft().toString());
			Assert::AreEqual(string("0/1"), f.getRight().toString());
			Assert::AreEqual((int)f.None, f.getOptn());

		}

	};
}