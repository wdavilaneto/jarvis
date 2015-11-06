//
// Created by walter on 02/11/15.
//

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

typedef vector<shared_ptr<NeuronCore> > NeuronLayer;

BOOST_AUTO_TEST_CASE(NeuronBuilderTest) {

    BOOST_TEST_MESSAGE("Check Point: Testsing Builder Behaviour\n Building a Simple layer with a single layer");
    NeuronGroupBuilder builder;
    // set the "fist", and so, the input layer size to ..
    shared_ptr<NeuronGroup> network = builder.initNetwork().addLayer(2).build();
    BOOST_CHECK(network->getInputLayer().size() == 2);

    NeuronLayer inputLayer = network->getInputLayer();
    BOOST_REQUIRE(!inputLayer.empty());
    shared_ptr<NeuronCore> neuron = network->getInputLayer().at(0);
    BOOST_CHECK(!neuron->getId().is_nil());

    BOOST_TEST_MESSAGE("Check Point: Building a new layer with 2 inputs and a single output");
    size_t SIZE = 2;
    network = builder.initNetwork().addLayer(SIZE).addLayer(1).build();
    BOOST_CHECK(network->getInputLayer().size() == SIZE);

    BOOST_TEST_MESSAGE("Check Point: Building a new layer with 3 inputs and a single output and autoconnect = false");
    network = builder.initNetwork(false).addLayer(SIZE+1).addLayer(1).build();
    BOOST_CHECK( network->getInputLayer().size() == SIZE+1);
    neuron = network->getInputLayer().at(0);
    size_t connSize = neuron->getConnections().size();
    BOOST_CHECK( connSize == 0 );
    shared_ptr<NeuronCore> neuron1 = network->getOutputLayer().at(1);
    neuron->connectTo(neuron1,);




};