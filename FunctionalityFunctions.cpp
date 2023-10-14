#include <iostream>
#include <string>
#include "InterfaceLookFunctions.cpp"

using namespace std;

void GameStart ( Word mistery );

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

bool ChooseTypeOfWords( bool * ChosenTypes ) {
    
    ChosenTypes = new bool [ GAME_PARAMETERS::number_of_word_types ];
    fill ( ChosenTypes, ChosenTypes + GAME_PARAMETERS::number_of_word_types, false );

    char c = 0;
    string temp;

    while ( c != '\n') {

        PrintWordTypesInChoosingScreen ( ChosenTypes ); 
        cout << "(Type \'q\' to exit, \'p\' or enter to proceed)\n\n";

        c = getchar();

        getline ( cin, temp );

        if ( c == 'q' ) {

            return false;
        }

        else if ( isdigit ( c ) ) {

            if ( c - '0' <= GAME_PARAMETERS::number_of_word_types ) {

                if ( *( ChosenTypes + ( c - '0' ) - 1 ) ) {

                     *( ChosenTypes + ( c - '0' ) - 1 ) = false;
                }

                else {

                     *( ChosenTypes + ( c - '0' ) - 1 ) = true;
                }
            }
        }

        else if ( c == '\n') {

            if ( IsThereNoTypeChosen ( ChosenTypes ) ) {

                c = 0;
            }
        }
        
    }

    if ( IsThereNoTypeChosen ( ChosenTypes ) ) {

        return false;
    }

    return true;
}

bool Play() {

    bool * ChosenTypes = new bool [ GAME_PARAMETERS::number_of_word_types ];

    if ( !ChooseTypeOfWords( ChosenTypes ) ) {

        return false;
    }

    Word mistery;

    GenerateAWord ( mistery, ChosenTypes, GAME_PARAMETERS::number_of_word_types, GAME_PARAMETERS::word_types_list );

    delete ChosenTypes;

    GameStart ( mistery );

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

bool GameIsNotLost ( char WasTheLetterChosen [ 26 ], int NumberOfMisses, Word mistery ) {

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

void GameStart ( Word mistery ) {

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

        if ( !mistery.LetterIsInsideAWord( CurrentLetterChosen ) ) {

            NumberOfMisses++;
            WasThatLetterChosen [ CurrentLetterChosen - 'A' ] ++;
        }

        else {

            if ( mistery.TheWordIsGuessed() ) {

                PrintGameScreen ( WasThatLetterChosen, NumberOfMisses, mistery, true );
                getchar();
                break;
            }
        }
    }
}