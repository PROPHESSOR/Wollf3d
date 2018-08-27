cmake_minimum_required(VERSION 2.8)

set(BINARY wolf3d)

project(Wolf3d)

message("
  ===============================
    Wolf3d PROPHESSOR's version

    If you see \"NO WOLFENSTEIN 3-D DATA FILES to be found!\" message check the version.h file
  ===============================
")

find_package(SDL REQUIRED)
if(NOT SDL_FOUND)
	message(SEND_ERROR "Failed to find SDL")
	message(SEND_ERROR "sudo apt install libsdl-dev")
	return()
else()
	include_directories(${SDL_INCLUDE_DIR})
endif()

find_package(SDL_mixer REQUIRED)
if(NOT SDL_MIXER_FOUND)
	message(SEND_ERROR "Failed to find SDL_mixer")
	message(SEND_ERROR "sudo apt install livsdl-mixer1.2-dev")
	return()
else()
	include_directories(${SDL_MIXER_INCLUDE_DIR})
endif()

find_package(OpenGL REQUIRED)
if(NOT OpenGL_FOUND)
    message(SEND_ERROR "Failed to find OpenGL")
    return()
else()
    include_directories(${OPENGL_INCLUDE_DIR})
endif()

set(SOURCE
            fmopl.cpp
            id_ca.cpp
            id_in.cpp
            id_pm.cpp
            id_sd.cpp
            id_us_1.cpp
            id_vh.cpp
            id_vl.cpp
            signon.cpp
            wl_act1.cpp
            wl_act2.cpp
            wl_agent.cpp
            wl_debug.cpp
            wl_draw.cpp
            wl_game.cpp
            wl_inter.cpp
            wl_main.cpp
            wl_menu.cpp
            wl_play.cpp
            wl_state.cpp
            wl_text.cpp
            crt.cpp
)

add_executable(${BINARY} ${SOURCE})

target_link_libraries(${BINARY} ${SDL_LIBRARY} ${SDL_MIXER_LIBRARY} ${OPENGL_LIBRARY})