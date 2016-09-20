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
	EXPECT_EQ(-1, romanToArabic((char*)"CCCC"));
	EXPECT_EQ(-1, romanToArabic((char*)"MMMM"));
	EXPECT_EQ(-1, romanToArabic((char*)"DD"));
	EXPECT_EQ(-1, romanToArabic((char*)"VV"));
	EXPECT_EQ(-1, romanToArabic((char*)"LL"));
	EXPECT_EQ(-1, romanToArabic((char*)"LL1"));
	EXPECT_EQ(-1, romanToArabic((char*)"V3V"));
	EXPECT_EQ(-1, romanToArabic((char*)"CiDD"));
	EXPECT_EQ(-1, romanToArabic((char*)"MMM3"));
}
TEST(Conversion, Subtraction){
	EXPECT_EQ(4, romanToArabic((char*)"IV"));
	EXPECT_EQ(640, romanToArabic((char*)"DCXL"));
	EXPECT_EQ(690, romanToArabic((char*)"DCXC"));
	EXPECT_EQ(2290, romanToArabic((char*)"MMCCXC"));
	EXPECT_EQ(2990, romanToArabic((char*)"MMCMXC"));
}
TEST(Conversion, UnexpectedSubtraction){
	EXPECT_EQ(-1, romanToArabic((char*)"LCC"));
	EXPECT_EQ(-1, romanToArabic((char*)"LLC"));
	EXPECT_EQ(-1, romanToArabic((char*)"DDM"));
	EXPECT_EQ(-1, romanToArabic((char*)"DM"));
	EXPECT_EQ(-1, romanToArabic((char*)"IVIV"));
	EXPECT_EQ(-1, romanToArabic((char*)"IIV"));
	EXPECT_EQ(-1, romanToArabic((char*)"IIX"));
	EXPECT_EQ(-1, romanToArabic((char*)"IM"));
}
TEST(Conversion, General){
	EXPECT_EQ(188, romanToArabic((char*)"CLXXXVIII"));
	EXPECT_EQ(200, romanToArabic((char*)"CC"));
	EXPECT_EQ(838, romanToArabic((char*)"DCCCXXXVIII"));
	EXPECT_EQ(1487, romanToArabic((char*)"MCDLXXXVII"));
	EXPECT_EQ(2347, romanToArabic((char*)"MMCCCXLVII"));
	EXPECT_EQ(-1, romanToArabic((char*)"iV"));
	EXPECT_EQ(2318, romanToArabic((char*)"MMCCCXVIII"));
	EXPECT_EQ(-1, romanToArabic((char*)" "));
}



int main(int argc, char** argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
