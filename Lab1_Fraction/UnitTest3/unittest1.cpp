#include "stdafx.h"
#include "CppUnitTest.h"
#include "fraction.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTestFrac)
	{
	public:
		
		TEST_METHOD(TestFracInit1)
		{
			// TODO: Разместите здесь код своего теста
			Fraction f(3, 6);
			Assert::AreEqual(1, f.getA());
			Assert::AreEqual(2, f.getB());
		}

		TEST_METHOD(TestFracInit2)
		{
			string str("3/6");
			Fraction f(str);
			Assert::AreEqual(1, f.getA());
			Assert::AreEqual(2, f.getB());
		}

		TEST_METHOD(TestFracCopy)
		{
			Fraction f(1, 2);
			Fraction t = f.copy();
			Assert::AreEqual(1, t.getA());
			Assert::AreEqual(2, t.getB());
		}

		TEST_METHOD(TestFracPlus)
		{
			Fraction q(1, 2);
			Fraction f(-3, 4);
			Fraction t = q + f;
			Assert::AreEqual(-1, t.getA());
			Assert::AreEqual(4, t.getB());
		}

		TEST_METHOD(TestFracMul)
		{
			Fraction q(1, 2);
			Fraction f(-3, 4);
			Fraction t = q * f;
			Assert::AreEqual(-3, t.getA());
			Assert::AreEqual(8, t.getB());
		}

		TEST_METHOD(TestFracMinus)
		{
			Fraction q(1, 2);
			Fraction f(1, 2);
			Fraction t = q - f;
			Assert::AreEqual(0, t.getA());
			Assert::AreEqual(1, t.getB());
		}

		TEST_METHOD(TestFracDiv)
		{
			Fraction q(3, 6);
			Fraction f(1, 2);
			Fraction t = q / f;
			Assert::AreEqual(1, t.getA());
			Assert::AreEqual(1, t.getB());
		}

		TEST_METHOD(TestFracSquare)
		{
			Fraction f(3, 2);
			Fraction t = f.square();
			Assert::AreEqual(9, t.getA());
			Assert::AreEqual(4, t.getB());
		}

		TEST_METHOD(TestFracReverse)
		{
			Fraction f(3, 2);
			Fraction t = f.reverse();
			Assert::AreEqual(2, t.getA());
			Assert::AreEqual(3, t.getB());
		}

		TEST_METHOD(TestFracMinusOne)
		{
			Fraction f(3, 2);
			Fraction t = -f;
			Assert::AreEqual(-3, t.getA());
			Assert::AreEqual(2, t.getB());
		}

		TEST_METHOD(TestFracEqual)
		{
			Fraction f(3, 2);
			Fraction t(2, 3);
			Assert::IsFalse(f == t);
		}

		TEST_METHOD(TestFracMoreThen)
		{
			Fraction f(3, 2);
			Fraction t(2, 3);
			Assert::IsFalse(t > f);
		}

		TEST_METHOD(TestFracGetA)
		{
			Fraction f(3, 2);
			Assert::AreEqual(3, f.getA());
		}

		TEST_METHOD(TestFracGetB)
		{
			Fraction f(3, 2);
			Assert::AreEqual(2, f.getB());
		}

		TEST_METHOD(TestFracGetAString)
		{
			Fraction f(32, 21);
			string str("32");
			Assert::AreEqual(str, f.getAstring());
		}

		TEST_METHOD(TestFracGetBString)
		{
			Fraction f(32, 21);
			string str("21");
			Assert::AreEqual(str, f.getBstring());
		}
		TEST_METHOD(TestFracToString)
		{
			Fraction f(32, 21);
			string str("32/21");
			Assert::AreEqual(str, f.toString());
		}
	};
}