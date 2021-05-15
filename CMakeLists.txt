cmake_minimum_required (VERSION 2.8.12)

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
add_dependencies(NonLinearSystem openmind)
target_link_libraries(NonLinearSystem math leveldb pthread boost_serialization)
