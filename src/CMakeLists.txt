list(APPEND TARGET_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/cpp)


# MACRO(SOURCE_GROUP_BY_FOLDER RELATIVE_DIRECTORY)
#     SET(SOURCE_GROUP_DELIMITER "/")
#     SET(source_group_root "Source Files${SOURCE_GROUP_DELIMITER}")
#     SET(last_dir "")
#     SET(files "")
#
#     list(APPEND SOURCE_GROUP_FILES ${SOURCE_FILES})
#     list(APPEND SOURCE_GROUP_FILES ${INCLUDE_FILES})
#     list(APPEND SOURCE_GROUP_FILES ${INTERFACE_FILES})
#
#     LIST(SORT SOURCE_GROUP_FILES)
#     FOREACH(file ${SOURCE_GROUP_FILES})
#         file(RELATIVE_PATH relative_file ${RELATIVE_DIRECTORY} ${file})
#         MESSAGE(STATUS "relative_file ${relative_file} file ${file} CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}")
#         GET_FILENAME_COMPONENT(dir "${relative_file}" PATH)
#         IF (NOT "${dir}" STREQUAL "${last_dir}")
#             IF (files)
#                 SOURCE_GROUP("${source_group_root}${last_dir}" FILES ${files})
#             ENDIF (files)
#             SET(files "")
#         ENDIF (NOT "${dir}" STREQUAL "${last_dir}")
#         SET(files ${files} ${file})
#         SET(last_dir "${dir}")
#     ENDFOREACH(file)
#     IF (files)
#         SOURCE_GROUP("${source_group_root}${last_dir}" FILES ${files})
#     ENDIF (files)
# ENDMACRO()

file(GLOB_RECURSE SRCS ${CMAKE_CURRENT_SOURCE_DIR}/cpp/*.c*)
file(GLOB_RECURSE HDRS ${CMAKE_CURRENT_SOURCE_DIR}/cpp/*.h)

set( TARGET_PROJECT_SOURCES ${TARGET_PROJECT_SOURCES} ${SRCS} ${HDRS} )
set( TARGET_RESOURCES ${TARGET_RESOURCES} ${ASSET_CATALOGUE} )

file(GLOB_RECURSE SRCS_TEST_CPP ${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp)
file(GLOB_RECURSE SRCS_TEST_C ${CMAKE_CURRENT_SOURCE_DIR}/test/*.c)
file(GLOB_RECURSE HDRS_TEST ${CMAKE_CURRENT_SOURCE_DIR}/test/*.h)

set( TARGET_PROJECT_SOURCES_TEST ${SRCS_TEST_CPP} ${SRCS_TEST_C} ${HDRS_TEST} )

set(INCLUDE_FILES ${TARGET_INCLUDE_DIRS})
set(SOURCE_FILES ${TARGET_PROJECT_SOURCES})
SOURCE_GROUP_BY_FOLDER(${CMAKE_CURRENT_SOURCE_DIR}/cpp)

add_subdirectory(platform)

if(NOT ANDROID)
    add_subdirectory(doc)
endif()

# add_subdirectory(swig)

