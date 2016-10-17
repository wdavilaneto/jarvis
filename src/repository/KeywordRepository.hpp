//
// Created by walter on 14/10/16.
//

#ifndef JARVIS_KEYWORDREPOSITORY_HPP
#define JARVIS_KEYWORDREPOSITORY_HPP

#include <domain>
#include <repository/BaseRepository.hpp>
#include <repository/DocumentRepository.hpp>

namespace soci {

    using std::string;
    using domain::KeyWord;

    template<>
    struct type_conversion<KeyWord> {
        typedef values base_type;
        static void from_base(values const &v, indicator /* ind */, KeyWord &p) {
            p.stemmed = v.get<string>("STEMMED");
            p.language = v.get<string>("LANGUAGE");
        }
        static void to_base(const KeyWord &p, values &v, indicator &ind) {
            v.set("STEMMED", p.stemmed);
            v.set("LANGUAGE", p.language);
        }
    };

    template<>
    struct type_conversion<KeyWord*> {
        typedef values base_type;
        static void from_base(values const &v, indicator /* ind */, KeyWord*p) {
            if (!p) {
                throw "Nullpointer Exception!";
            }
            p->stemmed = v.get<string>("UUID");
            p->language = v.get<string>("LANGUAGE");
        }
        static void to_base(KeyWord*p, values &v, indicator &ind) {
            if (!p) {
                throw "Nullpointer Exception!";
            }
            v.set("ID", p->stemmed);
            v.set("LANGUAGE", p->language);
        }
    };
};

namespace repository {

    USE_SHARED_PTR
    using std::string;
    using std::vector;
    using domain::KeyWord;

    class KeywordRepository : public BaseRepository {
    public:

        //TODO: Does this need pagination ?? probably yes...
        vector<shared_ptr<KeyWord> > findAll() {
            string query (getConfig().get<string>("findAllKeyword"));
            return nullptr;
        }
    };
};

#endif //JARVIS_KEYWORDREPOSITORY_HPP
