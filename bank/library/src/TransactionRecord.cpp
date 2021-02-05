//
// Created by daniel on 04.02.2021.
//

#include "TransactionRecord.h"

std::ostream& operator<<(std::ostream& stream, bank::TransactionRecord& rhs)
{
	stream << rhs.title << " " << rhs.amount;
	return stream;
}