#include <iostream>
#include <string>
#include "InterfaceLookFunctions.cpp"

class Word {

    private:
        std::string hint;
        int type;

    public:
        std::string guessWord;
        bool * ArrayOfPositionsGuessedCorrectly;

        Word ( std::string wo, std::string hi, int ty) {

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
    return false;
}

bool Play() {

    if ( !ChooseTypeOfWords() ) {

        return false;
    }

    //generate a word

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