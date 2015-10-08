//
// Created by walter on 05/10/15.
//

#ifndef JARVIS_NEURONGROUPBUILDER_H
#define JARVIS_NEURONGROUPBUILDER_H

#include "NeuronGroup.hpp"
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

namespace brain {

    using std::vector;

    class NeuronGroupBuilder {
    public:

        NeuronGroupBuilder() {};

        virtual ~NeuronGroupBuilder(){};

        NeuronGroupBuilder& addInputLayerSize(size_t counter){
            if (doneInput) {
                //throw new std:exception
            }
            // TODO change to a more optimized way to factory in blocks
            if (counter >0 ) {
                NeuronLayer inputLayer;
                for (size_t iCounter = 0; iCounter < counter; iCounter++) {
                    inputLayer.push_back(boost::make_shared<NeuronCore>());
                }
                layers.push_back(inputLayer);
            } else {
                //TODO exception
            }
            return *this;
        };

        NeuronGroupBuilder&  addHiddenLayerWithSize(size_t counter){
            // TODO to implement
            return *this;
        };

        NeuronGroupBuilder&  addOutputLayerWithSize(size_t counter){
            // TODO to implement
            return *this;
        };

        boost::shared_ptr<NeuronGroup> build(){
            //
            boost::shared_ptr<NeuronCore> output = boost::make_shared<NeuronCore>();
            size_t lastHiddenLayer = layers.size() -1;

            for(size_t iCounter = 0 ; iCounter < layers[lastHiddenLayer].size() ; iCounter++){
                //layers[lastHiddenLayer].at(iCounter)->connectTo(output);
            }

            boost::shared_ptr<NeuronGroup> ng = boost::make_shared<NeuronGroup>();
            ng->layers = layers;
            return ng;
        };

    private:
        bool doneInput = false;
        bool doneOutput = false;
        vector<NeuronLayer> layers;
    };

};

#endif //JARVIS_NEURONGROUPBUILDER_H
