#include <iostream>
#include <string>
#include <string.h>
#include <unistd.h>
#include <cstring>
#include <memory>
#include <stdexcept>
#include <array>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <fstream>

namespace FONT {

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

    void OutputACorrectLineOfACorrectCharacterInAFont ( char character, int line ) {

        if ( isdigit ( character ) ) {

            int digit = character - '0';

            std::cout << font_numbers [ digit ] [ line ];
        }

        else {

            if ( isalpha ( character ) ) {

                int which = character - 'A';

                std::cout << font_letters [ which ] [ line ];
            }

            else {

                std::cout << font_empty_space [ line ];
            }
        }

    }

    void PrintStringInSpecialFont ( std::string word ) {

        for ( int i = 0; i < word.length(); i ++ ) {

            word [ i ] = toupper ( word [ i ] );
        }

        for ( int line = 0; line < FontSizeUpward; line++ ) {

            for ( int j = 0; j < word.length(); j ++ ) {

                OutputACorrectLineOfACorrectCharacterInAFont ( word [ j ], line );
            }
            std::cout << "\n";
        }
    }

};

void PrintIntro() {

    system ( "clear" );
    printf ("                     +@@@@@@@@@@@@@@@@@@@@.\n                    +                   .=\n                    +                .@ ..@\n                    +                =.    +\n                    +                @.    @\n                    *.                @@@@.\n                    @.                  @\n                   .@.                  @.. +@\n                   .@                  .@.\n                    #                   -\n                                       -\n                   :.                 .@.\n                   @                 @...@..\n                   @             ..@.     .@.\n                   @                        .\n                   @\n       .           @\n                   .   .      .. )");

    printf ( "\n\n");
    sleep ( 1 );
    FONT::PrintStringInSpecialFont ( "HANGMAN" );
    sleep(1);

}

void PrintMenu() {

    //printing menu
}

void PrintExitMessage () {

    //printing exit message
}