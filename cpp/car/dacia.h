#pragma once

#include "car.h"
#include <iostream>


class Dacia : public Car {
public:
	Dacia* clone()override
	{
		return new Dacia(*this);
	}

	void start()override
	{
		std::cout << "Dacia has just started!\n";
	}

	void run()override
	{
		std::cout << "Dacia is running now!\n";
	}

	void stop()override
	{
		std::cout << "Dacia has stopped!\n";
	}
	
	virtual void print(std::ostream& os)const override
	{
		os << "I am a Dacia\n";
	}
};
