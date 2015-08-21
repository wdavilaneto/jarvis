
#include <iostream>
#include <boost/lexical_cast.hpp>
#include <boost/foreach.hpp>
#include <boost/make_shared.hpp>

#include "../headers/NeuronCore.h"

int main(int argc, char *argv[]) {
    using namespace std;
    using namespace brain;
    using namespace boost;

    cout << "Initializing Jarvis..." << endl;

    NeuronCore neuron;
    cout << "Neuron Id:" << boost::lexical_cast<std::string>(neuron.getId()) << endl;

    string stuff("hello world!");
    stuff.length();

    for (int iCounter = 0; iCounter < 10; iCounter++) {
        neuron.connections.push_back(make_shared<NeuronCore>());
    }

    while (true) {
        neuron.onTimeElapse();
    }

    return 0;
}
