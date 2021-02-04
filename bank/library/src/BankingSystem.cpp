//
// Created by daniel on 04.02.2021.
//

#include "BankingSystem.h"

#include <utility>
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
	void BankingSystem::transfer(AccountPtr from, AccountPtr to, double amount, std::string title)
	{
		auto tr = std::make_shared<TransactionRecord>(TransactionRecord(from,to,100,std::move(title)));
		from->transaction(-amount,tr);
		to->transaction(+amount,tr);
		transactions.push_back(tr);
	}
	void BankingSystem::transfer(AccountPtr from, int64_t number, double amount, std::string title)
	{
		transfer(std::move(from),getAccount(number),amount,std::move(title));
	}

}


