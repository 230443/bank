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
		void newCustomer(char type = 'x');
		bool logIn(uint64_t id, const std::string& password);

		virtual void customerMenu() = 0;
		virtual void logOut();
		virtual void deleteCustomer();
		virtual void newAccount(char type = 'x');
		virtual void getCustomerHistory() = 0;

		virtual void accountMenu() = 0;
		virtual void deleteAccount();
		virtual void getAccountHistory() = 0;
		TransactionRecordPtr transfer(AccountPtr to, double amount, std::string title);

	private:
		CustomerPtr owner;
		AccountPtr account;

	};
}

#endif //USERACCOUNT_H
