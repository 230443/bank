//
// Created by daniel on 04.02.2021.
//

//
// Created by daniel on 01.02.2021.
//

#include <boost/test/unit_test.hpp>

#include "../include/Customer.h"
#include "../include/typedefs.h"
//#include "../include/Person.h"
//#include "../include/Company.h"

using namespace bank;

//uint64_t Customer::counter = 0;

//using namespace types;

BOOST_AUTO_TEST_SUITE(CustomerTestSuit)

	BOOST_AUTO_TEST_CASE(Customer_createThenGetId)
	{
		Customer c1;
		Customer c2;
		Customer c3;
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

		auto History = c0->getTransactionHistory();


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

		auto History = c0->getTransactionHistoryOrdered();

		double i=1;
		for (const auto& transaction: *History)
		{
			BOOST_REQUIRE_CLOSE(transaction.amount,i++,0.1);
		}
	}

/*
	BOOST_AUTO_TEST_CASE(Customer_getID)
	{
		Customer c1("Daniel","w1 95-100",457154);
		Person c2("Daniel","w1 95-100",457154,11567187);
		Company c3("Daniel","w1 95-100",457154,18679814);

		Customer c4;
		Person c5;
		Company c6;

		BOOST_REQUIRE_EQUAL(c1.GetId(), 1);
		BOOST_REQUIRE_EQUAL(c2.GetId(), 2);
		BOOST_REQUIRE_EQUAL(c3.GetId(), 3);
		BOOST_REQUIRE_EQUAL(c4.GetId(), 4);
		BOOST_REQUIRE_EQUAL(c5.GetId(), 5);
		BOOST_REQUIRE_EQUAL(c6.GetId(), 6);
	}

	BOOST_AUTO_TEST_CASE(Customer_getName)
	{
		Customer c1("John","w1 95-100",457154);
		Person c2("Doe","w1 95-100",457154,11567187);
		Company c3("Kowalski","w1 95-100",457154,18679814);

		Customer c4;
		Person c5;
		Company c6;

		BOOST_REQUIRE_EQUAL(c1.GetName(), "John");
		BOOST_REQUIRE_EQUAL(c2.GetName(), "Doe");
		BOOST_REQUIRE_EQUAL(c3.GetName(), "Kowalski");
		BOOST_REQUIRE_EQUAL(c4.GetName(), "customer");
		BOOST_REQUIRE_EQUAL(c5.GetName(), "person");
		BOOST_REQUIRE_EQUAL(c6.GetName(), "company");
	}
	BOOST_AUTO_TEST_CASE(Customer_comparisonTest)
	{
		Person c1("Doe","w1 95-100",457154,11567187);
		Company c2("Kowalski","w1 95-100",457154,18679814);

		BOOST_REQUIRE_EQUAL(c1<c2, true);
		BOOST_REQUIRE_EQUAL(c2>=c1, true);
		BOOST_REQUIRE_EQUAL(c1==c1,true);
		BOOST_REQUIRE_EQUAL(c1!=c2,true);
	}

*/


BOOST_AUTO_TEST_SUITE_END()