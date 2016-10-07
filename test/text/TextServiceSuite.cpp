//
// Created by walter on 06/10/16.
//

#define BOOST_TEST_MODULE TextServiceSuite

#include <service/TextService.hpp>
#include <repository/TextRepository.hpp>
#include <server/server.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/unordered_map.hpp>
#include <repository/CorpusRepository.hpp>
#include <repository/DocumentRepository.hpp>


#include <boost/test/included/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(TextServiceSuite)

    BOOST_AUTO_TEST_CASE(TextServiceTest_1) {

        USE_SHARED_PTR;

        using std::string;
        using domain::Document;
        using domain::Corpus;
        using domain::TextDocument;

        using service::TextService;

        repository::CorpusRepository corpusRepository;
        repository::TextRepository textRepository;
        repository::DocumentRepository documentRepository;

        TextService textService;

        shared_ptr <Corpus> corpus = corpusRepository.get("pareceres");

        std::vector<TextDocument> result = textRepository.findAll();
        for (TextDocument td : result) {
            shared_ptr <Document> document = textService.toDocument(corpus, td);
            documentRepository.persist(document);
        }

        // TODO plan some testes here
    };

BOOST_AUTO_TEST_SUITE_END()
