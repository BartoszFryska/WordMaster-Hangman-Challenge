#include "../include/functionalityFunctions.h"
#include "../include/interfaceLookFunctions.h"
#include "../include/gameParameters.h"

using namespace std;

void Exit() {

    PrintExitMessage();

    delete [] GAME_PARAMETERS::word_types_list;
}

void InportTypesOfWordsInAList ( int * list ) {

        ifstream input2 ( "words" );

        string temp, temp2;

        int temp3;

        for ( int i = 0; i < GAME_PARAMETERS::number_of_words; i ++ ) {

            getline ( input2, temp );

            temp3 = 0;
            temp2.clear();

            for ( int j = 0; j < temp.size(); j ++ ) {

                if ( temp3 == 3 ) {

                    temp2.push_back ( temp [ j ] );
                }

                if ( temp [ j ] == '-') {

                    temp3 ++;
                }

                if ( temp3 == 2 ) {

                    temp3 ++;
                    j++;
                }
            }

            for ( int j = 0; j < GAME_PARAMETERS::number_of_words; j ++ ) {

                if ( GAME_PARAMETERS::word_types_list [ j ] == temp2 ) {

                    list [ i ] = j;

                    break;
                }
            }
        }

        input2.close();  
    }

void MakeInputUsable ( string &Input ) {

    int i = 0;

    for ( ; i < 20; i ++ ) {

        if ( isalnum(Input [ i ]) ) { Input [ i ] = tolower ( Input [ i ] ); i ++; break; }
    }

    if ( i == 20 ) { Input [ 0 ] = '\0'; return; }

    int j = i;

    for ( ; j < i + 20; j ++ ) {

        Input [ i ] = tolower ( Input [ i ] );

        if ( isblank ( Input [ j ] ) ) {

            return;
        }
    }

    string temp_str = "";

    temp_str.append ( Input.substr ( i - 1, j - i ) );

    Input.clear();

    Input.append ( temp_str );

    return;
}

bool IsNotExit ( int &OperationToPerform ) {

    PrintMenu ();

    string UserInput;

    getline ( cin, UserInput);

    MakeInputUsable ( UserInput );

    if ( UserInput == "exit" || UserInput == "quit" || UserInput == "4" || UserInput == "bye") {

        return false;
    }

    if (UserInput == "play" || UserInput == "1" || UserInput == "game" ) { OperationToPerform = 1; return true; }
    
    if ( UserInput == "add" || UserInput == "addword" || UserInput == "2" || UserInput == "addaword" ) { OperationToPerform = 2; return true; }

    if ( UserInput == "settings" || UserInput == "change" || UserInput == "3" ) { OperationToPerform = 3; return true; }

    OperationToPerform = -1; //default, input unknown

    return true;
}

bool IsThereNoTypeChosen ( bool * ChosenTypes ) {

    for ( int i = 0; i < GAME_PARAMETERS::number_of_word_types; i ++ ) {

        if ( ChosenTypes [ i ] )
            return false;
    }

    return true;
}

int GetInputInIntValue ( bool * ChosenTypes ) {

    string temp;
    char c;
    int temp_int;

    getline ( cin, temp );

    c = temp [ 0 ];

    if ( c == 'q' ) {

            return -1;
        }

    if ( isdigit ( c ) ) {

        temp_int = c - '0';

        c = temp [ 1 ];

        if ( isdigit ( c ) ) {

            if (  temp_int * 10 + (c - '0') <= GAME_PARAMETERS::number_of_word_types + 1 ) {

                return temp_int * 10 + (c - '0');
            }   
        }
    }

    if ( c - '0' <= GAME_PARAMETERS::number_of_word_types + 1) {

        return temp_int;
    }

    if ( c == '\n' ||  c == 'p') {

        return 0;
    }

    return -2;
}

bool isTheteAFalseInChosenOnes ( bool * ChosenTypes ) {

    for ( int i = 0; i < GAME_PARAMETERS::number_of_word_types; i ++  ) {

        if ( ! *( ChosenTypes + i ) ) {

            return true;
        }
    }

    return false;
}

bool ChooseTypeOfWords( bool * ChosenTypes ) {
    
    fill ( ChosenTypes, ChosenTypes + GAME_PARAMETERS::number_of_word_types, false );

    int temp_int = -2;

    do {

        PrintWordTypesInChoosingScreen ( ChosenTypes ); 

        temp_int = GetInputInIntValue ( ChosenTypes );
        

        if ( temp_int == -1 ) {

            return false;
        }

        if (  temp_int == GAME_PARAMETERS::number_of_word_types + 1 ) {

            if ( isTheteAFalseInChosenOnes ( ChosenTypes ) ) {

                for ( int i = 0; i < GAME_PARAMETERS::number_of_word_types; i++ ) {

                    *( ChosenTypes + i ) = true;
                }
            }

            else {

                for ( int i = 0; i < GAME_PARAMETERS::number_of_word_types; i++ ) {

                    *( ChosenTypes + i ) = false;
                }
            }

            continue;
        }


        if ( temp_int <= GAME_PARAMETERS::number_of_word_types ) {

            if ( *( ChosenTypes + temp_int - 1 ) ) {

                *( ChosenTypes + temp_int - 1 ) = false;
            }

            else {

                *( ChosenTypes + temp_int - 1 ) = true;
            }

            continue;
        }
            
        if ( temp_int == 0 ) {

            if ( IsThereNoTypeChosen ( ChosenTypes ) ) {

                temp_int = -2;
            }
        }

    } while ( temp_int );


    if ( IsThereNoTypeChosen ( ChosenTypes ) ) {

        return false;
    }

    return true;
}

bool Play( int * list_of_types_of_words_stored_in_a_file ) {

    bool * ChosenTypes = new bool [ GAME_PARAMETERS::number_of_word_types ];

    if ( !ChooseTypeOfWords( ChosenTypes ) ) {

        delete [] ChosenTypes;
        return false;
    }

    getchar();

    Word * mistery = new Word;

    GenerateAWord ( mistery, GAME_PARAMETERS::number_of_word_types, ChosenTypes, list_of_types_of_words_stored_in_a_file );
    
    delete [] ChosenTypes;

    GameStart ( mistery );

    mistery->DeleteWord();
    delete mistery;
    //play a game
    return true;
}

bool Add () {

    //add a word
    return false;
}

bool Settings () {


    //possibly changing size? idk what to set here
    return false;
}

bool GameIsNotLost ( char WasTheLetterChosen [ 26 ], int NumberOfMisses, Word * mistery ) {

    if ( NumberOfMisses >= 6 ) {
        
        PrintGameScreen ( WasTheLetterChosen, NumberOfMisses, mistery, false );
        getchar();
        return false;
    }

    return true;
}

char GetGameInput () {

    char c;
    c = getchar ();

    string input;
    getline ( cin, input );

    if ( isalpha( c ) ) {

        return toupper ( c );
        
    }

    else return 1;
}

void GameStart ( Word * mistery ) {

    //preparation for the game 

    char WasThatLetterChosen [ 26 ]; // state 0 represents a letter that was never chosen, 1 is a correct guess and 2 is a wrong guess
    fill( WasThatLetterChosen, WasThatLetterChosen + 26, 0 );
    int NumberOfMisses = 0;
    char CurrentLetterChosen;

    //gameplay

    while ( GameIsNotLost ( WasThatLetterChosen, NumberOfMisses, mistery ) ){

        PrintGameScreen ( WasThatLetterChosen, NumberOfMisses, mistery, false );

        CurrentLetterChosen = GetGameInput ();

        if ( CurrentLetterChosen == 1 ) continue;

        if ( WasThatLetterChosen [ CurrentLetterChosen - 'A' ] ) continue;

        WasThatLetterChosen [ CurrentLetterChosen - 'A' ] ++ ;

        if ( !mistery->LetterIsInsideAWord( CurrentLetterChosen ) ) {

            NumberOfMisses++;
            WasThatLetterChosen [ CurrentLetterChosen - 'A' ] ++;
        }

        else {

            if ( mistery->TheWordIsGuessed() ) {

                PrintGameScreen ( WasThatLetterChosen, NumberOfMisses, mistery, true );
                getchar();
                break;
            }
        }
    }
}