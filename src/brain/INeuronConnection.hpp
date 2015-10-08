//
// Created by walter on 07/10/15.
//

#ifndef JARVIS_INEURONCONNECTION_HPP_H
#define JARVIS_INEURONCONNECTION_HPP_H


namespace brain {

    template<class T>
    class INeuronConnection {
    public:

        virtual ~INeuronConnection() { };

        virtual void setWeight(float) = 0;

        virtual float getWeight() = 0;

        virtual T *getTarget() = 0;
    };

};

#endif //JARVIS_INEURONCONNECTION_HPP_H
