class Solution {
public:
    string toLowerCase(string s) {
        for(char& ch:s) 
            if('A'<=ch && ch<='Z') 
                ch += 32;
        return s;
    }
};