#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

struct Node
{
    int freq;
    std::string character;
    Node* left;
    Node* right;
};

void printCodes(Node* parent, const std::string& str) {
    if (parent == nullptr) {
        return;
    }

    if (parent->character.size() == 1) {
        std::cout << parent->character << ": " << str << std::endl;
    }

    printCodes(parent->left, str + "0");
    printCodes(parent->right, str + "1");
} 


int main() {

    std::vector<std::string> characters = {"a", "b", "c", "d", "e", "f"};
    std::vector<int> freq = {5, 9, 12, 13, 16, 45};

    std::vector<Node*> char_freq;
    for (int i = 0; i < characters.size(); i++) {
        Node* n = new Node();
        n->character = characters[i];
        n->freq = freq[i];
        n->left = nullptr;
        n->right = nullptr;
        char_freq.push_back(n);
    }

    std::make_heap(char_freq.begin(), char_freq.end(), [](Node* a, Node* b) {
        return a->freq > b->freq;
    });

    while (char_freq.size() > 1) {
        std::pop_heap(char_freq.begin(), char_freq.end(), [](Node* a, Node* b) {
            return a->freq > b->freq;
        });
        Node* n1 = char_freq.back();
        char_freq.pop_back();

        std::pop_heap(char_freq.begin(), char_freq.end(), [](Node* a, Node* b) {
            return a->freq > b->freq;
        });
        Node* n2 = char_freq.back();
        char_freq.pop_back();

        Node* n = new Node();
        n->freq = n1->freq + n2->freq;
        n->character = n1->character + n2->character;
        n->left = n1;
        n->right = n2;

        char_freq.push_back(n);
        std::push_heap(char_freq.begin(), char_freq.end(), [](Node* a, Node* b) {
            return a->freq > b->freq;
        });
    }

    Node* parent = char_freq[0];
    printCodes(parent, "");

    return 0;
}