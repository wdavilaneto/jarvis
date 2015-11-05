//
// Created by walter on 29/09/15.
//

#ifndef JARVIS_NEURONGROUP_H
#define JARVIS_NEURONGROUP_H

#include <iostream>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/foreach.hpp>
#define foreach_ BOOST_FOREACH

#include "NeuronCore.hpp"
#include "INeuronGroup.hpp"

namespace brain {

    using std::vector;

    using boost::shared_ptr;

    typedef vector<shared_ptr<NeuronCore> > NeuronLayer;

    class NeuronGroup : public INeuronGroup {
    public:

        // Empty Contructor
        NeuronGroup() { };

        // Destructor will delete all created neurons (he owns)
        virtual ~NeuronGroup() {
        };

        // Main Group Procces on all layers summaring rules/calculations
        virtual void process() {

            // before new process loop we clear output layer
            foreach_ (shared_ptr<NeuronCore> neuron , layers.back()){
                //neuron->setValue(1); // 1 do not changes what reaches output value
            };

            foreach_ (NeuronLayer& layer , layers ) {
                foreach_ (shared_ptr<NeuronCore>& neuron, layer){
                    neuron->process();
                }
            };
        };

        virtual NeuronCore* getNeuron(boost::uuids::uuid aid){
            return NULL;
        }

        virtual NeuronLayer &getInputLayer() {
            return layers.front();
        }

        virtual NeuronLayer &getOutputLayer() {
            return layers.back();
        }

    private:

        friend class NeuronGroupBuilder;

        vector<NeuronLayer> layers;
    };

    // Empty Contructor

};
#endif //JARVIS_NEURONGROUP_H
