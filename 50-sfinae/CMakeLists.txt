add_executable(51-traits
    51-traits.cpp
)

add_custom_target(run-51-traits
    DEPENDS 51-traits
    COMMAND ./51-traits
)

add_executable(52-void_t
    52-void_t.cpp
)

add_custom_target(run-52-void_t
    DEPENDS 52-void_t
    COMMAND ./52-void_t
)

add_custom_target(run-50-all)
add_dependencies(run-50-all
    run-51-traits
    run-52-void_t
)

add_dependencies(run-all
    run-50-all
)

