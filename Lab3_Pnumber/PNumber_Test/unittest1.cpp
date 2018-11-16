#include "stdafx.h"
#include "CppUnitTest.h"
#include "../PNumber/Pnumber.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestPnumber
{		
	TEST_CLASS(UnitTestPnumber)
	{
	public:
		
		TEST_METHOD(TestMethodConstruct1)
		{
			Pnumber p(1, 2, 3);
			Assert::AreEqual(1.0, p.a);
			Assert::AreEqual(2, p.b);
			Assert::AreEqual(3, p.c);
		}

		TEST_METHOD(TestMethodConstructString)
		{
			string a("C.F"), b("16"), c("1");
			Pnumber p(a, b, c);
			
			Assert::AreEqual(12.15, p.a);
			Assert::AreNotEqual(0, p.b);
			Assert::AreNotEqual(0, p.c);
			
			string aa("10.101"), bb("2"), cc("3");
			Pnumber p2(aa, bb, cc);

			Assert::AreEqual(2.5, p2.a);
			Assert::AreNotEqual(0, p2.b);
			Assert::AreNotEqual(0, p2.c);	
		}

		TEST_METHOD(TestMethodPlus)
		{
			Pnumber q(1.5, 2, 1);
			Pnumber w(3.5, 2, 1);
			Pnumber p = q + w;
			Assert::AreEqual(5.0, p.a);
			Assert::AreEqual(2, p.b);
			Assert::AreEqual(1, p.c);
		}

		TEST_METHOD(TestMethodMul)
		{
			Pnumber q(2, 2, 3);
			Pnumber w(3, 2, 3);
			Pnumber p = q * w;
			Assert::AreEqual(6.0, p.a);
			Assert::AreEqual(2, p.b);
			Assert::AreEqual(3, p.c);
		}

		TEST_METHOD(TestMethodMinus)
		{
			Pnumber q(5, 2, 3);
			Pnumber w(3, 2, 3);
			Pnumber p = q - w;
			Assert::AreEqual(2.0, p.a);
			Assert::AreEqual(2, p.b);
			Assert::AreEqual(3, p.c);
		}

		TEST_METHOD(TestMethodDiv)
		{
			Pnumber q(6, 2, 3);
			Pnumber w(3, 2, 3);
			Pnumber p = q / w;
			Assert::AreEqual(2.0, p.a);
			Assert::AreEqual(2, p.b);
			Assert::AreEqual(3, p.c);
		}

		TEST_METHOD(TestMethodReverse)
		{
			Pnumber q(2, 2, 3);
			Pnumber p = q.reverse();
			Assert::AreEqual(0.5, p.a);
			Assert::AreEqual(2, p.b);
			Assert::AreEqual(3, p.c);
		}

		TEST_METHOD(TestMethodSquare)
		{
			Pnumber q(6, 2, 3);
			Pnumber p = q.square();
			Assert::AreEqual(36.0, p.a);
			Assert::AreEqual(2, p.b);
			Assert::AreEqual(3, p.c);
		}

		TEST_METHOD(TestMethodGetA)
		{
			Pnumber p(6, 2, 3);
			Assert::AreEqual(6.0, p.getA());
		}

		TEST_METHOD(TestMethodGetAstring)
		{
			Pnumber p(154.255, 10, 3);
			string dec("154.255");
			Assert::AreEqual(dec, p.getAstring());

			p.setB(2);
			string bin("10011010.111");
			Assert::AreEqual(bin, p.getAstring());

			p.setB(8);
			string oct("232.377");
			Assert::AreEqual(oct, p.getAstring());			

			p.setB(16);
			string hex("9a.0ff");
			Assert::AreEqual(hex, p.getAstring());
		}
		TEST_METHOD(TestMethodGetB)
		{
			Pnumber p(6, 2, 3);
			Assert::AreEqual(2, p.getB());
		}
		TEST_METHOD(TestMethodGetBString)
		{
			Pnumber p(6, 2, 3);
			string strB("2");
			Assert::AreEqual(strB, p.getBstring());
		}

		TEST_METHOD(TestMethodGetC)
		{
			Pnumber p(6, 2, 3);
			Assert::AreEqual(3, p.getC());
		}

		TEST_METHOD(TestMethodGet—String)
		{
			Pnumber p(6, 2, 3);
			string strC("3");
			Assert::AreEqual(strC, p.getCstring());
		}

		TEST_METHOD(TestMethodSetB)
		{
			Pnumber p(6, 2, 3);
			p.setB(8);
			Assert::AreEqual(8, p.getB());
		}

		TEST_METHOD(TestMethodSetBstring)
		{
			Pnumber p(6, 2, 3);
			string str("8");
			p.setBstring(str);
			Assert::AreEqual(8, p.getB());
		}

		TEST_METHOD(TestMethodSetC)
		{
			Pnumber p(6, 2, 3);
			p.setC(4);
			Assert::AreEqual(4, p.getC());
		}

		TEST_METHOD(TestMethodSetCstring)
		{
			Pnumber p(6, 2, 3);
			string str("4");
			p.setCstring(str);
			Assert::AreEqual(4, p.getC());
		}
	};
}