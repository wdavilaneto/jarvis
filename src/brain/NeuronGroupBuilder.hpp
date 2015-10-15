//
// Created by walter on 05/10/15.
//

#ifndef JARVIS_NEURONGROUPBUILDER_H
#define JARVIS_NEURONGROUPBUILDER_H

#include <brain/NeuronGroup.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

namespace brain {

    using std::vector;
    using boost::shared_ptr;
    using boost::make_shared;

    class NeuronGroupBuilder {
    public:

        NeuronGroupBuilder() : network(nullptr){ };

        virtual ~NeuronGroupBuilder() {
        };

        NeuronGroupBuilder &initNetwork() {
            if (network != 0) {
                network.reset();
            }
            network = make_shared<NeuronGroup>();
            return *this;
        }

        /**
         * Prepare the input layer of a given network
         */
        NeuronGroupBuilder &addLayer(size_t counter) {
            if (network == nullptr) {
                //BOOST_THROW_EXCEPTION(BuilderException("This builder has already prepared an input layer"));
            }
            vector<NeuronCore> newLayer(counter);
            // Reference to be Copied into NeronGroup
            if (network->layers.size() > 0) {
                // get position of the last layer
                NeuronLayer &lastlayer = network->layers.back();
                // lop counter times to add neuron
                for (size_t iCounter = 0; iCounter < counter; iCounter++) {
                    INeuronCore &newNeuron = newLayer.at(iCounter);
                    for (size_t innerCounter = 0; innerCounter < lastlayer.size(); innerCounter++) {
                        lastlayer.at(innerCounter).connectTo(&newNeuron);
                    }
                }
            }
            // add this recently creted layer to network layers
            network->layers.push_back(newLayer);
            return *this;
        };

        boost::shared_ptr<NeuronGroup> build() {
            shared_ptr<NeuronGroup> result = network;
            network.reset();
            return result; // return container managed pointer...
        };

    private:
        shared_ptr<NeuronGroup> network;
    };

};

#endif //JARVIS_NEURONGROUPBUILDER_H
