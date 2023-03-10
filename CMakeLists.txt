cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

set(ProjectName CircleCITest)
set(LibraryName CircleCITest)
set(ExecutableName CircleCITestExe)

project(${ProjectName} VERSION 0.1.0)

if(NOT DEFINED ENV{CIRCLECI})
include("C:/MyLib/CMakeModules/deploy.cmake")
endif()

enable_testing()
add_subdirectory(tests)

file(GLOB_RECURSE LIB_SOURCES LIST_DIRECTORIES false CONFIGURE_DEPENDS "libsources/*.cpp")
file(GLOB_RECURSE EXE_SOURCES LIST_DIRECTORIES false CONFIGURE_DEPENDS "sources/*.cpp")

add_library(${LibraryName} ${LIB_SOURCES})
add_executable(${ExecutableName} ${EXE_SOURCES})

target_include_directories(${LibraryName} PUBLIC "libsources")

target_include_directories(${ExecutableName} PUBLIC "sources" "libsources")
target_link_directories(${ExecutableName} PUBLIC "build")
target_link_libraries(${ExecutableName} ${LibraryName})

if(NOT DEFINED ENV{CIRCLECI})
deploy_lib("test" ${LibraryName} ${ProjectName})
add_subdirectory(libsources)
endif()


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)