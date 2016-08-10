//
// Created by walter on 28/07/16.
//

#ifndef JARVIS_APPLICATION_HPP_HPP
#define JARVIS_APPLICATION_HPP_HPP

#include <iostream>
#include <boost/property_tree/ini_parser.hpp>

#define USE_SHARED_PTR using boost::shared_ptr; \
                        using boost::make_shared;

namespace core {

    using std::string;
    using boost::property_tree::ptree;

    class ApplicationAware {
    public:

        /**
         * Initialize an aplication aware Class based on application config
         * @return
         */
        ApplicationAware() {
            boost::property_tree::ini_parser::read_ini(DEFAULT_PATH, config);
        }

        virtual ~ApplicationAware() = default;

        ptree &getConfig() {
            return config;
        }

    private:
        // TODO: Change to application runtime root ...
        string DEFAULT_PATH = "../../resources/application.cfg"; // Thank you C++11 !!!
        ptree config;
    };

}
#endif //JARVIS_APPLICATION_HPP_HPP

