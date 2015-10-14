add_library(brain NeuronGroup.hpp NeuronGroupBuilder.hpp INeuronCore.hpp NeuronCore.hpp INeuronGroup.hpp INeuronConnection.hpp NeuronConnection.hpp Brain.cpp Brain.h)

target_link_libraries( brain
    ${Boost_LIBRARIES}
)
