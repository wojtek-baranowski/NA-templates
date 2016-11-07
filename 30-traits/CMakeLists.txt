add_executable(31-traits
    31-tests.cpp
)

add_custom_target(run-31-traits
    DEPENDS 31-traits
    COMMAND ./31-traits
)

add_executable(32-interesting
    32-interesting.cpp
)

add_custom_target(run-32-interesting
    DEPENDS 32-interesting
    COMMAND ./32-interesting
)

add_custom_target(run-30-all)
add_dependencies(run-30-all
    run-31-traits
    run-32-interesting
)

add_dependencies(run-all
    run-30-all
)

