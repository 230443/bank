//
// Created by daniel on 05.02.2021.
//

#ifndef PERSON_H
#define PERSON_H

#include "Customer.h"

namespace bank
{
	class Person : public Customer
	{
	public:
		Person(std::string name = "person", std::string address = "", unsigned int telephoneNumber = 0, uint64_t pesel = 0);

		std::string getInfo() const override;
		uint64_t getPesel() const;
		uint64_t getNumber() const override;
		void setPesel(uint64_t pesel);
		void setNumber(uint64_t number) override;

	private:
		uint64_t pesel;
	};
}

#endif //PERSON_H
