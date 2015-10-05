//
// Created by walter on 20/07/15.
//

#ifndef JARVIS_NEURONCORE_H
#define JARVIS_NEURONCORE_H

#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include "core/identifiable.h"

#define NEURON_CORE_DEFAULT_VOLTAGE_LIMIT 100
#define NEURON_CORE_DEFAULT_INNER_VOLTAGE 0

namespace brain {

    using std::vector;

    /**
     *
     * Simple 'NeuronNode' represented by an unique id and an
     * natural inner 'voltage'..
     * TODO next version must make it scriptable for behaviour
    */
    class NeuronCore : public jarvis::util::Identifiable {
    public:

        NeuronCore() : innerValue(NEURON_CORE_DEFAULT_INNER_VOLTAGE), actionPotential(NEURON_CORE_DEFAULT_VOLTAGE_LIMIT) {
        };

        void connectTo(boost::shared_ptr<NeuronCore> otherNeuron);

        vector<boost::shared_ptr<NeuronCore> > getConnections();

        float doSignal(float signal);

        float getValue();

    private:
        float innerValue;
        float actionPotential;
        vector<boost::shared_ptr<NeuronCore> > connections;
    };

}

#endif //JARVIS_NEURONCORE_H
