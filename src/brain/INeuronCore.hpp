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

    class INeuronCore {
    public:

        virtual ~INeuronCore() { };

        virtual void connectTo(INeuronCore *otherNeuron) = 0;

        virtual void signal(float) = 0;

//        virtual vector<shared_ptr<INeuronCore> > getConnections() = 0;
//
//        virtual vector<float> doSignal(vector<float> signal) = 0;

        //virtual INeuronCore* clone() const = 0; // The Virtual (Copy) Constructor
    };

};

#endif //JARVIS_INEURONCORE_H
