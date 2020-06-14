/* SENG1120: Assignment 3, Nathan Gervasoni: c3339961
    // BTNode.hpp.
    // Implementation for class template BTNode.hpp.
    // Illustrates how class BTNode.hpp works.
*/

#include "BTNode.h"

template<typename valueType>
BTNode<valueType>::BTNode()
{
    BTName = "";            // Because the valueType is known to be a string, it can be set to "".
    parentNode = NULL;      // parentNode, leftChild, and rightChild all set to NULL initially.
    leftChildNode = NULL;
    rightChildNode = NULL;
}

template<typename valueType>
BTNode<valueType>::BTNode(const valueType &inputName)
{
    BTName = inputName;     // valueType reference stored within BTName.
    parentNode = NULL;      // parentNode, leftChild, and rightChild all set to NULL initially.
    leftChildNode = NULL;
    rightChildNode = NULL;
}

template<typename valueType>
BTNode<valueType>::~BTNode()
{
    // delete BTName;       // data is deleted once out of scope.
    parentNode = NULL;      //
    leftChildNode = NULL;
    rightChildNode = NULL;
}

template<typename valueType>
void BTNode<valueType>::setBTName(const valueType &inputName)
{
    BTName = inputName;     // Sets BTName to given reference input.
}

template<typename valueType>
void BTNode<valueType>::setParentNode(BTNode <valueType> *parent)
{
    parentNode = parent;    // Set the parent node pointer.
}

template<typename valueType>
void BTNode<valueType>::setLeftChild(BTNode <valueType> *left)
{
    leftChildNode = left;   // Sets the left child node pointer.
}

template<typename valueType>
void BTNode<valueType>::setRightChild(BTNode <valueType> *right)
{
    rightChildNode = right; // Sets the right child node pointer.
}

template<typename valueType>
valueType BTNode<valueType>::getBtName() const
{
    return BTName;          // Return name stored within the node.
}

template<typename valueType>
valueType BTNode<valueType>::getParentName () const
{
    return parentNode->getBtName(); // Returns the inputNodes parentNodes inputName.
}

template<typename valueType>
BTNode <valueType>* BTNode<valueType>::getParentNode() const
{
    return parentNode;      // Returns parentNode pointer associated with the node.
}

template<typename valueType>
BTNode <valueType>* BTNode<valueType>::getLeftChildNode() const
{
    return leftChildNode;   // Returns leftChildNode pointer associated with the node.
}

template<typename valueType>
BTNode <valueType>* BTNode<valueType>::getRightChildNode() const
{
    return rightChildNode;  // Returns rightChildNode pointer associated with the node.
}

template<typename valueType>
bool BTNode<valueType>::checkLeftLeaf() const
{
    return leftChildNode == NULL; // Returns true if a node does not have a left child.
}

template<typename valueType>
bool BTNode<valueType>::checkRightLeaf() const
{
    return rightChildNode == NULL; // Returns true if a node does not have a right child.
}

