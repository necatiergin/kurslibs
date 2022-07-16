#pragma once

#include "car.h"
#include <iostream>


class Fiat : public Car {
public:
	
	Fiat* clone()override
	{
		return new Fiat(*this);
	}

	void start()override
	{
		std::cout << "Fiat has just started!\n";
	}
	
	void run()override
	{
		std::cout << "Fiat is running now!\n";
	}
	
	void stop()override
	{
		std::cout << "Fiat has stopped!\n";
	}

	virtual void print(std::ostream& os)const override
	{
		os << "I am a Fiat\n";
	}
};
