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
		void bankMenu() override;
		void customerMenu() override;
		void accountMenu() override;
		void logIn() override;
		void logOut() override;

		void newCustomer();
		void goToAccount(int position);
		void setName();
		void setpassword();
		void setAddres();

		void getCustomerHistory() override;
		void getAccountHistory() override;
		void deleteCustomer() override;
		void deleteAccount() override;
		void transfer() override;
	};

}
#endif //USERACCOUNTCLI_H
