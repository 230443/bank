//
// Created by daniel on 04.02.2021.
//

#include "TransactionRecord.h"
#include <ctime>

std::string getTimeStr(std::chrono::time_point<std::chrono::system_clock> date){
	std::time_t now = std::chrono::system_clock::to_time_t(date);

	std::string s(30, '\0');
	std::strftime(&s[0], s.size(), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
	return s;
}

/*

std::ostream& operator<<(std::ostream& stream, const bank::TransactionRecord& rhs)
{
	stream //<< rhs.date.time_since_epoch().count()<< " "
		<< getTimeStr(rhs.date) << " "
		<< rhs.title << " "
		<< rhs.amount << " "
		<< rhs.from_name << "("
		<< rhs.from_accountNumber << ") "
		<< rhs.to_name << "("
		<< rhs.to_accountNumber << ")";
	return stream;
}*/
std::ostream& bank::operator<<(std::ostream& os, const bank::TransactionRecord& rhs)
{
	os //<< rhs.date.time_since_epoch().count()<< " "
		<< getTimeStr(rhs.date) << " "
		<< rhs.title << " "
		<< rhs.amount << " "
		<< rhs.from_name << "("
		<< rhs.from_accountNumber << ") "
		<< rhs.to_name << "("
		<< rhs.to_accountNumber << ")";
	return os;
}
