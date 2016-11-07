#include <catch.hpp>

#include "implementation-void_t.h"

struct empty
{
};

struct some_metafunction
{
    using type = int;
};

struct some_object_type
{
    int member;
};

TEST_CASE("detect member type", "[sfinae]")
{
    CHECK(has_type_typedef<empty>::value == false);
    CHECK(has_type_typedef<some_metafunction>::value == true);
}

TEST_CASE("detect member variable", "[sfinae]")
{
    CHECK(has_member_variable<empty>::value == false);
    CHECK(has_member_variable<some_object_type>::value == true);
}

