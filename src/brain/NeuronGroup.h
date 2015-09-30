//
// Created by walter on 29/09/15.
//

#ifndef JARVIS_NEURONGROUP_H
#define JARVIS_NEURONGROUP_H

#include "NeuronCore.h"

namespace brain {

    using std::shared_ptr;
    using std::vector;

    class NeuronGroup {
    public:
        NeuronGroup(){

        }

    private:
        shared_ptr<vector<NeuronCore> > inputLayer;
        shared_ptr<vector<NeuronCore> > outputLayer;
    };

}
#endif //JARVIS_NEURONGROUP_H
