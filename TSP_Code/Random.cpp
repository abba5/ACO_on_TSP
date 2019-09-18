
#include <random>
#include <iostream>

int random_n(int n)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, n-1); // distribution in range [1, 6]

    return dist6(rng);
}

