#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Set/Set.h"
#include "../Set/Set.cpp"
#include "../../Lab1_Fraction/Fraction/fraction.h"
#include "../Set/iSet.h"
#include <random>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Set_Test
{		
	TEST_CLASS(SetUnitTest)
	{
	public:

		TEST_METHOD(Ñlear)
		{
			Set<Fraction> s;
			for (int i = 0; i < 10; i++) {
				Fraction f(rand() % 10, rand() % 10 + 1);
				s.add(f);

			}
			s.clear();
			bool r = s.isEmpty() ? true : false;
			Assert::IsTrue(r);
		}
		TEST_METHOD(Add)
		{
			Set<Fraction> s;
			for (int i = 0; i < 10; i++) {
				Fraction f(rand() % 10, rand() % 10);
				s.add(f);

			}
			//bool result = s.isEmpty() ? true : false;
			Assert::IsFalse(s.isEmpty());
		}
		TEST_METHOD(Del)
		{
			Set<Fraction> s;
			Fraction f1(1, 4);
			s.del(f1);
			Assert::IsFalse(s.contains(f1));
		}

		TEST_METHOD(isEmpty)
		{
			Set<Fraction> s;
			Assert::IsTrue(s.isEmpty());

		}
		TEST_METHOD(Contains)
		{
			Set<int> n;
			n.add(2);
			n.add(5);
			n.add(8);
			Assert::IsTrue(n.contains(2));
			Assert::IsTrue(n.contains(5));
			Assert::IsTrue(n.contains(8));
			Assert::IsFalse(n.contains(1));

		}
		TEST_METHOD(Merge)
		{
			Set<int> n;
			n.add(5);
			n.add(6);
			n.add(7);
			Set<int> n1;
			n1.add(2);
			n1.add(3);
			n = n.merge(n1);
			Assert::AreEqual(5, n.count());
		}
		TEST_METHOD(Diff)
		{
			Set<int> n;
			n.add(5);
			n.add(6);
			n.add(7);
			n.add(8);
			Set<int> n1;
			n1.add(7);
			n1.add(8);
			Set<int> n2;
			n2 = n.diff(n1);
			Assert::AreEqual(2, n2.count());
		}
		TEST_METHOD(Cross)
		{
			Set<int> n;
			n.add(5);
			n.add(6);
			n.add(7);
			n.add(8);
			Set<int> n1;
			n1.add(7);
			n1.add(8);
			n = n.cross(n1);
			Assert::AreEqual(2, n.count());
		}
		TEST_METHOD(Elem)
		{
			Set<int> n;
			n.add(5);
			n.add(6);
			n.add(7);
			Assert::AreEqual(7, n.elem(2));
			Assert::AreEqual(6, n.elem(1));
			Assert::AreEqual(5, n.elem(0));
		}
	};
	TEST_CLASS(iSetUnitTest) {
	public:
		TEST_METHOD(Ñlear)
		{
			iSet<Fraction> s;
			for (int i = 0; i < 10; i++) {
				Fraction f(rand() % 10, rand() % 10 + 1);
				s.insert(f);

			}
			s.clear();
			Assert::IsTrue(s.empty());
		}
	};
}