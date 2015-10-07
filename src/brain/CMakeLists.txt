add_library(brain NeuronGroup.hpp NeuronGroupBuilder.cpp NeuronGroupBuilder.h INeuronCore.hpp INeuronGroup.hpp INeuronConnection.hpp)

target_link_libraries( brain
    ${Boost_LIBRARIES}
)
