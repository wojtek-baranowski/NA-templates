#include <vector>
#include <list>

#include <catch.hpp>

#include "implementation.h"

TEST_CASE("size of vector", "[container_wrapper]")
{
    container_wrapper<std::vector<int>> c1;
    REQUIRE(c1.size() == 0);

    container_wrapper<std::vector<int>> c2 = std::vector<int>{ 1, 2, 3 };
    REQUIRE(c2.size() == 3);
}

TEST_CASE("size of list", "[container_wrapper]")
{
    container_wrapper<std::list<float>> c1;
    REQUIRE(c1.size() == 0);

    container_wrapper<std::list<float>> c2 = std::list<float>{ 1.f, 2.f };
    REQUIRE(c2.size() == 2);
}

