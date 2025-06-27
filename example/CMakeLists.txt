add_executable(
    demo
    demo.cpp
)

target_include_directories(
    demo
    PUBLIC
    "${PROJECT_SOURCE_DIR}/include/"
)

install(
    TARGETS
    demo
    DESTINATION
    ${PROJECT_SOURCE_DIR}/example
)
