
#include <iostream>

using namespace std;


// base class
class mammal
{
protected:

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
protected:

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
	using mammal::tiger;
	using mammal::lion;
	using mammal::zebra;
	using mammal::monkey;
	using mammal::buffalo;

	using bird::eagle;
	using bird::hawk;
	using bird::seagull;
	using bird::parrot;
	using bird::crow;

	using reptile::alligator;
	using reptile::snake;
	using reptile::lizard;
	using reptile::turtle;
	using reptile::crocodile;
};
class animal animals;