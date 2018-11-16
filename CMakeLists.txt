cmake_minimum_required(VERSION 3.10)

project(fcgi VERSION 0.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 11)

file(GLOB EMOJIC_DEPEND "src/*.emojic")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(${PROJECT_NAME} STATIC src/${PROJECT_NAME}.cpp ${PROJECT_NAME}_.o)

set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)
target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Wno-unused-result -Wno-missing-braces -pedantic -lssl -lcrypto)

get_filename_component(MAIN_FILE src/${PROJECT_NAME}.emojic ABSOLUTE)

add_custom_command(OUTPUT ${PROJECT_NAME}_.o COMMAND emojicodec -p ${PROJECT_NAME} -o ${PROJECT_NAME}_.o -i
    interface.emojii -c ${MAIN_FILE} --color DEPENDS ${EMOJIC_DEPEND})

install(FILES build/lib${PROJECT_NAME}.a DESTINATION lib/emojicode/${PROJECT_NAME})
install(FILES build/interface.emojii DESTINATION lib/emojicode/${PROJECT_NAME})