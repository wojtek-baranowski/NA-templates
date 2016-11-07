add_executable(41-find-if
    41-find-if.cpp
)

add_custom_target(run-41-find-if
    DEPENDS 41-find-if
    COMMAND ./41-find-if
)

add_executable(42-inner-product
    42-inner-product.cpp
)

add_custom_target(run-42-inner-product
    DEPENDS 42-inner-product
    COMMAND ./42-inner-product
)

add_executable(43-vector-erase
    43-vector-erase.cpp
)

add_custom_target(run-43-vector-erase
    DEPENDS 43-vector-erase
    COMMAND ./43-vector-erase
)

add_custom_target(run-40-all)
add_dependencies(run-40-all
    run-41-find-if
    run-42-inner-product
    run-43-vector-erase
)

add_dependencies(run-all
    run-40-all
)

