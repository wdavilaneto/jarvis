add_library(brain NeuronCore.cpp)

target_link_libraries( brain
    ${Boost_LIBRARIES}
)
