#define BOOST_TEST_MODULE TesteServerTestSuite

#include <brain/NeuronGroup.hpp>
#include <brain/NeuronGroupBuilder.h>

//#include <boost/mpi/environment.hpp>
//#include <boost/mpi/communicator.hpp>
#include <iostream>
#include <boost/test/unit_test.hpp>

using namespace brain;
using boost::shared_ptr;
using boost::make_shared;

BOOST_AUTO_TEST_CASE(NeuronTest) {

//    namespace mpi = boost::mpi;
//    mpi::environment env;
//    mpi::communicator world;
//    BOOST_TEST_MESSAGE( std::string("Number of processors running test ") << world.size());


    BOOST_TEST_MESSAGE("Creating Neuron Network general test");
    NeuronGroup network;

    BOOST_CHECK_NO_THROW(INeuronCore *neuron = network.createNeuron());

    BOOST_CHECK(network.getSize() == 1);

    BOOST_CHECK_NO_THROW(INeuronCore *neuron = network.createNeuron());
    BOOST_CHECK(network.getSize() == 2);

    for (size_t i = 0; i < (100); i++) {
        network.createNeuron();
    }

    NeuronGroupBuilder *builder = new NeuronGroupBuilder;

    // Single Neuron network test
    shared_ptr<NeuronGroup> group = builder->addInputLayerSize(2).build();

    BOOST_TEST_MESSAGE("Deleting Builder");
    delete builder;
}
