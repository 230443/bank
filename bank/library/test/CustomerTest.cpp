//
// Created by daniel on 04.02.2021.
//

//
// Created by daniel on 01.02.2021.
//

#include <boost/test/unit_test.hpp>

#include "../include/Customer.h"
#include "../include/typedefs.h"
#include "../include/Person.h"
#include "../include/Company.h"

using namespace bank;

//uint64_t Customer::counter = 0;

//using namespace types;

BOOST_AUTO_TEST_SUITE(CustomerTestSuit)

	BOOST_AUTO_TEST_CASE(Customer_createThenGetId)
	{
		Customer c1;
		Person c2;
		Company c3;
		BOOST_REQUIRE_LT(c1.getId(), c2.getId());
		BOOST_REQUIRE_GT(c3.getId(), c2.id);
		BOOST_REQUIRE_EQUAL(c3.getId(), c3.id);
	}


	BOOST_AUTO_TEST_CASE(Customer_createThenGetName)
	{
		Customer c("Daniel","w1 95-100",457154);
		BOOST_REQUIRE_EQUAL(c.getName(), "Daniel");
	}

	BOOST_AUTO_TEST_CASE(Customer_newAccount)
	{
		Customer c("Daniel","w1 95-100",457154);


		auto a0 = c.newAccount();
		auto a1 = c.newAccount();
		auto a2 = c.newAccount();

		BOOST_REQUIRE_LT(a0->getNumber(), a1->getNumber());
		BOOST_REQUIRE_EQUAL(a1->getNumber()+1, a2->getNumber());
	}

	BOOST_AUTO_TEST_CASE(Customer_TransactionHistory_unordered)
	{
		auto c0 = bs::Get().newCustomer();


		AccountPtr a[4];
		a[0] = c0->newAccount();
		a[1] = c0->newAccount();
		a[2] = c0->newAccount();
		a[3] = c0->newAccount();

		bs::Get().transfer(a[0],a[3],1, "tr1");
		bs::Get().transfer(a[3],a[1],2, "tr2");
		bs::Get().transfer(a[1],a[0],3, "tr3");
		bs::Get().transfer(a[2],a[2],4, "tr4");

		auto History = c0->getTransactionRecords();


		for (const auto& transaction: *History)
		{
			BOOST_REQUIRE_CLOSE(transaction->amount,2,200);
		}
	}

	BOOST_AUTO_TEST_CASE(Customer_TransactionHistory_ordered)
	{
		auto c0 = bs::Get().newCustomer();

		AccountPtr a[4];
		a[0] = c0->newAccount();
		a[1] = c0->newAccount();
		a[2] = c0->newAccount();
		a[3] = c0->newAccount();

		bs::Get().transfer(a[0],a[3],1, "tr1");
		bs::Get().transfer(a[3],a[1],2, "tr2");
		bs::Get().transfer(a[1],a[0],3, "tr3");
		bs::Get().transfer(a[2],a[2],4, "tr4");

		auto History = c0->getHistory();

		double i=1;
		for (const auto& transaction: *History)
		{
			BOOST_REQUIRE_CLOSE(transaction.amount,i++,0.1);
		}

	}

	BOOST_AUTO_TEST_CASE(Customer_getAccount)
	{
		auto c0 = bs::Get().newCustomer();

		AccountPtr a[4];
		a[0] = c0->newAccount();
		a[1] = c0->newAccount();
		a[2] = c0->newAccount();

		BOOST_REQUIRE_EQUAL(c0->getAccount(a[1]->number),a[1]);
		BOOST_REQUIRE_NE(c0->getAccount(a[2]->number),a[1]);
		BOOST_REQUIRE_THROW(c0->getAccount(a[2]->number+1),std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(Customer_deleteAccount)
	{
		auto c0 = bs::Get().newCustomer();

		AccountPtr a[4];
		a[0] = c0->newAccount();
		a[1] = c0->newAccount();
		a[2] = c0->newAccount();

		auto number = a[1]->number;
		BOOST_REQUIRE_EQUAL(c0->getAccount(number),a[1]);
		c0->deleteAccount(number);
		BOOST_REQUIRE_THROW(c0->getAccount(number),std::invalid_argument);
		BOOST_REQUIRE_THROW(c0->deleteAccount(number),std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(Customer_PrintAccounts)
	{
		auto c0 = bs::Get().newCustomer();

		AccountPtr a[4];
		a[0] = c0->newAccount();
		a[1] = c0->newAccount();
		a[2] = c0->newAccount();
		a[3] = c0->newAccount();

		bs::Get().transfer(a[0],a[3],1, "tr1");
		bs::Get().transfer(a[3],a[1],2, "tr2");
		bs::Get().transfer(a[1],a[0],3, "tr3");
		bs::Get().transfer(a[2],a[2],4, "tr4");

		auto accounts = c0->getAccounts();
		for (const auto& account: accounts)
		{
			std::cout<<*account<<std::endl;
		}
	}

	BOOST_AUTO_TEST_CASE(Customer_setNumber_Overriden)
	{
		Person c1("Doe","w1 95-100",457154,11567187);
		Company c2("Kowalski","w1 95-100",457154,18679814);

		CustomerPtr ptr1 = std::make_shared<Person>(c1);
		CustomerPtr ptr2 = std::make_shared<Company>(c2);
		uint64_t number = 789456132;
		ptr1->setNumber(number);
		ptr2->setNumber(number+100);
		BOOST_REQUIRE_EQUAL(ptr1->getNumber() , number);
		BOOST_REQUIRE_EQUAL(ptr2->getNumber() , number+100);

	}
	BOOST_AUTO_TEST_CASE(Customer_setNumber_OverridenOnRawPointers)
	{
		Person c1("Doe","w1 95-100",457154,11567187);
		Company c2("Kowalski","w1 95-100",457154,18679814);

		Customer* ptr1 = &c1;
		Customer* ptr2 = &c2;
		uint64_t number = 789456132;
		ptr1->setNumber(number);
		ptr2->setNumber(number+100);
		BOOST_REQUIRE_EQUAL(ptr1->getNumber() , number);
		BOOST_REQUIRE_EQUAL(ptr2->getNumber() , number+100);

	}



BOOST_AUTO_TEST_SUITE_END()