#pragma once

#include <vector>

struct type
{
};

struct variable
{
    struct type * type;
};

struct function
{
    std::vector<variable> arguments;
    type * return_type;
};

type * find_return_type(const std::vector<function> & overload_set, std::vector<type *> argument_types);

