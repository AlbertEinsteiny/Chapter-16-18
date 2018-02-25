#include "pch.h"
//#include "../Chapters_16_18_Report_2/Chapters_16_18_Report_2.cpp"
#include "../Chapters_16_18_Report_2/animals.h"

using namespace std;

// class that initializes members to test with
class animal_1 : public ::testing::Test
{
public:
	int tiger = 0;
	int lion = 0;
	int zebra = 0;
	int monkey = 0;
	int buffalo = 0;

	float eagle = 2.1;
	float hawk = 2.1;
	float seagull = 2.1;
	float parrot = 2.1;
	float crow = 2.1;

	bool alligator = 1;
	bool snake = 1;
	bool lizard = 1;
	bool turtle = 1;
	bool crocodile = 1;
};


TEST_F(animal_1, TestName)
{
	EXPECT_EQ(0, pick_animal_class(tiger));
	EXPECT_EQ(0, pick_animal_class(lion));
	EXPECT_EQ(0, pick_animal_class(zebra));
	EXPECT_EQ(0, pick_animal_class(monkey));
	EXPECT_EQ(0, pick_animal_class(buffalo));

	EXPECT_EQ(0, pick_animal_class(eagle));
	EXPECT_EQ(0, pick_animal_class(hawk));
	EXPECT_EQ(0, pick_animal_class(seagull));
	EXPECT_EQ(0, pick_animal_class(parrot));
	EXPECT_EQ(0, pick_animal_class(crow));

	EXPECT_EQ(0, pick_animal_class(alligator));
	EXPECT_EQ(0, pick_animal_class(snake));
	EXPECT_EQ(0, pick_animal_class(lizard));
	EXPECT_EQ(0, pick_animal_class(turtle));
	EXPECT_EQ(0, pick_animal_class(crocodile));
}