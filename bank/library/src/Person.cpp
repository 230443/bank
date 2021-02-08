//
// Created by daniel on 05.02.2021.
//

#include "Person.h"

#include <utility>

namespace bank
{
	Person::Person(std::string name, std::string address, unsigned int telephoneNumber, uint64_t pesel)
		: Customer(std::move(name), std::move(address), telephoneNumber), pesel(pesel)
	{
	}
	uint64_t Person::getPesel() const
	{
		return pesel;
	}
	void Person::setPesel(uint64_t pesel)
	{
		Person::pesel = pesel;
	}
	std::string Person::getInfo() const
	{
		return name + " " + address;;
	}
	void Person::setNumber(uint64_t number)
	{
		pesel = number;
	}
	uint64_t Person::getNumber() const
	{
		return pesel;
	}
}
