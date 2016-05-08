//
// Created by walter on 15/03/16.
//

#ifndef JARVIS_COMMAND_HPP
#define JARVIS_COMMAND_HPP

#include <boost/log/trivial.hpp>
#include <exception>

class ICommand {
public:

    virtual void onExecute () = 0;

    void execute() noexcept {

        BOOST_LOG_TRIVIAL(debug);

        try {
            return this->onExecute();
        } catch (std::exception& ex) {
            BOOST_LOG_TRIVIAL(error) << ex.what();
        }

    }
};

#endif //JARVIS_COMMAND_HPP
