//
// Created by daniel on 04.02.2021.
//

#include <boost/test/unit_test.hpp>
#include <memory>

#include "../include/TransactionRecord.h"

#include "../include/BankingSystem.h"
#include "../include/Customer.h"
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

		for (const auto& transaction: *History)
		{
			std::cout << transaction << std::endl;
		}
	}


BOOST_AUTO_TEST_SUITE_END()
