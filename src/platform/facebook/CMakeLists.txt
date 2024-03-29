
add_library(SDL2 UNKNOWN IMPORTED)
set_property(TARGET SDL2 APPEND PROPERTY IMPORTED_LOCATION  "${THIRDPARTY_DIR}/platform/macos/libSDL2.a")
list(APPEND TARGET_LIBRARIES SDL2)

add_library(SDL_test UNKNOWN IMPORTED)
set_property(TARGET SDL_test APPEND PROPERTY IMPORTED_LOCATION  "${THIRDPARTY_DIR}/platform/macos/libSDL_test.a")
list(APPEND TARGET_LIBRARIES SDL_test)

set_target_properties(SDL2 PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${THIRDPARTY_DIR}/includes/SDL2)

list(APPEND TARGET_INCLUDE_DIRS ${THIRDPARTY_DIR}/includes/SDL2)

list(APPEND TARGET_LIBRARIES "-framework CoreVideo")
list(APPEND TARGET_LIBRARIES "-framework Cocoa")
list(APPEND TARGET_LIBRARIES "-framework IOKit")
list(APPEND TARGET_LIBRARIES "-framework ForceFeedback")
list(APPEND TARGET_LIBRARIES "-framework Carbon")
list(APPEND TARGET_LIBRARIES "-framework CoreAudio")
list(APPEND TARGET_LIBRARIES "-framework AudioToolbox")
list(APPEND TARGET_LIBRARIES "-framework Metal")

set(ASSET_CATALOGUE ${CMAKE_CURRENT_SOURCE_DIR}/resources/Assets.xcassets)

list(APPEND TARGET_RESOURCES ${ASSET_CATALOGUE})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/resources/Info.plist.in ${CMAKE_BINARY_DIR}/Info.plist)
set_source_files_properties( ${TARGET_RESOURCES} PROPERTIES MACOSX_PACKAGE_LOCATION ${CMAKE_PROJECT_NAME}/Contents/Resources/)

add_executable( ${CMAKE_PROJECT_NAME} MACOSX_BUNDLE ${TARGET_PROJECT_SOURCES} ${TARGET_MAIN_SOURCES} ${TARGET_RESOURCES})
target_compile_definitions( ${CMAKE_PROJECT_NAME} PUBLIC ${TARGET_DEFINITIONS})
target_link_libraries( ${CMAKE_PROJECT_NAME} ${TARGET_LIBRARIES})
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY INCLUDE_DIRECTORIES ${TARGET_INCLUDE_DIRS})
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY RESOURCE ${TARGET_RESOURCES})
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY MACOSX_BUNDLE_INFO_PLIST ${CMAKE_BINARY_DIR}/Info.plist)
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY XCODE_ATTRIBUTE_ASSETCATALOG_COMPILER_APPICON_NAME "AppIcon")
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER ${TARGET_BUNDLE_ID}.macOS)
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY "Mac Developer")
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY MACOSX_BUNDLE TRUE)
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY XCODE_ATTRIBUTE_INSTALL_PATH "/Applications")

if(TARGET_PROJECT_SOURCES)
    add_library(${CMAKE_PROJECT_NAME}-static STATIC ${TARGET_PROJECT_SOURCES})
    target_compile_definitions(${CMAKE_PROJECT_NAME}-static PUBLIC ${TARGET_DEFINITIONS})
    target_link_libraries( ${CMAKE_PROJECT_NAME}-static ${TARGET_LIBRARIES})
    set_property(TARGET ${CMAKE_PROJECT_NAME}-static PROPERTY INCLUDE_DIRECTORIES ${TARGET_INCLUDE_DIRS})

    install(TARGETS ${CMAKE_PROJECT_NAME}-static EXPORT ${CMAKE_PROJECT_NAME}Targets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION archive
        RUNTIME DESTINATION bin)

    set(INCLUDE_FILES "")
    foreach(include_dir ${TARGET_INCLUDE_DIRS})
        set(_INCLUDE_FILES "")
        file(GLOB _INCLUDE_FILES ${include_dir}/*.h*)
        list(APPEND INCLUDE_FILES ${INCLUDE_FILES})
    endforeach()

    install(FILES ${INCLUDE_FILES} DESTINATION include/${CMAKE_PROJECT_NAME})

    add_library(${CMAKE_PROJECT_NAME}Framework SHARED ${TARGET_PROJECT_SOURCES})
    target_compile_definitions(${CMAKE_PROJECT_NAME}Framework PUBLIC ${TARGET_DEFINITIONS})
    target_link_libraries( ${CMAKE_PROJECT_NAME}Framework ${TARGET_LIBRARIES})
    set_property(TARGET ${CMAKE_PROJECT_NAME}Framework PROPERTY INCLUDE_DIRECTORIES ${TARGET_INCLUDE_DIRS})
    set_target_properties(${CMAKE_PROJECT_NAME}Framework PROPERTIES
        FRAMEWORK TRUE
        FRAMEWORK_VERSION C
        XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER ${TARGET_BUNDLE_ID}.macOS.framework
        MACOSX_FRAMEWORK_INFO_PLIST ${CMAKE_BINARY_DIR}/Info.plist
        VERSION 1.0.0
        SOVERSION 1.0.0
        PUBLIC_HEADER dynamicFramework.h
        XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY "Mac Developer"
        )

    install(TARGETS ${CMAKE_PROJECT_NAME}Framework EXPORT ${CMAKE_PROJECT_NAME}Targets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION archive
        RUNTIME DESTINATION bin
        FRAMEWORK DESTINATION framework)

endif()


enable_testing()
add_subdirectory(test)
