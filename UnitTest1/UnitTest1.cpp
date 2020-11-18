#include "CppUnitTest.h"
#include "../Lab1/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(ListTest)
	{
	public:
		List* list;
		List* list2;
		//before each test
		TEST_METHOD_INITIALIZE(create_list)
		{
			list = new List();
		}
		//after each test
		TEST_METHOD_CLEANUP(MrPropper)
		{
			list->~List();
		}
		TEST_METHOD(push_back_test1)
		{
			list->push_back(3);
			list->push_back(4);
			Assert::AreEqual(list->at(1), 4);
		}
		TEST_METHOD(push_back_test2)
		{
			list->push_back(3);
			Assert::AreEqual(list->at(0), 3);
		}
		TEST_METHOD(push_front_test1)
		{
			list->push_back(3);
			list->push_back(4);
			list->push_front(5);
			Assert::AreEqual(list->at(0), 5);
		}
		TEST_METHOD(push_front_test2)
		{
			list->push_front(6);
			Assert::AreEqual(list->at(0), 6);
		}
		TEST_METHOD(pop_back_test1)
		{
			int data;
			list->push_back(3);
			list->push_back(4);
			list->push_back(5);
			list->push_back(6);
			list->pop_back();
			Assert::AreEqual(list->at(2), 5);
			try
			{
				data = list->at(3);
			}
			catch (const std::out_of_range& message)
			{
				Assert::AreEqual(message.what(), "Index out of range!");
			}
		}
		TEST_METHOD(pop_back_test2)
		{
			Assert::IsTrue(list->isEmpty());
			list->push_back(3);
			list->pop_back();
			Assert::IsTrue(list->isEmpty());
		}
		TEST_METHOD(pop_front_test1)
		{
			list->push_back(3);
			list->push_back(4);
			list->push_back(5);
			list->pop_front();
			Assert::AreEqual(list->at(0), 4);
		}
		TEST_METHOD(pop_front_test2)
		{
			Assert::IsTrue(list->isEmpty());
			list->push_back(3);
			list->pop_front();
			Assert::IsTrue(list->isEmpty());
		}
		TEST_METHOD(insert_test1)
		{
			list->push_back(3);
			list->push_back(4);
			list->push_back(5);
			list->push_back(5);
			list->push_back(6);
			list->push_back(7);
			list->push_back(8);
			list->insert(11 , 4);
			Assert::AreEqual(list->at(4), 11);
		}
		TEST_METHOD(insert_test2)
		{
			list->push_back(3);
			list->push_back(4);
			list->push_back(5);
			list->push_back(5);
			list->push_back(6);
			list->push_back(7);
			list->push_back(8);
			list->insert(11, 0);
			Assert::AreEqual(list->at(0), 11);
		}
		TEST_METHOD(insert_test3)
		{
			list->push_back(3);
			list->push_back(4);
			list->push_back(5);
			list->push_back(5);
			list->push_back(6);
			list->push_back(7);
			list->push_back(8);
			list->insert(11, 6);
			Assert::AreEqual(list->at(6), 11);
		}
		TEST_METHOD(insert_test4)
		{
			list->push_back(3);
			list->push_back(4);
			list->push_back(5);
			list->push_back(5);
			list->push_back(6);
			list->push_back(7);
			list->push_back(8);
			try
			{
				list->insert(11, 7);
			}
			catch (const std::out_of_range& message)
			{
				Assert::AreEqual(message.what(), "Index out of range!");
			}
		}
		TEST_METHOD(insert_test5)
		{
			list->insert(11, 0);
			Assert::AreEqual(list->at(0), 11);
		}
		TEST_METHOD(remove_test1)
		{
			list->push_back(3);
			list->push_back(4);
			list->push_back(5);
			list->push_back(5);
			list->push_back(6);
			list->push_back(7);
			list->push_back(8);
			list->remove(0);
			Assert::AreEqual(list->at(0), 4);
		}
		TEST_METHOD(remove_test2)
		{
			list->push_back(3);
			list->push_back(4);
			list->push_back(5);
			list->push_back(5);
			list->push_back(6);
			list->push_back(7);
			list->push_back(8);
			list->remove(6);
			Assert::AreEqual(list->at(5), 7);
		}
		TEST_METHOD(remove_test3)
		{
			list->push_back(3);
			list->push_back(4);
			list->push_back(5);
			list->push_back(5);
			list->push_back(6);
			list->push_back(7);
			list->push_back(8);
			list->remove(5);
			Assert::AreEqual(list->at(5), 8);
		}
		TEST_METHOD(remove_test4)
		{
			list->push_back(3);
			list->push_back(4);
			list->push_back(5);
			list->push_back(5);
			list->push_back(6);
			list->push_back(7);
			list->push_back(8);
			list->remove(1);
			Assert::AreEqual(list->at(1), 5);
		}
		TEST_METHOD(remove_test5)
		{
			list->push_back(3);
			list->push_back(4);
			list->push_back(5);
			list->push_back(5);
			list->push_back(6);
			list->push_back(7);
			list->push_back(8);
			try
			{
				list->remove(7);
			}
			catch (const std::out_of_range& message)
			{
				Assert::AreEqual(message.what(), "Index out of range!");
			}
		}
		TEST_METHOD(get_size_test1)
		{
			size_t size;
			list->push_back(3);
			list->push_back(4);
			list->push_back(5);
			list->push_back(5);
			list->push_back(6);
			list->push_back(7);
			list->push_back(8);
			size = list->get_size();
			Assert::IsTrue(size == 7);
		}
		TEST_METHOD(get_size_test2)
		{
			size_t size;
			list->push_back(3);
			list->push_back(4);
			list->push_back(5);
			list->push_back(5);
			list->push_back(6);
			list->push_back(7);
			list->push_back(8);
			list->push_front(11);
			size = list->get_size();
			Assert::IsTrue(size == 8);
		}
		TEST_METHOD(get_size_test3)
		{
			size_t size;
			list->push_back(3);
			list->push_back(4);
			list->push_back(5);
			list->push_back(5);
			list->push_back(6);
			list->push_back(7);
			list->push_back(8);
			list->pop_back();
			size = list->get_size();
			Assert::IsTrue(size == 6);
		}
		TEST_METHOD(get_size_test4)
		{
			size_t size;
			list->push_back(3);
			list->push_back(4);
			list->push_back(5);
			list->push_back(5);
			list->push_back(6);
			list->push_back(7);
			list->push_back(8);
			list->pop_front();
			size = list->get_size();
			Assert::IsTrue(size == 6);
		}
		TEST_METHOD(get_size_test5)
		{
			size_t size;
			list->push_back(3);
			list->push_back(4);
			list->push_back(5);
			list->push_back(5);
			list->push_back(6);
			list->push_back(7);
			list->push_back(8);
			list->insert(11, 2);
			size = list->get_size();
			Assert::IsTrue(size == 8);
		}
		TEST_METHOD(get_size_test6)
		{
			size_t size;
			list->push_back(3);
			list->push_back(4);
			list->push_back(5);
			list->push_back(5);
			list->push_back(6);
			list->push_back(7);
			list->push_back(8);
			list->remove(2);
			size = list->get_size();
			Assert::IsTrue(size == 6);
		}
		TEST_METHOD(clear_test1)
		{
			list->push_back(3);
			list->push_back(4);
			list->push_back(5);
			list->push_back(5);
			list->push_back(6);
			list->push_back(7);
			list->push_back(8);
			list->clear();
			Assert::IsTrue(list->isEmpty());
		}
		TEST_METHOD(clear_test2)
		{
			list->push_back(3);
			list->clear();
			Assert::IsTrue(list->isEmpty());
		}
		TEST_METHOD(clear_test3)
		{
			list->clear();
			Assert::IsTrue(list->isEmpty());
		}

		TEST_METHOD(clear_test4)
		{
			list->push_back(3);
			list->~List();
			Assert::IsTrue(list->isEmpty());
		}
		TEST_METHOD(set_test1)
		{
			list->push_back(3);
			list->push_back(4);
			list->push_back(5);
			list->push_back(5);
			list->push_back(6);
			list->push_back(7);
			list->push_back(8);
			list->set(2, 11);
			Assert::AreEqual(list->at(2), 11);
		}
		TEST_METHOD(set_test2)
		{
			list->push_back(3);
			list->push_back(4);
			list->push_back(5);
			list->push_back(5);
			list->push_back(6);
			list->push_back(7);
			list->push_back(8);
			list->set(0, 11);
			Assert::AreEqual(list->at(0), 11);
		}
		TEST_METHOD(set_test3)
		{
			list->push_back(3);
			list->push_back(4);
			list->push_back(5);
			list->push_back(5);
			list->push_back(6);
			list->push_back(7);
			list->push_back(8);
			list->set(6, 11);
			Assert::AreEqual(list->at(6), 11);
		}
		TEST_METHOD(set_test4)
		{
			list->push_back(3);
			list->push_back(4);
			list->push_back(5);
			list->push_back(5);
			list->push_back(6);
			list->push_back(7);
			list->push_back(8);
			try
			{
				list->set(7, 11);
			}
			catch (const std::out_of_range& message)
			{
				Assert::AreEqual(message.what(), "Index out of range!");
			}
		}
		TEST_METHOD(contains_test1)
		{
			list->push_back(3);
			list->push_back(4);
			list->push_back(5);
			list->push_back(5);
			list->push_back(6);
			list->push_back(7);
			list->push_back(8);

			list2 = new List();
			list2->push_back(6);
			list2->push_back(7);
			list2->push_back(8);
			Assert::IsTrue(list->contains(*list2));
			list2->~List();
		}
		TEST_METHOD(contains_test2)
		{
			list->push_back(3);
			list->push_back(4);
			list->push_back(5);
			list->push_back(5);
			list->push_back(6);
			list->push_back(7);
			list->push_back(8);

			list2 = new List();
			list2->push_back(3);
			list2->push_back(7);
			list2->push_back(8);
			Assert::IsTrue(!list->contains(*list2));
			list2->~List();
		}
		TEST_METHOD(contains_test3)
		{
			list->push_back(3);
			list->push_back(4);
			list->push_back(5);
			list->push_back(5);
			list->push_back(6);
			list->push_back(7);
			list->push_back(8);

			list2 = new List();
			list2->push_back(5);
			list2->push_back(4);
			list2->push_back(3);
			Assert::IsTrue(!list->contains(*list2));
			list2->~List();
		}
		TEST_METHOD(contains_test4)
		{
			list->push_back(8);
			list->push_back(4);
			list->push_back(3);
			list->push_back(1);
			list->push_back(6);
			list->push_back(9);
			list->push_back(5);
			list->push_back(1);
			list->push_back(6);
			list->push_back(9);
			list->push_back(8);
			list->push_back(1);
			list->push_back(6);
			list->push_back(9);


			list2 = new List();
			list2->push_back(1);
			list2->push_back(6);
			list2->push_back(9);
			Assert::IsTrue(list->contains(*list2));
			list2->~List();

		}
		TEST_METHOD(contains_test5)
		{
			list->push_back(3);
			list->push_back(4);
			list->push_back(5);

			list2 = new List();
			list2->push_back(3);
			list2->push_back(4);
			list2->push_back(5);
			Assert::IsTrue(list->contains(*list2));
			list2->~List();
		}
		TEST_METHOD(contains_test6)
		{
			list2 = new List();
			list2->push_back(3);
			list2->push_back(4);
			list2->push_back(5);
			Assert::IsTrue(!list->contains(*list2));
			list2->~List();
		}
		TEST_METHOD(contains_test7)
		{
			list->push_back(3);
			list->push_back(4);
			list->push_back(5);

			list2 = new List();
			Assert::IsTrue(list->contains(*list2));
			list2->~List();
		}
	};
}