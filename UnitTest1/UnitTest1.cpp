#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_3rec/Lab_06_3rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestRec
{
	TEST_CLASS(UnitTestRec)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int arr1[5] = { 100, 50, 50, 25, 0 };
			int arr2[5] = { 100, 50, 60, 25, 0 };

			// Перевірка звичайної рекурсивної функції
			Assert::IsTrue(IsNonIncreasingRec(arr1, 5));
			Assert::IsFalse(IsNonIncreasingRec(arr2, 5));

			// Перевірка шаблонної рекурсивної функції
			double arrDouble[3] = { 3.14, 2.71, 1.41 };
			Assert::IsTrue(IsNonIncreasingRec<double>(arrDouble, 3));
		}
	};
}