//
// Created by walter on 11/08/16.
//

#ifndef JARVIS_CORPUSREPOSITORY_HPP
#define JARVIS_CORPUSREPOSITORY_HPP

#include <domain.hpp>
#include <repository/BaseRepository.hpp>
#include <boost/tokenizer.hpp>

namespace soci {

    using std::string;

    /**
     * Mapping Entity 'Word' to database
     */
    template<>
    struct type_conversion<domain::Corpus> {
        typedef values base_type;

        static void from_base(values const &v, indicator &ind, domain::Corpus &p) {
            try {
                p.id = v.get<int>("id");
                p.name = v.get<string>("name");
                p.language = v.get<string>("language");
                switch (v.get_properties("total_documents").get_data_type()) {
                    case dt_integer:
                        p.totalDocuments = v.get<int>("total_documents");
                        break;
                    case dt_double:
                        p.totalDocuments = v.get<double>("total_documents");
                        break;
                    case dt_string:
                        p.totalDocuments = atoll( v.get <string>("total_documents").c_str() );
                        break;
                    case dt_unsigned_long_long:
                        p.totalDocuments = v.get <unsigned long long>("total_documents");
                        break;
                    default:
                        p.totalDocuments = v.get <long long> ("total_documents");
                        break;


                }

            } catch (const boost::exception &ex) {
                BOOST_LOG_TRIVIAL(error) << "ConversionException Corpus";
            }
        }

        static void to_base(domain::Corpus &p, values &v, indicator &ind) {
            v.set("id", p.id);
            v.set("name", p.name);
            v.set("language", p.language);
            v.set("totalDocuments", p.totalDocuments);
        }
    };
};

namespace repository {

    USE_SHARED_PTR
    using namespace domain;
    using std::string;
    using std::vector;
    using soci::use;

    class CorpusRepository : BaseRepository {
    public:

        CorpusRepository() {
        };

        virtual ~CorpusRepository() = default;

        shared_ptr<Corpus> get(const size_t &id) {
            shared_ptr<Corpus> corpus = make_shared<Corpus>();
            session << getConfig().get<string>("repository.getCorpus"), soci::into(*corpus), use(id);
            if (!session.got_data()) {
                return shared_ptr<Corpus>(nullptr);
            }
            return corpus;
        };


    };

};

#endif //JARVIS_CORPUSREPOSITORY_HPP
