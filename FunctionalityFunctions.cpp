#include <iostream>
#include <string>
#include "InterfaceLookFunctions.cpp"

void PrintWordInSpecialFont ( Word mistery ) {

        std::string s = "";

        for ( int i = 0; i < mistery.guessWord.size(); i++ ) {

            if ( *( mistery.ArrayOfPositionsGuessedCorrectly + i ) ) {

                    s += mistery.guessWord [ i ];
            }

            else {

                s += " ";
            }
        }

        FONT::PrintStringInSpecialFont ( s );
    }

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

bool ChooseTypeOfWords( bool * ChosenTypes ) {

    //outputing types
    //getting input, if 'exit', exitting
    //writing all types selected
    return false;
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

bool GameIsNotLost ( int NumberOfMisses ) {

    if ( NumberOfMisses >= 8 ) {

        return false;
    }

    return true;
}

char GetGameInput () {

    string input;
    getline ( cin, input );

    if ( isalpha( input [ 0 ] ) ) {

        return toupper ( input [ 0 ] );
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

    while ( GameIsNotLost ( NumberOfMisses ) ) {

        PrintGameScreen ( WasThatLetterChosen, NumberOfMisses, mistery );

        CurrentLetterChosen = GetGameInput ();

        if ( CurrentLetterChosen == 1 ) continue;

        if ( WasThatLetterChosen [ CurrentLetterChosen ] ) continue;

        WasThatLetterChosen [ CurrentLetterChosen ] ++ ;

        if ( !mistery.LetterIsInsideAWord( CurrentLetterChosen ) ) {

            NumberOfMisses++;
            WasThatLetterChosen [ CurrentLetterChosen ] ++;
        }
    }
}