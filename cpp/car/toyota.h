#pragma once

#include "car.h"
#include <iostream>

class Toyota : public Car {
public:
	Toyota* clone()override
	{
		return new Toyota(*this);
	}

	void start()override
	{
		std::cout << "Toyota has just started!\n";
	}

	void run()override
	{
		std::cout << "Toyota is running now!\n";
	}

	void stop()override
	{
		std::cout << "Toyota has stopped!\n";
	}


	virtual void print(std::ostream& os)const override
	{
		os << "I am a Toyota\n";
	}

};
