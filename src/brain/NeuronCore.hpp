//
// Created by walter on 20/07/15.
//

#ifndef JARVIS_NEURONCORE_H
#define JARVIS_NEURONCORE_H

#include "core/identifiable.h"
#include "INeuronCore.hpp"
#include "NeuronConnection.hpp"

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

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
    class NeuronCore : public INeuronCore, public jarvis::util::Identifiable {
    public:

        NeuronCore() {
            currentVoltage = NEURON_CORE_DEFAULT_INNER_VOLTAGE;
            actionPotentialVoltage = NEURON_CORE_DEFAULT_VOLTAGE_LIMIT;
        };

        virtual ~NeuronCore() {
            if (!connections.empty()) {
                for (size_t i = 0; i < connections.size(); i++) {
                    NeuronConnection *n = connections.at(i);
                    if (n != 0) {
                        delete n;
                    }
                }
                connections.clear();
            }
        };

        virtual void connectTo(INeuronCore *otherNeuron) {
            NeuronConnection *connection = new NeuronConnection(otherNeuron, 0);
            connections.push_back(connection);
        };

        virtual void signal(float s) {
            currentVoltage += s;
        }

        // Non interface getter method
        virtual vector<NeuronConnection *> getConnections() {
            return connections;
        };

        // Non interface getter method
        virtual float getCurrentVoltage() {
            return currentVoltage;
        };

        // Non interface getter method
        virtual void setCurrentVoltage(float t) {
            currentVoltage = t;
        };

        // Non interface getter method
        virtual float getActionPotentialVoltage() {
            return actionPotentialVoltage;
        };

        // Non interface getter method
        virtual void setActionPotentialVoltage(float t) {
            actionPotentialVoltage = t;
        };

    private:
        float currentVoltage;
        float actionPotentialVoltage;
        vector<NeuronConnection *> connections;
    };

};

#endif //JARVIS_NEURONCORE_H
