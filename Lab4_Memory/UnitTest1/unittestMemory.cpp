#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Memory/Memory.h"
#include "../Memory/Memory.cpp"
#include "../../Lab1_Fraction/Fraction/fraction.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestMem
{		
	TEST_CLASS(UnitTestMem)
	{
	public:
		
		TEST_METHOD(MemConstruct)
		{
			Memory<Fraction> f;
			Assert::AreEqual(string("0/1"), f.get().toString());

			
		}
		TEST_METHOD(MemWrite)
		{
			Memory<int> w;
			w.write(0);
			Assert::AreEqual(0, w.get());
		}

		TEST_METHOD(MemAdd)
		{
			Memory<int> a;
			a.write(10);
			a.add(20);
			Assert::AreEqual(30, a.get());

		}

		TEST_METHOD(MemClear)
		{
			Memory<Fraction> f;
			f.write(string("1/2"));
			f.erase();
			Assert::AreEqual(string("_Off"),f.getState());
		}

		TEST_METHOD(MemgetState)
		{
			Memory <int> m;
			Memory <Fraction> f;
			m.write(100);
			Assert::AreEqual(string("_On"), m.getState());
			Assert::AreEqual(string("_Off"), f.getState());
		}

	};
}