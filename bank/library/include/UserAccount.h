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
	protected:
		bool logIn(uint64_t id, const std::string& password);
		void newCustomer(char type = 'x');
		void newAccount(char type = 'x');
		TransactionRecordPtr transfer(uint64_t to, double amount, std::string title);
	public:

		virtual void bankMenu() = 0;
		virtual void customerMenu() = 0;
		virtual void accountMenu() = 0;

		virtual bool logIn() = 0;
		virtual void logOut();

		virtual void getCustomerHistory() = 0;
		virtual void getAccountHistory() = 0;

		virtual void deleteCustomer();
		virtual void deleteAccount();

		virtual void transfer() = 0;

	protected:
		CustomerPtr owner;
		AccountPtr account;

	};
}

#endif //USERACCOUNT_H
