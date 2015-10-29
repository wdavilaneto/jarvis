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

    BOOST_TEST_MESSAGE("Check Point: Testsing Builder Behaviour\n Building a Simple layer with a single layer");
    NeuronGroupBuilder builder;
    // set the "fist", and so, the input layer size to ..
    shared_ptr<NeuronGroup> network = builder.initNetwork().addLayer(2).build();
    BOOST_CHECK(network->getInputLayer().size() == 2);

    vector<NeuronCore> &inputLayer = network->getInputLayer();
    BOOST_REQUIRE(!inputLayer.empty());
    NeuronCore &neuron1 = network->getInputLayer().at(0);
    BOOST_CHECK(!neuron1.getId().is_nil());

    BOOST_TEST_MESSAGE("Check Point: Building a new layer with 3 inputs and a single output");
    size_t SIZE = 100;
    network = builder.initNetwork().addLayer(SIZE).addLayer(1).build();
    BOOST_CHECK(network->getInputLayer().size() == SIZE);

    // Test Simple and Operation
    for (size_t i = 0; i < network->getInputLayer().size(); i++) {
        NeuronCore &neuron = network->getInputLayer().at(i);
        neuron.signal(30.0);
    };



};