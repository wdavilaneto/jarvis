#define BOOST_TEST_MODULE TesteServerTestSuite

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

#include <brain/NeuronCore.h>
#include <brain/NeuronGroup.h>
#include <boost/test/unit_test.hpp>
#include <brain/NeuronGroupBuilder.h>

using namespace brain;
using boost::shared_ptr;
using boost::make_shared;

BOOST_AUTO_TEST_CASE(NeuronTest) {

    NeuronGroupBuilder builder;

    // Single Neuron network test
    shared_ptr<NeuronGroup> group = builder.addInputLayerSize(2).build();





}