#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Process/Proc.h"
#include "../Process/Proc.cpp"
#include "../../Lab1_Fraction/Fraction/fraction.h"
<<<<<<< HEAD
=======
#include "../../Lab2_Complex/Complex/complex.h"
#include "../../Lab3_Pnumber/PNumber/Pnumber.h"
>>>>>>> 164653ded26e22ba8d4345b20b786dd24505a921

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Process_Test
{		
	TEST_CLASS(UnitTestProcess)
	{
	public:
		
<<<<<<< HEAD
		TEST_METHOD(TestConstruct)
=======
		TEST_METHOD(TestConstructor)
>>>>>>> 164653ded26e22ba8d4345b20b786dd24505a921
		{
			Proc<Fraction> f;
			Assert::AreEqual(string("0/1"), f.getLeft().toString());
			Assert::AreEqual(string("0/1"), f.getRight().toString());
			Assert::AreEqual((int)f.None, f.getOptn());
<<<<<<< HEAD
		}
		TEST_METHOD(ProcReset)
		{
			Proc<int> p;
			p.setLeft(1);
			p.setRight(0);
			p.reset();
			Assert::AreEqual((int)p.None, p.getOptn());

		}
		TEST_METHOD(OptnClear)
		{
			Proc<int> p;
			p.setOptn(p.Mul);
			p.OptnClear();
			Assert::AreEqual((int)p.None, p.getOptn());
		}
		TEST_METHOD(OptnRun)
		{
			Proc<int> p;
			p.setLeft(5);
			p.setRight(10);
			p.setOptn(p.Add);
			p.OptnRun();
			Assert::AreEqual(15, p.getLeft());
		}

		TEST_METHOD(FuncRun)
		{
			Proc<Fraction> f;
			f.setRight(string("1/2"));
			f.setOptn(f.Rev);
			f.FuncRun();
			Assert::AreEqual(string("2/1"), f.getRight().toString());
		}
=======

			Proc<Complex> c;
			Assert::AreEqual(string("0+i*0"), c.getLeft().toString());
			Assert::AreEqual(string("0+i*0"), c.getRight().toString());
			Assert::AreEqual((int)c.None, c.getOptn());

			Proc<Pnumber> p;
			Assert::AreEqual(string("0"), p.getLeft().getAstring());
			Assert::AreEqual(string("0"), p.getRight().getAstring());
			Assert::AreEqual((int)p.None, p.getOptn());
		}

>>>>>>> 164653ded26e22ba8d4345b20b786dd24505a921
	};
}