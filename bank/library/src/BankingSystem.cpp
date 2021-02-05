//
// Created by daniel on 04.02.2021.
//

#include "BankingSystem.h"
#include <stdexcept>

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
		auto account = accounts.find(number);
		if (account == accounts.end())
			throw std::invalid_argument( "Account does not exist" );
		if (account->second.expired())
		{
			accounts.erase(account);
			throw std::invalid_argument("Account has been deleted");
		}

		return accounts.find(number)->second.lock();
	}
	CustomerPtr BankingSystem::getCustomer(const int64_t number)
	{
		auto customer = customers.find(number);
		if (customer == customers.end())
			throw std::invalid_argument( "Customer does not exist" );
		return customer->second;
	}
	CustomerPtr BankingSystem::newCustomer()
	{
		auto newCustomer = std::make_shared<Customer>(Customer());
		customers.insert({newCustomer->id,newCustomer});
		return newCustomer;
	}
	TransactionRecordPtr BankingSystem::transfer(AccountPtr from, AccountPtr to, double amount, std::string title)
	{
		auto tr = std::make_shared<TransactionRecord>(TransactionRecord(from,to,amount,std::move(title)));
		from->transaction(-amount,tr);
		to->transaction(+amount,tr);
		transactions.push_back(tr);
		return tr;
	}
	TransactionRecordPtr BankingSystem::transfer(AccountPtr from, int64_t number, double amount, std::string title)
	{
		return transfer(std::move(from),getAccount(number),amount,std::move(title));
	}
	void BankingSystem::deleteCustomer(int64_t id)
	{
		//getCustomer(id).reset();
		customers.erase(id);
	}
	CustomerPtr BankingSystem::logIn(u_int64_t id, const std::string& password)
	{
		auto c = getCustomer(id);
		if (c->isPasswordValid(password))
			return c;
		else
			return nullptr;
	}

}


