//
// Created by walter on 10/10/16.
//

#ifndef JARVIS_CORPUSHANDLER_HPP
#define JARVIS_CORPUSHANDLER_HPP

#include <repository/CorpusRepository.hpp>
#include <server/server.hpp>

#include <boost/algorithm/string.hpp>
namespace server {
#define CORPUS_WORD_SIZE 7
#define URL_PATH_SEPARATOR "/"

    USE_SHARED_PTR
    using std::string;
    using domain::Corpus;



    class CorpusHandler : public IRequestHandler {
    public:
        CorpusHandler() {
            BOOST_LOG_TRIVIAL(info) << "Corpus Request Handling Registering ..." ;
        }

        virtual ~CorpusHandler() override = default;

        virtual bool urlMatches(const std::string aGivenUrl) override {
            return boost::istarts_with(aGivenUrl, "/corpus");
        }

    protected:
        virtual const string onHandle(const incoming_things &incoming, outgoing_things &outgoing) override {
            repository::CorpusRepository corpusRepository;

            string corpus_path = incoming.path.substr(CORPUS_WORD_SIZE);
            if (corpus_path.empty() || corpus_path == URL_PATH_SEPARATOR) {
                shared_ptr<Corpus> corpus = corpusRepository.get("pareceres");
                return corpus->toString();
            }
            if (boost::istarts_with(corpus_path, "")) {

            }
            static string message = "Service Not Found:";
            BOOST_LOG_TRIVIAL(info) << message << corpus_path ;
            outgoing.http_return = 404;
            return message;
        }
    };

}


#endif //JARVIS_CORPUSHANDLER_HPP
