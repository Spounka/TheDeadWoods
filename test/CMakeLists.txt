project(TheDeadWoodsTests)

include(GoogleTest REQUIRED)
include_directories(lib/googletest-release-1.10.0/googletest/include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests/bin)

