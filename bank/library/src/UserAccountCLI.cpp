//
// Created by daniel on 05.02.2021.
//

#include "UserAccountCLI.h"
#include "Customer.h"
#include <iostream>


using namespace std;

namespace bank
{
	void UserAccountCLI::bankMenu()
	{
		cout<<"Bank"<<endl
		<<'l'<<"\t"<<"Log in"<<endl
		<<'n'<<"\t"<<"Create Account"<<endl
		<<"q"<<"\t"<<"Exit"<<endl;

		int c;
		do {
			c = getchar();
			switch (c)
			{
			case 'l':
				logIn();
			case 'n':
				newCustomer();
			case 'q':
				exit(0);
			default:
				putchar(c);
			}
		} while (c != 'Q');
	}
	void UserAccountCLI::customerMenu()
	{
		cout<<"Your Account \t Client Id: "<<owner->getId()<<endl;
		const vector<AccountPtr> accounts = owner->getAccounts();

		cout<<" \t"<<"account Number"<<"\t"<<"balance"<<endl;
		for (int i = 0; i<accounts.size(); i++)
		{
			cout<<i++<<"\t"<<accounts[i]->getNumber()<<"\t"<<accounts[i]->getBalance()<<endl;
		}

		cout<<"n"<<"\t"<<"New Account"<<endl
			<<"h"<<"\t"<<"Transaction History"<<endl
			<<"sp"<<"\t"<<"Set password"<<endl
			<<"sn"<<"\t"<<"Set Name"<<endl
			<<"sa"<<"\t"<<"Set Address"<<endl
			<<"d"<<"\t"<<"Delete Customer Account"<<endl
			<<"q"<<"\t"<<"Log out"<<endl;


		string str;
		while (true)
		{
			cout<<endl<<":";
			cin >> str;

			if (str == "n")
			{
				UserAccount::newAccount();
				accountMenu();
			}
			if (str == "h")
				getCustomerHistory();
			if (str == "sp")
				setpassword();
			if (str == "sn")
				setName();
			if (str == "sa")
				setAddres();
			if (str == "d")
				deleteCustomer();
			if (str == "q")
				logOut();

			try
			{
				goToAccount(stoi(str));
			}
			catch (const std::invalid_argument& e)
			{
				std::cout << e.what() << "\n";
				continue;
			}
			catch (const std::out_of_range& e)
			{
				std::cout << e.what() << "\n";
				continue;
			}
			goToAccount(stoi(str));
		}

	}
	void UserAccountCLI::accountMenu()
	{
		cout<<"Account number: "<<account->getNumber()<<"\tBalance: "<<account->getBalance()<<endl
			<<"h"<<"\t"<<"Transaction History"<<endl
			<<"d"<<"\t"<<"Delete this Account"<<endl
			<<"t"<<"\t"<<"Make transfer"<<endl
			<<"b"<<"\t"<<"Go to the customer account"<<endl
			<<"q"<<"\t"<<"Log out"<<endl;

		int c;
		do {
			c = getchar();
			switch (c)
			{
			case 'h':
				getAccountHistory();
			case 'd':
				deleteAccount();
			case 't':
				transfer();
			case 'b':
			{
				account.reset();
				return;
			}
			case 'q':
				logOut();
			default:
				putchar(c);
			}
		} while (c != 'Q');

	}
	void UserAccountCLI::logIn()
	{

		while (true)
		{
			string id, password;
			cout << "Client ID: ";
			cin >> id;
			cout << "Password: ";
			cin >> password;

			try
			{
				UserAccount::logIn(stoi(id), password);
			}
			catch (const std::invalid_argument& e)
			{
				std::cout << e.what() << "\n";
				continue;
			}
			catch (const std::out_of_range& e)
			{
				std::cout << e.what() << "\n";
				continue;
			}

			UserAccount::logIn(stoi(id), password);
			customerMenu();
		}
	}
	void UserAccountCLI::logOut()
	{
		UserAccount::logOut();
		bankMenu();
	}
	void UserAccountCLI::getCustomerHistory()
	{

	}
	void UserAccountCLI::getAccountHistory()
	{

	}
	void UserAccountCLI::deleteCustomer()
	{
		UserAccount::deleteCustomer();
		logOut();
	}
	void UserAccountCLI::deleteAccount()
	{
		UserAccount::deleteAccount();
		customerMenu();
	}
	void UserAccountCLI::transfer()
	{

	}
	void UserAccountCLI::newCustomer()
	{
		cout<<"Choose Account type:"<<endl
			<<"p"<<"\t"<<"Personal"<<endl
			<<"c"<<"\t"<<"Company"<<endl;
		string input;
		cin>>input;
		while (true)
		{
			if (input == "q") return;
			try
			{
				UserAccount::newCustomer(input[0]);
			}
			catch (const std::invalid_argument& e)
			{
				std::cout << e.what() << "\n";
				continue;
			}
			catch (const std::out_of_range& e)
			{
				std::cout << e.what() << "\n";
				continue;
			}
			UserAccount::newCustomer(input[0]);
			customerMenu();

		}



	}
	void UserAccountCLI::goToAccount(int position)
	{
		auto accounts = owner->getAccounts();
		if (position>=1 && position<accounts.size())
		{
			account = accounts[position];
			accountMenu();
		}
		else
			throw std::invalid_argument("No account with this index");
	}
	void UserAccountCLI::setName()
	{
		cout<<"New name: ";
		string str;
		cin >> str;
		owner->setName(str);
	}
	void UserAccountCLI::setpassword()
	{
		cout<<"New password: ";
		string str;
		cin >> str;
		owner->setPassword(str);
	}
	void UserAccountCLI::setAddres()
	{
		cout<<"New Address: ";
		string str;
		cin >> str;
		owner->setAddress(str);

	}
	void UserAccountCLI::start()
	{
		static UserAccountCLI instance;
		instance.bankMenu();
	}
}