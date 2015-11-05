//
// Created by walter on 07/10/15.
//

#ifndef JARVIS_INEURALGROUP_HPP
#define JARVIS_INEURALGROUP_HPP

#include "INeuronCore.hpp"

namespace brain {

    class INeuronGroup {
    public:

        virtual ~INeuronGroup() { };

        virtual void process() = 0;

    };
};

#endif //JARVIS_INEURALGROUP_HPP
