//
// Created by walter on 29/09/15.
//

#ifndef JARVIS_NEURONGROUP_H
#define JARVIS_NEURONGROUP_H

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

#include "NeuronCore.h"

namespace brain {

    using std::vector;

    typedef std::vector<boost::shared_ptr<NeuronCore> > NeuronLayer;

    class NeuronGroupBuilder;

    class NeuronGroup {
        friend class NeuronGroupBuilder;
    public:
        NeuronGroup();

        virtual ~NeuronGroup();

        boost::shared_ptr<NeuronCore> getOutput();

    private:
        vector<NeuronLayer> layers;
        // TODO multiple is multiple outputs viable for backlearning ?
        //vector<boost::shared_ptr<NeuronCore> > outputLayer;
        boost::shared_ptr<NeuronCore> output;
    };

}
#endif //JARVIS_NEURONGROUP_H
