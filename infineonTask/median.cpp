#include "median.h"
#include <vector>

double median(std::vector<long long> v)
{
    int size = v.size();
    if (size % 2 != 0)
        return static_cast<double>(v[size / 2]);
    return static_cast<double>(v[(size - 1) / 2] + v[size / 2]) / 2.0;
}
