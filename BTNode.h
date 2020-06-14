/* SENG1120: Assignment 3, Nathan Gervasoni: c3339961
    // BTNode.h.
    // Header file and class definition of template class BTNode.h
    // BTNode.h class is then used to construct the BSTree class.
*/

#ifndef ASSIGNMENT3_BTNODE_H
#define ASSIGNMENT3_BTNODE_H
// Macro guard.

#include "cstdlib"
// Including relevant libraries.

template<typename valueType>
class BTNode
{
public:
/* Public members.*/
    BTNode();
        // Default constructor.
    BTNode(const valueType &inputName);
        // Constructor with reference to a valueType input.
    ~BTNode();
        // Destructor.
    void setBTName(const valueType& inputName);
        // Set the name stored within the Binary tree node.
        // Pre-condition: BTNode must be existing and input must be of valueType.
        // Post-condition: ValueType inputName is stored in the Node.
    void setParentNode(BTNode<valueType>* parentNode);
        // Set the parent node pointer.
        // Pre-condition: Pointer 'parentNode' must be existing, and either NULL, or pointing to another Node.
        // Post-condition: Pointer 'parentNode' is set to desired Node.
    void setLeftChild(BTNode<valueType>* leftChildNode);
        // Sets the left child node pointer.
        // Pre-condition: Pointer 'leftChildNode' must be existing, and either NULL, or pointing to another Node.
        // Post-condition: Pointer 'leftChildNode' is set to desired Node.
    void setRightChild(BTNode<valueType>* rightChildNode);
        // Sets the right child node pointer.
        // Pre-condition: Pointer 'rightChildNode' must be existing, and either NULL, or pointing to another Node.
        // Post-condition: Pointer 'rightChildNode' is set to desired Node.
    valueType getBtName() const;
        // Return name stored within the node.
        // Pre-condition: BTNode has been created, and has been allocated a BTName.
        // Post-condition: BTName stored within the node is returned.
    valueType getParentName() const;
        // Return name stored within the inputNodes parentNode.
        // Pre-condition: BTNode has been created, and has been allocated a BTName, and has a parentNode/Not the rootNode.
        // Post-condition: BTName stored within the parentNode is returned.
    BTNode<valueType>* getParentNode() const;
        // Returns parentNode pointer associated with the node.
        // Pre-condition: Pointer 'parentNode' must be existing, and either NULL, or pointing to another Node.
        // Post-condition: parentNode pointer is returned.
    BTNode<valueType>* getLeftChildNode() const;
        // Returns leftChildNode pointer associated with the node.
        // Pre-condition: Pointer 'leftChildNode' must be existing, and either NULL, or pointing to another Node.
        // Post-condition: leftChildNode  pointer is returned.
    BTNode<valueType>* getRightChildNode() const;
        // Returns rightChildNode pointer associated with the node.
        // Pre-condition: Pointer 'rightChildNode' must be existing, and either NULL, or pointing to another Node.
        // Post-condition: rightChildNode pointer is returned.
    bool checkLeftLeaf() const;
        // Checking if a node does not have a left child.
        // Pre-condition: BTNode exists.
        // Post-condition: Returns true if leftChildNode is NULL.
    bool checkRightLeaf() const;
        // Checking if a node does not have a right child.
        // Pre-condition: BTNode exists.
        // Post-condition: Returns true if rightChildNode is NULL.

/* Private members.*/
private:
    valueType BTName;
        // Stores the valueType value given by main. Which is known to be a string and a name.
    BTNode<valueType> *parentNode;
        // Pointer to the top, or otherwise known as the parent node. Which is less than rightChildNode and greater than leftChildNode.
    BTNode<valueType> *leftChildNode;
        // Pointer to the left child which is less than the parentNode and rightChildNode.
    BTNode<valueType> *rightChildNode;
        // Pointer to the right child which is less than the parentNode and rightChildNode.
};

#include "BTNode.hpp"
// Includes BTNode.hpp implementation file.
#endif //ASSIGNMENT3_BTNODE_H
