//
// Created by walter on 14/10/16.
//

#ifndef JARVIS_KEYWORDREPOSITORY_HPP
#define JARVIS_KEYWORDREPOSITORY_HPP

#include <domain/Word.hpp>
#include <repository/BaseRepository.hpp>
#include <repository/DocumentRepository.hpp>

namespace soci {

    using std::string;
    using domain::Word;


    /**
     * Mapping Entity 'Word' to database
     */
    template<>
    struct type_conversion<Word> {
        typedef values base_type;

        static void from_base(values const &v, indicator ind, Word p) {
            p.id = v.get<size_t>("id");
            p.name = v.get<string>("name");
            p.hitsOnDocuments = v.get<size_t>("hits_on_documents");
            p.isStop = v.get<size_t>("is_stop");
            p.total = v.get<size_t>("total");
            // here we should avoid retrieve corpus_id
        }

        static void to_base(Word p, values &v, indicator &ind) {
            v.set("id", p.id);
            v.set("name", p.name);
            v.set("total", p.total);
            v.set("is_stop", (p.isStop ? 1 : 0));
            v.set("hits_on_documents", p.hitsOnDocuments);
            v.set("corpus_id", p.corpus->id);
        }
    };
};

namespace repository {

    USE_SHARED_PTR
    using std::string;
    using std::vector;
    using domain::Word;

    class WordRepository : public BaseRepository {
    public:

        //TODO: Does this need pagination ?? probably yes...
        vector<shared_ptr<Word> > findAllWords(const size_t  & corpus_id) {
            string query(getConfig().get<string>("findAllKeyword"));

            vector<shared_ptr<Word> > result;
            Word doc;

            soci::statement st = (session.prepare << getConfig().get<string>("repository.findAllWords"), soci::into(doc), soci::use(corpus_id));
            st.execute();

            while (st.fetch()) {
                result.push_back( make_shared<Word>(doc));
            }
            return result;
        }

        shared_ptr<Word> get(const size_t &id) {
            shared_ptr<Word> word = make_shared<Word>();
            session << getConfig().get<string>("repository.getWord"), soci::into(word), soci::use(id) ;
            return word;
        };

        shared_ptr<Word> get(const string &name) {
            shared_ptr<Word> word = make_shared<Word>();
            session << getConfig().get<string>("repository.getWordByName"), soci::into(word), soci::use(name) ;
            return word;
        };

        void insert(shared_ptr<Word> word) {
            session << getConfig().get<string>("repository.insertWord"), soci::use(word);
        };

        void update(shared_ptr<Word> word) {
            session << getConfig().get<string>("repository.insertWord"), soci::use(word);
        };

        void remove(const size_t &id) {
            session << getConfig().get<string>("repository.deleteWord"), soci::use(id);
        };

        void remove(const string &name) {
            session << getConfig().get<string>("repository.deleteWord"), soci::use(name);
        };

        void deleteAll(const size_t &id) {
            session << getConfig().get<string>("repository.deleteAllWords"), soci::use(id);
        };

    };
};

#endif //JARVIS_KEYWORDREPOSITORY_HPP
