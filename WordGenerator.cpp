#include <iostream>

class Word {

    private:
        int type;

    public:
        std::string hint;
        std::string guessWord;
        bool * ArrayOfPositionsGuessedCorrectly;

        void FillWord ( std::string wo, std::string hi, int ty) {

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

bool GenerateAWord ( Word &mistery, bool * ChosenTypes, int NumberOfTypes, std::string * WordTypeslist ) {

    // generate a word randomly by choosing a random number and 
    return false;
}