#include <gtest/gtest.h>
#include "romanToArabic.hpp"



TEST(Conversion, Single){
	EXPECT_EQ(1, romanToArabic((char*)"I"));
	EXPECT_EQ(5, romanToArabic((char*)"V"));
	EXPECT_EQ(-1, romanToArabic((char*)"!"));
	EXPECT_EQ(-1, romanToArabic((char*)"U"));
	EXPECT_EQ(-1, romanToArabic((char*)"1"));
	EXPECT_EQ(-1, romanToArabic((char*)"i"));
	EXPECT_EQ(10, romanToArabic((char*)"X"));
	EXPECT_EQ(50, romanToArabic((char*)"L"));
	EXPECT_EQ(100, romanToArabic((char*)"C"));
	EXPECT_EQ(1000, romanToArabic((char*)"M"));
	EXPECT_EQ(500, romanToArabic((char*)"D"));


}



int main(int argc, char** argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
