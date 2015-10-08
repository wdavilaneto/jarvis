#define BOOST_TEST_MODULE TesteServerTestSuite

#include <brain/NeuronGroup.hpp>
#include <brain/NeuronGroupBuilder.hpp>

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

    BOOST_TEST_MESSAGE("*** Creating Neuron Network general test");
    NeuronGroup* network = new NeuronGroup;

    BOOST_TEST_MESSAGE("*** Factory creation " );
    BOOST_CHECK_NO_THROW(INeuronCore *neuron = network->createNeuron());
    BOOST_CHECK(network->getSize() == 1);

    BOOST_TEST_MESSAGE("***  Factory creation .. stacking neurons on owner ( network ) " );
    BOOST_CHECK_NO_THROW(INeuronCore *neuron = network->createNeuron());
    BOOST_CHECK(network->getSize() == 2);

    BOOST_TEST_MESSAGE("***  Connection Neuron 1 to neuron 2 " );
    NeuronCore *neuron1 = (NeuronCore *) network->allNeurons()[0];
    NeuronCore *neuron2 = (NeuronCore *) network->allNeurons()[1];
    BOOST_CHECK_NO_THROW(neuron1->connectTo(neuron2));
    BOOST_CHECK(neuron1->getConnections().at(0)->getTarget() == (INeuronCore*)neuron2);
    BOOST_CHECK(neuron1->getConnections().at(0)->getTarget() != (INeuronCore*)neuron1);

    BOOST_TEST_MESSAGE("***  Testing correct clean up of neurons, on a given network (owner) deleting this network" );
    delete network;
    BOOST_CHECK(neuron1 == neuron2 == 0 );

//    NeuronGroupBuilder *builder = new NeuronGroupBuilder;
//    shared_ptr<NeuronGroup> group = builder->addInputLayerSize(2).build();
//    BOOST_TEST_MESSAGE("*** Deleting Builder");
//    delete builder;
}
