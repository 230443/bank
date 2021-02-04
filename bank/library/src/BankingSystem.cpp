//
// Created by daniel on 04.02.2021.
//

#include "BankingSystem.h"
#include "Customer.h"

namespace bank
{
	BankingSystem& BankingSystem::Get()
	{
		static BankingSystem instance;
		return instance;
	}
	void BankingSystem::takeCustomer(CustomerPtr customer)
	{
		customers.insert({customer->id,customer});
	}
	void BankingSystem::takeAccount(AccountPtr account)
	{
		accounts.insert({account->number,account});
	}
	AccountPtr BankingSystem::getAccount(const int64_t number)
	{
		return accounts.find(number)->second.lock();
	}
	CustomerPtr BankingSystem::getCustomer(const int64_t number)
	{
		return customers.find(number)->second;
	}
	CustomerPtr BankingSystem::newCustomer()
	{
		auto newCustomer = std::make_shared<Customer>(Customer());
		customers.insert({newCustomer->id,newCustomer});
		return newCustomer;
	}

}


