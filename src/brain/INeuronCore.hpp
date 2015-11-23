//
// Created by walter on 07/10/15.
//

#ifndef JARVIS_INEURONCORE_H
#define JARVIS_INEURONCORE_H

#include <iostream>
#include <vector>
#include <boost/smart_ptr/shared_ptr.hpp>

namespace brain {

    using std::vector;
    using boost::shared_ptr;

    // TODO: change float to template
    //template <class T>
    class INeuronCore {
    public:

        virtual ~INeuronCore() { };

        virtual void connectTo(shared_ptr<INeuronCore> otherNeuron, float weight) = 0;

        virtual float signal(float) = 0;

        virtual void process() = 0;

        virtual float getValue() = 0;

    };

};

#endif //JARVIS_INEURONCORE_H
