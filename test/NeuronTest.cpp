#define BOOST_TEST_MODULE TesteServerTestSuite

#include <brain/NeuronCore.h>
#include <brain/NeuronGroup.h>
#include <boost/test/unit_test.hpp>

using namespace brain;
using namespace std;

BOOST_AUTO_TEST_CASE(NeuronTest) {

    // fist layer
    vector<NeuronCore> inputLayer(4);
    shared_ptr<NeuronCore> output(make_shared<NeuronCore>());

    // first layer
    for (int iCounter = 0; iCounter <= 4; iCounter++) {
        inputLayer[iCounter].connections.push_back(make_shared<NeuronCore>());
        inputLayer[iCounter].connections[0]->connections.push_back(output);
    }

    for (int iCounter = 0; iCounter <= 4; iCounter++) {
        inputLayer[iCounter].onRecieveSignal(1);
    }


}