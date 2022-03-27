cmake_minimum_required (VERSION 3.6)

project (NonLinearSystem)

enable_language(CXX)
set (CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(OPENMIND_MATH_USE_LEVELDB_CACHE "Use Google LevelDB library to cache solutions" OFF)

include(FetchContent)
FetchContent_Declare(openmind 
	GIT_REPOSITORY https://github.com/ohhmm/openmind.git
	GIT_TAG main
	)
FetchContent_MakeAvailable(openmind)

exe(math)
