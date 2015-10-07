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

    typedef std::vector<boost::shared_ptr<NeuronCore> > NeuronLayer;

    class NeuronGroupBuilder {
    public:

        NeuronGroupBuilder();

        virtual ~NeuronGroupBuilder();

        NeuronGroupBuilder& addInputLayerSize(size_t counter);

        NeuronGroupBuilder&  addHiddenLayerWithSize(size_t counter);

        boost::shared_ptr<NeuronGroup> build();

    private:
        vector<NeuronLayer> layers;
    };

};

#endif //JARVIS_NEURONGROUPBUILDER_H
