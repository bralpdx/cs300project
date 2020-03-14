#include "pch.h"
#include "CppUnitTest.h"

#include "../../param.h"
#include "../../utilities.h"
#include "../../utilities.cpp"
#include "../../bst.h"
#include "../../bst.cpp"
#include "../../user_service_obj.h"
#include "../../user_service_obj.cpp"
#include "../../hash-library-master/sha256.h"
#include "../../hash-library-master/sha256.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(Account_Tests)
	{
	public:
		TEST_METHOD(add_to_account_equal)
		{
			int doll = 100;
			int cent = 0;
			Account acc1(doll, cent);
			Account acc2(doll, cent);

			acc1.add(50, 0);
			acc2.add(50, 0);

			Assert::IsTrue((acc1 == acc2));
		}
		TEST_METHOD(add_to_account_notequal)
		{
			int doll = 100;
			int cent = 0;
			Account acc1(doll, cent);
			Account acc2(doll, cent);

			acc1.add(50, 0);
			acc2.add(10, 0);

			Assert::IsTrue((acc1 != acc2));
		}
	};
}
