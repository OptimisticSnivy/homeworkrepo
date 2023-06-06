
#include <iostream>
#include <string>

struct Node {
    std::string keyword;
    std::string meaning;
    Node* left;
    Node* right;

    Node(const std::string& key, const std::string& value)
        : keyword(key), meaning(value), left(nullptr), right(nullptr) {}
};

class Dictionary {
private:
    Node* root;

public:
    Dictionary() : root(nullptr) {}

    void insert(const std::string& keyword, const std::string& meaning) {
        root = insertRecursive(root, keyword, meaning);
    }

    void remove(const std::string& keyword) {
        root = removeRecursive(root, keyword);
    }

    void update(const std::string& keyword, const std::string& meaning) {
        Node* node = findNode(root, keyword);
        if (node) {
            node->meaning = meaning;
            std::cout << "Keyword updated successfully." << std::endl;
        } else {
            std::cout << "Keyword not found." << std::endl;
        }
    }

    void displayAscending() {
        displayAscendingRecursive(root);
    }

    void displayDescending() {
        displayDescendingRecursive(root);
    }

    int getMaxComparisons(const std::string& keyword) {
        return getMaxComparisonsRecursive(root, keyword);
    }

private:
    Node* insertRecursive(Node* node, const std::string& keyword, const std::string& meaning) {
        if (node == nullptr) {
            return new Node(keyword, meaning);
        }

        if (keyword < node->keyword) {
            node->left = insertRecursive(node->left, keyword, meaning);
        } else if (keyword > node->keyword) {
            node->right = insertRecursive(node->right, keyword, meaning);
        }

        return node;
    }

    Node* removeRecursive(Node* node, const std::string& keyword) {
        if (node == nullptr) {
            return nullptr;
        }

        if (keyword < node->keyword) {
            node->left = removeRecursive(node->left, keyword);
        } else if (keyword > node->keyword) {
            node->right = removeRecursive(node->right, keyword);
        } else {
int main() {
    Dictionary dictionary;

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
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            } else if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                Node* minRightNode = findMinNode(node->right);
                node->keyword = minRightNode->keyword;
                node->meaning = minRightNode->meaning;
                node->right = removeRecursive(node->right, minRightNode->keyword);
            }
        }

        return node;
    }

    Node* findNode(Node* node, const std::string& keyword) {
        if (node == nullptr || node->keyword == keyword) {
            return node;
        }

        if (keyword < node->keyword) {
            return findNode(node->left, keyword);
        }

        return findNode(node->right, keyword);
    }

    void displayAscendingRecursive(Node* node) {
        if (node == nullptr) {
            return;
        }

        displayAscendingRecursive(node->left);
        std::cout << node->keyword << ": " << node->meaning << std::endl;
        displayAscendingRecursive(node->right);
    }

    void displayDescendingRecursive(Node* node) {
        if (node == nullptr) {
            return;
        }

        displayDescendingRecursive(node->right);
        std::cout << node->keyword << ": " << node->meaning << std::endl;
        displayDescendingRecursive(node->left);
    }

    Node* findMinNode(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    int getMaxComparisonsRecursive(Node* node, const std::string& keyword, int count = 0) {
        if (node == nullptr || node->keyword == keyword) {
            return count;
        }

        if (keyword < node->keyword) {
            return getMaxComparisonsRecursive(node->left, keyword, count + 1);
        }

        return getMaxComparisonsRecursive(node->right, keyword, count + 1);
    }
};

int main() {
    Dictionary dictionary;

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
