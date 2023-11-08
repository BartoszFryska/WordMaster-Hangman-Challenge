#include "wordGenerator.h"

using namespace std;

bool IsOneOfTheChosenTypes ( int number, bool * ChosenTypes, int * list_of_types_of_words_stored_in_a_file) {

    int *type = list_of_types_of_words_stored_in_a_file + number;

    return ChosenTypes [ *type ];
}

bool GenerateAWord ( Word *mistery, int NumberOfWordTypes, bool * ChosenTypes, int * list_of_types_of_words_stored_in_a_file ) {

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

            mistery->FillWord ( temp_guessword, temp_hint, list_of_types_of_words_stored_in_a_file [ temp ] );
            
            one.close();

            break;
        }
    }

    return true;
}

