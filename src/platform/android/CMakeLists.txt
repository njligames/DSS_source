
add_library(hidapi UNKNOWN IMPORTED)
set_property(TARGET hidapi APPEND PROPERTY IMPORTED_LOCATION  "${THIRDPARTY_DIR}/platform/android/${ANDROID_ABI}/libhidapi.so")
list(APPEND TARGET_LIBRARIES hidapi)

add_library(main UNKNOWN IMPORTED)
set_property(TARGET main APPEND PROPERTY IMPORTED_LOCATION  "${THIRDPARTY_DIR}/platform/android/${ANDROID_ABI}/libmain.so")
list(APPEND TARGET_LIBRARIES main)

add_library(SDL2 UNKNOWN IMPORTED)
set_property(TARGET SDL2 APPEND PROPERTY IMPORTED_LOCATION  "${THIRDPARTY_DIR}/platform/android/${ANDROID_ABI}/libSDL2.so")
list(APPEND TARGET_LIBRARIES SDL2)

set_target_properties(SDL2 PROPERTIES INTERFACE_INCLUDE_DIRECTORIES "${THIRDPARTY_DIR}/includes/SDL2")

find_library( log-lib log)
list(APPEND TARGET_LIBRARIES ${log-lib})

list(APPEND TARGET_PROJECT_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/native-lib.cpp")

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/resources/strings.xml.in" "${CMAKE_CURRENT_SOURCE_DIR}/resources/res/values/strings.xml")

add_library(native-lib SHARED ${TARGET_PROJECT_SOURCES} ${TARGET_MAIN_SOURCES})
target_compile_definitions(native-lib PUBLIC ${TARGET_DEFINITIONS})
target_link_libraries( native-lib ${TARGET_LIBRARIES})
set_target_properties(native-lib PROPERTIES INTERFACE_INCLUDE_DIRECTORIES "${TARGET_INCLUDE_DIRS}")
include_directories(${TARGET_INCLUDE_DIRS})

