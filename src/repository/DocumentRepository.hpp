//
// Created by walter on 20/09/16.
//

#ifndef JARVIS_DOCUMENTREPOSITORY_HPP
#define JARVIS_DOCUMENTREPOSITORY_HPP

#include <domain.hpp>
#include <repository/BaseRepository.hpp>
#include <repository/pagination/Page.hpp>
#include <repository/DocumentRepository.hpp>

namespace soci {

    using std::string;
    using boost::shared_ptr;
    using domain::Document;

    template<>
    struct type_conversion<Document> {
        typedef values base_type;
        static void from_base(values const &v, indicator /* ind */, Document &p) {
            p.uuid = v.get<string>("uuid");
            throw "not implemented exception";
        }
        static void to_base(const Document &p, values &v, indicator &ind) {
            v.set("uuid", p.uuid);
            throw "not implemented exception";
        }
    };

    template<>
    struct type_conversion<Document*> {
        typedef values base_type;
        static void from_base(values const &v, indicator /* ind */, Document*p) {
            if (!p) {
                throw "Nullpointer Exception!";
            }
            p->uuid = v.get<string>("uuid");
            p->refId = v.get<size_t>("ref_id");
            p->corpus_id = v.get<size_t>("corpus_id");
        }
        static void to_base(Document*p, values &v, indicator &ind) {
            if (!p) {
                throw "Nullpointer Exception!";
            }
            v.set<string>("uuid", p->uuid);
            v.set<size_t>("ref_id", p->refId);
            v.set<size_t>("corpus_id", p->corpus_id);
        }
    };

};

namespace repository {

    using boost::shared_ptr;
    using std::string;
    using domain::Document;
    using domain::TextDocument;

    class DocumentRepository : public BaseRepository {
    public:

        DocumentRepository() {
        };

        virtual ~DocumentRepository() {

        };

        void persist(shared_ptr<Document> document) {
            try {
                string query = getConfig().get<string>("repository.insertDocument", "");
                session << query, soci::use(document.get());
//                for (auto word : document->words) {
//                    //session << getConfig().get<string>("repository.insertWordOnDocument"), soci::use(word);
//                }
            } catch (std::exception *exception) {
                BOOST_LOG_TRIVIAL(fatal) << "deu merda";
            }
        }

        std::vector<shared_ptr<Document> > findAll() {

            std::vector<shared_ptr<Document> > result;
            Document* doc = new Document;

            soci::statement st = (session.prepare << getConfig().get<string>("repository.findAllDocuments"), soci::into(doc));
            st.execute();

            while (st.fetch()) {
                result.push_back(make_shared<Document>(*doc));
            }
            return result;
        };

        Document get(size_t id) {
            domain::Document doc;
            session << "select nr_mp as ID, pdf as TEXT  from bi_manifestacao where nr_mp = :1", soci::into(
                    doc), soci::use(id);
            return doc;
        };


    };

};


#endif //JARVIS_DOCUMENTREPOSITORY_HPP
