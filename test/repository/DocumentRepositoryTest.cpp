//
// Created by walter on 06/10/16.
//

#define BOOST_TEST_MODULE DocumentRepositorySuite

#include <repository/TextRepository.hpp>
#include <repository/CorpusRepository.hpp>
#include <repository/DocumentRepository.hpp>
#include <service/TextService.hpp>

#include <boost/test/included/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(DocumentRepositorySuite)

    BOOST_AUTO_TEST_CASE(DocumentRepositoryTest_1) {

        USE_SHARED_PTR;

        using std::string;
        using namespace domain;
        using namespace repository;

        using service::TextService;

        repository::CorpusRepository corpusRepository;
        repository::TextRepository textRepository;
        repository::DocumentRepository documentRepository;

        TextService textService;

        shared_ptr <Corpus> corpus = corpusRepository.get("pareceres");

        std::vector<TextDocument> result = textRepository.findAll();
        for (TextDocument td : result) {
            shared_ptr <Document> document = textService.toDocument(corpus, td);
            try {
                //documentRepository.persist(document);
            } catch (const std::exception& exception){
                BOOST_LOG_TRIVIAL(info) << "already found values"; // TODO check exception
            } catch (...){
                BOOST_LOG_TRIVIAL(info) << "already found values"; // TODO check exception
            }
            for (auto word : document->words) {
                std::cout << word.first << std::endl;
            }
        }

        auto docs = documentRepository.findAll();
        // TODO plan some testes here
    };

BOOST_AUTO_TEST_SUITE_END()
