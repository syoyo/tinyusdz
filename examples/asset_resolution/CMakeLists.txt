# Assume this cmake is called from tinyusdz root(../../)
set(EXAMPLE_TARGET "asset_resolution_example")

set(TINYUSDZ_API_TUTORIAL_SOURCES
    asset-resolution-example.cc
    )

add_executable(${EXAMPLE_TARGET} ${TINYUSDZ_API_TUTORIAL_SOURCES})
add_sanitizers(${EXAMPLE_TARGET})

target_include_directories(${EXAMPLE_TARGET} PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(${EXAMPLE_TARGET} tinyusdz_static)


set_target_properties(${EXAMPLE_TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
