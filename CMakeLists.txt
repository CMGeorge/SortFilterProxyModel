#TODO: Add mising things from old version (Like StaticRole or ValueFilter)
cmake_minimum_required(VERSION 3.22)

project(SortFilterProxyModel VERSION 1.0 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED
    Core
    Qml
    Core5Compat
    )

set(CMAKE_AUTOMOC ON)
#set(CMAKE_INCLUDE_CURRENT_DIR ON) # This is to find generated *.moc and *.h files in build dir

qt_add_library(SortFilterProxyModel STATIC)
qt_add_qml_module(SortFilterProxyModel
    URI SortFilterProxyModel
    VERSION 1.0
    SOURCES
        qqmlsortfilterproxymodel.cpp
        qqmlsortfilterproxymodel.h
        qvariantlessthan.cpp
        filters/containsfilter.h
        filters/containsfilter.cpp
        filters/filter.h
        filters/filter.cpp
        filters/filtercontainer.h
        filters/filtercontainer.cpp
        filters/rolefilter.h
        filters/rolefilter.cpp
        filters/valuefilter.h
        filters/valuefilter.cpp
        filters/indexfilter.h
        filters/indexfilter.cpp
        filters/regexpfilter.h
        filters/regexpfilter.cpp
        filters/rangefilter.h
        filters/rangefilter.cpp
        filters/expressionfilter.h
        filters/expressionfilter.cpp
        filters/filtercontainerfilter.h
        filters/filtercontainerfilter.cpp
        filters/anyoffilter.h
        filters/anyoffilter.cpp
        filters/alloffilter.h
        filters/alloffilter.cpp
#        filters/filtersqmltypes.cpp - Olt implementation of qml registration
        sorters/sorter.h
        sorters/sorter.cpp
        sorters/sortercontainer.cpp
        sorters/rolesorter.h
        sorters/rolesorter.cpp
        sorters/stringsorter.cpp
        sorters/expressionsorter.cpp
        sorters/sortersqmltypes.cpp
        proxyroles/proxyrole.cpp
        proxyroles/proxyrolecontainer.cpp
        proxyroles/joinrole.cpp
        proxyroles/joinrole.h
        proxyroles/switchrole.cpp
        proxyroles/expressionrole.cpp
#        proxyroles/proxyrolesqmltypes.cpp
        proxyroles/singlerole.cpp
        proxyroles/regexprole.cpp
        sorters/filtersorter.cpp
        proxyroles/filterrole.cpp


)
target_link_libraries(SortFilterProxyModel PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Qml
    Qt${QT_VERSION_MAJOR}::Core5Compat
)

target_include_directories(SortFilterProxyModel PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/proxyroles
    ${CMAKE_CURRENT_SOURCE_DIR}/filters
    ${CMAKE_CURRENT_SOURCE_DIR}/sorters
    $<TARGET_PROPERTY:Qt6::Core,INTERFACE_INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:Qt6::Qml,INTERFACE_INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:Qt6::Core5Compat,INTERFACE_INCLUDE_DIRECTORIES>
    )
install(TARGETS SortFilterProxyModel
    EXPORT sortFilterProxyModelTargets
    LIBRARY DESTINATION "lib"
    ARCHIVE DESTINATION "lib"
    RUNTIME DESTINATION "bin"
    PUBLIC_HEADER DESTINATION "include/SFPM"
)
