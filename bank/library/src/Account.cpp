//
// Created by daniel on 04.02.2021.
//

#include "Account.h"
#include "Customer.h"


namespace bank
{
	uint64_t Account::counter = 0;

	const uint64_t Account::getNumber() const
	{
		return number;
	}
	double Account::getBalance() const
	{
		return balance;
	}
	Account::Account(std::weak_ptr<Customer> owner)
		: number(counter++), balance(0), owner(owner)
	{
	}
	CustomerPtr Account::getOwner() const
	{
		return owner.lock();
	}
	std::string Account::getName()
	{
		return owner.lock()->getName();
	}
	void Account::transaction(double amount, TransactionRecordPtr record)
	{
		balance+=amount;
		transactionHistory.insert(record);
	}
	const std::set<TransactionRecordPtr>& Account::getTransactionRecords() const
	{
		return transactionHistory;
	}
	std::shared_ptr<std::set<TransactionRecord>> Account::getHistory() const
	{
		using namespace std;
		//shared_ptr<set<TransactionRecord>> history;
		auto history = make_shared<set<TransactionRecord>>();
		for (const auto& it : transactionHistory)
			history->insert(*it);
		return history;
	}
	std::ostream& operator<<(std::ostream& os, const Account& account)
	{
		os << "number: " << account.number << " balance: " << account.balance;
		return os;
	}
}