#define BOOST_TEST_MODULE TesteServerTestSuite

#include <brain/NeuronGroup.hpp>
#include <brain/NeuronGroupBuilder.hpp>

#include <iostream>
#include <boost/test/unit_test.hpp>

using namespace brain;
using boost::shared_ptr;
using boost::make_shared;

BOOST_AUTO_TEST_CASE( NeuronTest ) {

    typedef vector<shared_ptr<NeuronCore> > NeuronLayer;

    shared_ptr<INeuronCore> sanityNeuroCheck(make_shared<NeuronCore>());

    sanityNeuroCheck->signal(10);
    BOOST_CHECK(sanityNeuroCheck->getValue() == 10);

    BOOST_TEST_MESSAGE("Check Point: Testsing Builder Behaviour\n Building a Simple layer with a single layer");
    NeuronGroupBuilder builder;
    // set the "fist", and so, the input layer size to ..
    BOOST_TEST_MESSAGE("Check Point: Building a new layer with 3 inputs and a single output");
    size_t SIZE = 3;
    shared_ptr<NeuronGroup> network = builder.initNetwork().addLayer(SIZE).addLayer(1).build();
    BOOST_CHECK(network->getInputLayer().size() == SIZE);

    BOOST_TEST_MESSAGE("Check Point: Send a random signal to input layer");
    foreach_ (shared_ptr<NeuronCore> &neuron, network->getInputLayer()) {
        neuron->signal(30.0);
    }

    BOOST_TEST_MESSAGE("Check Point: Without any proccess, output layer should remain with empty values");
    foreach_ (shared_ptr<NeuronCore> &neuron, network->getOutputLayer()) {
        BOOST_CHECK(neuron->getValue() == 0);
    }

    BOOST_TEST_MESSAGE("Withou new input, as many proccess happens, output layer should remain with last value");
    const static size_t max_loops = 3;
    for (size_t i = 0; i < max_loops; i++) {
        network->process();
    }

    for (size_t i = 0; i < network->getOutputLayer().size(); i++) {
        shared_ptr<NeuronCore> neuron = network->getOutputLayer().at(i);
        BOOST_CHECK(neuron->getValue() == 90.0);
        BOOST_LOG_TRIVIAL(debug) << "valor encontrado: " << neuron->getValue();
    };

};