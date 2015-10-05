add_library(brain NeuronCore.cpp NeuronGroup.cpp NeuronGroup.h NeuronGroupBuilder.cpp NeuronGroupBuilder.h)

target_link_libraries( brain
    ${Boost_LIBRARIES}
)
