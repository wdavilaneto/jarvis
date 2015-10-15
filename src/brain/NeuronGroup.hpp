//
// Created by walter on 29/09/15.
//

#ifndef JARVIS_NEURONGROUP_H
#define JARVIS_NEURONGROUP_H

#include <iostream>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

#include "NeuronCore.hpp"
#include "INeuronGroup.hpp"

namespace brain {

    using std::vector;

    typedef vector<NeuronCore> NeuronLayer;

    class NeuronGroup : public INeuronGroup {
    public:

        // Empty Contructor
        NeuronGroup() { };

        // Destructor will delete all created neurons (he owns)
        virtual ~NeuronGroup() {
        };

        virtual vector<NeuronCore>& getInputLayer() {
            return layers.front();
        }

    private:
        friend class NeuronGroupBuilder;
        vector<NeuronLayer> layers;
    };

    // Empty Contructor

};
#endif //JARVIS_NEURONGROUP_H
