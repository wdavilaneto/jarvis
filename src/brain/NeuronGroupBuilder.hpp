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

    class NeuronGroupBuilder {
    public:

        NeuronGroupBuilder() : network(0) { };

        virtual ~NeuronGroupBuilder() {

        };

        NeuronGroupBuilder &initNetwork() {
            if (network == 0) {
                network = new NeuronGroup;
            } else {
                //BOOST_THROW_EXCEPTION(BuilderException("Incorrect use of builder. This builder is already buinding a network"));
            }
            return *this;
        }

        /**
         * Prepare the input layer of a given network
         */
        NeuronGroupBuilder &addLayer(size_t counter) {
            if (network == 0) {
                //BOOST_THROW_EXCEPTION(BuilderException("This builder has already prepared an input layer"));
            }
            // TODO change to a more optimized way to factory in blocks
            if (counter > 0) {
                // Reference to be Copied into NeronGroup
                NeuronLayer inputLayer;
                // lop counter times to add neuron
                for (size_t iCounter = 0; iCounter < counter; iCounter++) {
                    INeuronCore *newNeuron = network->createNeuron();
                    // add neuron to this layer
                    inputLayer.push_back(newNeuron);
                    // lets connect if possible, last layer to this one
                    if (layers.size() > 0) {
                        // get position of the last layer
                        size_t lastLayerSize = layers.size() - 1;
                        for (size_t innerCounter = 0; innerCounter < layers[lastLayerSize].size(); innerCounter++) {
                            layers.at(lastLayerSize).at(innerCounter)->connectTo(newNeuron);
                        }
                    }
                }
                // add this recentlycreted layer to network layers
                layers.push_back(inputLayer);
            } else {
                //boost::throw_exception(BuilderException("Neuron networks can not have input layer zero length or less"));
            }
            return *this;
        };

        boost::shared_ptr<NeuronGroup> build() {
            // Pass this pointer to sharedPointer administration
            boost::shared_ptr<NeuronGroup> ng((NeuronGroup *) network);
            // value copy .. TODO enhance the performance of this operation
            ng->layers = layers;
            network = NULL; // set pointer reference to ZERO and
            layers.clear(); // clear inner layers
            return ng; // return container managed pointer...
        };

    private:
        vector<NeuronLayer> layers;
        INeuronGroup *network;
    };

};

#endif //JARVIS_NEURONGROUPBUILDER_H
