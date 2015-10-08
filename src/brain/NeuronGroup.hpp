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
    typedef std::vector<boost::shared_ptr<NeuronCore> > NeuronLayer;

    class NeuronGroupBuilder;

    class NeuronGroup : public INeuronGroup {
        friend class NeuronGroupBuilder;

    public:
        // Empty Contructor
        NeuronGroup() {
        };
        // Destructor will delete all created neurons (he owns)
        virtual ~NeuronGroup() {
            if (!neurons.empty()) {
                for (std::vector<INeuronCore *>::reverse_iterator it = neurons.rbegin(); it != neurons.rend(); ++it) {
                        delete (*it);
                }
                neurons.clear();
            }
        };

        virtual INeuronCore *createNeuron() {
            INeuronCore *neuron = new NeuronCore;
            neurons.push_back(neuron);
            return neuron;
        };


        const size_t getSize()  {
            return neurons.size();
        }

    private:
        vector<INeuronCore *> neurons; // hold pointers to neurons on this system
        vector<NeuronLayer> layers;
        // TODO multiple is multiple outputs viable for backlearning ?
        //vector<boost::shared_ptr<NeuronCore> > outputLayer;
        boost::shared_ptr<NeuronCore> output;
    };

};
#endif //JARVIS_NEURONGROUP_H
