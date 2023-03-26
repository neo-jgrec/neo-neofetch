# Initialize project
cmake_minimum_required(VERSION 3.24.2)
project(neo-neofetch)

set(CMAKE_C_STANDARD 11)
set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS ON)

# Install dependencies
find_package(Curses REQUIRED)

if(NOT CURSES_FOUND)
  message("ncurses library not found on the system, installing...")
  include(FetchContent)
  FetchContent_Declare(
    ncurses
    GIT_REPOSITORY https://github.com/mirror/ncurses.git
    GIT_TAG        master
  )
  FetchContent_MakeAvailable(ncurses)
  set(CURSES_LIBRARIES ${ncurses_LIBRARY})
endif()

# Build project
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/main.c)
target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})

include_directories(${PROJECT_SOURCE_DIR}/include)
add_subdirectory(src)
target_link_libraries(${PROJECT_NAME} src)
