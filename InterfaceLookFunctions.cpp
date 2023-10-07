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
#include "FunctionalityFunctions.cpp"

#define SPECIAL_FONT_SIZE_UPWARD 6
#define SPECIAL_FONT_SIZE_HORIZONTAL 27

namespace FONT {

    const int FontSizeUpward = 6;
    const int FontSizeHorizontal = 27;

    string font_letter [ 26 ] = {

        "  █████      ██   ██     ███████     ██   ██     ██   ██    ─────────   ", //letter A
        " ██████      ██   ██     ██████      ██   ██     ██████     ─────────   ", //letter B
        "  ██████     ██          ██          ██           ██████    ─────────   ", //letter C
        " ██████      ██   ██     ██   ██     ██   ██     ██████     ─────────   ", //letter D
        " ███████     ██          █████       ██          ███████    ─────────   ", //letter E
        " ███████     ██          █████       ██          ██         ─────────   ", //letter F
        " ██████     ██          ██   ███    ██    ██     ██████     ─────────   ", //letter G
        " ██   ██     ██   ██     ███████     ██   ██     ██   ██    ─────────   ", //letter H
        "    ██          ██          ██          ██          ██      ─────────   ", //letter I
        "      ██          ██          ██     ██   ██      █████     ─────────   ", //letter J
        " ██   ██     ██  ██      █████       ██  ██      ██   ██    ─────────   ", //letter K
        " ██          ██          ██          ██          ███████    ─────────   ", //letter L
        "███    ███  ████  ████  ██ ████ ██  ██  ██  ██  ██      ██  ─────────   ", //letter M
        "███    ██   ████   ██   ██ ██  ██   ██  ██ ██   ██   ████   ─────────   ", //letter N
        "  ██████     ██    ██    ██    ██    ██    ██     ██████    ─────────   ", //letter O
        " ██████      ██   ██     ██████      ██          ██         ─────────   ", //letter P
        "  ██████     ██    ██    ██    ██    ██ ▄▄ ██     ██████    ─────▀▀──   ", //letter Q
        " ██████      ██   ██     ██████      ██   ██     ██   ██    ─────────   ", //letter R
        " ███████     ██          ███████          ██     ███████    ─────────   ", //letter S
        "████████       ██          ██          ██          ██       ─────────   ", //letter T
        " ██    ██    ██    ██    ██    ██    ██    ██     ██████    ─────────   ", //letter U
        " ██    ██    ██    ██    ██    ██     ██  ██       ████     ─────────   ", //letter V
        "██     ██   ██     ██   ██  █  ██   ██ ███ ██    ███ ███    ─────────   ", //letter W
        " ██   ██      ██ ██        ███        ██ ██      ██   ██    ─────────   ", //letter X
        " ██    ██     ██  ██       ████         ██          ██      ─────────   ", //letter Y
        " ███████        ███        ███        ███        ███████    ─────────   "  //letter Z
    };

    string font_numbers [ 10 ];

    string font_empty_space = "                                                            ─────────   ";

    void OutputACorrectLineOfACorrectCharacterInAFont ( char letter, int line ) {

    

    
    }

    void PrintStringInSpecialFont ( std::string word ) {

        for ( int i = 0; i < word.size())
    }
};

void OutputACorrectLineOfACorrectCharacterInAFont ( char letter, int line ) {

    

    
}

void PrintStringInSpecialFont ( std::string word ) {

    for ( int i = 0; i < word.size())
}

void PrintWordInSpecialFont ( Word mistery ) {

    string s = "";

    for ( int i = 0; i < mistery.guessWord.size(); i++ ) {

        if ( *( mistery.ArrayOfPositionsGuessedCorrectly + i ) ) {

            s += mistery.guessWord [ i ];
        }

        else {

            s += " ";
        }
    }

    PrintStringInSpecialFont ( s );
}

void PrintIntro() {

    system ( "clear" );
    printf ("                     +@@@@@@@@@@@@@@@@@@@@.\n                    +                   .=\n                    +                .@ ..@\n                    +                =.    +\n                    +                @.    @\n                    *.                @@@@.\n                    @.                  @\n                   .@.                  @.. +@\n                   .@                  .@.\n                    #                   -\n                                       -\n                   :.                 .@.\n                   @                 @...@..\n                   @             ..@.     .@.\n                   @                        .\n                   @\n       .           @\n                   .   .      .. )");

    printf ( "\n\n");
    sleep ( 1 );

}

void PrintMenu() {

    //printing menu
}

void PrintExitMessage () {

    //printing exit message
}