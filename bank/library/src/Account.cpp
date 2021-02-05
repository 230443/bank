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
	const std::set<TransactionRecordPtr>& Account::getTransactionHistory() const
	{
		return transactionHistory;
	}

}