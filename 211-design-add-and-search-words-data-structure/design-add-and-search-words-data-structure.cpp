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

    bool searchInNode(string& word, TireNode* node, int index) {
        if (index == word.size()) {
            return node->isEnd();
        }
        char ch = word[index];
        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->childrens[i] != nullptr && searchInNode(word, node->childrens[i], index + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            if (!node->doesHave(ch)) {
                return false;
            }
            return searchInNode(word, node->get(ch), index + 1);
        }
    }

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
        return searchInNode(word, root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
