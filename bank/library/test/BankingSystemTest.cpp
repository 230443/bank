//
// Created by daniel on 04.02.2021.
//

//
// Created by daniel on 02.02.2021.
//

#include <boost/test/unit_test.hpp>
#include <Account.h>


#include "../include/BankingSystem.h"
#include "../include/Customer.h"
#include "../include/typedefs.h"


//class Person;
//class Company;
//unsigned Customer::counter = 0;

using namespace bank;

uint64_t Customer::counter = 0;
uint64_t Account::counter = 0;

BOOST_AUTO_TEST_SUITE(BankingSystemTestSuit)


	BOOST_AUTO_TEST_CASE(BankingSystem_addCustomer)
	{
		//Person p("Person","w1 95-100",457154,11567187);
		//Company c("Company","w1 95-100",457154,18679814);
		//customer1 = BankingSystem::Get().addCustomer(p);
		//customer2 = BankingSystem::Get().addCustomer(c);
		auto c1 = std::make_shared<Customer>(Customer());
		auto c2 = std::make_shared<Customer>(Customer());

		auto id1 = c1->id;
		auto id2 = c2->id;

		bs::Get().takeCustomer(c1);
		bs::Get().takeCustomer(c2);

		BOOST_REQUIRE_NE(id1,id2);
		BOOST_REQUIRE_EQUAL(id1,bs::Get().getCustomer(id1)->id);
		BOOST_REQUIRE_EQUAL(id2,bs::Get().getCustomer(id2)->id);
		BOOST_REQUIRE_GT(bs::Get().getCustomer(id2)->id,bs::Get().getCustomer(id1)->id);
	}

	BOOST_AUTO_TEST_CASE(BankingSystem_newCustomer)
	{
		auto c3 = std::make_shared<Customer>(Customer("c3"));
		auto c4 = std::make_shared<Customer>(Customer("c4"));
		auto c1 = bs::Get().newCustomer();
		auto c2 = bs::Get().newCustomer();

		auto id1 = c1->id;
		auto id2 = c2->id;

		BOOST_REQUIRE_NE(id1,id2);
		BOOST_REQUIRE_EQUAL(id1,bs::Get().getCustomer(id1)->id);
		BOOST_REQUIRE_EQUAL(id2,bs::Get().getCustomer(id2)->id);
		BOOST_REQUIRE_GT(bs::Get().getCustomer(id2)->id,bs::Get().getCustomer(id1)->id);

	}


	BOOST_AUTO_TEST_CASE(BankingSystem_addAccount)
	{
		auto c1 = bs::Get().newCustomer();
		auto c2 = bs::Get().newCustomer();
		c1->setName("c1");
		c2->setName("c2");

		auto a1 = c1->newAccount();
		auto a2 = c1->newAccount();
		auto a3 = c2->newAccount();
		auto a4 = c2->newAccount();

		auto number = a1->getNumber();
		BOOST_REQUIRE_EQUAL(a1->getName(),c1->getName());
		BOOST_REQUIRE_EQUAL(bs::Get().getAccount(number)->getName(),"c1");
		BOOST_REQUIRE_EQUAL(bs::Get().getAccount(number+2)->getName(),"c2");
		BOOST_REQUIRE_EQUAL(bs::Get().getAccount(number)->getNumber()+3,bs::Get().getAccount(number+3)->getNumber());
	}


	BOOST_AUTO_TEST_CASE(BankingSystem_transfer)
	{

	}

	BOOST_AUTO_TEST_CASE(BankingSystem_transferByAccountNumber)
	{

	}

	BOOST_AUTO_TEST_CASE(BankingSystem_TestSingleInstance)
	{

	}


BOOST_AUTO_TEST_SUITE_END()
