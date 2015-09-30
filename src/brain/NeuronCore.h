//
// Created by walter on 20/07/15.
//

#ifndef JARVIS_NEURONCORE_H
#define JARVIS_NEURONCORE_H

#include <vector>
#include "core/identifiable.h"

#define NEURON_CORE_DEFAULT_VOLTAGE_LIMIT 100
#define NEURON_CORE_DEFAULT_INNER_VOLTAGE 0

namespace brain {

    using std::vector;
    using std::shared_ptr;

    class Connection;

    typedef shared_ptr<Connection> connection_ptr;

    /**
     *
     * Simple 'NeuronNode' represented by an unique id and an
     * natural inner 'voltage'..
     * TODO next version must make it scriptable for behaviour
    */
    class NeuronCore : public jarvis::util::Identifiable {
    public:

        NeuronCore() :
                Identifiable(),
                innerVoltage(NEURON_CORE_DEFAULT_INNER_VOLTAGE),
                actionPotential(NEURON_CORE_DEFAULT_VOLTAGE_LIMIT) {
        };

        void onTimeElapse();

        float onRecieveSignal(float signal);

        void getConnections();

        float getValue();

    private:
        float innerVoltage;
        float actionPotential;
        vector<connection_ptr> connections;
    };


    /**
     * Represents an Connection between 2 "neurons cores"
     */
    class Connection : public jarvis::util::Identifiable {
    public:

        float sendValue(float value) {

        }

    private:
        float weight;
        shared_ptr<NeuronCore> from;
        shared_ptr<NeuronCore> to;
    };

}

#endif //JARVIS_NEURONCORE_H
