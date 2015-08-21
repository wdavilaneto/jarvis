//
// Created by walter on 20/07/15.
//

#ifndef JARVIS_NEURONCORE_H
#define JARVIS_NEURONCORE_H


#include <vector>
#include <boost/foreach.hpp>
#include "identifiable.h"


namespace brain {

    using namespace std;
    using boost::shared_ptr;


    class Synapse : public jarvis::util::Identifiable {
    public:
        float voltage;
    };


    // Simple 'NeuronNode' represented by an unique id and an
    // natural inner 'voltage'
    class NeuronCore : public jarvis::util::Identifiable {
    public:

        NeuronCore() :
                Identifiable(),
                innerVoltage(.01),
                defaultVoltageLimit(3) {
        };

        void onTimeElapse();

        void sendSignal(float signal);

        vector<shared_ptr<NeuronCore> > connections;

    private:
        float innerVoltage;
        float defaultVoltageLimit;
    };

}

#endif //JARVIS_NEURONCORE_H
