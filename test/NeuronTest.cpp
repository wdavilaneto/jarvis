#define BOOST_TEST_MODULE TesteServerTestSuite

#include <brain/NeuronGroup.hpp>
#include <brain/NeuronGroupBuilder.h>

#include <iostream>
#include <boost/test/unit_test.hpp>

using namespace brain;
using boost::shared_ptr;
using boost::make_shared;

BOOST_AUTO_TEST_CASE(NeuronTest) {
    BOOST_TEST_MESSAGE( "Creating Neuron Network general test" );
    NeuronGroup network;

    INeuronCore* neuron = network.createNeuron();

    BOOST_TEST( network.getSize() == 1 , "a New Neuron created ina a network");
    neuron = network.createNeuron();

    BOOST_TEST( network.getSize() == 2 , "Apos criado um segundo neuron numa network, a quantidades de neuron na mesma esta invalida");



    NeuronGroupBuilder* builder = new NeuronGroupBuilder;

    // Single Neuron network test
    shared_ptr<NeuronGroup> group = builder->addInputLayerSize(2).build();

    BOOST_TEST_MESSAGE( "Deleting Builder" );
    delete builder;
}
