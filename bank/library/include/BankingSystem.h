//
// Created by daniel on 04.02.2021.
//

#ifndef BANKINGSYSTEM_H
#define BANKINGSYSTEM_H

#include <map>
#include <list>
#include "typedefs.h"
#include "TransactionRecord.h"
//#include "Customer.h"


namespace bank
{

	class BankingSystem
	{
	private:
		std::list<TransactionRecordPtr> transactions;
		std::map<const uint64_t,std::weak_ptr<Account>> accounts;
		std::map<const uint64_t,CustomerPtr> customers;
		//BankingSystem(const BankingSystem&);
	public:
		static BankingSystem& Get();



		AccountPtr getAccount(int64_t number);
		CustomerPtr getCustomer(int64_t number);

		void takeCustomer(CustomerPtr customer);
		void takeAccount(AccountPtr account);

		CustomerPtr newCustomer();
		void deleteCustomer(int64_t id);

		void transfer(AccountPtr from, int64_t number,double amount, std::string title = "Transfer");
		void transfer(AccountPtr from, AccountPtr to, double amount, std::string title = "Transfer");


		CustomerPtr LogIn( u_int64_t id, std::string password);

	};

}
#endif //BANKINGSYSTEM_H
