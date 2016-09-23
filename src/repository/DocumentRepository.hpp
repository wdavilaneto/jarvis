//
// Created by walter on 20/09/16.
//

#ifndef JARVIS_DOCUMENTREPOSITORY_HPP
#define JARVIS_DOCUMENTREPOSITORY_HPP

#include <repository/DocumentRepository.hpp>
#include <domain.hpp>
#include <soci/soci.h>
#include "BaseRepository.hpp"

namespace soci {

    using std::string;
    using domain::Document;

    template<>
    struct type_conversion<Document> {
        typedef values base_type;

        static void from_base(values const &v, indicator /* ind */, Document &p) {
            p.uuid = v.get<string>("UUID");
            p.refId = atoll(v.get<string>("REF_ID").c_str());
        }

        static void to_base(const Document &p, values &v, indicator &ind) {
            v.set("ID", p.uuid);
            v.set("TEXT", p.refId);
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
            session << getConfig().get<string>("repository.insertDocument"), soci::use(*document);
            //for (auto word : document->words) {
                //session << getConfig().get<string>("repository.insertWordOnDocument"), soci::use(*word);
            //}
        }

        std::vector<Document> findAll() {

            std::vector<Document> result;
            Document doc;

            soci::statement st = ( session.prepare << getConfig().get<string>("repository.findAllDocuments"), soci::into(doc) );
            st.execute();

            while (st.fetch()) {
                result.push_back(doc);
            }
            return result;
        };

        Document get(size_t id) {
            domain::Document doc;
            session << "select nr_mp as ID, pdf as TEXT  from bi_manifestacao where nr_mp = :1", soci::into(doc), soci::use(id);
            return doc;
        };


    };

};


#endif //JARVIS_DOCUMENTREPOSITORY_HPP
