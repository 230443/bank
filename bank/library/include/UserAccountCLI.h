//
// Created by daniel on 05.02.2021.
//

#ifndef USERACCOUNTCLI_H
#define USERACCOUNTCLI_H

#include "UserAccount.h"


namespace bank
{
	class UserAccountCLI : public UserAccount
	{
	public:
		static void start();
	private:
		void bankMenu() override;
		void customerMenu() override;
		void accountMenu() override;
		void printBankMenu();
		void printCustomerMenu();
		void printAccountMenu();
		void printYourAccounts();
		bool logIn() override;
		void logOut() override;

		bool newCustomer();
		void goToAccount();
		void setName();
		void setPassword();
		void setAddress();
		bool isNumber(std::string str);

		void getCustomerHistory() override;
		void getAccountHistory() override;
		void deleteCustomer() override;
		void deleteAccount() override;
		void transfer() override;
	};

}
#endif //USERACCOUNTCLI_H
