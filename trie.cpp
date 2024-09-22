#include <bits/stdc++.h>

using namespace std;


struct Trie {
    Trie* child[26];


    bool wordEnd ;


    Trie()
    {
        wordEnd = false;
        for (int i = 0; i < 26; i++)
        {
            child[i] = nullptr;
        }
        
    }
    
    


};


void insertKey(Trie* root , string key)
{
    Trie* curr = root;

    for(char c : key)
    {
        if(curr->child[c - 'a'] == nullptr)
        {
            Trie* newnode = new Trie();

            curr -> child[c-'a'] = newnode;
        }

        curr = curr->child[c-'a'];
    }

    curr->wordEnd = true;
}


bool search(Trie* root , string word)
{
    Trie* curr = root;

    for(char c : word)
    {
        if(curr->child[c - 'a'] == nullptr)
        {
            return false;
        }

        curr = curr->child[c-'a'];
    }

    return curr->wordEnd;
}



int main()
{
    Trie* trie = new Trie();

    insertKey(trie , "gello");
    insertKey(trie , "pad");
    insertKey(trie , "hello");
    insertKey(trie , "pad");

    bool value = search(trie , "pad");

    cout  << bool(value) << endl;
    
}