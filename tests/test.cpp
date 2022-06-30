#include "pch.h"
#include "../infineonTask/median.cpp"

TEST(test_calculations, simple_arr)
{
	std::vector<long long> v = { 1, 5, 4, 6, 7, 9, 8, 10, 2, 3 };
    float medianValue = median(v);
    EXPECT_FLOAT_EQ(medianValue, 5.5);
}