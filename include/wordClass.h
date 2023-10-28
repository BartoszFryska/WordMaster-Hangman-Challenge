#ifndef __WORDCLASS_H__
#define __WORDCLASS_H__

class Word {

    private:
        int type;

    public:
        std::string hint;
        std::string guessWord;
        bool * ArrayOfPositionsGuessedCorrectly;

        /**
         * @brief function fills the word with 'word' as 'guessword', 'sentence' as 'hint' and 'number' as number 'type'
         * 
         * @param string guessword to fill
         * @param string hint to fill
         * @param int number of a type, which that guessword is
         * @return function returns void
        */
        void FillWord ( std::string word, std::string sentence, int number );

        /**
         * @brief function deletes the word by deleting all of the parameters and deallocating memory
         * 
         * @return function returns void
        */
        void DeleteWord ();

        /**
         * @brief function checkes if letter was inside a word
         * 
         * @param char letter to check
         * @return function returns true if letter was inside a word and false if it was not
        */
        bool LetterIsInsideAWord ( char c );


        /**
         * @brief function checkes if the word is guessed
         * 
         * @return function returns true if the word is guessed and false if it is not
        */
        bool TheWordIsGuessed ();
};



#endif