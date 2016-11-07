#include <catch.hpp>

#include "implementation.h"

type integer;
type boolean;
type string;
type float_;

std::vector<function> overload_set{
    { { variable{ &integer }, variable{ &integer } }, &boolean },
    { { variable{ &boolean }, variable{ &boolean } }, &boolean },
    { { variable{ &string }, variable{ &string } }, &boolean },
    { { variable{ &boolean }, variable{ &string } }, &float_ },
    { { variable{ &string }, variable{ &string }, variable{ &string } }, &string }
};

TEST_CASE("find_return_type", "[overload set]")
{
    CHECK(find_return_type(overload_set, { &boolean, &string }) == &float_);
    CHECK(find_return_type(overload_set, { &string, &string, &string }) == &string);
    CHECK(find_return_type(overload_set, { &boolean }) == nullptr);
}

