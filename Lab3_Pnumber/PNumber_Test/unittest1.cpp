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
			string a("1"), b("2"), c("3");
			Pnumber p(a, b, c);
			Assert::AreEqual(1.0, p.a);
			Assert::AreEqual(2, p.b);
			Assert::AreEqual(3, p.c);
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
			string str1("10011010.000");
			Pnumber p1(154, 2, 3);
			Assert::AreEqual(str1, p1.getAstring());
			
			string str2("ABCDEF.000");
			Pnumber p2(11259375, 16, 3);
			Assert::AreEqual(str2, p2.getAstring());

			string str3("A.6F0");
			Pnumber p3(10.111, 16, 3);
			Assert::AreEqual(str3, p3.getAstring());
			/*
			string str4("101.10");
			string str5("110.111");
			Pnumber p4(5.1, 2, 2);
			Pnumber p5(6.7, 2, 3);
			Assert::AreEqual(str4, p4.getAstring());
			Assert::AreEqual(str5, p5.getAstring());
			*/

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