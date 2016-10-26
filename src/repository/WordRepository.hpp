//
// Created by walter on 14/10/16.
//

#ifndef JARVIS_KEYWORDREPOSITORY_HPP
#define JARVIS_KEYWORDREPOSITORY_HPP

#include <domain.hpp>
#include <repository/BaseRepository.hpp>
#include <repository/DocumentRepository.hpp>

namespace soci {

    USE_SHARED_PTR
    using std::string;
    using domain::Word;


    /**
     * Mapping Entity 'Word' to database
     */
    template<>
    struct type_conversion<Word> {
        typedef values base_type;

        static void from_base(values const &v, indicator /*ind*/, Word &p) {
            if (!p.corpus) {
                p.corpus = make_shared<domain::Corpus>();
            }
            if (v.get_number_of_columns() > 4) {
                p.id = v.get<int>("id");
            }
            p.corpus->id = v.get<int>("corpus_id");
            p.name = v.get<string>("name");
            p.total = v.get<int>("total");
            p.hitsOnDocuments = v.get<int>("hits_on_documents");
            p.isStop = v.get<int>("is_stop") >= 1;
            // here we should avoid retrieve corpus_id
        }

        static void to_base(Word &p, values &v, indicator &ind) {
            v.set("corpus_id", p.corpus->id);
            v.set("name", p.name);
            v.set("total", p.total);
            v.set("hits_on_documents", p.hitsOnDocuments);
            v.set("is_stop", (p.isStop ? 1 : 0));
            ind = i_ok;
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
        vector<shared_ptr<Word> > findAllWords(const size_t &corpus_id) {
            string query(getConfig().get<string>("findAllKeyword"));

            vector<shared_ptr<Word> > result;
            Word doc;

            soci::statement st = (session.prepare << getConfig().get<string>("repository.findAllWords"), soci::into(doc), soci::use(corpus_id));
            st.execute();

            while (st.fetch()) {
                result.push_back(make_shared<Word>(doc));
            }
            return result;
        }

        shared_ptr<Word> get(const size_t &id) {
            shared_ptr<Word> word = make_shared<Word>();
            session << getConfig().get<string>("repository.getWord"), soci::into(*word), soci::use(id);
            return word;
        };

        shared_ptr<Word> get(const string &name) {
            shared_ptr<Word> word = make_shared<Word>();
            session << getConfig().get<string>("repository.getWordByName"), soci::into(*word), soci::use(name);
            if (!session.got_data()) {
                return shared_ptr<Word>(nullptr);
            }
            return word;
        };

        void insert(shared_ptr<Word> word) {
            soci::statement st = (session.prepare << getConfig().get<string>("repository.insertWord"), soci::use(*word));
            st.execute(false);
        };

        void update(shared_ptr<Word> word) {
            session.begin();
            session << getConfig().get<string>("repository.updateWord"), soci::use(*word);
            session.commit();
        };

        void remove(const size_t &id) {
            session.begin();
            session << getConfig().get<string>("repository.deleteWord"), soci::use(id);
            session.commit();
        };

        void remove(const string &name) {
            session.begin();
            session << getConfig().get<string>("repository.deleteWord"), soci::use(name);
            session.commit();
        };

        void deleteAll(const size_t &id) {
            session.begin();
            session << getConfig().get<string>("repository.deleteAllWords"), soci::use(id);
            session.commit();
        };

    };
};

#endif //JARVIS_KEYWORDREPOSITORY_HPP
