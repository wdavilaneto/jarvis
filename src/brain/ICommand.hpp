//
// Created by walter on 21/11/15.
//

#ifndef JARVIS_INEURONFUNCIONCOMAND_HPP
#define JARVIS_INEURONFUNCIONCOMAND_HPP

#include <boost/log/trivial.hpp>
#include <exception>

namespace brain {

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

}

#endif //JARVIS_INEURONFUNCIONCOMAND_HPP
