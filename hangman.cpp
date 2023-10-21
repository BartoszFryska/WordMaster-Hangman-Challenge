#include <iostream>

#include "FunctionalityFunctions.cpp"

int main () {

    GAME_PARAMETERS::InporGameParameters();

    PrintIntro ();

    int OperationToPerform;
    int * TypesOfWordsInAList = new int [ GAME_PARAMETERS::number_of_words ]; 
    InportTypesOfWordsInAList ( TypesOfWordsInAList );

    while ( IsNotExit ( OperationToPerform ) ) {

        switch ( OperationToPerform ) { 

            case 1:
            Play ( TypesOfWordsInAList );
            break; 

            case 2: 
            Add();
            break;
 
            case 3:
            Settings();
            break;

            default:
            system("clear");
            break;
        }
    } 
 
    PrintExitMessage ();      
}       

/* plan to do:

    finish gameplay aspects -> manage files -> finish generator -> finished first product
*/