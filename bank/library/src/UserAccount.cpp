//
// Created by daniel on 05.02.2021.
//

#include "Person.h"
#include "Company.h"
#include "UserAccount.h"

#include <utility>

namespace bank
{

	void UserAccount::newCustomer(char type)
	{
		CustomerPtr customer;
		switch (type)
		{
		case 'p':
		{
			customer = std::make_shared<Customer>(Person());
			break;
		}
		case 'c':
		{
			customer = std::make_shared<Customer>(Company());
			break;
		}
		default:
		{
			customer = std::make_shared<Customer>(Customer());
		}
		}
		bs::Get().takeCustomer(customer);
		owner = customer;
	}
	bool UserAccount::logIn(uint64_t id, const std::string& password)
	{
		auto customer = bs::Get().logIn(id,password);
		if (customer!= nullptr)
		{
			owner = customer;
			return true;
		}
		else
			return false;
	}
	void UserAccount::logOut()
	{
		account.reset();
		owner.reset();
	}
	void UserAccount::deleteCustomer()
	{
		bs::Get().deleteCustomer(owner->id);
		logOut();
	}
	void UserAccount::newAccount(char type)
	{
		account = owner->newAccount();
	}
	void UserAccount::deleteAccount()
	{
		owner->deleteAccount(account);
		account.reset();
	}
	TransactionRecordPtr UserAccount::transfer(AccountPtr to, double amount, std::string title)
	{
		if (account != nullptr)
			return bs::Get().transfer(account,std::move(to),amount,std::move(title));
		else
			throw std::exception();
	}
}
