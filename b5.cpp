#include <iostream>

// Node class representing each node in the tree
class Node {
public:
    std::string name;
    Node* child;
    Node* sibling;
    int numChildren;

    Node(const std::string& nodeName)
        : name(nodeName), child(nullptr), sibling(nullptr), numChildren(0) {}

    // Method to add a child node to the current node
    void addChild(Node* childNode) {
        if (child == nullptr) {
            child = childNode;
        } else {
            Node* siblingNode = child;
            while (siblingNode->sibling != nullptr) {
                siblingNode = siblingNode->sibling;
            }
            siblingNode->sibling = childNode;
        }
        numChildren++;
    }

    // Method to recursively print the nodes of the tree
    void printNodes(int depth = 0) {
        // Indentation based on depth for better visualization
        std::string indentation(depth, '-');

        // Print the name of the current node
        std::cout << indentation << name << std::endl;

        // Print the nodes of the children
        Node* childNode = child;
        while (childNode != nullptr) {
            childNode->printNodes(depth + 1);
            childNode = childNode->sibling;
        }
    }
};

int main() {
    // Create the nodes for the book structure
    Node* book = new Node("Book");
    Node* chapter1 = new Node("Chapter 1");
    Node* section1_1 = new Node("Section 1.1");
    Node* subsection1_1_1 = new Node("Subsection 1.1.1");
    Node* section1_2 = new Node("Section 1.2");
    Node* chapter2 = new Node("Chapter 2");
    Node* section2_1 = new Node("Section 2.1");

    // Build the book hierarchy
    book->addChild(chapter1);
    book->addChild(chapter2);
    chapter1->addChild(section1_1);
    section1_1->addChild(subsection1_1_1);
    chapter1->addChild(section1_2);
    chapter2->addChild(section2_1);

    // Print the nodes of the book
    book->printNodes();

    // Clean up the allocated memory
    delete book;
    delete chapter1;
    delete section1_1;
    delete subsection1_1_1;
    delete section1_2;
    delete chapter2;
    delete section2_1;

    return 0;
}

