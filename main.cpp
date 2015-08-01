//
// sync_client.cpp
// ~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2012 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <iostream>
#include "brain/NeuronCore.h"
#include <boost/lexical_cast.hpp>
#include <boost/foreach.hpp>
#include <boost/make_shared.hpp>

int main(int argc, char *argv[]) {
    using namespace std;
    using namespace brain;
    using namespace boost;

    cout << "Initializing Jarvis..." << endl;

    NeuronCore neuron;
    cout << "Neuron Id:" << boost::lexical_cast<std::string>(neuron.getId()) << endl;

    for (int iCounter = 0; iCounter < 10; iCounter++) {
        neuron.connections.push_back(make_shared<NeuronCore>());
    }

    while (true) {
        neuron.onTimeElapse();
    }

    return 0;
}
