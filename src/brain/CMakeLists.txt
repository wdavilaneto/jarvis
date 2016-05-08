find_package(Boost REQUIRED COMPONENTS serialization log log_setup system filesystem date_time)
find_package(Threads)

add_library(brain Brain.cpp Brain.h NeuronGroup.hpp NeuronGroupBuilder.hpp INeuronCore.hpp NeuronCore.hpp INeuronGroup.hpp NeuronConnection.hpp Brain.cpp Brain.h)

target_link_libraries(brain
        pthread
        ${Boost_LIBRARIES}
        )
