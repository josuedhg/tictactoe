#include <gtest/gtest.h>

TEST(Sample, ThisShouldBeTrue)
{
	ASSERT_TRUE(true);
}

int main()
{
	::testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
