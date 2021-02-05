//
// Created by daniel on 05.02.2021.
//

#ifndef COMPANY_H
#define COMPANY_H


#include "Customer.h"

namespace bank
{
	class Company : public Customer
	{
	public:
		Company(std::string name = "company", std::string address = "", unsigned int telephoneNumber = 0, uint64_t nip = 0);

		uint64_t getNip() const;
		void setNip(uint64_t nip);

	private:
		uint64_t nip;
	};
}


#endif //COMPANY_H
