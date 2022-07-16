#pragma once

#include "car.h"
#include <iostream>


class Volvo : public Car {
public:
	Volvo* clone()override
	{
		return new Volvo(*this);
	}

	void open_sunroof()
	{
		std::cout << "Volvo sun-roof opened\n";
	}

	void start()override
	{
		std::cout << "Volvo has just started!\n";
	}

	void run()override
	{
		std::cout << "Volvo is running now!\n";
	}

	void stop()override
	{
		std::cout << "Volvo has stopped!\n";
	}

	virtual void print(std::ostream& os)const override
	{
		os << "I am a Volvo\n";
	}
};


class VolvoS60 : public Volvo {
public:
	
	VolvoS60* clone()override
	{
		return new VolvoS60(*this);
	}

	void start()override
	{
		std::cout << "VolvoS60 has just started!\n";
	}

	void run()override
	{
		std::cout << "VolvoS60 is running now!\n";
	}

	void stop()override
	{
		std::cout << "VolvoS60 has stopped!\n";
	}

	virtual void print(std::ostream& os)const override
	{
		os << "I am a VolvoS60\n";
	}

};

class VolvoXC90 : public Volvo {
public:
	
	VolvoXC90* clone()override
	{
		return new VolvoXC90(*this);
	}

	void start()override
	{
		std::cout << "VolvoXC90 has just started!\n";
	}

	void run()override
	{
		std::cout << "VolvoXC90 is running now!\n";
	}

	void stop()override
	{
		std::cout << "VolvoXC90 has stopped!\n";
	}

	virtual void print(std::ostream& os)const override
	{
		os << "I am a VolvoXC90\n";
	}
};
