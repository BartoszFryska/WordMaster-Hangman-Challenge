#include "../include/fontNamespace.h"
#include "../include/interfaceLookFunctions.h"
#include "../include/gameParameters.h"

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

        FONT::PrintWordInSpecialFont ( mistery );

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