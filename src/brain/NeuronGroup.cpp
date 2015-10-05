//
// Created by walter on 29/09/15.
//

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include "NeuronGroup.h"

namespace brain {

    using std::vector;

    NeuronGroup::NeuronGroup() {

    }

    NeuronGroup::~NeuronGroup() {

    }

    boost::shared_ptr<NeuronCore> NeuronGroup::getOutput(){
        return output;
    }

};