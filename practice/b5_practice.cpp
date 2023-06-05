#include<iostream>

class node{
public:
  std::string name;
  node* child;
  node* sibling;
  int numChildern;

  node(const std::string& nodeName)
      :name(nodeName),child(nullptr),sibling(nullptr),numChildern(0) {}

  void addChild(node* childnode){
    if(child==nullptr){
      child=childnode;
    }
    else{
      node* siblingnode=child;
      while(siblingnode->sibling=nullptr){
        siblingnode=siblingnode->sibling;
      }
      siblingnode->sibling=childnode;
    }
    numChildern++;
  }

  void printnodes(int depth=0){
    std::string indent(depth,'-');
    std::cout<< indent << name << std::endl;

    node* childnode=child;
    while(childnode!=nullptr){
      childnode->printnodes(depth+1);
      childnode=childnode->sibling;
    }
  }
};

int main() {
    // Create the nodes for the book structure
    node* book = new node("Book");
    node* chapter1 = new node("Chapter 1");
    node* section1_1 = new node("Section 1.1");
    node* subsection1_1_1 = new node("Subsection 1.1.1");
    node* section1_2 = new node("Section 1.2");
    node* chapter2 = new node("Chapter 2");
    node* section2_1 = new node("Section 2.1");

    // Build the book hierarchy
    book->addChild(chapter1);
    book->addChild(chapter2);
    chapter1->addChild(section1_1);
    section1_1->addChild(subsection1_1_1);
    chapter1->addChild(section1_2);
    chapter2->addChild(section2_1);

    // Print the nodes of the book
    book->printnodes();

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
