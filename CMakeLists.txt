cmake_minimum_required(VERSION 3.15)

if ($ENV{GITHUB_RUN_NUMBER})
    project (Print_IP VERSION 0.0.$ENV{GITHUB_RUN_NUMBER})
else()
    project (Print_IP VERSION 0.0.1)
endif()

configure_file(version.h.in version.h)
 
add_executable(print_ip 
src/main.cpp
)

set_target_properties(print_ip 
PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(print_ip
    PRIVATE 
    ./include
    "${CMAKE_BINARY_DIR}"
)

if (MSVC)
    target_compile_options(print_ip 
        PRIVATE
        /EHsc /W4 /WX
    )
 else ()
    target_compile_options(print_ip 
        PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
  
endif()

install(TARGETS print_ip RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT madim-neodart@rambler.ru)
include(CPack)

