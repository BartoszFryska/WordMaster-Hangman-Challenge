#include "../include/fontNamespace.h"



    
    void FONT::OutputACorrectLineOfACorrectCharacterInAFont ( char character, int line ) {

        if ( isdigit ( character ) ) {

            int digit = character - '0';

            //std::cout << font_numbers [ digit ] [ line ];
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

    void FONT::PrintStringInSpecialFont ( std::string word ) {

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

    void FONT::PrintWordInSpecialFont ( Word * mistery ) {

        std::string s = "";

        for ( int i = 0; i < mistery->guessWord.size(); i++ ) {

            if ( *( mistery->ArrayOfPositionsGuessedCorrectly + i ) || mistery->guessWord [ i ] == ' ' ) {

                    s.push_back(mistery->guessWord [ i ]);
            }

            else {

                s.push_back ( 1 );
            }
        }

        PrintStringInSpecialFont ( s );
    }

