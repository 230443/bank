//
// Created by daniel on 04.02.2021.
//
//
// Created by daniel on 04.02.2021.
//

#include <boost/test/unit_test.hpp>
#include <memory>

#include "../include/TransactionRecord.h"
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

		BOOST_REQUIRE_EQUAL(a0->getTransactionRecords().size(),1);
		BOOST_REQUIRE_EQUAL(a1->getTransactionRecords().size(),1);
		BOOST_REQUIRE_EQUAL(*(a0->getTransactionRecords().begin())==*(a1->getTransactionRecords().begin()),true);
	}
	BOOST_AUTO_TEST_CASE(Customer_PrintAccounts)
	{
		auto c0 = bs::Get().newCustomer();

		AccountPtr a[4];
		a[0] = c0->newAccount();
		a[1] = c0->newAccount();
		a[2] = c0->newAccount();
		a[3] = c0->newAccount();

		bs::Get().transfer(a[0], a[3], 1, "tr1");
		bs::Get().transfer(a[1], a[0], 2, "tr2");
		bs::Get().transfer(a[2], a[0], 3, "tr3");
		bs::Get().transfer(a[3], a[0], 4, "tr4");

		auto history = a[0]->getHistory();
		for (TransactionRecord record: *history)
		{
			std::cout<<record<<std::endl;
		}

	}
	BOOST_AUTO_TEST_SUITE_END()

