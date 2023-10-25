file(GLOB cpp_sources ${CMAKE_SOURCE_DIR}/src/*.cc)

add_executable(tictactoe ${cpp_sources})
target_include_directories(tictactoe PRIVATE ${CMAKE_SOURCE_DIR}/src)
