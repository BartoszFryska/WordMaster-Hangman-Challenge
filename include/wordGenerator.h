#ifndef __WORDGENERATOR_H__
#define __WORDGENERATOR_H__

/**
 * @brief function checks if a numbers word stored in a file corresponding type is one of the chosen ones for the generation
 * 
 * @param[in] number number of the word to check (counting form 0)
 * @param[in] ChosenTypes bool array of chosen types for the generation
 * @param[in] list_of_types_of_words_stored_in_a_file array of numerated types of all of the words
 * @return function returns true if the words type is chosen, false if it is not
*/
bool IsOneOfTheChosenTypes ( int number, bool * ChosenTypes, int * list_of_types_of_words_stored_in_a_file);

/**
 * @brief function generates a random word
 * 
 * @param[in] mistery pointer to a place, where a generated word will be putted
 * @param[in] NumberOfWordTypes number of a word types
 * @param[in] ChosenTypes bool array of chosen types for the generation
 * @param[in] list_of_types_of_words_stored_in_a_file array of numerated types of all of the words
 * @return returns void
*/
bool GenerateAWord ( Word *mistery, int NumberOfWordTypes, bool * ChosenTypes, int * list_of_types_of_words_stored_in_a_file );

#endif