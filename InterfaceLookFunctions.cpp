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

void PrintIntro() {

    system ( "clear" );
    printf ("                     +@@@@@@@@@@@@@@@@@@@@.\n                    +                   .=\n                    +                .@ ..@\n                    +                =.    +\n                    +                @.    @\n                    *.                @@@@.\n                    @.                  @\n                   .@.                  @.. +@\n                   .@                  .@.\n                    #                   -\n                                       -\n                   :.                 .@.\n                   @                 @...@..\n                   @             ..@.     .@.\n                   @                        .\n                   @\n       .           @\n                   .   .      .. )");

    printf ( "\n\n");
    sleep ( 1 );

    system ( "figlet -f block \"Hangman\"" );
}

void PrintExitMessage () {

    //printing exit message
}