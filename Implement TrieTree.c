#include <stdbool.h>
#include <stdlib.h>

typedef struct TrieNode {
    struct TrieNode* children[26];
    bool isEndOfWord;
} TrieNode;

typedef struct {
    TrieNode* root;
} Trie;

TrieNode* createNode(void) {
    TrieNode* node = calloc(1, sizeof(TrieNode));
    return node;
}

Trie* trieCreate(void) {
    Trie* obj = malloc(sizeof(Trie));
    obj->root = createNode();
    return obj;
}

void trieInsert(Trie* obj, char* word) {
    TrieNode* curr = obj->root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (curr->children[index] == NULL) {
            curr->children[index] = createNode();
        }

        curr = curr->children[index];
    }

    curr->isEndOfWord = true;
}

TrieNode* findNode(Trie* obj, char* str) {
    TrieNode* curr = obj->root;

    for (int i = 0; str[i] != '\0'; i++) {
        int index = str[i] - 'a';

        if (curr->children[index] == NULL) {
            return NULL;
        }

        curr = curr->children[index];
    }

    return curr;
}

bool trieSearch(Trie* obj, char* word) {
    TrieNode* node = findNode(obj, word);
    return node != NULL && node->isEndOfWord;
}

bool trieStartsWith(Trie* obj, char* prefix) {
    return findNode(obj, prefix) != NULL;
}

void freeTrieNode(TrieNode* node) {
    if (node == NULL) return;

    for (int i = 0; i < 26; i++) {
        freeTrieNode(node->children[i]);
    }

    free(node);
}

void trieFree(Trie* obj) {
    if (obj == NULL) return;

    freeTrieNode(obj->root);
    free(obj);
}