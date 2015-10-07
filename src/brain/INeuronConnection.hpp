//
// Created by walter on 07/10/15.
//

#ifndef JARVIS_INEURONCONNECTION_HPP_H
#define JARVIS_INEURONCONNECTION_HPP_H


namespace brain {

    template<class T>
    class IConnection<T> {
    public:

        virtual IConnection() = 0;

        virtual IConnection(<T> from, <T> to) = 0;

        virtual ~IConnection() = 0;

        virtual void setOrigin(<T> from) = 0;

        virtual void setTarget(<T> to) = 0;

    };

};

#endif //JARVIS_INEURONCONNECTION_HPP_H
