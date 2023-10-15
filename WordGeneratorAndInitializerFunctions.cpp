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

using namespace std;

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

    void InportTypesOfWordsInAList ( ) {

        ifstream input2 ( "words" );

        string temp, temp2;

        int temp3;

        for ( int i = 0; i < number_of_words; i ++ ) {

            getline ( input2, temp );

            temp3 = 0;

            for ( int j = 0; j < temp.size(); j ++ ) {

                if ( temp [ i ] == '-') {

                    temp3 ++;
                }

                if ( temp3 == 2 ) {

                    temp2.clear();

                    temp2 = temp.substr ( i + 2, temp.size() - i - 2 );

                    //cout << temp.substr ( i + 2, temp.size() - i - 2 ) << " ";

                    break;
                }
            }

            for ( int j = 0; j < number_of_word_types; j ++ ) {

                if ( word_types_list [ j ] == temp2 ) {

                    list_of_types_of_words_stored_in_a_file [ i ] = j;

                    break;
                }
            }
        }

        input2.close();  
    }

    bool InporGameParameters () {

        ifstream input ( "types" );

        input >> number_of_word_types;

        word_types_list = new string [ number_of_word_types ];

        for ( int i = 0; i < number_of_word_types; i ++ ) {

            input >> word_types_list [ i ];
        }

        input.close();

        ifstream input2 ( "words" );

        std::string temp;
        std::string temp2;
        int temp3 = 0;

        number_of_words = 0;

        while ( !input2.eof() ) {

            number_of_words ++;
            getline ( input2, temp );
        }

        int * list_of_types_of_words_stored_in_a_file = new int [number_of_words];

        input2.close();

        InportTypesOfWordsInAList ( );

        return true;
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

