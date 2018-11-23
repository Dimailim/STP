#include "stdafx.h"
#include "CppUnitTest.h"
#include "../PEditor/PEditor.h"
#include "../PEditor/PEditor.cpp"
//#include "../../Lab1_Fraction/Fraction/fraction.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_PEditor
{		
	TEST_CLASS(UnitTest_PEditor)
	{
	public:
		
		TEST_METHOD(PEdit_Construct)
		{
			TEditor t;
			string output = "10";
			t.SetStore(output);
			Assert::AreEqual(output, t.GetStore());


		}

	};
}