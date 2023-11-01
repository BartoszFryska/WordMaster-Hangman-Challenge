#ifndef __INTERFACELOOKFUNCTIONS_H__
#define __INTERFACELOOKFUNCTIONS_H__

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

/**
 * @brief prints game intro
 * 
 * @return returns void
*/
void PrintIntro();

/**
 * @brief prints exit game message
 * 
 * @return returns void
*/
void PrintExitMessage ();

/**
 * @brief prints word types to choose for the generation, chosen one in green, not chosen in red
 * 
 * @param[in] ChosenTypes bool array of chosen types for the generation
 * @return returns void
*/
void PrintWordTypesInChoosingScreen ( bool * ChosenTypes );

/**
 * @brief prints all letters in the english alphabet during gameplay, aviable without color, correctly guessed in green, incorrectly in red
 * 
 * @param[in] WasTheLetterChosen control array of letters in aplhabetic order, counted from 0 (letter A), 
 * value 0 if was never chosen, 1 if was correct, 2 if was incorrect
 * @return returns void
*/
void PrintLettersInColours( char WasTheLetterChosen [ 26 ] );

/**
 * @brief prints a hint pointing to the guessword
 * 
 * @param[in] hint member of a Word class called hint; note: please put a string not a pointer to that parameter
 * @return returns void
*/
void PrintHint ( std::string hint  );

/**
 * @brief prints a separator made of '-' characters during gameplay screen
 * 
 * @return returns void
*/
void PrintGameScreenComponentsSeparator ();

/**
 * @brief prints a gameplay screen
 * 
 * @param[in] WasTheLetterChosencontrol array of letters in aplhabetic order, counted from 0 (letter A), 
 * value 0 if was never chosen, 1 if was correct, 2 if was incorrect
 * @param[in] NumberOfMisses number of incorrect guesses
 * @param[in] mistery pointer to a member of 'Word' class, which contains a word to guess
 * @param[in] IsTheWordGuessed bool parameter, true if the word is guessed, false if it is not
 * @return returns void
*/
void PrintGameScreen ( char WasTheLetterChosen [ 26 ], int NumberOfMisses, Word * mistery, bool IsTheWordGuessed );

#endif