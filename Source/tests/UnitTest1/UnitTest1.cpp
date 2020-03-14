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

		TEST_METHOD(add_to_account_less)
		{
			int doll = 100;
			int cent = 0;
			Account acc1(doll, cent);
			Account acc2(doll, cent);

			acc1.add(50, 0);
			acc2.add(500, 0);

			Assert::IsTrue((acc1 < acc2));
		}

		TEST_METHOD(add_to_account_greater)
		{
			int doll = 100;
			int cent = 0;
			Account acc1(doll, cent);
			Account acc2(doll, cent);

			acc1.add(100, 0);
			acc2.add(10, 0);

			Assert::IsTrue((acc1 > acc2));
		}
		TEST_METHOD(subtract_from_account_equal)
		{
			int doll = 100;
			int cent = 0;
			Account acc1(doll, cent);
			Account acc2(doll, cent);

			acc1.subtract(50, 0);
			acc2.subtract(50, 0);

			Assert::IsTrue((acc1 == acc2));
		}
		TEST_METHOD(subtract_from_account_notequal)
		{
			int doll = 100;
			int cent = 0;
			Account acc1(doll, cent);
			Account acc2(doll, cent);

			acc1.subtract(50, 0);
			acc2.subtract(10, 0);

			Assert::IsTrue((acc1 != acc2));
		}
		TEST_METHOD(subtract_from_account_less)
		{
			int doll = 100;
			int cent = 0;
			Account acc1(doll, cent);
			Account acc2(doll, cent);

			acc1.subtract(50, 0);
			acc2.subtract(10, 0);

			Assert::IsTrue((acc1 < acc2));
		}

		TEST_METHOD(subtract_from_account_greater)
		{
			int doll = 100;
			int cent = 0;
			Account acc1(doll, cent);
			Account acc2(doll, cent);

			acc1.subtract(10, 0);
			acc2.subtract(100, 0);

			Assert::IsTrue((acc1 > acc2));
		}
	};

	TEST_CLASS(BSTtests)
	{
		TEST_METHOD(Provider_addTo)
		{
			BST bst("../../user_info.txt", 1);
			Provider obj1;

			Assert::IsTrue((bst.AddToBST(obj1)));
		}

		TEST_METHOD(Provider_removeFrom)
		{
			BST bst("../../user_info.txt", 1);
			Provider obj1;

			bst.AddToBST(obj1);

			Assert::IsTrue((bst.RemoveFromBST(obj1)));
		}
		TEST_METHOD(Provider_EditTree)
		{
			BST bst("../../user_info.txt", 1);
			Provider obj1;

			bst.AddToBST(obj1);

			Assert::IsTrue((bst.EditBST(obj1)));
		}
		TEST_METHOD(Member_addTo)
		{
			BST bst("../../user_info.txt", 1);
			Member obj1;

			Assert::IsTrue((bst.AddToBST(obj1)));
		}

		TEST_METHOD(Member_removeFrom)
		{
			BST bst("../../user_info.txt", 1);
			Member obj1;

			bst.AddToBST(obj1);

			Assert::
				IsTrue((bst.RemoveFromBST(obj1)));
		}
		TEST_METHOD(Member_EditTree)
		{
			BST bst("../../user_info.txt", 1);
			Member obj1;

			bst.AddToBST(obj1);

			Assert::IsTrue((bst.EditBST(obj1)));
		}

		TEST_METHOD(searchTree)
		{
			BST bst("../../user_info.txt", 1);
			Member obj1;
			Provider obj2;

			obj1.Insert("Jon", "1111 NW main st.", "Portland", "OR", 97201, "111122233");
			obj2.Insert("Mike", "1111 NW main st.", "Portland", "OR", 97201, "111122244");


			bst.AddToBST(obj1);
			bst.AddToBST(obj2);

			Assert::IsTrue((bst.Search(obj1)));
		}
		TEST_METHOD(countTree)
		{
			BST bst("../../user_info.txt", 1);
			Member obj1;
			Provider obj2;

			obj1.Insert("Jon", "1111 NW main st.", "Portland", "OR", 97201, "111122233");
			obj2.Insert("Mike", "1111 NW main st.", "Portland", "OR", 97201, "111122244");


			bst.AddToBST(obj1);
			bst.AddToBST(obj2);

			Assert::IsTrue((bst.CountTree() > 0));
		}
	};

	TEST_CLASS(UserTests)
	{
		TEST_METHOD(createMember)
		{
			Member* obj = new Member();

			obj->Insert("Jon", "1111 NW main st.", "Portland", "OR", 97201, "111122233"); 

			Assert::IsNotNull(obj);
		}

		TEST_METHOD(createProvider)
		{
			Provider* obj = new Provider();

			obj->Insert("Jon", "1111 NW main st.", "Portland", "OR", 97201, "111122233");

			Assert::IsNotNull(obj);
		}
	};

	TEST_CLASS(UtilityTests)
	{
		TEST_METHOD(TestFileOpen)
		{
			std::ifstream filein;
			bool flag = true;

			filein.open("../../Source/access-codes.txt");

			if (!filein)
				flag = false;

			Assert::IsTrue(flag);
		}
		TEST_METHOD(testPreHash)
		{
			std::ifstream filein;
			filein.open("../../Source/access-codes.txt");

			bool flag = false;

			if (filein)
				flag = true;

			Assert::IsTrue(flag);
		}
		TEST_METHOD(testHash)
		{
			std::ifstream filein;
			filein.open("../../Source/access-codes.txt");

			int val = hash_file(filein);
			bool flag = false;

			if (val >= 0)
				flag = true;

			Assert::IsTrue(flag);
		}
	};
}
