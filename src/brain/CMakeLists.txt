add_library(brain NeuronCore.cpp NeuronGroup.cpp NeuronGroup.h)

target_link_libraries( brain
    ${Boost_LIBRARIES}
)
