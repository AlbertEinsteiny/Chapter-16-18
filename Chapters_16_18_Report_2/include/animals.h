
#include <iostream>

using namespace std;


// base class
class mammal
{
protected:
	// to be defined elsewhere
	//virtual animal_type();


	int tiger;
	int lion;
	int zebra;
	int monkey;
	int buffalo;
};
class mammal mammals;


// base class
class bird
{
public:

	float eagle;
	float hawk;
	float seagull;
	float parrot;
	float crow;
};
class bird birds;

// base class
class reptile
{
protected:

	bool alligator;
	bool snake;
	bool lizard;
	bool turtle;
	bool crocodile;
};
class reptile reptiles;

// derived class
class animal : protected mammal, protected bird, protected reptile
{
public:

	// 3 different types
	/*
	int tiger;
	int lion;
	int zebra;
	int monkey;
	int buffalo;

	float eagle;
	float hawk;
	float seagull;
	float parrot;
	float crow;

	bool alligator;
	bool snake;
	bool lizard;
	bool turtle;
	crocodile;*/

	//float birds.hawk = 5;

	// function template to work with all types
	template <typename A>
	void pick_animal_class(A)
	{
		if (A == int)
		{
			cout << "This animal is a mammal" << endl;
		}
		else if (A == float)
		{
			cout << "This animal is a bird" << endl;
		}
		else if (A == bool)
		{
			cout << "This animal is a reptile" << endl;
		}

	}

};
class animal animals;