cmake_minimum_required(VERSION 3.25)
project(squeal)

set(CMAKE_CXX_STANDARD 17)

find_package(SQLite3 REQUIRED)
find_package(OpenGL REQUIRED)

# glfw
find_package(glfw3 REQUIRED)
option(GLFW_BUILD_EXAMPLES "Build the GLFW example programs" OFF)
option(GLFW_BUILD_TESTS "Build the GLFW test programs" OFF)
option(GLFW_BUILD_DOCS "Build the GLFW documentation" OFF)
option(GLFW_INSTALL "Generate installation target" OFF)
option(GLFW_DOCUMENT_INTERNALS "Include internals in documentation" OFF)
#add_subdirectory(${GLFW_DIR} binary_dir EXCLUDE_FROM_ALL)
include_directories(${GLFW_DIR}/include)


include_directories(${SQLite3_INCLUDE_DIRS})
include_directories(${OPENGL_INCLUDE_DIR})

# Dearm ImGui
set(IMGUI_DIR lib/imgui/)
include_directories(${IMGUI_DIR} ${IMGUI_DIR}/backends ..)

set(SQUEAL_EXE lib/sqlitewrap.cpp lib/fonts.cpp lib/gui.cpp)
set(IMGUI_EXE ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp ${IMGUI_DIR}/imgui.cpp ${IMGUI_DIR}/imgui_draw.cpp ${IMGUI_DIR}/imgui_demo.cpp ${IMGUI_DIR}/imgui_tables.cpp ${IMGUI_DIR}/imgui_widgets.cpp lib/gui_modals.cpp lib/gui_modals.h lib/constants.hpp)

add_executable(squeal main.cpp ${SQUEAL_EXE} ${IMGUI_EXE})
target_link_libraries(squeal ${SQLite3_LIBRARIES} glfw OpenGL::GL)
