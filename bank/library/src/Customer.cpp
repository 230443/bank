//
// Created by daniel on 23.01.2021.
//

#include "Customer.h"

#include <utility>

namespace bank
{
	uint64_t Customer::counter = 0;

	Customer::Customer(std::string name, std::string address, unsigned int telephoneNumber)
	:name(std::move(name)), address(std::move(address)), telephoneNumber(telephoneNumber), id(counter++)
	{

	}
	const uint64_t Customer::getId() const
	{
		return id;
	}
	const std::string& Customer::getName() const
	{
		return name;
	}
	const std::string& Customer::getAddress() const
	{
		return address;
	}
	unsigned int Customer::getTelephoneNumber() const
	{
		return telephoneNumber;
	}
	const std::vector<AccountPtr>& Customer::getAccounts() const
	{
		return accounts;
	}
	void Customer::setName(const std::string& name)
	{
		Customer::name = name;
	}
	void Customer::setAddress(const std::string& address)
	{
		Customer::address = address;
	}
	void Customer::setPassword(const std::string& password)
	{
		Customer::password = password;
	}
	void Customer::setTelephoneNumber(unsigned int telephoneNumber)
	{
		Customer::telephoneNumber = telephoneNumber;
	}
	AccountPtr Customer::newAccount()
	{
		//Account account(shared_from_this());
		AccountPtr account = std::make_shared<Account>(weak_from_this());
		accounts.push_back(account);
		bs::Get().takeAccount(accounts.back());
		return account;
	}

	std::shared_ptr<std::set<TransactionRecordPtr>> Customer::getTransactionRecords()
	{
		using namespace std;

		auto TrHist = make_shared<set<TransactionRecordPtr>>();
		for(const auto& account : accounts)
		{
			TrHist->insert(account->getTransactionRecords().begin(), account->getTransactionRecords().end());
		}
		return TrHist;
	}

	std::shared_ptr<std::set<TransactionRecord>> Customer::getHistory()
	{
		using namespace std;

		using namespace std;

		auto TrHist = make_shared<set<TransactionRecord>>();
		for(const auto& account : accounts)
		{
			auto accountHistory = account->getHistory();
			TrHist->insert(accountHistory->begin(),accountHistory->end());
		}
		return TrHist;
	}
	const AccountPtr Customer::getAccount(uint64_t number) const
	{
		for(auto account : accounts)
			if (account->number == number)
				return account;
		throw std::invalid_argument("Account does not exist");
	}
	void Customer::deleteAccount(uint64_t number)
	{
		for (auto it = accounts.begin(); it != accounts.end();  ++it )
			if ((*it)->number == number)
			{
				accounts.erase(it);
				return;
			}
		throw std::invalid_argument("Account already does not exist");
	}
	void Customer::deleteAccount(const AccountPtr& account)
	{
		for (auto it = accounts.begin(); it != accounts.end();  ++it )
			if (*it == account)
			{
				accounts.erase(it);
				return;
			}
		throw std::invalid_argument("Account does not exist");
	}
	bool Customer::isPasswordValid(const std::string& password)
	{
		return Customer::password == password;
	}

	void Customer::takeAccount(const AccountPtr& account)
	{
		accounts.push_back(account);
		bs::Get().takeAccount(accounts.back());
	}
	std::string Customer::getInfo() const
	{
		return name;
	}
	void Customer::setNumber(uint64_t number)
	{


	}
	uint64_t Customer::getNumber() const
	{
		return 100;
	}

}
