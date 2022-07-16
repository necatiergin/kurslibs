#pragma once

#include "bmw.h"
#include "fiat.h"
#include "volvo.h"
#include "toyota.h"
#include "dacia.h"
#include <random>

Car* create_random_car()
{
	static std::mt19937 eng{ std::random_device{}() };
	static std::uniform_int_distribution dist{ 1, 7 };

	switch (dist(eng)) {
	case 1:  return new Bmw;
	case 2:  return new Fiat;
	case 3:	 return new Volvo;
	case 4:  return new Toyota;
	case 5:  return new Dacia;
	case 6:  return new VolvoS60;
	case 7:  return new VolvoXC90;
	}

	return nullptr;
}
