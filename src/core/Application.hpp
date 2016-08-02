//
// Created by walter on 28/07/16.
//

#ifndef JARVIS_APPLICATION_HPP_HPP
#define JARVIS_APPLICATION_HPP_HPP

#include <iostream>
#include <boost/property_tree/ini_parser.hpp>

namespace core {

    using std::string;
    using boost::property_tree::ptree;

    class ApplicationAware {
    public:
        //ApplicationAware(string path = DEFAULT_PATH) {
        ApplicationAware() {
            boost::property_tree::ini_parser::read_ini(DEFAULT_PATH, config);
        }

        ~ApplicationAware() = default;

        ptree &getConfig() {
            return config;
        }

    private:
        string DEFAULT_PATH = "../../resources/application.cfg"; // Thank you C++14 !!!
        ptree config;
    };

}
#endif //JARVIS_APPLICATION_HPP_HPP

