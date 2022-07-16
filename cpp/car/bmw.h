#pragma once

#include "car.h"
#include <iostream>

class Bmw : public Car {
public:
	
	Bmw* clone()override
	{
		return new Bmw(*this);
	}

	void start()override
	{
		std::cout << "Bmw has just started!\n";
	}

	void run()override
	{
		std::cout << "Bmw is running now!\n";
	}

	void stop()override
	{
		std::cout << "Bmw has stopped!\n";
	}

	virtual void print(std::ostream& os)const override
	{
		os << "I am a BMW\n";
	}

};
