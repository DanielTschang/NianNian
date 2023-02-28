cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

# Set project name and version
project(NianNian VERSION 0.1)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


set(SFML_DIR SFML/lib/cmake/SFML)
link_directories("SFML/lib")
link_directories("SFML/include")
link_directories("SFML/bin")
include_directories(SFML/include)
include_directories(SFML/bin)

# Find SFML shared libraries
find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

# Compile executable
# SET (CMAKE_CXX_COMPILER  "/usr/bin/clang++")
file(GLOB SRC_FILES src/game/*.cpp)
file(GLOB HEADER_FILES src/game/*.hpp)

add_executable(NianNian
        src/Main.cpp
        ${SRC_FILES}
        ${SFML_HEADER_FILES}
        ${HEADER_FILES})
FILE(COPY resources/ DESTINATION "${CMAKE_BINARY_DIR}/resources")
FILE(COPY Config/ DESTINATION "${CMAKE_BINARY_DIR}/Config")
FILE(COPY Fonts/ DESTINATION "${CMAKE_BINARY_DIR}/Fonts")
# Set include directory search paths

target_include_directories(NianNian PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(NianNian
        PRIVATE
        "${CMAKE_SOURCE_DIR}/"
        "${CMAKE_SOURCE_DIR}/src"
        "${CMAKE_SOURCE_DIR}/include"
        "${CMAKE_SOURCE_DIR}/SFML/include"
        )


if(NOT USE_INSTALL_RESOURCE_PATH)
  set(RESOURCE_PATH "${PROJECT_SOURCE_DIR}/resources/")
else()
  set(RESOURCE_PATH "${CMAKE_INSTALL_PREFIX}/share/${CMAKE_PROJECT_NAME}/resources/")
endif()

#target_link_libraries(NianNian
#        SFML/bin/sfml-system-d-2.dll
#        SFML/bin/sfml-audio-d-2.dll
#        SFML/bin/sfml-graphics-d-2.dll
#        SFML/bin/sfml-window-d-2.dll
#        )


# Link executable to required SFML modules
target_link_libraries(NianNian sfml-graphics sfml-audio sfml-window sfml-system)


# Set executable install location
install(TARGETS NianNian DESTINATION bin)

# # Set install location for resources
# install(DIRECTORY content
#   DESTINATION "${CMAKE_INSTALL_PREFIX}/share/${CMAKE_PROJECT_NAME}"
# )
