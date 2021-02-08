//
// Created by daniel on 23.01.2021.
//

#ifndef OOPPROJECT_CUSTOMER_H
#define OOPPROJECT_CUSTOMER_H

#include <string>
#include <vector>

#include "typedefs.h"
#include "Account.h"
#include "BankingSystem.h"



namespace bank
{

class Customer : public std::enable_shared_from_this<Customer>
	{
	public:
		Customer(std::string name = "customer", std::string address = "", unsigned int telephoneNumber = 0);

		bool isPasswordValid(const std::string& password);


		// getters
		const uint64_t getId() const;
		virtual uint64_t getNumber() const;
		virtual std::string getInfo() const;
		const std::string& getName() const;
		const std::string& getAddress() const;
		unsigned int getTelephoneNumber() const;
		const std::vector<AccountPtr>& getAccounts() const;
		const AccountPtr getAccount(uint64_t number) const;
		std::shared_ptr<std::set<TransactionRecordPtr>> getTransactionRecords();
		std::shared_ptr<std::set<TransactionRecord>> getHistory();


		// setters
		void setName(const std::string& name);
		virtual void setNumber(uint64_t number);
		void setAddress(const std::string& address);
		void setPassword(const std::string& password);
		void setTelephoneNumber(unsigned int telephoneNumber);

		//member functions

		AccountPtr newAccount();
		void takeAccount(const AccountPtr& account);

		void deleteAccount(uint64_t number);
		void deleteAccount(const AccountPtr& account);
		AccountPtr at(int position);



		//	operators
		bool operator==(const Customer& rhs) const = default;
		auto operator<=>(const Customer& rhs) const
		{
			return id <=> rhs.id;
		}


		//	members

		const uint64_t id;
private:
	static uint64_t counter;
protected:
		//info
		std::string name;
		std::string address;
		std::string password;
		unsigned int telephoneNumber;

		std::vector<AccountPtr> accounts;
	};

}
#endif //OOPPROJECT_CUSTOMER_H
