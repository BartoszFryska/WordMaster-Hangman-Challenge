#ifndef __FONTNAMESPACE_H__
#define __FONTNAMESPACE_H__

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */

#include <iostream>
#include "wordClass.h"

namespace FONT {

    namespace {
        
        const int FontSizeUpward = 6;

        std::string font_letters [ 26 ] [ FontSizeUpward ] = {

            {"  █████     "," ██   ██    "," ███████    "," ██   ██    "," ██   ██    ","─────────   "}, //letter A
            {" ██████     "," ██   ██    "," ██████     "," ██   ██    "," ██████     ","─────────   "}, //letter B
            {"  ██████    "," ██         "," ██         "," ██         ","  ██████    ","─────────   "}, //letter C
            {" ██████     "," ██   ██    "," ██   ██    "," ██   ██    "," ██████     ","─────────   "}, //letter D
            {" ███████    "," ██         "," █████      "," ██         "," ███████    ","─────────   "}, //letter E
            {" ███████    "," ██         "," █████      "," ██         "," ██         ","─────────   "}, //letter F
            {" ██████     ","██          ","██   ███    ","██    ██    "," ██████     ","─────────   "}, //letter G
            {" ██   ██    "," ██   ██    "," ███████    "," ██   ██    "," ██   ██    ","─────────   "}, //letter H
            {"    ██      ","    ██      ","    ██      ","    ██      ","    ██      ","─────────   "}, //letter I
            {"      ██    ","      ██    ","      ██    "," ██   ██    ","  █████     ","─────────   "}, //letter J
            {" ██   ██    "," ██  ██     "," █████      "," ██  ██     "," ██   ██    ","─────────   "}, //letter K
            {" ██         "," ██         "," ██         "," ██         "," ███████    ","─────────   "}, //letter L
            {"███    ███  ","████  ████  ","██ ████ ██  ","██  ██  ██  ","██      ██  ","─────────   "}, //letter M
            {"███    ██   ","████   ██   ","██ ██  ██   ","██  ██ ██   ","██   ████   ","─────────   "}, //letter N
            {"  ██████    "," ██    ██   "," ██    ██   "," ██    ██   ","  ██████    ","─────────   "}, //letter O
            {" ██████     "," ██   ██    "," ██████     "," ██         "," ██         ","─────────   "}, //letter P
            {"  ██████    "," ██    ██   "," ██    ██   "," ██ ▄▄ ██   ","  ██████    ","─────▀▀──   "}, //letter Q
            {" ██████     "," ██   ██    "," ██████     "," ██   ██    "," ██   ██    ","─────────   "}, //letter R
            {" ███████    "," ██         "," ███████    ","      ██    "," ███████    ","─────────   "}, //letter S
            {"████████    ","   ██       ","   ██       ","   ██       ","   ██       ","─────────   "}, //letter T
            {" ██    ██   "," ██    ██   "," ██    ██   "," ██    ██   ","  ██████    ","─────────   "}, //letter U
            {" ██    ██   "," ██    ██   "," ██    ██   ","  ██  ██    ","   ████     ","─────────   "}, //letter V
            {"██     ██   ","██     ██   ","██  █  ██   ","██ ███ ██   "," ███ ███    ","─────────   "}, //letter W
            {" ██   ██    ","  ██ ██     ","   ███      ","  ██ ██     "," ██   ██    ","─────────   "}, //letter X
            {" ██    ██   ","  ██  ██    ","   ████     ","    ██      ","    ██      ","─────────   "}, //letter Y
            {" ███████    ","    ███     ","   ███      ","  ███       "," ███████    ","─────────   "}  //letter Z
        };

        std::string font_numbers [ 10 ]; // Will add

        std::string font_empty_space [ FontSizeUpward ] = { "            ","            ","            ","            ","            ","─────────   " };
        std::string space [ FontSizeUpward ] = { "          ","          ","          ","          ","          ","          " };

    }

    /**
     * @brief outputs a line of a character passed as an input in a specially designed font; 
     * 
     * function prints a layer of a character which is supossed to be writen in a font, layer number form upward is determined bu the parameter 'line'; 
     * 
     * note: please input parameter line counting layers form 0, meaning 0 is the first layer etc.
     * 
     * @param[in] character character to output
     * @param[in] line number of a line
     * @return returns void
    */
    void OutputACorrectLineOfACorrectCharacterInAFont ( char character, int line );

    /**
     * @brief prints string in a font; 
     * 
     * prints a string in a special font going form the first layer to the bottom, outputing every character using a fuction 'OutputACorrectLineOfACorrectCharacterInAFont'
     * @param[in] word set of characters to write in a pecial font
     * @return returns void
    */
    void PrintStringInSpecialFont ( std::string word );

    /**
     * @brief prints a guessword form a class Word in a font; 
     * 
     * prints a guessword form a class Word in a font by putting it into function 'PrintStringInSpecialFont'
     * 
     * @param[in] mistery pointer to a member of a class Word
     * @return returns void
    */
    void PrintWordInSpecialFont ( Word * mistery );
};

#endif