#include <iostream>
#include <string>

using namespace std;

class Word {

    private:
        string hint;
        int type;

    public:
        string guessWord;
        bool * ArrayOfPositionsGuessedCorrectly;

        Word ( string wo, string hi, int ty) {

            guessWord = wo;
            hint = hi;
            type = ty;

            ArrayOfPositionsGuessedCorrectly = new bool [ guessWord.length() ];
            fill( ArrayOfPositionsGuessedCorrectly, ArrayOfPositionsGuessedCorrectly + guessWord.length(), false );
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

    if ( UserInput == "exit" || UserInput == "4" || UserInput == "bye") {

        return false;
    }

    if (UserInput == "play" || UserInput == "1" || UserInput == "game" ) { OperationToPerform = 1; return true; }
    
    if ( UserInput == "add" || UserInput == "addword" || UserInput == "2" || UserInput == "addaword" ) { OperationToPerform = 2; return true; }

    if ( UserInput == "settings" || UserInput == "change" || UserInput == "3" ) { OperationToPerform = 3; return true; }

    OperationToPerform = -1; //default, input unknown

    return true;
}

bool ChooseTypeOfWords() {

    //outputing types
    //getting input, if 'exit', exitting
    //writing all types selected
}

bool Play() {

    if ( !ChooseTypeOfWords() ) {

        return false;
    }

    //generate a word

    //play a game
}

bool Add () {

    //add a word
}

bool Settings () {

    //possibly changing size? idk what to set here
}