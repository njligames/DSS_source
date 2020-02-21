set(${CMAKE_PROJECT_NAME}_LUA_SWIG_ENABLED_BY_DEFAULT ON)
set(${CMAKE_PROJECT_NAME}_LUA_SWIG ${${CMAKE_PROJECT_NAME}_LUA_SWIG_ENABLED_BY_DEFAULT} CACHE BOOL "Build the swig module for ${CMAKE_PROJECT_NAME}")

# list(APPEND CMAKE_MODULE_PATH "${${CMAKE_PROJECT_NAME}_REPO_DIRECTORY}/cmake")

macro(LUA_SWIG INTERFACE_NAME)
    
    set(extra_macro_args ${ARGN})
    # Did we get any optional args?
    list(LENGTH extra_macro_args num_extra_args)
    if (${num_extra_args} GREATER 0)
        list(GET extra_macro_args 0 IS_SHARED)
    endif ()

    if (${num_extra_args} GREATER 1)
        list(GET extra_macro_args 1 BASE_PATH)
    endif ()

    set(WRAPPER_LANGUAGE "lua")
    if (${num_extra_args} GREATER 2)
        list(GET extra_macro_args 1 WRAPPER_LANGUAGE)
    endif ()

    set(TARGET_EXTENSION "-static")
    if (IS_SHARED)
        set(TARGET_EXTENSION "")
    endif ()

    string(TOLOWER ${INTERFACE_NAME} INTERFACE_NAME_LOWER)

    if (NOT CMAKE_PROJECT_NAME)
        MESSAGE(FATAL_ERROR "CMAKE_PROJECT_NAME variable is empty.")
    endif ()

    # if (NOT ${CMAKE_PROJECT_NAME}_REPO_DIRECTORY)
    #     MESSAGE(FATAL_ERROR "${CMAKE_PROJECT_NAME}_REPO_DIRECTORY variable is empty.")
    # endif ()

    set(${INTERFACE_NAME}_SWIG_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../swig.in/${BASE_PATH}/${INTERFACE_NAME_LOWER})
    message(STATUS "${INTERFACE_NAME}_SWIG_INCLUDE_DIR ${${INTERFACE_NAME}_SWIG_INCLUDE_DIR}")

    if (NOT ${INTERFACE_NAME}_SWIG_INCLUDE_DIR)
        message(FATAL_ERROR "${INTERFACE_NAME}_SWIG_INCLUDE_DIR variable is empty.")
    endif ()

    # if (NOT ${INTERFACE_NAME}_INCLUDE_DIR)
    #     MESSAGE(FATAL_ERROR "${INTERFACE_NAME}_INCLUDE_DIR variable is empty.")
    # endif ()

    if (NOT EXISTS "${${INTERFACE_NAME}_SWIG_INCLUDE_DIR}")
        message(FATAL_ERROR "Path doesn't exist: ${${INTERFACE_NAME}_SWIG_INCLUDE_DIR}")
    endif ()

    # if (NOT EXISTS "${${INTERFACE_NAME}_INCLUDE_DIR}")
    #     MESSAGE(FATAL_ERROR "Path doesn't exist: ${${INTERFACE_NAME}_INCLUDE_DIR}")
    # endif ()

    if (NOT EXISTS "${${INTERFACE_NAME}_SWIG_INCLUDE_DIR}/${INTERFACE_NAME_LOWER}.i")
        message(FATAL_ERROR "Path doesn't exist: ${${INTERFACE_NAME}_SWIG_INCLUDE_DIR}/${INTERFACE_NAME_LOWER}.i")
    endif ()

    file(GLOB_RECURSE LUA_SWIG_SOURCE_FILES ${${INTERFACE_NAME}_SWIG_INCLUDE_DIR}/*.swg)

    list(APPEND LUA_SWIG_SOURCE_FILES "${${INTERFACE_NAME}_SWIG_INCLUDE_DIR}/${INTERFACE_NAME_LOWER}.i")

    # SUBDIRLIST(SUBDIRS "${${INTERFACE_NAME}_SWIG_INCLUDE_DIR}" ${INTERFACE_NAME}_SWIG_INCLUDE_DIRS)

    # list(APPEND ${INTERFACE_NAME}_SWIG_INCLUDE_DIRS ${${INTERFACE_NAME}_INCLUDE_DIRS})

    set(CMAKE_SWIG_FLAGS "-includeall")
    list(APPEND CMAKE_SWIG_FLAGS "-fvirtual")
    list(APPEND CMAKE_SWIG_FLAGS "-v")
    list(APPEND CMAKE_SWIG_FLAGS "-w201")
    list(APPEND CMAKE_SWIG_FLAGS "-w312")
    list(APPEND CMAKE_SWIG_FLAGS "-ignoremissing")
    list(APPEND CMAKE_SWIG_FLAGS "-DBT_INFINITY")
    list(APPEND CMAKE_SWIG_FLAGS "-DSWIG_TYPE_TABLE=myprojectname")
    list(APPEND CMAKE_SWIG_FLAGS "-D__GL_2__")
    if (GL_ES2)
        list(APPEND CMAKE_SWIG_FLAGS "-D__GL_ES2__")
    elseif (GL_ES3)
        list(APPEND CMAKE_SWIG_FLAGS "-D__GL_ES3__")
    elseif (GL_2)
        list(APPEND CMAKE_SWIG_FLAGS "-D__GL_2__")
    elseif (GL_3)
        list(APPEND CMAKE_SWIG_FLAGS "-D__GL_3__")
    endif ()

    foreach (_SWIG_SOURCE_FILE ${LUA_SWIG_SOURCE_FILES})
        set_property(SOURCE ${_SWIG_SOURCE_FILE} PROPERTY CPLUSPLUS ON)
        set_property(SOURCE ${_SWIG_SOURCE_FILE} PROPERTY SWIG_INCLUDE_DIRECTORIES "${${INTERFACE_NAME}_SWIG_INCLUDE_DIRS}")
    endforeach ()

    include_directories(
            ${${INTERFACE_NAME}_SWIG_INCLUDE_DIRS}
    )

    get_property(_INCLUDE_DIRECTORIES DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
    list(REMOVE_ITEM _INCLUDE_DIRECTORIES "/usr/include")
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES ${_INCLUDE_DIRECTORIES})

    list(APPEND ${CMAKE_PROJECT_NAME}_DEFINITIONS ${INTERFACE_NAME}_SWIG=1)

    if (${CMAKE_VERSION} VERSION_LESS "3.8")
        swig_add_module(
                ${CMAKE_PROJECT_NAME}-${WRAPPER_LANGUAGE}-swig-${INTERFACE_NAME_LOWER}${TARGET_EXTENSION}
                ${WRAPPER_LANGUAGE}
                "${LUA_SWIG_SOURCE_FILES}"
        )
    else ()
        if (IS_SHARED)
            swig_add_library(
                    ${CMAKE_PROJECT_NAME}-${WRAPPER_LANGUAGE}-swig-${INTERFACE_NAME_LOWER}${TARGET_EXTENSION}
                    TYPE SHARED
                    LANGUAGE ${WRAPPER_LANGUAGE}
                    SOURCES "${LUA_SWIG_SOURCE_FILES}"
            )
        else ()
            swig_add_library(
                    ${CMAKE_PROJECT_NAME}-${WRAPPER_LANGUAGE}-swig-${INTERFACE_NAME_LOWER}${TARGET_EXTENSION}
                    TYPE STATIC
                    LANGUAGE ${WRAPPER_LANGUAGE}
                    SOURCES "${LUA_SWIG_SOURCE_FILES}"
            )
        endif ()
    endif ()

    if (ANDROID)
        if (TARGET native-lib)
            add_dependencies(native-lib ${CMAKE_PROJECT_NAME}-${WRAPPER_LANGUAGE}-swig-${INTERFACE_NAME_LOWER}${TARGET_EXTENSION})
        endif ()
    else ()
        if (TARGET ${CMAKE_PROJECT_NAME}-exe)
            add_dependencies(${CMAKE_PROJECT_NAME}-exe ${CMAKE_PROJECT_NAME}-${WRAPPER_LANGUAGE}-swig-${INTERFACE_NAME_LOWER}${TARGET_EXTENSION})
        endif ()
    endif ()

    if (TARGET ${CMAKE_PROJECT_NAME}-static)
        add_dependencies(${CMAKE_PROJECT_NAME}-static ${CMAKE_PROJECT_NAME}-${WRAPPER_LANGUAGE}-swig-${INTERFACE_NAME_LOWER}${TARGET_EXTENSION})
    endif ()
    if (TARGET ${CMAKE_PROJECT_NAME})
        add_dependencies(${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}-${WRAPPER_LANGUAGE}-swig-${INTERFACE_NAME_LOWER}${TARGET_EXTENSION})
    endif ()

    if (APPLE)
        if (IOS OR TVOS)
            SET_TARGET_PROPERTIES(
                    ${CMAKE_PROJECT_NAME}-${WRAPPER_LANGUAGE}-swig-${INTERFACE_NAME_LOWER}${TARGET_EXTENSION} PROPERTIES
                    XCODE_PRODUCT_TYPE "com.apple.product-type.library.static"
            )
        endif ()
    endif ()

    if (ANDROID)
        if (IS_SHARED)
            SET_TARGET_PROPERTIES(
                    ${CMAKE_PROJECT_NAME}-${WRAPPER_LANGUAGE}-swig-${INTERFACE_NAME_LOWER}${TARGET_EXTENSION} PROPERTIES
                    POSITION_INDEPENDENT_CODE ON
            )
        endif ()
    endif ()

    target_compile_definitions(${CMAKE_PROJECT_NAME}-${WRAPPER_LANGUAGE}-swig-${INTERFACE_NAME_LOWER}${TARGET_EXTENSION} PUBLIC ${TARGET_DEFINITIONS})

    # Had to comment this out for windows...
    target_link_libraries(${CMAKE_PROJECT_NAME}-${WRAPPER_LANGUAGE}-swig-${INTERFACE_NAME_LOWER}${TARGET_EXTENSION} ${CMAKE_PROJECT_NAME}-static)
    # if (ANDROID)
    #     # target_link_libraries( main ${CMAKE_PROJECT_NAME}-${WRAPPER_LANGUAGE}-swig-${INTERFACE_NAME_LOWER}${TARGET_EXTENSION})
    #     # target_compile_definitions(main PUBLIC ${${CMAKE_PROJECT_NAME}_DEFINITIONS})
    # endif ()

    list(APPEND EXTRA_LIBS ${CMAKE_PROJECT_NAME}-${WRAPPER_LANGUAGE}-swig-${INTERFACE_NAME_LOWER}${TARGET_EXTENSION})
    list(APPEND INTERFACE_FILES ${LUA_SWIG_SOURCE_FILES})

    set(_INSTALL_LIBS "${CMAKE_PROJECT_NAME}-${WRAPPER_LANGUAGE}-swig-${INTERFACE_NAME_LOWER}${TARGET_EXTENSION}" ${_INSTALL_LIBS})
    target_include_directories(${CMAKE_PROJECT_NAME}-${WRAPPER_LANGUAGE}-swig-${INTERFACE_NAME_LOWER}${TARGET_EXTENSION}
            PRIVATE $<BUILD_INTERFACE:${${CMAKE_PROJECT_NAME}_THIRDPARTY_INCLUDE_DIRS}>
            PRIVATE $<BUILD_INTERFACE:${${CMAKE_PROJECT_NAME}_PROJECT_INCLUDE_DIRECTORES}>
            )
    target_compile_definitions(${CMAKE_PROJECT_NAME}-${WRAPPER_LANGUAGE}-swig-${INTERFACE_NAME_LOWER}${TARGET_EXTENSION} PUBLIC ${TARGET_DEFINITIONS})
endmacro()



























if (${CMAKE_VERSION} VERSION_LESS "3.6")
    message("Please consider to switch to CMake 3.6 in order to use SWIG")
else ()
    find_package(SWIG REQUIRED)

    if (${SWIG_FOUND})
        MESSAGE(STATUS "SWIG_FOUND ${SWIG_FOUND}")
        MESSAGE(STATUS "SWIG_DIR ${SWIG_DIR}")
        MESSAGE(STATUS "SWIG_EXECUTABLE ${SWIG_EXECUTABLE}")
        MESSAGE(STATUS "SWIG_VERSION ${SWIG_VERSION}")

        include(${SWIG_USE_FILE})

        if (RASPBERRYPI)
            set(CMAKE_SWIG_OUTDIR "${CMAKE_BINARY_DIR}/.swig/lua/raspberrypi")
            set(SWIG_OUTFILE_DIR "${CMAKE_BINARY_DIR}/.swig/lua/raspberrypi")
        else ()
            set(CMAKE_SWIG_OUTDIR "${CMAKE_BINARY_DIR}/.swig/lua/${CMAKE_SYSTEM_NAME}")
            set(SWIG_OUTFILE_DIR "${CMAKE_BINARY_DIR}/.swig/lua/${CMAKE_SYSTEM_NAME}")
        endif ()

        if (ANDROID)
            if (${ANDROID_ABI} STREQUAL "armeabi-v7a" OR ${ANDROID_ABI} STREQUAL "x86")
                list(APPEND ${CMAKE_PROJECT_NAME}_THIRDPARTY_INCLUDE_DIRS ${ANDROID_SYSROOT}/usr/include/arm-linux-androideabi)
            elseif (${ANDROID_ABI} STREQUAL "arm64-v8a" OR ${ANDROID_ABI} STREQUAL "x86_64")
                list(APPEND ${CMAKE_PROJECT_NAME}_THIRDPARTY_INCLUDE_DIRS ${ANDROID_SYSROOT}/usr/include/aarch64-linux-android)
            elseif (${ANDROID_ABI} STREQUAL "x86")
                list(APPEND ${CMAKE_PROJECT_NAME}_THIRDPARTY_INCLUDE_DIRS ${ANDROID_SYSROOT}/usr/include/i686-linux-android)
            elseif (${ANDROID_ABI} STREQUAL "x86_64")
                list(APPEND ${CMAKE_PROJECT_NAME}_THIRDPARTY_INCLUDE_DIRS ${ANDROID_SYSROOT}/usr/include/x86_64-linux-android)
            endif ()
        endif ()

        if (MSVC AND NOT LIBC)
            add_definitions(-DSTATIC_LINKED)
        endif ()

        # configure_file("${CMAKE_BINARY_DIR}/swig.in/script/njlic/_Defines.swg.in" "${CMAKE_BINARY_DIR}/swig.in/script/njlic/_Defines.swg")

        if (ANDROID)
            LUA_SWIG(${CMAKE_PROJECT_NAME} TRUE)
            # LUA_SWIG(BULLET3 TRUE "thirdparty")
            # LUA_SWIG(GLM "thirdparty")
        else ()
            LUA_SWIG(${CMAKE_PROJECT_NAME} FALSE)
            # LUA_SWIG(BULLET3 FALSE "thirdparty")
            # LUA_SWIG(GLM "thirdparty")
        endif ()

        file(GLOB_RECURSE TARGET_GENERATED_FILES "${SWIG_OUTFILE_DIR}/*.c*")

        set_property(DIRECTORY PROPERTY ADDITIONAL_MAKE_CLEAN_FILES ${TARGET_GENERATED_FILES})
        set_source_files_properties(${TARGET_GENERATED_FILES} PROPERTIES GENERATED TRUE)
    else()
        message("swig need to be installed to generate the doxygen documentation")
    endif ()
endif ()

