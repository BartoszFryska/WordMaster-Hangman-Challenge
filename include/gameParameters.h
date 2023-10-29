#ifndef __GAMEPARAMETERS_H__
#define __GAMEPARAMETERS_H__

#include <iostream> 
#include <fstream>

namespace GAME_PARAMETERS {

    int number_of_word_types;
    std::string * word_types_list;
    int number_of_words;

    /**
     * @brief inports all of the game parameters form files 'types' and 'words'
     * 
     * @return returns true if all went well, false if there has been a problem
    */
    bool InporGameParameters ();

    /**
     * @brief adds a word type **TO BE MADE**
    */
    bool AddWordType ();

    /**
     * @brief adds a word **TO BE MADE**
    */
    bool AddAWord ();

};

#endif