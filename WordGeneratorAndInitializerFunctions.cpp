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
    int number_of_words;

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

        //InportTypesOfWordsInAList ( list_of_types_of_words_stored_in_a_file );

        return true;
    }

    bool AddWordType () {

        //adding a word type
        return false;
    }

    bool AddAWord () {

        return false;
    }

};

bool IsOneOfTheChosenTypes ( int number, bool * ChosenTypes, int * list_of_types_of_words_stored_in_a_file) {

    int *type = list_of_types_of_words_stored_in_a_file + number;

    return ChosenTypes [ *type ];
}

bool GenerateAWord ( Word &mistery, int NumberOfWordTypes, bool * ChosenTypes, int * list_of_types_of_words_stored_in_a_file ) {

    // generate a word randomly by choosing a random number, checking list 
    system ( "clear" );
    cout << "Generating..";
    srand( time ( NULL ) );

    int temp;
    string temp_line;
    string temp_guessword = "";
    string temp_hint = "";
    string cha;
    
    while ( true ) {

        temp = rand() % GAME_PARAMETERS::number_of_words;

        //cout << temp << " ";
        //getchar();

        if ( IsOneOfTheChosenTypes ( temp, ChosenTypes, list_of_types_of_words_stored_in_a_file) ) {

            ifstream one ("words");


            for ( int i = 0; i < temp; i++ ) {

                getline ( one, temp_line );
            }

            one >> temp_guessword; //getting in guessword
            one >> cha; //getting in a separator
            one >> cha; //getting another word

            while ( cha != "-" ) {

                temp_hint += cha;
                temp_hint += " ";

                one >> cha;
            }

            mistery.FillWord ( temp_guessword, temp_hint, list_of_types_of_words_stored_in_a_file [ temp ] );
            
            one.close();

            break;
        }
    }

    return true;
}

