cmake_minimum_required(VERSION 3.21)
project(QtOpenCVStarter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Help Qt Creator find Homebrew OpenCV on Apple Silicon Macs without extra setup.
if(NOT OpenCV_DIR AND EXISTS "/opt/homebrew/opt/opencv/lib/cmake/opencv4")
    set(OpenCV_DIR "/opt/homebrew/opt/opencv/lib/cmake/opencv4")
endif()

find_package(OpenCV REQUIRED)

add_executable(QtOpenCVStarter
    main.cpp
    MainWindow.cpp
    MainWindow.h
    ../../Downloads/media/arvis.png
)

target_link_libraries(QtOpenCVStarter
    PRIVATE
        Qt6::Widgets
        ${OpenCV_LIBS}
)

target_include_directories(QtOpenCVStarter
    PRIVATE
        ${OpenCV_INCLUDE_DIRS}
)
