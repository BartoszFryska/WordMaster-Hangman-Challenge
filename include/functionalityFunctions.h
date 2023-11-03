#ifndef __FUNCTIONALITYFUNCTIONS_H__
#define __FUNCTIONALITYFUNCTIONS_H__

#include <iostream>
#include <string>

/**
 * @brief function prepares for leaving the program
 * @return returns void
*/
void Exit();

/**
 * @brief function inports only types of words form file 'words' and stores them in an int array, where index number 
 * corresponds with a line which word has a such type, for eg. if a type 'animal' corresponding number is 2, and 3rd word 
 * in a file 'words' is a type of animal, array [ 2 ] = 2 (bcause we count form 0)
 * 
 * @param[in] list pointer to a list of types of words stored in a file 'words'
 * @return returns void
*/
void InportTypesOfWordsInAList ( int * list );

/**
 * @brief function makes user console nput usable to be used in the main menu
 * 
 * @param[in] Input user input as a string
 * @return returns void, usable input is passed as the 'Input' parameter
*/
void MakeInputUsable ( std::string &Input );

/**
 * @brief function is a function designed to be used in the menu section to print menu, get user input, process it
 * and pass an intiger characteristic of the desired operation as a parameter 'OperationToPerform'
 * 
 * @param[in] OperationToPerform an intiger to dump a operation choosen by the player, '1' equals 'play', '2' equals 'add', '3' equals settings, '-1' equals unknown input
 * @return returns 'true' if the person input does not point to the desire of quitting, 'false' if it is time to end the game 
*/
bool IsNotExit ( int &OperationToPerform );

/**
 * @brief control function to check whether there is any type chosen in the type choosing screen before generation
 * 
 * @param[in] ChosenTypes bool array of chosen types
 * @return function returns 'false' if there was at least one type chosen, 'true' if none of the types were chosen
*/
bool IsThereNoTypeChosen ( bool * ChosenTypes );

/**
 * @brief function for the type choosing screen before generation, takes user input and processes it to return
 * an intiger value of the operation to perform
 * 
 * @param[in] ChosenTypes bool array of chosen types
 * @return function return intiger of an operation to perform, '-1' equlas quit, '-2' equals unknown input, '0' 
 * equals proceed to generation, any intiger other than that equals the number of the type chosen in that input
*/
int GetInputInIntValue ( bool * ChosenTypes );

/**
 * @brief function for a functionality which marks all of the types as chosen for the generation, or unmarks them if all are marked
 * 
 * @param[in] ChosenTypes bool array of chosen types
 * @return function return 'true' if ChosenTypes has any valuse 'false, and 'false' if it does not
*/
bool isTheteAFalseInChosenOnes ( bool * ChosenTypes );

/**
 * @brief function is the main component of the choosing types for the generation operation,
 * it takes the ChosenTypes array, fills it with false value, prints a PrintWordTypesInChoosingScreen,
 * gets user input, processes it, marks the types chosen by the user, or returns values deciding whether to abort and proceed
 * 
 * @param[in] ChosenTypes bool array of chosen types, unprocessed
 * @return function return 'true' if it is time to proceed, and 'false' if it is time to abort
*/
bool ChooseTypeOfWords( bool * ChosenTypes );

/**
 * @brief function is the main component of the action 'Play" in the main menu, it sets up the gameplay, passes arguments to generate 
 * a random word and starts the game
 * 
 * @param[in] list_of_types_of_words_stored_in_a_file array of types of words stored in a file
 * @return function return 'true' if the gameplay went well, false if there was a problem or the person has quited gameplay
*/
bool Play( int * list_of_types_of_words_stored_in_a_file );

/**
 * @brief TO BE ADDED
*/
bool Add ();

/**
 * @brief TO BE ADDED
*/
bool Settings ();

/**
 * @brief control function duting gameplay to check if the player has more than 6 mistakes, therefore loosing the game, when 
 * the game is lost prints 'you lost' message
 * 
 * @param[in] WasTheLetterChosen control array of letters in aplhabetic order, counted from 0 (letter A), 
 * value 0 if was never chosen, 1 if was correct, 2 if was incorrect
 * @param[in] NumberOfMisses intiger containing a number of misses
 * @param[in] mistery pointer to the member of a 'Word' class, containing the guessword amngst other parameters
 * @return function return 'true' if the game is not lost, and 'false' if there is no hope, and the playes has lost
*/
bool GameIsNotLost ( char WasTheLetterChosen [ 26 ], int NumberOfMisses, Word * mistery );

/**
 * @brief function gets an input during the game, processes it and returns only a char, also clears buffer
 * 
 * @return function returns an upper version of a character which the user wants to put as an input, or a value '1' if there was no valuable input
*/
char GetGameInput ();

/**
 * @brief function is the main component of the gameplay, it handles printing, getting the in-game inputs and handles loosing the game
 * 
 * @param[in] mistery pointer to the member of a 'Word' class, containing the guessword amngst other parameters
 * @return returns void
*/
void GameStart ( Word * mistery );

#endif