//
// Created by walter on 05/10/15.
//

#ifndef JARVIS_NEURONGROUPBUILDER_H
#define JARVIS_NEURONGROUPBUILDER_H

#include <brain/NeuronGroup.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/log/trivial.hpp>
#include <boost/foreach.hpp>
#define foreach_ BOOST_FOREACH
//#define debug BOOST_LOG_TRIVIAL(debug)

namespace brain {

    using std::vector;
    using boost::shared_ptr;
    using boost::make_shared;

    typedef vector<shared_ptr<NeuronCore> > NeuronLayer;

    class NeuronGroupBuilder {
    public:

        NeuronGroupBuilder() : network(nullptr), autoconnect(true) { };

        NeuronGroupBuilder(bool autoconnect) : network(nullptr) , autoconnect(autoconnect)  {
        };

        virtual ~NeuronGroupBuilder() {
        };

        NeuronGroupBuilder &initNetwork() {
            BOOST_LOG_TRIVIAL(debug) << "Initializing a new NeuralGroup via Default Builder";
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

            BOOST_ASSERT_MSG(counter > 0 , "Neuron Layer can not be zero nor negative");
            BOOST_ASSERT_MSG( network != nullptr , "This builder has already prepared an input layer, Call initNetwork first ");

            NeuronLayer newLayer(counter); // Initialize a new Layer
            foreach_(shared_ptr<NeuronCore> &neuron, newLayer) {
                neuron = make_shared<NeuronCore>();
            }

            // If this is the first layer declared.. mark as input
            if (network->layers.size() == 0) {
                foreach_ (shared_ptr<NeuronCore>& neuron , newLayer){
                    neuron->markAsInputLayer();
                }
            } else if (autoconnect) { //  Caso nao seja a primeira e autoconnecto
                // get reference  of the last layer
                foreach_ (shared_ptr<NeuronCore>& newNeuron , newLayer){
                    // lop counter times to add neuron
                    foreach_ (shared_ptr<NeuronCore>& neuron , network->layers.back()){
                        neuron->connectTo(newNeuron);
                    }
                }
            }
            // add/move this recently creted layer to network layers
            network->layers.emplace_back(newLayer);
            return *this;
        };

        virtual shared_ptr<NeuronGroup> build() {
            shared_ptr<NeuronGroup> result = network;
            network.reset();
            return result; // return container managed pointer...
        };
    private:
        shared_ptr<NeuronGroup> network;
        bool autoconnect;
    };

};

#endif //JARVIS_NEURONGROUPBUILDER_H
