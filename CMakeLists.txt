cmake_minimum_required(VERSION 3.5)

project(ChessGame LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
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
  add_library(ChessGame SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
  )
else()
  add_executable(ChessGame
    main.cpp
    mainwindow.cpp
    chronometer.cpp
    filemovementpiecemanager.cpp
    fileuimanageropen.cpp
    fileuimanagersave.cpp
    locker.cpp
    managerviewpiecekilled.cpp
    movementpiece.cpp
    piece.cpp
    pieceAlfil.cpp
    pieceHorse.cpp
    pieceKing.cpp
    piecePawn.cpp
    pieceQueen.cpp
    pieceTower.cpp
    player.cpp
    position.cpp
    mainwindow.h
    chronometer.h
    filemovementpiecemanager.h
    fileuimanageropen.h
    fileuimanagersave.h
    locker.h
    managerviewpiecekilled.h
    movementpiece.h
    piece.h
    pieceAlfil.h
    pieceHorse.h
    pieceKing.h
    piecePawn.h
    pieceQueen.h
    pieceTower.h
    player.h
    position.h
    mainwindow.ui
    resources.qrc
  )
endif()

target_link_libraries(ChessGame PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
