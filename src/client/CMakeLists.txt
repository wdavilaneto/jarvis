add_library(jarvisApp Jarvis.cpp Jarvis.h)

include_directories(
)

target_link_libraries( jarvisApp
    ${Boost_LIBRARIES}
)
