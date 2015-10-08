//
// Created by walter on 08/10/15.
//

#ifndef JARVIS_NEURONCONNECTION_H
#define JARVIS_NEURONCONNECTION_H

#include "INeuronConnection.hpp"
#include "INeuronCore.hpp"

namespace brain {

    class NeuronConnection : public INeuronConnection<INeuronCore> {
    public:

        NeuronConnection(INeuronCore *target, float weight) {
            this->target = target;
            this->weight = weight;
        }

        virtual ~NeuronConnection() { };

        virtual INeuronCore *getTarget() {
            return target;
        };

        virtual void setWeight(float d) {
            this->weight = d;
        };

        virtual float getWeight() {
            return weight;
        };

    private:
        float weight;
        INeuronCore *target;
    };

};

#endif //JARVIS_NEURONCONNECTION_H
