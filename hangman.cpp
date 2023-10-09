#include <iostream>

#include "FunctionalityFunctions.cpp"

int main () {

    PrintIntro ();

    int OperationToPerform;

    while ( IsNotExit ( OperationToPerform ) ) {

        switch ( OperationToPerform ) { 

            case 1:
            Play ();
            break;

            case 2:
            Add();
            break;

            case 3:
            Settings();
            break;

            default:
            system("clear");
            printf ( "Unknown input, please try again" );
        }
    } 

    PrintExitMessage ();    
}       