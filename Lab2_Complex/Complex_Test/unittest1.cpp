#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Complex/complex.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab3
{		
	TEST_CLASS(UnitTestLab3)
	{
	public:
		
		TEST_METHOD(TestMethodConstruct)
		{
			Complex c(1.5, 2.5);
			Assert::AreEqual(1.5, c.a);
			Assert::AreEqual(2.5, c.b);
		}

		TEST_METHOD(TestMethodConstructString)
		{
			string str("1.5+i*2.5");
			Complex c(str);
			Assert::AreEqual(1.5, c.a);
			Assert::AreEqual(2.5, c.b);
		}
		TEST_METHOD(TestMethodConstructCopy)
		{
			Complex c(1.5 ,2.5);
			Complex d = c.copy();
			Assert::AreEqual(1.5, d.a);
			Assert::AreEqual(2.5, d.b);
		}
		TEST_METHOD(TestMethodConstructPlus)
		{
			Complex c(1.5, 2.5);
			Complex d(0.5, 0.5);
			Complex e = c + d;
			Assert::AreEqual(2.0, e.a);
			Assert::AreEqual(3.0, e.b);
		}
		TEST_METHOD(TestMethodConstructMul)
		{
			Complex c(1.5, 2.5);
			Complex d(1.0, 0.0);
			Complex e = c * d;
			Assert::AreEqual(1.5, e.a);
			Assert::AreEqual(2.5, e.b);
		}
		TEST_METHOD(TestMethodConstructSquare)
		{
			Complex c(1.5, 2.5);
			Complex e = c.square();
			Assert::AreEqual(-4.0, e.a);
			Assert::AreEqual(7.5, e.b);
		}
		TEST_METHOD(TestMethodConstructReverse)
		{
			Complex c(1.0,2.0);
			Complex e = c.reverse();
			Assert::AreEqual(0.2, e.a);
			Assert::AreEqual(0.4, e.b);
		}
		TEST_METHOD(TestMethodConstructMin)
		{
			Complex c(1.5, 2.5);
			Complex d(0.5, 0.5);
			Complex e = c - d;
			Assert::AreEqual(1.0, e.a);
			Assert::AreEqual(2.0, e.b);
		}
		TEST_METHOD(TestMethodConstructDiv)
		{
			Complex c(1.5, 2.5);
			Complex d(0.5, 0.5);
			Complex e = c / d;
			Assert::AreEqual(4.0, e.a);
			Assert::AreEqual(1.0, e.b);
		}
		TEST_METHOD(TestMethodConstructUnMinus)
		{
			Complex c(1.5, 2.5);
			Complex e = -c;
			Assert::AreEqual(-1.5, e.a);
			Assert::AreEqual(-2.5, e.b);
		}
		TEST_METHOD(TestMethodConstructCmod)
		{
			Complex c(2.0, 2.0);
			double e = c.cmod();
			Assert::AreEqual(sqrt(8.0), e);
		}
		TEST_METHOD(TestMethodConstructCRad)
		{
			Complex c(2.0, 2.0);
			double e = c.crad();
			Assert::AreEqual(atan(1.0), e);

			c = Complex(0.0, 2.0);
			e = c.crad();
			Assert::AreEqual(M_PI / 2, e);

			c = Complex(-1.0, 2.0);
			e = c.crad();
			Assert::AreEqual(atan(-2.0) + M_PI, e);

			c = Complex(0.0, 0.0);
			e = c.crad();
			Assert::AreEqual(-M_PI / 2, e);
		}
		TEST_METHOD(TestMethodConstructCdeg)
		{
			Complex c(0.0, 2.0);
			double e = c.cdeg();
			Assert::AreEqual((M_PI / 2) * 180 / M_PI, e);
		}
		TEST_METHOD(TestMethodConstructCpow)
		{
			Complex c(1.5, 2.5);
			Complex e = c.cpow(2);
			Assert::AreEqual(-4.0, e.a);
			Assert::AreEqual(7.5, e.b);
		}
		TEST_METHOD(TestMethodConstructCsqrt)
		{
			Complex c(0.0, 2.0);
			Complex e = c.csqrt(2,1);
			double a = sqrt(2) * (cos((M_PI / 2 + 2 * 1 * M_PI) / 2));
			double b = sqrt(2) * (sin((M_PI / 2 + 2 * 1 * M_PI) / 2));
			Assert::AreEqual(a, e.a);
			Assert::AreEqual(b, e.b);
		}
		TEST_METHOD(TestMethodConstructEqual)
		{
			Complex c(1.5, 2.5);
			Complex e(2.0,1.0);
			Assert::IsFalse(c == e);
		}
		TEST_METHOD(TestMethodConstructNotEqual)
		{
			Complex c(1.5, 2.5);
			Complex e(1.5,2.5);
			Assert::IsFalse(c != e);
		}
		TEST_METHOD(TestMethodConstructGetRe)
		{
			Complex c(1.5, 2.5);
			Assert::AreEqual(1.5, c.getRe());
		}
		TEST_METHOD(TestMethodConstructGetReString)
		{
			Complex c(1.5, 2.5);
			string str("1.5");
			Assert::AreEqual(str, c.getReString());
		}
		TEST_METHOD(TestMethodConstructGetIm)
		{
			Complex c(1.5, 2.5);
			Assert::AreEqual(2.5, c.getIm());
		}
		TEST_METHOD(TestMethodConstructGetImString)
		{
			Complex c(1.5, 2.5);
			string str("2.5");
			Assert::AreEqual(str, c.getImString());
		}
		TEST_METHOD(TestMethodConstructToString)
		{
			Complex c(1.5, 2.5);
			string str("1.5+i*2.5");
			Assert::AreEqual(str, c.toString());
		}


	};
}