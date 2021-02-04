//
// Created by daniel on 23.01.2021.
//

#ifndef OOPPROJECT_CUSTOMER_H
#define OOPPROJECT_CUSTOMER_H

#include <string>
#include <list>

#include "typedefs.h"
#include "Account.h"
#include "BankingSystem.h"



namespace bank
{

class Customer : public std::enable_shared_from_this<Customer>
	{
	public:
		Customer(std::string name = "customer", std::string address = "", unsigned int telephoneNumber = 0);


		// getters
		const uint64_t getId() const;
		const std::string& getName() const;
		const std::string& getAddress() const;
		unsigned int getTelephoneNumber() const;
		const std::list<AccountPtr>& getAccounts() const;

		// setters
		void setName(const std::string& name);
		void setAddress(const std::string& address);
		void setPassword(const std::string& password);
		void setTelephoneNumber(unsigned int telephoneNumber);

		//member functions

		AccountPtr newAccount();

		bool LogIn(std::string password);
		AccountPtr at(int position);
		void take(const std::shared_ptr<Account>& account);



		//	operators
		bool operator==(const Customer& rhs) const = default;
		auto operator<=>(const Customer& rhs) const
		{
			return id <=> rhs.id;
		}


		//	members

		const uint64_t id;
	static uint64_t counter;
private:
	protected:
		//info
		std::string name;
		std::string address;
		std::string password;
		unsigned int telephoneNumber;

		std::list<AccountPtr> accounts;
	};

}
#endif //OOPPROJECT_CUSTOMER_H
