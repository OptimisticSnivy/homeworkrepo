#include <iostream>
#include <string>

class Node {
private:
    std::string name;
    Node* child;
public:
    Node(const std::string& nodeName)
        : name(nodeName), child(nullptr) {}

    void addChild(Node* newNode) {
        if (child == nullptr) {
            child = newNode;
        } else {
            Node* siblingNode = child;
            while (siblingNode->child != nullptr) {
                siblingNode = siblingNode->child;
            }
            siblingNode->child = newNode;
        }
    }

    void printNodes() {
        std::cout << name << std::endl;
        Node* currentNode = child;
        while (currentNode != nullptr) {
            currentNode->printNodes();
            currentNode = currentNode->child;
        }
    }
};

int main() {
    Node* book = new Node("Book");

    Node* chapter1 = new Node("Chapter 1");
    book->addChild(chapter1);

    Node* section1_1 = new Node("Section 1.1");
    chapter1->addChild(section1_1);

    Node* section1_2 = new Node("Section 1.2");
    chapter1->addChild(section1_2);

    Node* chapter2 = new Node("Chapter 2");
    book->addChild(chapter2);

    Node* section2_1 = new Node("Section 2.1");
    chapter2->addChild(section2_1);

    book->printNodes();

    // Clean up memory
    delete section2_1;
    delete chapter2;
    delete section1_2;
    delete section1_1;
    delete chapter1;
    delete book;

    return 0;
}
