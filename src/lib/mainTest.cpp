#include <gtest/gtest.h>
#include "romanToArabic.hpp"



TEST(Conversion, Single){
	EXPECT_EQ(1, romanToArabic((char*)"I"));
	EXPECT_EQ(5, romanToArabic((char*)"V"));
	EXPECT_EQ(10, romanToArabic((char*)"X"));
	EXPECT_EQ(50, romanToArabic((char*)"L"));
	EXPECT_EQ(100, romanToArabic((char*)"C"));
	EXPECT_EQ(500, romanToArabic((char*)"D"));
	EXPECT_EQ(1000, romanToArabic((char*)"M"));
	EXPECT_EQ(-1, romanToArabic((char*)"!"));
	EXPECT_EQ(-1, romanToArabic((char*)"U"));
	EXPECT_EQ(-1, romanToArabic((char*)"1"));
	EXPECT_EQ(-1, romanToArabic((char*)"i"));
}
TEST(Conversion, Addition){
	EXPECT_EQ(2, romanToArabic((char*)"II"));
	EXPECT_EQ(1007, romanToArabic((char*)"MVII"));
	EXPECT_EQ(7, romanToArabic((char*)"VII"));
	EXPECT_EQ(1280, romanToArabic((char*)"MCCLXXX"));
	EXPECT_EQ(3000, romanToArabic((char*)"MMM"));
	EXPECT_EQ(2678, romanToArabic((char*)"MMDCLXXVIII"));
}
TEST(Conversion, UnexpectedAddition){
	EXPECT_EQ(-1, romanToArabic((char*)"IIII"));
	EXPECT_EQ(-1, romanToArabic((char*)"XXXX"));
}



int main(int argc, char** argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
