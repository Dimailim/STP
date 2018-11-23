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
		TEST_METHOD(PEdit_AddSign)
		{
			TEditor t;
			string str = "9";
			t.SetStore(str);
			TEditor t1;
			string str1 = "-9";
			t1.SetStore(str1);
			Assert::AreEqual(str1, t.AddSign());
			Assert::AreEqual(str, t.AddSign());

		}
		TEST_METHOD(PEdit_NumberisNull)
		{
			TEditor t;
			string str = "0,";
			TEditor t1;
			string str1 = "-0,";
			TEditor t2;
			string str2 = "1";
			t.SetStore(str);
			t.NumberIsNull();
			t1.SetStore(str1);
			t1.NumberIsNull();
			t2.SetStore(str2);
			t2.NumberIsNull();
			Assert::IsTrue(t.NumberIsNull());
			Assert::IsTrue(t1.NumberIsNull());
			Assert::IsFalse(t2.NumberIsNull());
		}
		TEST_METHOD(PEdit_AddPNumber)
		{
			TEditor t;
			
			Assert::AreEqual(string("A"), t.AddPNumber(10));
		}
		TEST_METHOD(PEdit_AddNull)
		{
			TEditor t;
			string str = "5";
			t.SetStore(str);
			Assert::AreEqual(string("05"), t.AddNull());
		}
		TEST_METHOD(PEdit_Backspace)
		{
			TEditor t;
			string str = "10";
			t.SetStore(str);
			t.BackSpace();
			//Assert::AreEqual(string("1"), t.GetStore());
			Assert::AreEqual(string("1"), t.BackSpace());

		}
		TEST_METHOD(PEdit_Clear)
		{
			TEditor t;
			t.SetStore("5");
			t.Clear();
			Assert::AreEqual(string("0,"), t.GetStore());
		}
	};
}