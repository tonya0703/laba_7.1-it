#include "pch.h"
#include "CppUnitTest.h"
#include "../ap_laba_7.1 a/7.1 a.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71
{
	TEST_CLASS(UnitTest71)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int rowCount = 9;
			const int colCount = 6;
			int** c = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				c[i] = new int[colCount];

			int S = 0;
			int k = 0;

			Calc(c, rowCount, colCount, S, k);

			for (int i = 0; i < rowCount; i++)
			delete[] c[i];
			delete[] c;

		}
	};
}
