#include <bits/stdc++.h>

using namespace std;

class Trie{
    public:
    Trie* child[26];

    bool wordEnd;

    Trie()
    {
        for (int i = 0; i < 26; i++)
        {
            child[i] = nullptr;
        }

        wordEnd = false;
        
    }

    void insert (string word)
    {
        Trie* node = this;

        for (char ch : word)
        {
            if(node->child[ch-'a'] == nullptr)
            {
                Trie* newNode = new Trie();
                node->child[ch-'a'] = newNode;
            }

            node = node->child[ch-'a'];
        }
        

        node->wordEnd = true;
    }

};

class WordDictionary {
public:
    Trie* root;
    WordDictionary() {

        root = new Trie();
        
    }
    
    void addWord(string word) {

        root->insert(word);
        
    }
    
    bool search(string word) {
        return dfs(word, 0 , root);
    }


    bool dfs (string word , int index , Trie* root)
    {
        

        if(word.size() == index)
        {
            return root->wordEnd;
        }


        char c = word[index];
        
            if(c == '.')
            {
                for(Trie* ch : root->child)
                {
                    if(ch && dfs(word , index+1 , ch))
                    {
                        return true;
                    }
                }
            }
            else
            {
                Trie* children = root->child[c-'a'];
                if(children && dfs(word, index+1 , children))
                {
                    return true;
                }
            }
        
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */