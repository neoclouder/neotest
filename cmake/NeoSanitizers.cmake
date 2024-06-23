set(DEFAULT_SANITIZERS "address,undefined")

function(neo_add_sanitizers target)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug" AND NEOTEST_ENABLE_SANITIZERS)
        target_compile_options(${target} PRIVATE -fno-omit-frame-pointer -fsanitize=${DEFAULT_SANITIZERS})
        target_link_options(${target} PUBLIC -fno-omit-frame-pointer -fsanitize=${DEFAULT_SANITIZERS})
    endif()
endfunction()
