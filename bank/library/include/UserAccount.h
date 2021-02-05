//
// Created by daniel on 05.02.2021.
//

#ifndef USERACCOUNT_H
#define USERACCOUNT_H


#include "BankingSystem.h"
#include "typedefs.h"

namespace bank
{

	class UserAccount
	{
	public:

		virtual void bankMenu() = 0;
		void newCustomer(char type);
		bool logIn(uint64_t id, uint64_t password);

		virtual void customerMenu() = 0;
		void logOut();
		void deleteCustomer();
		void newAccount(char type);
		std::shared_ptr<std::set<TransactionRecord>> getCustomerHistory();

		virtual void accountMenu() = 0;
		void deleteAccount();
		std::shared_ptr<std::set<TransactionRecord>> getAccountHistory();
		TransactionRecordPtr transfer(AccountPtr to, double amount, std::string title);

	private:
		CustomerPtr owner;
		CustomerPtr account;

	};
}

#endif //USERACCOUNT_H
