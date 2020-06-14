/* SENG1120: Assignment 3, Nathan Gervasoni: c3339961
    // HTable.h
    // Header file and class definition of template class HTable.h
*/

// Macro guards.
#ifndef ASSIGNMENT3_HTABLE_H
#define ASSIGNMENT3_HTABLE_H

// Including relevant libraries.
#include <iostream>
#include <cstdlib>

template<typename valueType>
class HTable
{
public:
/* Public members.*/
    HTable();
        // Default constructor.
    ~HTable();
        // Destructor.
    void add(const valueType &inputName);
        // Adds valueType to the hashArray.
        // Pre-condition: hashArray has been created. There is room within array, and the inputName is of valueType.
        // Post-condition: valueType data is stored within the hashArray via an index value.
    void remove(const valueType &inputName);
        // Removes valueType from the hashArray.
        // Pre-condition: hashArray has been created. There is an inputName of valuetype that matches.
        // Post-condition: inputName is removed.
    void print();
        // Called from << operator. Prints out contents of array.
        // Pre-condition: HTable must be existing and filled with valueType values.
        // Post-condition: Prints out inputList with valid entries.

/* Private members.*/
private:
    static const int size = 150;
        // Indicates total size allowed for the array.
    valueType hashArray[150];
        // An array that stores valueType data. Has a limit of 150.
    int hashFun(const valueType &inputName);
        // Iterates through inputName and adds ASCII values up then returns that to the hashArray.
        // Pre-condition: hashArray has been created and inputName is valid.
        // Post-condition: Returns an int representing the index number of the inputName.
};

template<typename valueType>
std::ostream &operator<<(std::ostream &output, HTable<valueType> &inputList);
// Overloaded << operator.
#include "HTable.hpp"

#endif //ASSIGNMENT3_HTABLE_H