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
			customer = std::make_shared<Person>(Person());
			break;
		}
		case 'c':
		{
			customer = std::make_shared<Company>(Company());
			break;
		}
		default:
		{
			throw std::invalid_argument("Type type does not exist");
		}

		}
		bs::Get().takeCustomer(customer);
		owner = customer;
	}
	bool UserAccount::logIn(uint64_t id, const std::string& password)
	{
		try{
			auto customer = bs::Get().logIn(id,password);
		}
		catch (std::exception& e)
		{
			return false;
		}
		auto customer = bs::Get().logIn(id,password);
		if (customer != nullptr)
		{
			owner = customer;
			return true;
		}
		else
			return false;
	}
	void UserAccount::logOut()
	{
		account = AccountPtr(nullptr);
		owner = CustomerPtr(nullptr);
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
	TransactionRecordPtr UserAccount::transfer(uint64_t to, double amount, std::string title)
	{
		if (account != nullptr)
			return bs::Get().transfer(account,to,amount,std::move(title));
		else
			throw std::exception();
	}
}
