//
// Created by daniel on 04.02.2021.
//

#include <boost/test/unit_test.hpp>
#include <memory>

#include "../include/TransactionRecord.h"
//#include "../include/typedefs.h"


//class Person;
//class Company;
using namespace bank;

BOOST_AUTO_TEST_SUITE(DataTypesTestSuit)


	BOOST_AUTO_TEST_CASE(transactionRecord_operators)
	{
		bank::TransactionRecord tr1("acconut0", 45184641571, "account1 address ...", 2345678234567, 100, "first transfer");
		bank::TransactionRecord tr2("acconut0", 45184641571, "account1 address ...", 2345678234567, 100, "first transfer");
		bank::TransactionRecord tr3("acconut0", 45184641571, "account1 address ...", 2345678234567, 100, "first transfer");

		BOOST_REQUIRE_EQUAL(tr1<tr2,true);
		BOOST_REQUIRE_EQUAL(tr2>tr1,true);
		BOOST_REQUIRE_EQUAL(tr3!=tr2,true);
		BOOST_REQUIRE_EQUAL(tr3==tr3,true);

		//BOOST_REQUIRE_EQUAL(tr3==tr3, true);
		//BOOST_REQUIRE_EQUAL(tr3==tr4, false);

	}




BOOST_AUTO_TEST_SUITE_END()
