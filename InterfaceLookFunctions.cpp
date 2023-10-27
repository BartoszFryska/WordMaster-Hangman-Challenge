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
    std::string space [ FontSizeUpward ] = { "          ","          ","          ","          ","          ","          " };

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

                if ( character == 1 ) {

                   std::cout << font_empty_space [ line ]; 
                }
                
                else {

                    std::cout << space [ line ];
                }
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

void PrintWordInSpecialFont ( Word * mistery ) {

        std::string s = "";

        for ( int i = 0; i < mistery->guessWord.size(); i++ ) {

            if ( *( mistery->ArrayOfPositionsGuessedCorrectly + i ) || mistery->guessWord [ i ] == ' ' ) {

                    s.push_back(mistery->guessWord [ i ]);
            }

            else {

                s.push_back ( 1 );
            }
        }

        FONT::PrintStringInSpecialFont ( s );
    }

void PrintIntro() {

    system ( "clear" );
    printf ("                     +@@@@@@@@@@@@@@@@@@@@.\n                    +                   .=\n                    +                .@ ..@\n                    +                =.    +\n                    +                @.    @\n                    *.                @@@@.\n                    @.                  @\n                   .@.                  @.. +@\n                   .@                  .@.\n                    #                   -\n                                       -\n                   :.                 .@.\n                   @                 @...@..\n                   @             ..@.     .@.\n                   @                        .\n                   @\n       .           @\n                   .   .      .. )");

    printf ( "\n\n");
    sleep ( 1 );
    FONT::PrintStringInSpecialFont ( "HANGMAN" );
    sleep(1);

}

void PrintMenu() {

    system ( "clear" );

    FONT::PrintStringInSpecialFont ( "HANGMAN");
    printf ("\n\n");

    printf ( "\t\t1. Play\n");
    printf ( "\t\t2. Add a word //not functioning\n");
    printf ( "\t\t3. Settings //not functioning\n");
    printf ("\t\t4. Exit\n" );
    printf ( "\n" );
}

void PrintExitMessage () {

    system ( "clear" );

    FONT::PrintStringInSpecialFont ( "Bye" );

    sleep ( 1 );
}

void PrintWordTypesInChoosingScreen ( bool * ChosenTypes ) {
    
    system ( "clear" );
    
    std::cout << "Please choose types of guesswords :\n";

    for ( int i = 0; i < GAME_PARAMETERS::number_of_word_types; i++ ) {

        if ( ChosenTypes [ i ] ) {

            std::cout << GREEN << i + 1 << ". " << GAME_PARAMETERS::word_types_list [ i ] << RESET;
        }

        else {
            std::cout << RED << i + 1 << ". " << GAME_PARAMETERS::word_types_list [ i ] << RESET;
        }

        if ( i % 4 == 3 ) {

            std::cout << '\n';
        }

        else {

            std::cout << "\t";
        }
    }

    std::cout <<  GAME_PARAMETERS::number_of_word_types + 1 << ". Select All";

    std::cout << "\n\n";

    std::cout << "(Type \'q\' to exit, \'p\' or enter to proceed)\n\n";
}

void PrintLettersInColours( char WasTheLetterChosen [ 26 ] ) {

    for ( int i = 0; i < 26; i ++ ) {

        switch ( (int) WasTheLetterChosen [ i ] ) {

            case 0:
            std::cout << (char) (i + 'A') << " ";
            break;

            case 1:
            std::cout << GREEN << (char) (i + 'A') << RESET << " ";
            break;

            case 2:
            std::cout << RED << (char) (i + 'A') << RESET << " ";
            break;
        }
    }

    std::cout << '\n';
}

void PrintHint ( std::string hint  ) {

    printf ( "Hint: " );

    for ( int i = 0; i < hint.size(); i++ ) {

        if ( (i + 7) % 105 == 0 ) printf ( "\n" );
        printf ( "%c", hint [ i ] );
    }
    printf ("\n");
}

void PrintGameScreenComponentsSeparator () {

    printf ( "--------------------------------------------------------------------------------------------------------\n" );
}

void PrintGameScreen ( char WasTheLetterChosen [ 26 ], int NumberOfMisses, Word * mistery, bool IsTheWordGuessed ) {

        system ( "clear" );

        switch ( NumberOfMisses ) { //first half (to chosen letter indicator)

            case 0:
            printf ( "\n");
            printf ( "\n");
            printf ( "\n");
            printf( "                                                   ____    _   _    _____    ____     ____  \n");
            printf ("                                                  / ___|  | | | |  | ____|  / ___|   / ___| \n");
            printf ("                                                 | |  _   | | | |  |  _|    \\___ \\   \\___ \\ \n");
            printf ("                                                 | |_| |  | | | |  | |___    ___) |   ___) |\n");
            printf ("                                                  \\____|   \\___/   |_____|  |____/   |____/ \n");
            printf ("\n");
            printf ( "\n");
            printf ( "\n");
            printf ("                                              ");
            break;

            case 1:
            printf ("\n");
            printf ("\n");
            printf ("\n");
            printf ("                         *   *                     ____    _   _    _____    ____     ____  \n");
            printf ("                      *         *                 / ___|  | | | |  | ____|  / ___|   / ___| \n");
            printf ("                     *           *               | |  _   | | | |  |  _|    \\___ \\   \\___ \\ \n");
            printf ("                     *           *               | |_| |  | | | |  | |___    ___) |   ___) |\n");
            printf ("                      *         *                 \\____|   \\___/   |_____|  |____/   |____/ \n");
            printf ("                         *   *\n");
            printf ("\n");
            printf ("\n");
            printf ("                                              ");
            break;

            case 2:
            printf ("\n");
            printf ("\n");
            printf ("\n");
            printf ("                         *   *                     ____    _   _    _____    ____     ____  \n");
            printf ("                      *         *                 / ___|  | | | |  | ____|  / ___|   / ___| \n");
            printf ("                     *           *               | |  _   | | | |  |  _|    \\___ \\   \\___ \\ \n");
            printf ("                     *           *               | |_| |  | | | |  | |___    ___) |   ___) |\n");
            printf ("                      *         *                 \\____|   \\___/   |_____|  |____/   |____/ \n");
            printf ("                         *   *\n");
            printf ("                           |\n");
            printf ("                           |\n");
            printf ("                           |                  ");
            break;

            case 3:
            printf ("\n");
            printf ("\n");
            printf ("\n");
            printf ("                         *   *                     ____    _   _    _____    ____     ____  \n");
            printf ("                      *         *                 / ___|  | | | |  | ____|  / ___|   / ___| \n");
            printf ("                     *           *               | |  _   | | | |  |  _|    \\___ \\   \\___ \\ \n");
            printf ("                     *           *               | |_| |  | | | |  | |___    ___) |   ___) |\n");
            printf ("                      *         *                 \\____|   \\___/   |_____|  |____/   |____/ \n");
            printf ("                         *   *\n");
            printf ("                           |\n");
            printf ("                           |\n");
            printf ("                           |                  ");
            break;

            case 4:
            printf ("                           █\n");
            printf ("                           █\n");
            printf ("                           █\n");
            printf ("                         *   *                     ____    _   _    _____    ____     ____  \n");
            printf ("                      *         *                 / ___|  | | | |  | ____|  / ___|   / ___| \n");
            printf ("                     *           *               | |  _   | | | |  |  _|    \\___ \\   \\___ \\ \n");
            printf ("                     *           *               | |_| |  | | | |  | |___    ___) |   ___) |\n");
            printf ("                      *         *                 \\____|   \\___/   |_____|  |____/   |____/ \n");
            printf ("                         *   *\n");
            printf ("                           |\n");
            printf ("                           |\n");
            printf ("                           |                  ");
            break;

            case 5:
            printf ("           ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n");
            printf ("                           █\n");
            printf ("                           █\n");
            printf ("                         *   *                     ____    _   _    _____    ____     ____  \n");
            printf ("                      *         *                 / ___|  | | | |  | ____|  / ___|   / ___| \n");
            printf ("                     *           *               | |  _   | | | |  |  _|    \\___ \\   \\___ \\ \n");
            printf ("                     *           *               | |_| |  | | | |  | |___    ___) |   ___) |\n");
            printf ("                      *         *                 \\____|   \\___/   |_____|  |____/   |____/ \n");
            printf ("                         *   *\n");
            printf ("                           |\n");
            printf ("                           |\n");
            printf ("                           |                  ");
            break;

            case 6:
            printf ("          █▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n");
            printf ("          █                █\n");
            printf ("          █                █\n");
            printf ("          █              *   *                       ____       _       __  __    _____  \n");
            printf ("          █           *         *                   / ___|     / \\     |  \\/  |  | ____| \n");
            printf ("          █          *   X   X   *                 | |  _     / _ \\    | |\\/| |  |  _|   \n");
            printf ("          █          *           *                 | |_| |   / ___ \\   | |  | |  | |___  \n");
            printf ("          █           *    ◠    *                  \\____|  /_/   \\_\\  |_|  |_|  |_____|\n");
            printf ("          █              *   *                        ___    __     __   _____    ____   \n");
            printf ("          █                |                         / _ \\   \\ \\   / /  | ____|  |  _ \\  \n");
            printf ("          █                |                        | | | |   \\ \\ / /   |  _|    | |_) | \n");
            printf ("          █                |                        | |_| |    \\ V /    | |___   |  _ <  \n");
            printf ("          █         ───────┼───────                  \\___/      \\_/     |_____|  |_| \\_\\ \n");
            printf ("          █                |\n");
            printf ("          █                |\n");
            printf ("          █                |\n");
            printf ("          █                |                  ");
            break;
        }

        PrintLettersInColours( WasTheLetterChosen );

        switch ( NumberOfMisses ) { //second half

            case 0:
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            break;

            case 1:
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            break;

            case 2:
            printf ( "                           |\n" );
            printf ( "                           |\n" );
            printf ( "                           |\n" );
            printf ( "                           |\n" );
            printf ( "                           |\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            break;

            case 3:
            printf ( "                    ───────┼───────\n" );
            printf ( "                           |\n" );
            printf ( "                           |\n" );
            printf ( "                           |\n" );
            printf ( "                           |\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            break;

            case 4:
            printf ( "                    ───────┼───────\n" );
            printf ( "                           |\n" );
            printf ( "                           |\n" );
            printf ( "                           |\n" );
            printf ( "                           |\n" );
            printf ( "                          /\n" );
            printf ( "                         /\n" );
            printf ( "                        /\n" );
            printf ( "                       /\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            break;

            case 5:
            printf ( "                    ───────┼───────\n" );
            printf ( "                           |\n" );
            printf ( "                           |\n" );
            printf ( "                           |\n" );
            printf ( "                           |\n" );
            printf ( "                          / \\ \n" );
            printf ( "                         /   \\ \n" );
            printf ( "                        /     \\ \n" );
            printf ( "                       /       \\ \n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            printf ( "\n" );
            break;

            case 6:
            printf ( "          █               / \\\n" );
            printf ( "          █              /   \\\n" );
            printf ( "          █             /     \\\n" );
            printf ( "          █            /       \\\n" );
            printf ( "          █\n" );
            printf ( "          █\n" );
            printf ( "          █\n" );
            printf ( "   ▄▄▄▄▄▄▄█▄▄▄▄▄▄▄\n" );
            break;
        }

        printf ( "\n" );

        PrintGameScreenComponentsSeparator ();

        PrintHint ( mistery->hint );

        PrintGameScreenComponentsSeparator ();

        printf ( "\n\n");

        PrintWordInSpecialFont ( mistery );

        if ( NumberOfMisses < 6 ) {

            if ( IsTheWordGuessed ) printf ( "Congratulations! You won! To continue enter any character: ");
            
            else printf ( "Your guess: ");

        }
        else printf ( "To continue enter any character: ");
}


/*

          █▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█                                                              
          █                █                                                           
          █                █                                                            
          █              *   *                       ____       _       __  __    _____              
          █           *         *                   / ___|     / \     |  \/  |  | ____| 
          █          *   X   X   *                 | |  _     / _ \    | |\/| |  |  _|   
          █          *           *                 | |_| |   / ___ \   | |  | |  | |___  
          █           *    ◠    *                   \____|  /_/   \_\  |_|  |_|  |_____|
          █              *   *                        ___    __     __   _____    ____   
          █                |                         / _ \   \ \   / /  | ____|  |  _ \  
          █                |                        | | | |   \ \ / /   |  _|    | |_) | 
          █                |                        | |_| |    \ V /    | |___   |  _ <  
          █         ───────┼───────                  \___/      \_/     |_____|  |_| \_\ 
          █                |                     
          █                |                                                                                                                                                        
          █                |
          █                |                  A B C D E F G H I J K L M N O P 1 R S T U V W X Y Z                                        
          █               / \                                                             
          █              /   \                                                           
          █             /     \                                                          
          █            /       \
          █
          █
          █ 
   ▄▄▄▄▄▄▄█▄▄▄▄▄▄▄

--------------------------------------------------------------------------------------------------------



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
          █              *   *                       ____       _       __  __    _____              
          █           *         *                   / ___|     / \     |  \/  |  | ____| 
          █          *   X   X   *                 | |  _     / _ \    | |\/| |  |  _|   
          █          *           *                 | |_| |   / ___ \   | |  | |  | |___  
          █           *    ◠    *                   \____|  /_/   \_\  |_|  |_|  |_____|
          █              *   *                        ___    __     __   _____    ____   
          █                |                         / _ \   \ \   / /  | ____|  |  _ \  
          █                |                        | | | |   \ \ / /   |  _|    | |_) | 
          █                |                        | |_| |    \ V /    | |___   |  _ <  
          █         ───────┼───────                  \___/      \_/     |_____|  |_| \_\ 
          █                |                     
          █                |                                                                                                                                                        
          █                |
          █                |                  A B C D E F G H I J K L M N O P 1 R S T U V W X Y Z                                        
          █               / \                                                             
          █              /   \                                                           
          █             /     \                                                          
          █            /       \
          █
          █
          █ 
   ▄▄▄▄▄▄▄█▄▄▄▄▄▄▄

*/