#include <gtest/gtest.h>
#include "romanToArabic.hpp"



TEST(Conversion, Single){
	EXPECT_EQ(1, romanToArabic((char*)"I"));
	EXPECT_EQ(5, romanToArabic((char*)"V"));
	EXPECT_EQ(-1, romanToArabic((char*)"!"));
	EXPECT_EQ(-1, romanToArabic((char*)"U"));
	EXPECT_EQ(-1, romanToArabic((char*)"1"));
	EXPECT_EQ(-1, romanToArabic((char*)"i"));

}



int main(int argc, char** argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
