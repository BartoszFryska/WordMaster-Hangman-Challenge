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
#endif