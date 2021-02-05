//
// Created by daniel on 04.02.2021.
//

#ifndef TRANSACTIONRECORD_H
#define TRANSACTIONRECORD_H

#include <chrono>
#include <string>
#include <compare>
#include <utility>
//#include <memory>

#include "typedefs.h"
#include "Account.h"

namespace currency
{

}

namespace bank
{
	struct TransactionRecord
	{
		const std::chrono::time_point<std::chrono::system_clock> date;
		const double amount;
		const std::string from_name;
		const uint64_t from_accountNumber;
		const std::string to_name;
		const uint64_t to_accountNumber;
		const std::string title;
		//const currency c;

		TransactionRecord(
			const AccountPtr& formAccount,
			const AccountPtr& toAccount,
			const double amount,
			std::string  title = "Transfer")
			: date(std::chrono::system_clock::now()),
			  amount(amount),
			  from_name(formAccount->getName()),
			  from_accountNumber(formAccount->getNumber()),
			  to_name(toAccount->getName()),
			  to_accountNumber(toAccount->getNumber()),
			  title(std::move(title))
		{
		}

		TransactionRecord(std::string fromName,
			uint64_t fromAccountNumber,
			std::string toName,
			uint64_t toAccountNumber,
			double amount,
			std::string title)
			: from_name(std::move(fromName)), from_accountNumber(fromAccountNumber), to_name(std::move(toName)),
			  to_accountNumber(toAccountNumber), title(std::move(title)), date(std::chrono::system_clock::now()), amount(amount)//, c(currency)
		{
		}

		auto operator<=>(const TransactionRecord& rhs) const
		{
			return date <=> rhs.date;
		}
		bool operator==(const TransactionRecord& rhs) const = default;
	};
}

#endif //TRANSACTIONRECORD_H
