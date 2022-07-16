#pragma once

#include <iosfwd>

class Car {
public:
	virtual ~Car() = default;
	virtual Car* clone() = 0;
	virtual void start() = 0;
	virtual void run() = 0;
	virtual void stop() = 0;
	virtual void print(std::ostream&)const = 0;
};


