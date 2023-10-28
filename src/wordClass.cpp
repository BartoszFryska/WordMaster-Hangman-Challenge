#include <iostream>

#include "../include/wordClass.h"

void Word::FillWord ( std::string wo, std::string hi, int ty) {

        guessWord = wo;
        hint = hi;
        type = ty;

        ArrayOfPositionsGuessedCorrectly = new bool [ guessWord.length() ];
        std::fill( ArrayOfPositionsGuessedCorrectly, ArrayOfPositionsGuessedCorrectly + guessWord.length(), false );
}

void Word::DeleteWord () {

    guessWord = "";
    hint = "";
    type = 0;

    delete [] ArrayOfPositionsGuessedCorrectly ;
}

bool Word::LetterIsInsideAWord ( char c ) {

    bool WasThereATrue = false;

    for ( int i = 0; i < guessWord.size(); i++ ) {

        if ( guessWord [ i ] == c ) {

            ArrayOfPositionsGuessedCorrectly [ i ] = true;

            WasThereATrue = true;
        }
    }

    return WasThereATrue;
}

bool Word::TheWordIsGuessed () {

    for ( int i = 0; i < guessWord.size(); i++ ) {

        if ( ! (*(ArrayOfPositionsGuessedCorrectly + i)) ) {

            return false;
        }
    }

    return true;
}