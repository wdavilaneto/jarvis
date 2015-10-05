//
// Created by walter on 20/07/15.
//
#include <iostream>
#include "NeuronCore.h"

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

    void NeuronCore::connectTo(boost::shared_ptr<NeuronCore> otherNeuron) {
        connections.push_back(otherNeuron);
    };

    vector<boost::shared_ptr<NeuronCore> > NeuronCore::getConnections() {
        return connections;
    };

    float NeuronCore::doSignal(float signal) {
        innerValue = signal;
    };

    float NeuronCore::getValue() {
        return innerValue;
    };

};
