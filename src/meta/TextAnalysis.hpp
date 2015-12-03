//
// Created by walter on 26/11/15.
//

#ifndef JARVIS_TEXTANALYSIS_HPP
#define JARVIS_TEXTANALYSIS_HPP

#include <string>

namespace domain {

    using std::string;

    class TextAnalysis {
    public:

         TextAnalysis(string& text) {
             original = text;
         }
        virtual ~TextAnalysis(){};

        virtual void run(){

        }

    private:
        string original;
        string withouStopwords;
        string stemmed;
    };


}

#endif //JARVIS_TEXTANALYSIS_HPP
