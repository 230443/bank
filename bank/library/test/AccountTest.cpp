//
// Created by daniel on 04.02.2021.
//
//
// Created by daniel on 04.02.2021.
//

#include <boost/test/unit_test.hpp>
#include <memory>

#include "../include/Account.h"
#include "../include/Customer.h"
//#include "../include/typedefs.h"


//class Person;
//class Company;
using namespace bank;

BOOST_AUTO_TEST_SUITE(AccountTestSuit)


	BOOST_AUTO_TEST_CASE(Account_Constructor)
	{
		auto owner = std::make_shared<Customer>(Customer());
		Account a0(owner);
		Account a1(owner);
		Account a2(owner);
		Account a3(owner);
		BOOST_REQUIRE_EQUAL(a0.getNumber(),0);
		BOOST_REQUIRE_EQUAL(a1.getNumber(),1);
		BOOST_REQUIRE_EQUAL(a2.getNumber(),2);
		BOOST_REQUIRE_EQUAL(a3.getNumber(),3);
		BOOST_REQUIRE_EQUAL(a3.getName(),"customer");
	}




BOOST_AUTO_TEST_SUITE_END()

