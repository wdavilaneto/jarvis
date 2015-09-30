//
// Created by walter on 05/08/15.
//

#ifndef JARVIS_IDENTIFIABLE_H
#define JARVIS_IDENTIFIABLE_H

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <random>

namespace jarvis {

    namespace util {

        /**
         * Utility class to interface and implement a universal unique Id (uuid)
         */
        class Identifiable {
        public:

            Identifiable() : id( boost::uuids::random_generator()()) {
            }

            boost::uuids::uuid getId() { return id; }

        private:
            boost::uuids::uuid id;
        };
    };
};
#endif //JARVIS_IDENTIFIABLE_H
