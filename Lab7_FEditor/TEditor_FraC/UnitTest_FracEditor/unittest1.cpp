#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TEditor_FraC/TEditor.h"
#include "../TEditor_FraC/TEditor.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_FracEditor
{		
	TEST_CLASS(UnitTest_FracEditor)
	{
	public:
		
		TEST_METHOD(Construct)
		{
			FEditor f;
			string out = "2/3";
			f.SetStore(out);
			Assert::AreEqual(out, f.GetStore());
		}

		TEST_METHOD(PEdit_AddSign)
		{
			FEditor f;
			string str = "9/6";
			f.SetStore(str);
			f.AddSign();
			FEditor f1;
			string str1 = "-9/6";
			f1.SetStore(str1);
			f1.AddSign();

			Assert::AreEqual(str1, f.GetStore());
			Assert::AreEqual(str, f1.GetStore());

		}
		TEST_METHOD(NumberisNull)
		{
			FEditor f;
			string str = "0/1";
			FEditor f1;
			string str1 = "-0/1";
			FEditor f2;
			string str2 = "1/2";
			f.SetStore(str);
			f1.SetStore(str1);
			f2.SetStore(str2);
			Assert::IsTrue(f.FracIsNull());
			Assert::IsTrue(f1.FracIsNull());
			Assert::IsFalse(f2.FracIsNull());
		}
		TEST_METHOD(AddFracNumber)
		{
			FEditor f;
			f.AddFracNumber(4);
			Assert::AreEqual(string("4"), f.GetStore());
		}
		TEST_METHOD(AddNull)
		{
			FEditor f;
			string str = "6";
			f.SetStore(str);
			f.AddNull();
			Assert::AreEqual(string("60"), f.GetStore());

		}
		TEST_METHOD(BackSpace)
		{
			FEditor f(string("12/14"));
			f.Backspace();
			Assert::AreEqual(string("12/1"), f.GetStore());
			f.Backspace();
			Assert::AreEqual(string("12/"), f.GetStore());
			f.Backspace();
			Assert::AreEqual(string("12"), f.GetStore());
			f.Backspace();
			Assert::AreEqual(string("1"), f.GetStore());
			f.Backspace();
			Assert::AreEqual(string("0/1"), f.GetStore());


		}
		TEST_METHOD(Clear)
		{
			FEditor f;
			f.SetStore("2/4");
			f.Clear();
			Assert::AreEqual(string("0/1"), f.GetStore());
		}
		TEST_METHOD(Edit) 
		{
			FEditor f;
			f.Edit(5);
			Assert::AreEqual(string("5"), f.GetStore());
			f.Edit(1);
			Assert::AreEqual(string("51"), f.GetStore());
			f.Edit(f.Erase);
			Assert::AreEqual(string("5"), f.GetStore());
			f.Edit(f.Separator);
			Assert::AreEqual(string("5/"), f.GetStore());
			f.Edit(4);
			Assert::AreEqual(string("5/4"), f.GetStore());
			f.Edit(f.Sign);
			Assert::AreEqual(string("-5/4"), f.GetStore());
			f.Edit(f.RemoveAll);
			Assert::AreEqual(string("0/1"), f.GetStore());
		
		}
		TEST_METHOD(PEdit_SetStore)
		{
			FEditor t;
			t.SetStore("1/2");
			Assert::AreEqual(string("1/2"), t.GetStore());
			t.SetStore("-1/4");
			Assert::AreEqual(string("-1/4"), t.GetStore());
			t.SetStore("Z");
			Assert::AreEqual(string("-1/4"), t.GetStore());

		}

	};
}