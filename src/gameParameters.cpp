#include "../include/gameParameters.h"

bool GAME_PARAMETERS::InporGameParameters () {

    ifstream input ( "types" );

    number_of_word_types = 0;

    std::string temp;

    while ( !input.eof() ) {

        input >> temp;
        number_of_word_types++;
    }

    input.close();
    input.open ( "types" );

    word_types_list = new string [ number_of_word_types ];

    for ( int i = 0; i < number_of_word_types; i ++ ) {

        input >> word_types_list [ i ];
    }

    input.close();

    ifstream input2 ( "words" );

    std::string temp2;
    int temp3 = 0;

    number_of_words = 0;

    while ( !input2.eof() ) {

        number_of_words ++;
        getline ( input2, temp );
    }

    int * list_of_types_of_words_stored_in_a_file = new int [number_of_words];

    input2.close();

    return true;
}

    bool GAME_PARAMETERS::AddWordType () {

        //adding a word type
        return false;
    }

    bool GAME_PARAMETERS::AddAWord () {

        return false;
    }