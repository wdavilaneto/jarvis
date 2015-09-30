//
// Created by walter on 20/07/15.
//
#include <iostream>
#include <boost/smart_ptr/shared_ptr.hpp>
#include "NeuronCore.h"
#include "core/identifiable.h"

namespace brain {

    /**
     * Inner package class implementation for smal variations on neural voltages
     * Completly usless bunch of code, just for futere chaotic behaviour feature tests
     * This class is not thread safe.. It requires an previous initialization from an "System Manager"
     * */
    class InnerVoltageVariation {
    public:

        // Inner voltage with default values ??
        // TODO to think on self continuous process of analisis....
        InnerVoltageVariation() : minVariation(-.01f), maxVariation(.01f), gen(rd()) {
            // TODO: read variations from property file
            std::uniform_real_distribution<> dis(minVariation, maxVariation);
        }

        static InnerVoltageVariation &Default() {
            static InnerVoltageVariation s;
            return s;
            // Micro Random Voltage Synaptic Weight Variation

        }

        float get() {
            std::uniform_real_distribution<> dis(getMin(), getMax());
            return static_cast<float>(dis(gen));
        }

        float getMin() {
            return minVariation;
        }

        float getMax() {
            return maxVariation;
        }

    private:
        float minVariation;
        float maxVariation;
        std::random_device rd;
        std::mt19937 gen;

    };


    void NeuronCore::onTimeElapse(void) {

        // Random variation on inner voltage
        InnerVoltageVariation &ivv = InnerVoltageVariation::Default();
        float variation = ivv.get();

        if (connections.empty()) {
            variation = variation * 1.618; // TODO remove this test multiplier
        }
        // if it will not empty cell voltage (death ?)
        if ((innerVoltage + variation) > 0 && innerVoltage < 100) {
            innerVoltage += variation;
        }

        if (innerVoltage > 2) {
            std::cout << getId() << " - " << innerVoltage << std::endl;
        }
    };

     getConnections

    void NeuronCore::onRecieveSignal(float signal) {

    };

    float NeuronCore::getValue() {
        return innerVoltage;
    };

};
