add_executable(61-stm
    61-stm.cpp
)

add_custom_target(run-61-stm
    DEPENDS 61-stm
    COMMAND ./61-stm
)

add_custom_target(run-60-all)
add_dependencies(run-60-all
    run-61-stm
)

add_dependencies(run-all
    run-60-all
)

