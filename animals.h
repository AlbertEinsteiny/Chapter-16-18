#include <iostream>

using namespace std;

namespace base_classes {
	// base class
	namespace one {
		class mammal
		{
		protected:

			int tiger = 0;
			int lion = 0;
			int zebra = 0;
			int monkey = 0;
			int buffalo = 0;
		};
		class mammal mammals;
	}

	// base class
	namespace two {
		class bird
		{
		protected:

			float eagle = 2.1;
			float hawk = 2.1;
			float seagull = 2.1;
			float parrot = 2.1;
			float crow = 2.1;
		};
		class bird birds;
	}

	// base class
	namespace three {
		class reptile
		{
		protected:

			bool alligator = 1;
			bool snake = 1;
			bool lizard = 1;
			bool turtle = 1;
			bool crocodile = 1;
		};
		class reptile reptiles;
	}
}
namespace bc = base_classes;
namespace mam = bc::one;

// derived class
namespace derived_class {
	class animal : protected mam::mammal, protected bc::two::bird, protected bc::three::reptile
	{
	public:
		mammal::tiger;
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
}
