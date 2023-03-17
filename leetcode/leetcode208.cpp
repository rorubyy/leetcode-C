#include <iostream>
#include <vector>
#include <queue>

#define ALPHABET_SIZE 26
using namespace std;
class Trie
{
public:
    Trie()
    {
    }
    struct TrieNode
    {
        bool is_end_of_word;
        TrieNode *children[ALPHABET_SIZE];

        TrieNode()
        {
            is_end_of_word = false;
            for (int i = 0; i < ALPHABET_SIZE; i++)
            {
                {
                    children[i] = NULL;
                }
            }
        }
    };

    TrieNode *root = new TrieNode();

    void insert(string word)
    {
        TrieNode *cur = root;
        for (char ch : word)
        {
            int idx = ch - 'a';
            if (cur->children[idx] == NULL)
                cur->children[idx] = new TrieNode();
            cur = cur->children[idx];
        }
        cur->is_end_of_word = true;
    }

    bool search(string word)
    {
        TrieNode *cur = root;
        for (char ch : word)
        {
            int idx = ch - 'a';
            if (cur->children[idx] == NULL)
                return false;
            cur = cur->children[idx];
        }
        return cur->is_end_of_word;
    }

    bool startsWith(string prefix)
    {
        TrieNode *cur = root;
        for (char ch : prefix)
        {
            int idx = ch - 'a';
            if (cur->children[idx] == NULL)
                return false;
            cur = cur->children[idx];
        }
        return true;
    }
};

int main()
{
    Trie *obj = new Trie();
    obj->insert("apple");
    obj->search("apple");
    obj->search("app");
    obj->startsWith("app");
    obj->insert("app");
    obj->search("app");

    return 0;
}