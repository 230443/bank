//
// Created by daniel on 04.02.2021.
//
//
// Created by daniel on 04.02.2021.
//

#include <boost/test/unit_test.hpp>
#include <memory>
#include <TransactionRecord.h>

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
		BOOST_REQUIRE_EQUAL(a0.getNumber()+1,a1.getNumber());
		BOOST_REQUIRE_EQUAL(a2.getNumber()-1,a1.getNumber());
		BOOST_REQUIRE_EQUAL(a3.getName(),"customer");
	}
	BOOST_AUTO_TEST_CASE(Account_transaction_checkBalance)
	{
		auto owner = std::make_shared<Customer>(Customer());
		auto a0 = owner->newAccount();
		auto a1 = owner->newAccount();
		//TransactionRecord tr(100,a0,a1);
		auto tr = std::make_shared<TransactionRecord>(TransactionRecord(a0,a1,100));
		a0->transaction(-100,tr);
		a1->transaction(100,tr);

		BOOST_REQUIRE_EQUAL(a0->getBalance(),-100);
		BOOST_REQUIRE_EQUAL(a1->getBalance(),100);
	}
	BOOST_AUTO_TEST_CASE(Account_transaction_checkTransactionHistory)
	{
		auto owner = std::make_shared<Customer>(Customer());
		auto a0 = owner->newAccount();
		auto a1 = owner->newAccount();
		//TransactionRecord tr(100,a0,a1);
		auto tr = std::make_shared<TransactionRecord>(TransactionRecord(a0,a1,100));
		a0->transaction(-100,tr);
		a1->transaction(100,tr);

		BOOST_REQUIRE_EQUAL(a0->getTransactionHistory().size(),1);
		BOOST_REQUIRE_EQUAL(a1->getTransactionHistory().size(),1);
		BOOST_REQUIRE_EQUAL(*(a0->getTransactionHistory().begin())==*(a1->getTransactionHistory().begin()),true);
	}




BOOST_AUTO_TEST_SUITE_END()

