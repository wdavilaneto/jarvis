//
// Created by walter on 29/09/15.
//

#ifndef JARVIS_NEURONGROUP_H
#define JARVIS_NEURONGROUP_H

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

#include "NeuronCore.hpp"
#include "INeuronGroup.hpp"

namespace brain {

    using std::vector;

    typedef std::vector<INeuronCore *> NeuronLayer;

    class NeuronGroup : public INeuronGroup {
        friend class NeuronGroupBuilder;

    public:

        // Empty Contructor
        NeuronGroup(){};

        // Destructor will delete all created neurons (he owns)
        virtual ~NeuronGroup() {
            if (!neurons.empty()) {
                for (size_t i = 0; i < neurons.size(); i++) {
                    INeuronCore *n = neurons.at(i);
                    if (n != 0) {
                        delete (n);
                    }
                }
                neurons.clear();
            }
        };

        virtual INeuronCore *createNeuron() {
            INeuronCore *neuron = new NeuronCore;
            neurons.push_back(neuron);
            return neuron;
        };

        const size_t getSize() {
            return neurons.size();
        }

        virtual vector<INeuronCore *> allNeurons() {
            return neurons;
        }

        virtual vector<INeuronCore *> getInputLayer(){
            if (layers.size()>0) {
                return layers.at(0);
            }
            return vector<INeuronCore *>(); // empty vector
        }

    private:
        vector<INeuronCore *> neurons; // hold pointers to neurons on this system
        vector<NeuronLayer> layers;
    };

    // Empty Contructor

};
#endif //JARVIS_NEURONGROUP_H
