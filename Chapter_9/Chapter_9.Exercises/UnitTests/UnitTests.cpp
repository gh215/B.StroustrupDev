#include "pch.h"
#include "CppUnitTest.h"
#include "..\Chapter 9. Еxercises\Header_ex1_4_and_10_18.h"
#include "..\Chapter 9. Еxercises\Header_ex5_9.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:	
		TEST_METHOD(TestCheckISBN)
		{
			Assert::IsTrue(Book::checkISBN("123-456-789-X"));
			Assert::IsFalse(Book::checkISBN("fsk-456-789-X"));
			Assert::IsFalse(Book::checkISBN("123-asd-789-X"));
			Assert::IsFalse(Book::checkISBN("123-312-jhl-X"));
			Assert::IsFalse(Book::checkISBN("123-312-789-5*"));
			Assert::IsFalse(Book::checkISBN("-123-312-789-X"));
			Assert::IsFalse(Book::checkISBN("123--312-789-X"));
			Assert::IsFalse(Book::checkISBN("123-312--789-X"));
			Assert::IsFalse(Book::checkISBN(""));
		}
	};
}
