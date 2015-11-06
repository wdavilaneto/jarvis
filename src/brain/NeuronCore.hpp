//
// Created by walter on 20/07/15.
//

#ifndef JARVIS_NEURONCORE_H
#define JARVIS_NEURONCORE_H

#include "core/identifiable.h"
#include <brain/INeuronCore.hpp>
#include <brain/NeuronConnection.hpp>

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

#define NEURON_CORE_DEFAULT_VOLTAGE_LIMIT 100
#define NEURON_CORE_DEFAULT_INNER_VOLTAGE 0
#define NEURON_DEFAULT_SYNAPSE_WEIGHT  1

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
            isInput = false;
        };

        virtual ~NeuronCore() {
            // Destructor deletes all Connections
            if (!connections.empty()) {
                for (size_t i = 0; i < getConnections().size(); i++) {
                    NeuronConnection *n = connections.at(i);
                    if (n != 0) {
                        delete n;
                    }
                }
                connections.clear();
            }
        };

        /**
         * Connect this neuron with other one
         */
        void connectTo(shared_ptr<INeuronCore> otherNeuron, float weight = NEURON_DEFAULT_SYNAPSE_WEIGHT) {
            BOOST_ASSERT_MSG( this != otherNeuron.get() , "A Neuron can't be connected to itself");
            NeuronConnection *connection = new NeuronConnection(otherNeuron, weight);
            connections.push_back(connection);
        };

        virtual float signal(float s) {
            currentVoltage += s;
            return currentVoltage;
        }

        virtual void process(){
            if (isInputLayer()) {
                foreach_ (NeuronConnection* connection, getConnections() ){
                    connection->synapse(currentVoltage);
                }
                // if input-layer or any hidden layer clear value
                if (! isOutputLayer()){
                    currentVoltage = 0 ;
                } // OutputLayer should mantain last value unless cleared by NeuronGroup
            }
        };

        // Non interface getter method
        virtual vector<NeuronConnection *> getConnections() {
            return connections;
        };

        float getValue(){
            return currentVoltage;
        }

        void setValue(float f){
            this->currentVoltage = f;
        }

        // Non interface getter method
        virtual float getActionPotentialVoltage() {
            return actionPotentialVoltage;
        }

        virtual bool isInputLayer() {
            return isInput;
        }

        virtual bool isOutputLayer() {
            return connections.size() == 0;
        }

        virtual void markAsInputLayer() {
            isInput = true;
        }

        virtual float getActivationValue(){
            return activation() ? getActionPotentialVoltage() : 0;
        }

    protected:
        virtual bool activation() {
            if (currentVoltage > getActionPotentialVoltage()) {
                return true;
            }
            return false;
        }

    private:
        bool isInput;
        float currentVoltage;
        float actionPotentialVoltage;
        vector<NeuronConnection *> connections;
    };

};

#endif //JARVIS_NEURONCORE_H
