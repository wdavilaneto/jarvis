//
// Created by walter on 20/07/15.
//

#ifndef JARVIS_NEURONCORE_H
#define JARVIS_NEURONCORE_H

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include "core/identifiable.h"
#include "INeuronCore.hpp"

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
    class NeuronCore : public INeuronCore , public jarvis::util::Identifiable  {
    public:

        NeuronCore() {
        };

        virtual ~NeuronCore(){};

    private:
        vector<float> innerValues;
        vector<boost::shared_ptr<INeuronCore> > connections;
    };

};

#endif //JARVIS_NEURONCORE_H
