#include <catch.hpp>

#include "implementation.h"

TEST_CASE("check trait", "[is_any_of]")
{
    CHECK((is_any_of<int, int, float, bool>::value));
    CHECK((is_any_of<int, float, int, bool>::value));
    CHECK((is_any_of<int, float, bool, int>::value));
    CHECK((!is_any_of<int, float, bool, double>::value));
}

