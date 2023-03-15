
add_executable(loaddisplaysave loaddisplaysave.cpp)

target_link_libraries(loaddisplaysave ${OpenCV_LIBS})

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

set(IMAGES ${CMAKE_SOURCE_DIR}/images/puppy.bmp ${CMAKE_SOURCE_DIR}/images/smalllogo.png)
file(COPY ${IMAGES} DESTINATION .)
file(COPY ${IMAGES} DESTINATION "Debug")
file(COPY ${IMAGES} DESTINATION "Release")
