cmake_minimum_required(VERSION 3.10.3 FATAL_ERROR)
project(NativeScript CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Standalone/Unity options
option(BUILD_STANDALONE_SIMULATION "Build a standalone executable to run as a headless process" OFF)

if (BUILD_STANDALONE_SIMULATION)
	message("-- Setting up project for standalone simulation")
else()
	message("-- Setting up project for Unity native plugin")
endif()

# Math
option(USE_BULLET_MATH OFF)
option(USE_EIGEN_MATH OFF)

set(USE_EIGEN_MATH ON)

if (USE_BULLET_MATH)
	add_definitions(-DUSE_BULLET_MATH)
endif()
if(USE_EIGEN_MATH)
	add_definitions(-DUSE_EIGEN_MATH)
endif()


# Useful path variables
set(NATIVE_SCRIPT_SOURCE_DIR ${CMAKE_SOURCE_DIR}/Source)
set(THIRD_PARTY_SOURCE_DIR ${CMAKE_SOURCE_DIR}/ThirdParty)

if (BUILD_STANDALONE_SIMULATION)
	set(STANDALONE_OUTPUT ${CMAKE_SOURCE_DIR}/Build)
else()
	set(UNITY3D_PROJECT_NAME UnityProject)
	set(UNITY3D_DLL_OUTPUT ${CMAKE_SOURCE_DIR}/../${UNITY3D_PROJECT_NAME}/Assets/Plugins)
endif()

# Set platform-dependent compilation defines matching C#
if (NOT BUILD_STANDALONE_SIMULATION)
	add_definitions(-DUNITY_NATIVE_DLL)
	if (EDITOR)
		add_definitions(-DTARGET_OS_EDITOR)
		if (WIN32)
			add_definitions(-DTARGET_OS_EDITOR_WIN)
		elseif (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
			add_definitions(-DTARGET_OS_EDITOR_OSX)
		elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
			add_definitions(-DTARGET_OS_EDITOR_LINUX)
		endif()
	else()
		add_definitions(-DTARGET_OS_STANDALONE)
		if (WIN32)
			add_definitions(-DTARGET_OS_WIN)
		elseif (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
			add_definitions(-DTARGET_OS_OSX)
		elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
			add_definitions(-DTARGET_OS_LINUX)
		endif()
	endif()
endif()

# Set output path
if (BUILD_STANDALONE_SIMULATION)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${STANDALONE_OUTPUT})
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${STANDALONE_OUTPUT})
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${STANDALONE_OUTPUT})
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${STANDALONE_OUTPUT})
else()
	if (WIN32 OR (${CMAKE_SYSTEM_NAME} MATCHES "Darwin") OR (${CMAKE_SYSTEM_NAME} MATCHES "Linux"))
		if (EDITOR)
			set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${UNITY3D_DLL_OUTPUT}/Editor)
			set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${UNITY3D_DLL_OUTPUT}/Editor)
			set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${UNITY3D_DLL_OUTPUT}/Editor)
			set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELWITHDEBINFO ${UNITY3D_DLL_OUTPUT}/Editor)
		else()
			set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${UNITY3D_DLL_OUTPUT})
			set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${UNITY3D_DLL_OUTPUT})
			set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${UNITY3D_DLL_OUTPUT})
			set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELWITHDEBINFO ${UNITY3D_DLL_OUTPUT})
		endif()
	endif()
endif()

# Set the directories for NativeScript and game C++ as include directories
include_directories(
	${THIRD_PARTY_SOURCE_DIR}/entt/single_include
	
	
	${NATIVE_SCRIPT_SOURCE_DIR}/
	${NATIVE_SCRIPT_SOURCE_DIR}/Bindings
	${NATIVE_SCRIPT_SOURCE_DIR}/Game	
	${NATIVE_SCRIPT_SOURCE_DIR}/Simulation)

if (USE_BULLET_MATH)
	include_directories(
		${THIRD_PARTY_SOURCE_DIR}/bullet3/src)
endif()

if (USE_EIGEN_MATH)
	include_directories(
		${THIRD_PARTY_SOURCE_DIR}/eigen/Eigen)
endif()

# Set all .cpp files for NativeScript and the game as sources
if (BUILD_STANDALONE_SIMULATION)
	file(GLOB BINDING_S)
	file(GLOB BINDING_H)
else()
	file(GLOB BINDING_S ${NATIVE_SCRIPT_SOURCE_DIR}/Bindings/*.cpp)
	file(GLOB BINDING_H ${NATIVE_SCRIPT_SOURCE_DIR}/Bindings/*.h)
endif()
file(GLOB GAME_S ${NATIVE_SCRIPT_SOURCE_DIR}/Game/*.cpp)
file(GLOB GAME_H ${NATIVE_SCRIPT_SOURCE_DIR}/Game/*.h)
file(GLOB SIMULATION_S ${NATIVE_SCRIPT_SOURCE_DIR}/Simulation/*.cpp)
file(GLOB SIMULATION_H ${NATIVE_SCRIPT_SOURCE_DIR}/Simulation/*.h)
file(GLOB SIMULATION_ECS_S ${NATIVE_SCRIPT_SOURCE_DIR}/Simulation/*/*.cpp)
file(GLOB SIMULATION_ECS_H ${NATIVE_SCRIPT_SOURCE_DIR}/Simulation/*/*.h)
set(
	SOURCES
	${GAME_S}
	${GAME_H}
	${BINDING_S}
	${BINDING_H}
	${SIMULATION_S} 
	${SIMULATION_H}
	${SIMULATION_ECS_S} 
	${SIMULATION_ECS_H})

# Build target
if (BUILD_STANDALONE_SIMULATION)
	# Build an executable
	add_executable(${PROJECT_NAME} ${SOURCES})
else()
	# Build a library. If on an Apple platform, build it in a bundle.
	add_library(${PROJECT_NAME} MODULE ${SOURCES})
	set_target_properties(${PROJECT_NAME} PROPERTIES BUNDLE TRUE DEBUG_POSTFIX "" RELWITHDEBINFO_POSTFIX "" RELEASE_POSTFIX "")
endif()

target_link_libraries( 
	${PROJECT_NAME}
)

# Set prebuild command to generate ECS bindings
if (NOT BUILD_STANDALONE_SIMULATION)
	if (WIN32)
		set(BINDINGS_GENERATOR_DIR ${CMAKE_SOURCE_DIR}/../Tools/BindingsGenerator/)
		set(BINDINGS_GENERATOR_FULL_PATH ${BINDINGS_GENERATOR_DIR}/BindingsGenerator.exe)
	endif()

	add_custom_command(
		TARGET ${PROJECT_NAME}
		PRE_BUILD 
		COMMAND ${BINDINGS_GENERATOR_FULL_PATH} --ecs
		WORKING_DIRECTORY ${BINDINGS_GENERATOR_DIR}
	)
endif()

# Precompile header
target_precompile_headers(${PROJECT_NAME} 
	PRIVATE 
		${NATIVE_SCRIPT_SOURCE_DIR}/Game/Universal.h
)

# Enable C++11
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

# Setup VS solution structure
if (WIN32)
	function (add_subdirectory_with_folder folder_name)
		function (add_library name type)
			_add_library (${ARGV})
			# Do not wrap creation of INTERFACE libraries
			if (type STREQUAL INTERFACE)
				return()
			endif()

			set_target_properties(${name}
				PROPERTIES
				FOLDER "${folder_name}"
			)
		endfunction()

		function (add_executable name)
			_add_executable (${ARGV})
			set_target_properties(${name}
				PROPERTIES
				FOLDER "${folder_name}"
			)
		endfunction()

		add_subdirectory (${ARGN})
	endfunction()

	# Prepare third party libraries
	## bullet3
	if (USE_BULLET_MATH)
		message("-- Configure Bullet 3")
		set(USE_GLUT OFF)
		set(BUILD_UNIT_TESTS OFF)
		set(BUILD_CPU_DEMOS OFF)
		set(BUILD_BULLET2_DEMOS OFF)
		set(BUILD_OPENGL3_DEMOS OFF)
		set(BUILD_EXTRAS OFF)
		set(BUILD_ENET OFF)
		set(BUILD_CLSOCKET OFF)
		set(BUILD_EGL OFF)
		set(BUILD_PYBULLET OFF)
		set(BUILD_BULLET3 OFF)
		set(USE_MSVC_RUNTIME_LIBRARY_DLL ON)
		add_subdirectory_with_folder( "ThirdParty/Bullet3" ${THIRD_PARTY_SOURCE_DIR}/bullet3 )
	endif()

	## entt
	
	# Main source
	source_group(TREE ${NATIVE_SCRIPT_SOURCE_DIR} PREFIX "Source" FILES ${SOURCES})
endif()