set(lib shana) # library name


# Define a function to add tests easily
function(add_tests test_name test_source)
    add_executable(${test_name} ${test_source})
    target_link_libraries(${test_name} PRIVATE ${lib})
    add_test(NAME ${test_name} COMMAND ${test_name})
endfunction()

# Enable testing
enable_testing()


# Add all test files here
add_tests(test_vector test_vector.c)
add_tests(test_stack test_stack.c)


