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
		printBankMenu();

		int c;
		do {
			c = getchar();
			switch (c)
			{
			case 'l':
			{
				if (logIn())
					customerMenu();
				printBankMenu();
				continue;
			}
			case 'n':
				if (newCustomer())
					customerMenu();
				printBankMenu();
				continue;
			case 'q':
				exit(0);
			default:
				putchar(c);
			}
		} while (c != 'Q');
	}
	void UserAccountCLI::customerMenu()
	{
		printCustomerMenu();
		string str;
		do
		{
			cout<<endl<<":";
			cin >> str;
			if (str == "a")
			{
				printYourAccounts();
				printCustomerMenu();
				continue;
			}
			if (str == "n")
			{
				UserAccount::newAccount();
				accountMenu();
				printCustomerMenu();
				continue;
			}
			if (str == "h")
			{
				getCustomerHistory();
				continue;
			}
			if (str == "sp")
			{
				setPassword();
				printCustomerMenu();
				continue;
			}
			if (str == "sn")
			{
				setName();
				printCustomerMenu();
				continue;
			}
			if (str == "sa")
			{
				setAddress();
				printCustomerMenu();
				continue;
			}
			if (str == "d")
			{
				deleteCustomer();
				continue;
			}
			cout<<"Command not found."<<endl;
		} while (str != "q"||str != "Q");
		logOut();
	}
	void UserAccountCLI::accountMenu()
	{
		cout<<"Account number: "<<account->getNumber()<<"\tBalance: "<<account->getBalance()<<endl
			<<"h"<<"\t"<<"Transaction History"<<endl
			<<"d"<<"\t"<<"Delete this Account"<<endl
			<<"t"<<"\t"<<"Make transfer"<<endl
			<<"b"<<"\t"<<"Go to the customer account"<<endl;

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
				account = AccountPtr(nullptr);
				return;
			}
			default:
				putchar(c);
			}
		} while (c != 'Q');

	}
	bool UserAccountCLI::logIn()
	{

		while (true)
		{
			string id, password;
			cout << "Client ID: ";
			cin >> id;
			cout << "Password: ";
			cin >> password;

			if (isNumber(id))
			{
				if (UserAccount::logIn(stoi(id), password))
					return true;
			}
			else
			{
				cout << "login failed. Do you want to continue?[y/N]: ";
				string c;
				cin >> c;
				if (c == "Y" || c == "y")
					continue;
				else
					return false;
			}
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
	bool UserAccountCLI::newCustomer()
	{
		while (true)
		{
		cout<<"Choose Account type:"<<endl
			<<"p"<<"\t"<<"Personal"<<endl
			<<"c"<<"\t"<<"Company"<<endl
			<<"q"<<"\t"<<"quit"<<endl;
		string input;
		cin>>input;
			if (input == "q") return false;
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
			setPassword();
			setName();
			setAddress();
			return true;
		}


	}
	void UserAccountCLI::goToAccount(string position)
	{
		printYourAccounts();

		if (!isNumber(position))	return;
		int p = stoi(position);

		auto accounts = owner->getAccounts();
		if (p>=1 && p<accounts.size())
		{
			account = accounts[p];
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
	void UserAccountCLI::setPassword()
	{
		cout<<"New password: ";
		string str;
		cin >> str;
		owner->setPassword(str);
	}
	void UserAccountCLI::setAddress()
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
	void UserAccountCLI::printCustomerMenu()
	{

		cout<<"Your Account \t Client Id: "<<owner->getId()<<endl;

		cout<<"n"<<"\t"<<"New Account"<<endl
			<<"a"<<"\t"<<"Your accounts"<<endl
			<<"h"<<"\t"<<"Transaction History"<<endl
			<<"sp"<<"\t"<<"Set password"<<endl
			<<"sn"<<"\t"<<"Set Name"<<endl
			<<"sa"<<"\t"<<"Set Address"<<endl
			<<"d"<<"\t"<<"Delete Customer Account"<<endl
			<<"q"<<"\t"<<"Log out"<<endl;
	}
	void UserAccountCLI::printYourAccounts()
	{
		auto accounts = owner->getAccounts();
		int i = 1;
		for (const auto& account: accounts)
		{
			cout<<i<<"\t"<<*account<<endl;
		}
	}
	bool UserAccountCLI::isNumber(std::string str)
	{
		try
		{
			stoi(str);
		}
		catch (const exception& e)
		{
			return false;
		}
		return true;
	}
	void UserAccountCLI::printBankMenu()
	{
		cout<<"Bank"<<endl
			<<'l'<<"\t"<<"Log in"<<endl
			<<'n'<<"\t"<<"Create Account"<<endl
			<<"q"<<"\t"<<"Exit"<<endl;
	}
}