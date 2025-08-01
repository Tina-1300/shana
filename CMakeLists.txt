# cmake .. -DCMAKE_BUILD_TYPE=Release
# cmake --build .
# cmake --install .

cmake_minimum_required(VERSION 3.10)


set(PROJECT_NAME shana) # library name
set(PROJECT_VERSION 0.1.0)


project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Force a default build type if not defined
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

set(SOURCES
    src/vector.c
    src/stack.c

)

set(HEADERS
    include/${PROJECT_NAME}/vector.h
    include/${PROJECT_NAME}/stack.h
    
)

# Create the static library
add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

# Add compilation options (e.g. to enable optimizations)
target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<CONFIG:Debug>:-g -Wall -Wextra -Wpedantic -Werror>
    $<$<CONFIG:Release>:-O3 -Wall -Wextra>
)

# Link options when compiling the static library
# Oleaut32
# target_link_libraries(${PROJECT_NAME} PRIVATE 
#     ole32   
#     uuid 
# )

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)


# Set the output directory for the compiled library
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Set the installation location
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/${PROJECT_NAME})

# Add a folder for header files
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_PREFIX}/include)

# Install the library in the lib/ folder
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)

# launching unit tests

enable_testing()
add_subdirectory(tests)
