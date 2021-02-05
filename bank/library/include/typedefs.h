//
// Created by daniel on 04.02.2021.
//

#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <memory>

namespace bank
{
	class Account;
	class Customer;
	class TransactionRecord;
	class BankingSystem;
	class Person;
	class Company;

	using bs = bank::BankingSystem;

	typedef std::shared_ptr<Account> AccountPtr;
	typedef std::shared_ptr<Customer> CustomerPtr;
	typedef std::shared_ptr<TransactionRecord> TransactionRecordPtr;
}




#endif //TYPEDEFS_H
