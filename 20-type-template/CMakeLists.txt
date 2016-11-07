add_executable(21-container-wrapper
    21-tests.cpp
)

add_custom_target(run-21-container-wrapper
    DEPENDS 21-container-wrapper
    COMMAND ./21-container-wrapper
)

add_executable(22-invalid
    EXCLUDE_FROM_ALL
    22-invalid.cpp
)

add_executable(23-wrapped-optional
    23-optional.cpp
)

add_custom_target(run-23-wrapped-optional
    DEPENDS 23-wrapped-optional
    COMMAND ./23-wrapped-optional
)

add_custom_target(run-20-all)
add_dependencies(run-20-all
    run-21-container-wrapper
    run-23-wrapped-optional
)

add_dependencies(run-all
    run-20-all
)

