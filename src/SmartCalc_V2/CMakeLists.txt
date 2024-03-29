cmake_minimum_required(VERSION 3.5)

project(SmartCalc_V2 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets PrintSupport)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -fsanitize=address -g")


#    ../view/viewdepositcalc.h
#    ../view/viewcreditcalc.h
#    ../model/anuitetcalc.h
#    ../model/diferentcalc.h
#    ../model/deposit.h
#    ../view/viewcreditcalc.cc
#    ../view/viewdepositcalc.cc
#    ../model/anuitetcalc.cc
#    ../model/diferentcalc.cc
#    ../model/deposit.cc

set(PROJECT_SOURCES
    ../controller/calccontrol.h
    ../view/viewsmartcalc.h
    ../view/qcustomplot.h
    ../view/calclulatorbutton.h
    ../model/expressionConverter.h
    ../model/calculation.h
    ../model/element.h
    ../model/graph_model.h
    ../controller/calccontrol.cc
    ../view/viewsmartcalc.cc
    ../view/qcustomplot.cpp
    ../view/calculatorbutton.cc
    ../model/expressionConverter.cc
    ../model/calculation.cc
    ../model/element.cc
    ../model/graph_model.cc
    main.cpp
)

set_source_files_properties(calculatorbutton.cc PROPERTIES COMPILE_FLAGS "-Wno-unused-parameter")


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SmartCalc_V2
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(SmartCalc_V2 SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(SmartCalc_V2
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(SmartCalc_V2 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::PrintSupport)

set_target_properties(SmartCalc_V2 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS SmartCalc_V2
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SmartCalc_V2)
endif()
