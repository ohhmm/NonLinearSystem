cmake_minimum_required (VERSION 2.6)

project (NonLinearSystem)

include(ExternalProject)
ExternalProject_Add(openmind 
	GIT_REPOSITORY https://github.com/ohhmm/openmind.git
	GIT_TAG main
	INSTALL_COMMAND ""
	)
include_directories(
	${CMAKE_BINARY_DIR}/openmind-prefix/src
	${CMAKE_BINARY_DIR}/openmind-prefix/src/openmind
	)
link_directories(${CMAKE_BINARY_DIR}/openmind-prefix/src/openmind-build/omnn/math)

add_executable(NonLinearSystem NonLinearSystem.cpp)
target_link_libraries(NonLinearSystem math)
add_dependencies(NonLinearSystem openmind)
