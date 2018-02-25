// Chapters_16_18_Report_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "animals.h"

namespace dc = derived_class;

// function template to work with all types
template <class AnimalType>
AnimalType pick_animal_class(AnimalType A)
{
	if (A == 0)
	{
		cout << "this animal is a mammal" << endl;
	}
	else if (A >= 2.0)
	{
		cout << "this animal is a bird" << endl;
	}
	else if (A == 1)
	{
		cout << "this animal is a reptile" << endl;
	}

	return 0;
};


int main()
{
	using namespace dc;
	try {
		// mammals
		pick_animal_class(animals.tiger);
		pick_animal_class(animals.lion);
		pick_animal_class(animals.zebra);
		pick_animal_class(animals.monkey);
		pick_animal_class(animals.buffalo);

		// birds
		pick_animal_class(animals.eagle);
		pick_animal_class(animals.hawk);
		pick_animal_class(animals.seagull);
		pick_animal_class(animals.parrot);
		pick_animal_class(animals.crow);

		// reptiles
		pick_animal_class(animals.alligator);
		pick_animal_class(animals.snake);
		pick_animal_class(animals.lizard);
		pick_animal_class(animals.turtle);
		pick_animal_class(animals.crocodile);
	}
	catch (...) {
		cout << "some exception occrued" << endl;
	}

	return 0;
};
