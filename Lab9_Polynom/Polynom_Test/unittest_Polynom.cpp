#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Polynom/Poly.h"
#include "../Polynom/Poly.cpp"
#include "../Polynom/Member.h"
#include "../Polynom/Member.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Polynom_Test
{		
	TEST_CLASS(UnitTest_Polynom)
	{
	public:
		
		TEST_METHOD(Construct)
		{
			Poly e(0, 1); // коэффицент равен 0, поэтому степень не важна и зануляется
			Assert::AreEqual(0, e.deg()); 

			Poly f(1, 2);
			Assert::AreEqual(2, f.deg());
			Assert::AreEqual(1, f.coef(2));
		}
		TEST_METHOD(Clear) 
		{
			Poly p(1, 2);
			p.clear();
			Assert::AreEqual(0, p.deg());
			Assert::AreEqual(0, p.coef(2));
		}
		TEST_METHOD(Sum)
		{
			Poly a(1, 3);
			Poly b(1, 2);
			Poly c(3, 1);
			Poly res;
			res = a + b + b + c;
			Assert::AreEqual(string("x^3+2x^2+3x"), res.toString());	
		}
		TEST_METHOD(Minus)
		{
			Poly a(1, 3);
			Poly b(3, 2);
			Poly c(1, 2);
			Poly res;
			res = a - b - c;
			Assert::AreEqual(string("x^3+2x^2"), res.toString());

		}
		TEST_METHOD(Mul) 
		{
			Poly a(1, 2);
			Poly b(2, 2);
			Poly c(3, 1);
			Poly res;
			res = a * b * c;
			Assert::AreEqual(string("6x^5"), res.toString());
		}
		TEST_METHOD(UnarMinus)
		{
			Poly a(1, 2);
			a = -a;
			Assert::AreEqual(string("-x^2"), a.toString());
		}
		TEST_METHOD(Equal)
		{
			Poly a(2, 2);
			Poly b(3, 2);
			Poly c(4, 3);
			Poly d = a + b + c;
			Poly e = b + a + c;
			Assert::IsTrue(d == e);
			Assert::IsFalse(a == b);
		}
		TEST_METHOD(Diff)
		{
			Poly a(1, 3);
			Poly b(1, 2);
			Poly c(3, 1);
			Poly res;
			res = a + b + b + c;
			Assert::AreEqual(string("3x^2+4x+3"), res.diff().toString());
		}
		TEST_METHOD(Calc)
		{
			Poly a(1, 3);
			Poly b(1, 2);
			Poly c(3, 1);
			Poly res;
			res = a + b + b + c;
			Assert::AreEqual(54.0, res.calculate(3));
			Assert::AreEqual(23.0, res.diff().calculate(2));
		}

	};
}