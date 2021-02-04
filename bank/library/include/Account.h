//
// Created by daniel on 04.02.2021.
//

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <vector>
#include <memory>
#include "typedefs.h"


struct TransactionRecord;


namespace bank
{

	class Account
	{
	public:
		Account(CustomerPtr owner);

		const uint64_t getNumber() const;
		double getBalance() const;
		CustomerPtr getOwner() const;
		std::string getName();

		//virtual void transaction(double amount, TransactionRecordPtr record);
		//std::string getOwnerInfo();

// member fields
		const uint64_t number;
		static uint64_t counter;
	protected:
		double balance;
		std::vector<TransactionRecordPtr> transaction_history;
		std::weak_ptr<Customer> owner;
	private:

	};

}
#endif //ACCOUNT_H
