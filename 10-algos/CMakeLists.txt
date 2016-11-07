add_executable(11-algos
    11-algos.cpp
    implementation.cpp
)

add_custom_target(run-11-algos
    DEPENDS 11-algos
    COMMAND ./11-algos
)

add_custom_target(run-10-all)
add_dependencies(run-10-all
    run-11-algos
)

add_dependencies(run-all
    run-10-all
)

