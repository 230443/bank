//
// Created by daniel on 05.02.2021.
//

#include "Company.h"
namespace bank
{
	Company::Company(std::string name, std::string address, unsigned int telephoneNumber, uint64_t nip)
		: Customer(std::move(name), std::move(address), telephoneNumber), nip(nip)
	{
	}
	uint64_t Company::getNip() const
	{
		return nip;
	}
	void Company::setNip(uint64_t nip)
	{
		Company::nip = nip;
	}

}
