//
// Created by daniel on 04.02.2021.
//

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <set>
#include <memory>
#include "typedefs.h"



namespace bank
{

	class Account
	{
	public:
		Account(std::weak_ptr<Customer> owner);

		const uint64_t getNumber() const;
		double getBalance() const;
		CustomerPtr getOwner() const;
		std::string getName();
		const std::set<TransactionRecordPtr>& getTransactionRecords() const;
		std::shared_ptr<std::set<TransactionRecord>> getHistory() const;

		virtual void transaction(double amount, TransactionRecordPtr record);
		//std::string getOwnerInfo();

// member fields
		const uint64_t number;
	protected:
		double balance;
		std::set<TransactionRecordPtr> transactionHistory;
		std::weak_ptr<Customer> owner;
	private:
		static uint64_t counter;
	};

}
#endif //ACCOUNT_H
