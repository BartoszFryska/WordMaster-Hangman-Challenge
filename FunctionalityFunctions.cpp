#include <iostream>
#include <string>

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