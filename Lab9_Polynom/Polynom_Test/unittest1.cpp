#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Polynom/Poly.h"
#include "../Polynom/Poly.cpp"
#include "../Polynom/Member.h"
#include "../Polynom/Member.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Plynom_Test
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestConstruct)
		{
			Poly e(0, 1); // коэффицент равен 0, поэтому степень не важна и зануляется
			Assert::AreEqual(0, e.deg()); 

			Poly f(1, 2);
			Assert::AreEqual(2, f.deg());
		}

	};
}