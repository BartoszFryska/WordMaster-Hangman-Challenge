#include <iostream>

class Word {

    private:
        int type;

    public:
        std::string hint;
        std::string guessWord;
        bool * ArrayOfPositionsGuessedCorrectly;

        void FillWord ( std::string wo, std::string hi, int ty) {

            guessWord = wo;
            hint = hi;
            type = ty;

            ArrayOfPositionsGuessedCorrectly = new bool [ guessWord.length() ];
            std::fill( ArrayOfPositionsGuessedCorrectly, ArrayOfPositionsGuessedCorrectly + guessWord.length(), false );
        }

        bool LetterIsInsideAWord ( char c ) {

            bool WasThereATrue = false;

            for ( int i = 0; i < guessWord.size(); i++ ) {

                if ( guessWord [ i ] == c ) {

                    ArrayOfPositionsGuessedCorrectly [ i ] = true;

                    WasThereATrue = true;
                }
            }

            return WasThereATrue;
        }

};

namespace GAME_PARAMETERS {

    int number_of_word_types;
    std::string * word_types_list;
    int * list_of_types_of_words_stored_in_a_file;

    bool InportWordTypes () {

        //inporting from the file
        return false;
    }

    bool InportListOfStoredWordTypes () {

        //inporting a list
        return false;
    }

    bool AddWordType () {

        //adding a word type
        return false;
    }

};


bool GenerateAWord ( Word &mistery, bool * ChosenTypes, int NumberOfTypes, std::string * WordTypeslist ) {

    // generate a word randomly by choosing a random number, checking list 
    mistery.FillWord ( "ANIA", "Najukochansza sziewczyna na swiecie", 1 );
    return true;
}

