//
// Created by walter on 20/07/15.
//
#include <iostream>
#include <boost/smart_ptr/shared_ptr.hpp>
#include "NeuronCore.h"
#include "core/identifiable.h"

namespace brain {

    void NeuronCore::onTimeElapse(void) {

        // Random variation on inner voltage
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-.01f, 0.01f);
        float variation = static_cast<float>(dis(gen));
        if (connections.empty()) {
            variation = variation * 1.618;
        }
        // if it will not empty cell voltage (death ?)
        if ((innerVoltage + variation) > 0 && innerVoltage < 100) {
            innerVoltage += variation;
        }
        BOOST_FOREACH(shared_ptr < NeuronCore > child, connections)
        {
            if (innerVoltage > 1) {
                float disposevalue = ((innerVoltage - 1) * 0.618);
                child->sendSignal(disposevalue);
                innerVoltage -= disposevalue;
            }
            child->onTimeElapse();
        }
        if (innerVoltage > 2) {
            std::cout << getId() << " - " << innerVoltage << endl;
        }
    }

    void NeuronCore::sendSignal(float signal) {
        if ((innerVoltage + signal) > 0 && innerVoltage < 100) {
            innerVoltage += signal;
        }
    }
};
