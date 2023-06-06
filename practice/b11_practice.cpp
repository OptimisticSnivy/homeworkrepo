#include<iostream>
using namespace std;

struct node{
  string keyword;
  string meaning;
  node* left;
  node* right;

  node(const string& key,const string& key)
    :keyword(key),meaning(value),left(nullptr),right(nullptr){}
}

class dictionary{
private:
  node* root;
public:
  dictionary(){
    root(nullptr);
  }

  void insert(const string& keyword,const string& meaning){
    root=insertRecursive(root,keyword,meaning);
  }
  
  void update(const string* keyword,const string& meaning){
    node* node1=findNode(root,keyword);
    if(node){
      node->meaning=meaning;q
      cout<<"Keyword Updated!"<endl;
    }
    else{
      cout<<"Keyword Not Found!"<<endl;
    }
  }
  remove(const string& keyword){
    root=removeRecursive(root,keyword);
  }

  void displayAscending(){
    displayAscendingRecursive();
  }
 
  void displayDescenfing(){
    displayDescenfingRecursive();
  }

  int getMaxComparisons(const string& keyword){
    return getMaxComparisonsRecursive(root,keyword);
  }

private:
  node* insertRecursive(node* node,const string& keyword,const string& meaning){
    if(node==nullptr){
      return new node(keyword,meaning);
    }
    if(keyword < node->keyword){
      node->left=insertRecursive(node->left,keyword,meaning);
    }
    else{
      node->right=insertRecursive(node->right,keyword,meaning);
    }  
    return node;
  }

  node* removeRecursive(node* node,const string& keyword){
    if(node==nullptr){
      return nullptr;
    }
    
    if(keyword < node->keyword){
      node->left=removeRecursive(node->left,keyword);
    }
    else if(keyword > node->keyword){
      node->right=removeRecursive(node->right,keyword);
    }
    else{
      if(node->left==nullptr && node->right==nullptr){
        delete node;
        return nullptr;
      }
      else if (node->left==nullptr) {
        node* temp=node->right;
        delete node->right;
        return temp;
      }
      else if(node->right==nullptr){
        node* temp=node->left;
        delete node->left;
        return temp;
      }
      else{
        node* minRightNode=findMinNode(node->right);
        node->keyword=minRightNode->keyword;
        node->meaning=minRightNode->meaning;
        node->right=removeRecursive(node->right,minRightNode->keyword);
      }
    }
    return node;
  }
  
  node* findMinNode(node* node){
    while(node->left!=nullptr){
      node=node->left;
    }
    return node;
  }
}


int main() {
    dictionary dictionary;

    dictionary.insert("apple", "A fruit");
    dictionary.insert("banana", "A tropical fruit");
    dictionary.insert("cat", "A domestic animal");
    dictionary.insert("dog", "A domestic animal");

    std::cout << "Dictionary (Ascending Order):" << std::endl;
    dictionary.displayAscending();

    std::cout << std::endl;

    std::cout << "Dictionary (Descending Order):" << std::endl;
    dictionary.displayDescending();

    std::cout << std::endl;

    std::cout << "Maximum comparisons for 'dog': " << dictionary.getMaxComparisons("dog") << std::endl;
    std::cout << "Maximum comparisons for 'elephant': " << dictionary.getMaxComparisons("elephant") << std::endl;

    dictionary.update("apple", "A delicious fruit");

    std::cout << std::endl;

    std::cout << "Dictionary after updating 'apple':" << std::endl;
    dictionary.displayAscending();

    dictionary.remove("banana");

    std::cout << std::endl;

    std::cout << "Dictionary after removing 'banana':" << std::endl;
    dictionary.displayAscending();

    return 0;
}
