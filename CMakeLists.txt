cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

# Set project name and version
project(NianNian VERSION 0.1)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Find SFML shared libraries
find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

# Compile executable
# SET (CMAKE_CXX_COMPILER  "/usr/bin/clang++")
file(GLOB SRC_FILES src/game/*.cpp)
file(GLOB HEADER_FILES src/game/*.hpp)

add_executable(NianNian 
    src/Main.cpp
    ${SRC_FILES}
    ${HEADER_FILES} src/game/ObjectCollection.cpp)
FILE(COPY resources/ DESTINATION "${CMAKE_BINARY_DIR}/resources")
# Set include directory search paths

target_include_directories(NianNian PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(NianNian
    PRIVATE
    "${CMAKE_SOURCE_DIR}/"
    "${CMAKE_SOURCE_DIR}/src"
    "${CMAKE_SOURCE_DIR}/include"
)


if(NOT USE_INSTALL_RESOURCE_PATH)
  set(RESOURCE_PATH "${PROJECT_SOURCE_DIR}/resources/")
else()
  set(RESOURCE_PATH "${CMAKE_INSTALL_PREFIX}/share/${CMAKE_PROJECT_NAME}/resources/")
endif()



# Link executable to required SFML modules
target_link_libraries(NianNian sfml-graphics sfml-audio)

# Set executable install location
install(TARGETS NianNian DESTINATION bin)

# # Set install location for resources
# install(DIRECTORY content
#   DESTINATION "${CMAKE_INSTALL_PREFIX}/share/${CMAKE_PROJECT_NAME}"
# )
