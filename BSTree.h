/* SENG1120: Assignment 3, Nathan Gervasoni: c3339961
    // BSTree.h
    // Header file and class definition of template class BSTree.h
*/

#ifndef ASSIGNMENT3_BSTREE_H
#define ASSIGNMENT3_BSTREE_H
// Macro guard.


#include <iostream>
#include "BTNode.h"
// Including relevant libraries.

template<typename valueType>
class BSTree
{
public:
/** Public members. **/
    BSTree();
        // Default constructor with no input.
    BSTree(const valueType& inputName);
        // Constructor with valueType reference given.
    ~BSTree();
        // Destructor.
    void add(const valueType &inputName);
        // Adds valueType to the binary search tree. Calls private method addNode().
        // Pre-condition: BSTree exists. And the inputName is of valueType.
        // Post-condition: addNode() adds valueType data to a node which is then stored within the binary tree
    void remove(const valueType &inputName);
        // Removes valueType from the binary search tree. Calls private method removeNode().
        // Pre-condition: BSTree has been created. And the inputName is of valueType.
        // Post-condition: removeNode() removes valueType data and node from the binary tree.
    void printTree();
        // Prints valueType data stored within tree. Calls private method inOrderTraversal() to print in-order.
        // Pre-condition: BSTree exists. And data of valueType is stored within.
        // Post-condition: inOrderTraversal() prints out given valueType data. Which is known to be names of string data type.

private:
/** Private members. **/
    void addNode(const valueType& data, BTNode<valueType>* inputNode);
        // Called from add(). Traverses tree and adds valueType node to the appropriate branch.
        // Pre-condition: BSTree exists.
        // Post-condition: valueType node is stored correctly within tree.
    void removeNode(const valueType& data, BTNode<valueType>* inputNode);
        // Called from remove(). Traverses tree and removes valueType node, then adjusts remaining nodes to their appropriate branches.
        // Pre-condition: BSTree, and specified BTNode exists within tree.
        // Post-condition: valueType node is removed. Remaining nodes are re-arranged correctly.
    void inOrderTraversal(BTNode<valueType>* rootNode);
        // Called from print(). Traverses tree and prints out BTNames in-order. Which is leftNode, rootNode, and then rightNode.
        // Pre-condition: BSTree exists and contains BTNodes with valid valueType data.
        // Post-condition: Prints out valid BTNames in-order.
    int compareNames(const valueType& inputName1, const valueType& inputName2);
        // Called with add, remove, and inOrderTraversal(). Compares two names stored within nodes to determine which is bigger.
        // Pre-condition: BSTree and two BTNodes with valueType data exists.
        // Post-condition: The value of two string names are compared and the string .compare function is used to return an int which is then used in a switch statement.
    BTNode<valueType>* smallestChild(BTNode<valueType>* inputNode) const;
    BTNode<valueType>* rootNode;
        // Pointer to record start of tree.
  //  BTNode<valueType>* currentNode;
        // Pointer to traverse the tree.
    int listSize;
        // Unused for assignment, int to keep track of number of Nodes within tree.
};

template<typename valueType>
std::ostream& operator << (std::ostream& output, BSTree<valueType>& inputList);

#include "BSTree.hpp"
#endif //ASSIGNMENT3_BSTREE_H

