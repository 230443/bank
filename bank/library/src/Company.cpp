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
	std::string Company::getInfo() const
	{
		return name + " " + std::to_string(nip);
	}
	void Company::setNumber(uint64_t number)
	{
		nip = number;
	}
	uint64_t Company::getNumber() const
	{
		return nip;
	}

}
