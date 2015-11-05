//
// Created by walter on 08/10/15.
//

#ifndef JARVIS_NEURONCONNECTION_H
#define JARVIS_NEURONCONNECTION_H

#include "INeuronCore.hpp"

namespace brain {

    using boost::shared_ptr;

    class NeuronConnection {
    public:

        NeuronConnection(shared_ptr<INeuronCore> t, float w) : target(t), weight(w) {
        }

        virtual ~NeuronConnection() { };

        virtual shared_ptr<INeuronCore> getTarget() {
            return target;
        };

        virtual void setWeight(float d) {
            this->weight = d;
        };

        virtual float getWeight() {
            return weight;
        };

        virtual float synapse(float f) {
            return getTarget()->signal(f * getWeight());
        }


    private:
        float weight;
        shared_ptr<INeuronCore> target;
    };

};

#endif //JARVIS_NEURONCONNECTION_H
