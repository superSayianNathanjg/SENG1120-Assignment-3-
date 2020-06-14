/* SENG1120: Assignment 3, Nathan Gervasoni: c3339961
    // HTable.hpp.
    // Implementation for class template HTable.hpp.
    // Illustrates how class HTable.hpp works.
*/

template<typename valueType>
HTable<valueType>::HTable()
{
    for (int i = 0; i < size; i++)
    {
        hashArray[i] = ""; // Because the valueType is known to be a string, it can be set to "".
    }
}

template<typename valueType>
HTable<valueType>::~HTable()
{
    for (int i = 0; i < size; i++)
    {
        hashArray[i] = (""); // Because the valueType is known to be a string, it can be set to "".
    }
}

template<typename valueType>
void HTable<valueType>::add(const valueType &inputName)
{
    int hashIndex = hashFun(inputName);  // Calls hashFun() on the inputName and returns an int representing index.
    if (hashArray[hashIndex] != "")      // If index value does not equal to default, then it has a value stored and cannot add another.
    {
        std::cout << "\nError! Failed to add name.\nArray index contains existing item. Try again. " << std::endl;
    } else                              // If index value == to default, then adds value to hashArray.
    {
        hashArray[hashIndex] = inputName;
    }
}

template<typename valueType>
void HTable<valueType>::remove(const valueType &inputName)
{
    int hashIndex = hashFun(inputName); // Calls hashFun() on the inputName and returns an int representing index.
    if (hashArray[hashIndex] != "")     // If inputName is not equal to default value, then make it default/remove value.
    {
        if(hashArray[hashIndex].length() == inputName.length()) // If inputName matches a hashName within the array.
        {
            hashArray[hashIndex] = "";                          // Sets it to default "".
        }
    }
//    } else
//    {
//        //std::cout << "\nError! Failed to remove name.\nArray does not contain this index or value. Try again. " << std::endl;
//    }
}

template<typename valueType>
void HTable<valueType>::print()
{
    for (int i = 0; i < size; i++)  // Traverses through size of Array.
    {
        if (hashArray[i] != "") // If index 'i' does not hold a default value.
        {
            std::cout << hashArray[i] << " "; // Prints out value of 'i'.
        }
    }
}

template<typename valueType>
int HTable<valueType>::hashFun(const valueType &inputName)
{
    int addResult = 0;  // Variable for the index.
    for (int i = 0; i < inputName.length(); i++) // Traverses through inputName length.
    {
        addResult = addResult + (int) inputName[i]; // Result of 'addResult' is incremented with the ASCII value.
    }
    return addResult % 150; // Returns the modular of addResult.
}

template<typename valueType>
std::ostream &operator<<(std::ostream &output, HTable<valueType> &inputList)
{
    inputList.print();
    return output;
}