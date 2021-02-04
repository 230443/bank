//
// Created by daniel on 04.02.2021.
//

#ifndef BANKINGSYSTEM_H
#define BANKINGSYSTEM_H

#include <map>
#include <list>
#include "typedefs.h"
//#include "Customer.h"


namespace bank
{

	class BankingSystem
	{
	private:
		std::list<TransactionRecordPtr> transactions;
		std::map<const uint64_t,std::weak_ptr<Account>> accounts;
		std::map<const uint64_t,CustomerPtr> customers;
	public:
		//BankingSystem(const BankingSystem&) = delete;
		static BankingSystem& Get();



		AccountPtr getAccount(int64_t number);
		CustomerPtr getCustomer(int64_t number);

		void takeCustomer(CustomerPtr customer);
		void takeAccount(AccountPtr account);

		CustomerPtr newCustomer();

		void transfer(std::shared_ptr<Account> from, int64_t number, std::string& title, double amount);
		void transfer(std::shared_ptr<Account> from, std::shared_ptr<Account> to, std::string& title, double amount);
		void addAccount(std::weak_ptr<Account> account);
		std::shared_ptr<Customer> addCustomer(const Customer& customer);

		std::shared_ptr<Customer>GetCustomer(int64_t id);

		std::shared_ptr<Customer> LogIn(std::string password, u_int64_t id);

	};

}
#endif //BANKINGSYSTEM_H
