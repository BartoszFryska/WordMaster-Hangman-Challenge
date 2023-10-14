#include <iostream>
#include <string>
#include <string.h>
#include <unistd.h>
#include <cstring>
#include <memory>
#include <stdexcept>
#include <array>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <fstream>

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

        bool TheWordIsGuessed () {

            for ( int i = 0; i < guessWord.size(); i++ ) {

                if ( ! (*(ArrayOfPositionsGuessedCorrectly + i)) ) {

                    return false;
                }
            }

            return true;
        }

};

namespace GAME_PARAMETERS {

    int number_of_word_types;
    std::string * word_types_list;
    int * list_of_types_of_words_stored_in_a_file;
    int number_of_words;

    bool InporGameParameters () {

        ifstream input ( "types" );

        input >> number_of_word_types;

        word_types_list = new string [ number_of_word_types ];

        for ( int i = 0; i < number_of_word_types; i ++ ) {

            input >> word_types_list [ i ];
        }

        input.close();

        ifstream input ( "words" );

        std::string temp;

        number_of_words = 0;

        while ( !input.eof() ) {

            number_of_words ++;
            getline ( input, temp );
        }
    }

    bool InportListOfStoredWordTypes () {

        //inporting a list
        return false;
    }

    bool AddWordType () {

        //adding a word type
        return false;
    }

    bool AddAWord () {

        return false;
    }

};

bool GenerateAWord ( Word &mistery, bool * ChosenTypes, int NumberOfTypes, std::string * WordTypeslist ) {

    // generate a word randomly by choosing a random number, checking list 
    mistery.FillWord ( "ANIA", "Najukochansza sziewczyna na swiecie", 1 );
    return true;
}

