class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        if (name[0] != typed[0]) {
            return false;
        }
        while (j < typed.length()) {
            if (name[i] == typed[j]) {
                i++;
                j++;
            } else if (name[i - 1] == typed[j]) {
                j++;
            } else {
                return false;
            }
        }
        if (i == name.length()) {
            return true;
        }
        return false;
    }
};