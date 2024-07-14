#include <queue>

struct TireNode {
    TireNode* childrens[26];
    bool flag = false;

    bool doesHave(char ch) {
        return childrens[ch - 'a'] != nullptr;
    }

    void put(char ch, TireNode* node) {
        childrens[ch - 'a'] = node;
    }

    TireNode* get(char ch) {
        return childrens[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class WordDictionary {

private:
    TireNode* root;

public:
    WordDictionary() {
        root = new TireNode();
    }

    void addWord(string word) {
        TireNode* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->doesHave(word[i])) {
                node->put(word[i], new TireNode());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word) {
        queue<pair<TireNode*, int>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            auto [node, index] = q.front();
            q.pop();
            
            if (index == word.size()) {
                if (node->isEnd()) return true;
                continue;
            }
            
            char ch = word[index];
            if (ch == '.') {
                for (int i = 0; i < 26; i++) {
                    if (node->childrens[i] != nullptr) {
                        q.push({node->childrens[i], index + 1});
                    }
                }
            } else {
                if (node->doesHave(ch)) {
                    q.push({node->get(ch), index + 1});
                }
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
