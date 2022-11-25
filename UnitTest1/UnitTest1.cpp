#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\никола\Desktop\ХПИ\Lab IPZ\Lab IPZ\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(calculate_Tests)
	{
	public:
		TEST_METHOD(Calculateequalszero) // Проверка при х = 0
		{
			double actual = calculate(0, 3);
			Assert::AreEqual(-0.5, actual);
		}
		TEST_METHOD(CalculateMoreZero) // Проверка при х > 0, trunc - отбрасывает дробную часть (потому что число получается с плавающей точкой)
		{
			double actual = trunc(calculate(10, 13));
			Assert::AreEqual(206535.0, actual);
		}
		TEST_METHOD(CalculateLessZero) // Проверка при х < 0
		{
			double actual = trunc(calculate(-12, 5));
			Assert::AreEqual(-14.0, actual);
		}
	};
	TEST_CLASS(checkValidParams_Tests)
	{
	public:
		TEST_METHOD(checkValidParams1) {
			int n = 0.5;

			try
			{
				checkValidParams(n);
				Assert::Fail;
			}
			catch (...) 
			{
				Assert::IsTrue(true);
			}
		}
		TEST_METHOD(checkValidParams2) {
			int n = 1;

			try
			{
				checkValidParams(n);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	};
}
