cmake_minimum_required(VERSION 3.5)

project(masterChess LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

if(ANDROID)
  add_library(masterChess SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui

  )
else()
  add_executable(masterChess
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    board.cpp
    board.h
    board.ui
    box.h
    box.cpp
    piece.h
    piece.cpp
    imgs/
    imgs.qrc
    horse.h
    horse.cpp
    pawn.cpp
    pawn.h
    tower.cpp
    tower.h
    bishop.cpp
    bishop.h
    queen.cpp
    queen.h
    king.h
    king.cpp


  )
endif()

target_link_libraries(masterChess PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
