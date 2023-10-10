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
#include "WordGeneratorAndInitializerFunctions.cpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */

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

void PrintGameScreen ( char WasTheLetterChosen [ 26 ], int NumberOfMisses, Word mistery ) {

        switch ( NumberOfMisses ) {

            case 0:
            printf ( "")
        }
}



/*
-----------------------



                                                   ____    _   _    _____    ____     ____  
                                                  / ___|  | | | |  | ____|  / ___|   / ___| 
                                                 | |  _   | | | |  |  _|    \___ \   \___ \ 
                                                 | |_| |  | | | |  | |___    ___) |   ___) |
                                                  \____|   \___/   |_____|  |____/   |____/ 



                                              A B C D E F G H I J K L M N O P 1 R S T U V W X Y Z










               


 ---------------------                                                                                       



                         *   *                     ____    _   _    _____    ____     ____  
                      *         *                 / ___|  | | | |  | ____|  / ___|   / ___| 
                     *           *               | |  _   | | | |  |  _|    \___ \   \___ \ 
                     *           *               | |_| |  | | | |  | |___    ___) |   ___) |
                      *         *                 \____|   \___/   |_____|  |____/   |____/ 
                         *   *
                                                                                                                             
                                                                                                                             
                                              A B C D E F G H I J K L M N O P 1 R S T U V W X Y Z
                                                                                        
                                                                                        
                                                                                                                                                                                    
                           
                                                                                    
                                                                                      
                                                                               
                                                                          
                       
               
               
                
 
 ---------------------                                                                                       
                                                                      
                                                                                      
                                                                                       
                         *   *                     ____    _   _    _____    ____     ____           
                      *         *                 / ___|  | | | |  | ____|  / ___|   / ___|        
                     *           *               | |  _   | | | |  |  _|    \___ \   \___ \      
                     *           *               | |_| |  | | | |  | |___    ___) |   ___) | 
                      *         *                 \____|   \___/   |_____|  |____/   |____/      
                         *   *                                                              
                           |                                                                                                  
                           |                                                                                                  
                           |                  A B C D E F G H I J K L M N O P 1 R S T U V W X Y Z
                           |                                                             
                           |                                                             
                           |                                                                                                                                                         
                           |
                           |                                                             
                                                                                      
                                                                               
                                                                          
                       
               
               
                
 
----------------------------                                                                                       
                                                                      
                                                                                      
                                                                                       
                         *   *                     ____    _   _    _____    ____     ____           
                      *         *                 / ___|  | | | |  | ____|  / ___|   / ___|        
                     *           *               | |  _   | | | |  |  _|    \___ \   \___ \      
                     *           *               | |_| |  | | | |  | |___    ___) |   ___) | 
                      *         *                 \____|   \___/   |_____|  |____/   |____/      
                         *   *                                                              
                           |                                                                                                  
                           |                                                                                                  
                           |                  A B C D E F G H I J K L M N O P 1 R S T U V W X Y Z
                    ───────┼───────                                                             
                           |                                                             
                           |                                                                                                                                                         
                           |
                           |                                                             
                                                                                      
                                                                               
                                                                          
                       
               
               
                
     
--------------                                                             
                                                                      
                                                                                      
                                                                                       
                         *   *                     ____    _   _    _____    ____     ____   
                      *         *                 / ___|  | | | |  | ____|  / ___|   / ___| 
                     *           *               | |  _   | | | |  |  _|    \___ \   \___ \ 
                     *           *               | |_| |  | | | |  | |___    ___) |   ___) | 
                      *         *                 \____|   \___/   |_____|  |____/   |____/ 
                         *   * 
                           | 
                           |
                           |                  A B C D E F G H I J K L M N O P 1 R S T U V W X Y Z
                    ───────┼───────                                                             
                           |                                                             
                           |                                                                                                                                                         
                           |
                           |                                                             
                          /                                                              
                         /                                                              
                        /                                                               
                       /       
               
               
                

-----
                           █                                                              
                           █                                                           
                           █                                                            
                         *   *                     ____    _   _    _____    ____     ____           
                      *         *                 / ___|  | | | |  | ____|  / ___|   / ___|        
                     *           *               | |  _   | | | |  |  _|    \___ \   \___ \      
                     *           *               | |_| |  | | | |  | |___    ___) |   ___) | 
                      *         *                 \____|   \___/   |_____|  |____/   |____/                                                           
                         *   *                                                              
                           |                                                                                                  
                           |                                                                                                  
                           |                  A B C D E F G H I J K L M N O P 1 R S T U V W X Y Z
                    ───────┼───────                                                             
                           |                                                             
                           |                                                                                                                                                         
                           |
                           |                                                             
                          / \                                                             
                         /   \                                                           
                        /     \                                                          
                       /       \
               
               
                
              
-----
           ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█                                                              
                           █                                                           
                           █                                                            
                         *   *                     ____    _   _    _____    ____     ____           
                      *         *                 / ___|  | | | |  | ____|  / ___|   / ___|        
                     *           *               | |  _   | | | |  |  _|    \___ \   \___ \      
                     *           *               | |_| |  | | | |  | |___    ___) |   ___) | 
                      *         *                 \____|   \___/   |_____|  |____/   |____/   
                         *   *                                                              
                           |                                                                                                  
                           |                                                                                                  
                           |                                                             
                    ───────┼───────                                                             
                           |                                                             
                           |                                                                                                                                                         
                           |
                           |                                                             
                          / \                                                             
                         /   \                                                           
                        /     \                                                          
                       /       \
               
               
                
        
==========
          █▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█                                                              
          █                █                                                           
          █                █                                                            
          █              *   *                     ____    _                      
          █           *         *                 / ___|  | | | |  | ____|  / ___|   / ___|  
          █          *   X   X   *               | |  _   | | | |  |  _|    \___ \   \___ \   
          █          *           *               | |_| |  | | | |  | |___    ___) |   ___) | 
          █           *    ◠    *                 \____|   \___/   |_____|  |____/   |____/   
          █              *   *                                                              
          █                |                                                                                                  
          █                |                                                                                                  
          █                |                                                             
          █         ───────┼───────                                                             
          █                |                                                             
          █                |                                                                                                                                                        
          █                |
          █                |                         A B C D E F G H I J K L M N O P 1 R S T U V W X Y Z                                        
          █               / \                                                             
          █              /   \                                                           
          █             /     \                                                          
          █            /       \
          █
          █
          █ 
   ▄▄▄▄▄▄▄█▄▄▄▄▄▄▄

*/