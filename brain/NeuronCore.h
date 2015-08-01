//
// Created by walter on 20/07/15.
//

#ifndef JARVIS_NEURONCORE_H
#define JARVIS_NEURONCORE_H

#include <vector>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/foreach.hpp>
#include <random>

namespace brain {

    using namespace std;
    using boost::shared_ptr;

    class Identifiable {
    public:
        Identifiable() : id(boost::uuids::random_generator()()) {
        }

        boost::uuids::uuid getId() { return id; }

    private:
        boost::uuids::uuid id;
    };

    class Synapse : public Identifiable {
    public:
        float voltage;
    };


    class NeuronCore : public Identifiable {
    public:

        NeuronCore() : Identifiable(), innerVoltage(.01), defaultVoltageLimit(3) {
        };

        void onTimeElapse() {
            // Random variation on inner voltage
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<> dis(-.01f, 0.01);
            float variation = static_cast <float> (dis(gen));
            if (connections.empty()) {
                variation = variation * 1.618;
            }
            // if it will not empty cell voltage (death ?)
            if ((innerVoltage + variation) > 0 && innerVoltage < 100) {
                innerVoltage += variation;
            }
            BOOST_FOREACH(shared_ptr<NeuronCore> child, connections) {
                if (innerVoltage > 1) {
                    float disposevalue = ((innerVoltage - 1) * 0.618);
                    child->sendSignal(disposevalue);
                    innerVoltage -= disposevalue;

                }
                child->onTimeElapse();
            }
            if (innerVoltage > 1 ) {
                cout << getId() << " - " << innerVoltage << endl;
            }
        }

        void sendSignal(float signal) {
            if ((innerVoltage + signal) > 0 && innerVoltage < 100) {
                innerVoltage += signal;
            }
        }

        vector<shared_ptr<NeuronCore> > connections;
    private:
        float innerVoltage;
        float defaultVoltageLimit;
    };

}

#endif //JARVIS_NEURONCORE_H
