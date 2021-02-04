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
		BOOST_REQUIRE_EQUAL(c1.getId(), 0);
		BOOST_REQUIRE_EQUAL(c2.getId(), 1);
		BOOST_REQUIRE_EQUAL(c3.getId(), 2);
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

		BOOST_REQUIRE_EQUAL(a0->getNumber(), 0);
		BOOST_REQUIRE_EQUAL(a1->getNumber(), 1);
		BOOST_REQUIRE_EQUAL(a2->getNumber(), 2);
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