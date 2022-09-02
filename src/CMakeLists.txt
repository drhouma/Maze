cmake_minimum_required(VERSION 3.5)

project(Maze VERSION 1.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "~/Qt/6.3.1/gcc_64")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        model/core/core.h
        model/core/core.cpp
        model/core/matrix.h
        model/core/matrix.inl
        model/core/coordinate.h
        model/core/coordinate.cpp
        model/maze/maze.h
        model/maze/maze_core.cpp
        model/maze/maze_generator.cpp
        model/maze/maze_reader.cpp
        model/maze/maze_solution.cpp
        model/cave/cave.h
        model/cave/cave.cpp
        model/cave/cave_reader.cpp
        controller/controller.h
        controller/controller.cpp
        view/main.cpp
        view/main_window.cpp
        view/main_window.h
        view/main_window.ui
        view/maze_scene.h
        view/maze_scene.cpp
        view/cave_window.h
        view/cave_window.cpp
        view/cave_window.ui
        view/cave_scene.h
        view/cave_scene.cpp
        )

set(QRC qrc/res.qrc)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Maze
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
            ${QRC}
            )
else()
    add_executable(Maze
            ${PROJECT_SOURCES}
            ${QRC}
            )
endif()

target_link_libraries(Maze PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Maze PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
        )

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Maze)
endif()
