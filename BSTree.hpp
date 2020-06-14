/* SENG1120: Assignment 3, Nathan Gervasoni: c3339961
    // BSTree.hpp.
    // Implementation for class template BSTree.hpp.
    // Illustrates how class BSTree.hpp works.
*/

#include "BSTree.h"

/** Constructors and Destructor. **/

template<typename valueType>
BSTree<valueType>::BSTree()
{
    rootNode = NULL; // rootNode of the tree set to NULL initially.
   // currentNode = NULL;
    listSize = 0;
}

template<typename valueType>
BSTree<valueType>::BSTree(const valueType &inputName)
{
    add(inputName); // Calls add() with inputName reference.
    listSize = 0;
}

template<typename valueType>
BSTree<valueType>::~BSTree()
{
    delete rootNode; // Deletes rootNode pointer and therefore the tree.
}

/** Public methods. **/
template<typename valueType>
void BSTree<valueType>::add(const valueType &inputName)
{
    addNode(inputName, rootNode); // Calls private method with inputName.
}

template<typename valueType>
void BSTree<valueType>::remove(const valueType &inputName)
{
        removeNode(inputName, rootNode); // Calls private method with inputName.
//    else
//    {
//        std::cout << "\nError!\nNo nodes to remove.\n" << std::endl; // Gives error if there's not Nodes within tree.
//    }
}

template<typename valueType>
void BSTree<valueType>::printTree()
{
    inOrderTraversal(rootNode); // Calls private function inOrderTraversal() to print in required way from the rootNode pointer.
}

/** Private methods. **/

template<typename valueType>
void BSTree<valueType>::addNode(const valueType &inputName, BTNode<valueType> *inputNode)
{
    if(rootNode == NULL)                             // If rootnode is NULL.
    {
        rootNode = new BTNode<valueType>(inputName); // Set rootNode to value of a new BTNode.
        listSize++;
    }

    else if(compareNames(inputName, inputNode->getBtName()) > 0)            // Else if, two names are compared using string.compare -
        {                                                                   // and the value returned is greater than 0.
            if(inputNode->checkRightLeaf())                                 // If the inputNode does not contain a rightChildNode.
        {
            BTNode<valueType>* tempNode = new BTNode<valueType>(inputName); // Create a new tempNode.
            inputNode->setRightChild(tempNode);                             // The rightChildNode of inputNode now points at the tempNode.
            tempNode->setParentNode(inputNode);                             // The parentNode of tempNode now points at the inputNode.
            listSize ++;                                                    // Increments list size.
        }
        else
        {
            addNode(inputName, inputNode->getRightChildNode());             // Recursively calls the addNode function and traverses until-
        }                                                                   // it finds a node with the rightChild NULL.
    }

    else
    {
        if(inputNode->checkLeftLeaf())                                      // If the inputNode does not contain a leftChildNode.
        {
            BTNode<valueType>* tempNode = new BTNode<valueType>(inputName); // Create a new tempNode.
            inputNode->setLeftChild(tempNode);                              // The leftChildNode of inputNode now points at the tempNode.
            tempNode->setParentNode(inputNode);                             // The parentNode of tempNode now points at the inputNode.
            listSize ++;                                                    // Increments list size.
        } else
        {
            addNode(inputName, inputNode->getLeftChildNode());              // Recursively calls the addNode function and traverses until-
        }                                                                   // it finds a node with the leftChild NULL.
    }
}

template<typename valueType>
void BSTree<valueType>::removeNode(const valueType &inputName, BTNode<valueType> *inputNode)
{
    if(rootNode != NULL)                                                // If there are nodes within tree.
    {
        if(inputNode == NULL)                                           // If node doesn't exist then return.
        {
            return;
        }

        else if (compareNames(inputName, inputNode->getBtName()) > 0)     // Two names are compared using string.compare() -
        {                                                                 // and the value returned is greater than 0.
            removeNode(inputName, inputNode->getRightChildNode());        // Recursively calls the remove function and traverses until-
        }                                                                 // it finds a node with the rightChildNode NULL.

        else if (compareNames(inputName, inputNode->getBtName()) < 0)     // Two names are compared using string.compare() -
        {                                                                 // and the value returned is less than 0.
            removeNode(inputName, inputNode->getLeftChildNode());         // Recursively calls the remove function and traverses until-
        }                                                                 // it finds a node with the leftChildNode NULL.

            // Once found, conditions are given for removing a leaf node, node with one child, and node with two children.
        else
        {
            if(inputNode->checkLeftLeaf() && inputNode->checkRightLeaf()) // Checks to see if the inputNode is a leaf within tree.
            {
                if(rootNode->getBtName() == inputNode->getBtName())       // Checks if the leaf inputNode is the rootNode of tree.
                {
                    rootNode = NULL;                                      // Sets the rootNode to NULL.
                    listSize--;                                           // Reduces listSize.
                }
                else
                {
                    if (compareNames(inputNode->getBtName(), inputNode->getParentName()) < 0) // inputNode name and it's parentNode name are compared using string.compare() -
                    {                                                                         // and the value returned is less than 0.
                        inputNode->getParentNode()->setLeftChild(NULL);                       // Sets the parentNodes leftChild to NULL.
                    }
                    else
                    {
                        inputNode->getParentNode()->setRightChild(NULL);                      // Sets parentNodes rightChild to NULL.
                    }
                }
                delete inputNode;                                                             // Deletes the inputNode.
                listSize--;                                                                   // Reduces listSize.
            }

            else if((inputNode->checkLeftLeaf() && !inputNode->checkRightLeaf()) || (!inputNode->checkLeftLeaf() && inputNode->checkRightLeaf()))
            {
                if (compareNames(inputName, rootNode->getBtName()) == 0)                    // Deleting the rootNode.
                {
                    if(!inputNode->checkLeftLeaf())                                               // If the rootNode has a leftChild.
                    {
                        inputNode->getLeftChildNode()->setParentNode(NULL);                       // Makes the inputNodes leftChild set its parentNode to NULL.
                        rootNode = inputNode->getLeftChildNode();                                 // Sets the rootNode to the inputNodes leftChild.
                    }
                    else
                    {
                        inputNode->getRightChildNode()->setParentNode(NULL);                      // Makes the inputNodes rightChild set its parentNode to NULL.
                        rootNode = inputNode->getRightChildNode();                                // Sets the rootNode to the inputNodes rightChild.
                    }
                }
                else if(!inputNode->checkLeftLeaf())                                              // inputNode contains a leftChild.
                {
                    inputNode->getLeftChildNode()->setParentNode(inputNode->getParentNode());     // Makes the inputNodes leftChild set its parentNode to the inputNodes parent.
                    if(compareNames(inputName, inputNode->getParentName()) < 0)                   // inputNode name and it's parentNode name are compared using string.compare() -
                    {                                                                             // and the value returned is less than 0.
                        inputNode->getParentNode()->setLeftChild(inputNode->getLeftChildNode());  // Makes the inputNodes parentNode set its leftChild to the inputNodes leftChild.
                    }
                    else
                    {
                        inputNode->getParentNode()->setRightChild(inputNode->getLeftChildNode()); // Makes the inputNodes parentNode set its rightChild to the inputNodes leftChild.
                    }
                }
                else
                {
                    inputNode->getRightChildNode()->setParentNode(inputNode->getParentNode());    // Makes the inputNodes rightChild set its parentNode to the inputNodes parent.
                    if(compareNames(inputName, inputNode->getParentName()) < 0)                   // inputNode name and it's parentNode name are compared using string.compare() -
                    {                                                                             // and the value returned is less than 0.
                        inputNode->getParentNode()->setLeftChild(inputNode->getRightChildNode()); // Makes the inputNodes parentNode set its leftChild to the inputNodes leftChild.
                    }
                    else
                    {
                        inputNode->getParentNode()->setRightChild(inputNode->getRightChildNode());// Makes the inputNodes parentNode set its rightChild to the inputNodes rightChild.
                    }
                }
                delete inputNode;                                                                 // deletes inputNode.
                listSize--;                                                                       // Reduces listSize.
            }
            else
            {
                BTNode<valueType>* tempNode = smallestChild(inputNode->getRightChildNode());      // Creates a new Node and calls the smallestChild function.
                valueType* tempName = new valueType(tempNode->getBtName());                       // ValueType object used to store the tempNodes BTName.
                removeNode(tempNode->getBtName(), tempNode);                                      // Recursively calls the tempNode.
                inputNode->setBTName(*tempName);                                                  // Sets the tempNodes BTName to that of the inputNodes rightChildNodes inputName. 
            }
        }
    }
    else
    {
        std::cout << "\nError!\nTree is empty or name does not exist.\n";
        return;
    }
}

template<typename valueType>
void BSTree<valueType>::inOrderTraversal(BTNode<valueType> *inputNode)
{
    if(rootNode != NULL)
    {
        if(inputNode != NULL)
        {
            inOrderTraversal(inputNode->getLeftChildNode());  // Recursively calls this function until it finds the smalled leftChildNode.
            std::cout << inputNode->getBtName() << " " ;      // Prints out each BTName with space.
            inOrderTraversal(inputNode->getRightChildNode()); // Repeats for the rightChildNodes.
        }
    }
}

template<typename valueType>
int BSTree<valueType>::compareNames(const valueType &inputName1, const valueType &inputName2) {
    if (inputName1 < inputName2)        // Returns negative if the first name is less than second.
    {
        return -1;
    }

    else if (inputName1 == inputName2)  // Returns 0 if the first name is equal to second.
    {
        return 0;
    }

    else
    {
        return 1;            // Returns positive if the first name is greater than second.
    }
}

template<typename valueType>
BTNode<valueType> *BSTree<valueType>::smallestChild (BTNode<valueType> *inputNode) const
{
    if(!inputNode->checkLeftLeaf())                           // If inputNodes leftChild contains a node.
    {
        return smallestChild(inputNode->getLeftChildNode());  // Calls the inputNode to find the next leftChildNode.
    }
    else
    {
        return inputNode;                                     // Returns the inputNode once it's found the last leftChildNode.
    }
}

/* Overloaded operator. */
template<typename valueType>
std::ostream& operator << (std::ostream& output, BSTree<valueType>& inputList)
{
    inputList.printTree(); // Calls public printTree function.
    return output;
}