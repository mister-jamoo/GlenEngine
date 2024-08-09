set(MODULE_NAME GlenEngine)

file(GLOB_RECURSE SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/private/src/*.cpp"
)

add_library(${MODULE_NAME} SHARED ${SOURCES})

target_include_directories(${MODULE_NAME}
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/public>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/private/include
)

# Add any third-party libraries
target_link_libraries(${MODULE_NAME}
    PRIVATE
        # Add any private dependencies
    PUBLIC
        # Add any public dependencies
)


target_compile_options(${MODULE_NAME} PRIVATE
        $<$<CONFIG:Debug>:-DDEBUG -D_DEBUG>
)