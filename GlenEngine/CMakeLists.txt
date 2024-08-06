set(MODULE_NAME GlenEngine)

file(GLOB_RECURSE SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/private/src/*.cpp"
)

file(GLOB_RECURSE HEADERS 
    "${CMAKE_CURRENT_SOURCE_DIR}/public/${MODULE_NAME}/*.h"
)

add_library(${MODULE_NAME} ${SOURCES} ${HEADERS})

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

if(BUILD_SHARED_LIBS)
    target_compile_definitions(${MODULE_NAME} 
        PRIVATE GLENENGINE_EXPORTS
        INTERFACE GLENENGINE_IMPORTS
    )
endif()
