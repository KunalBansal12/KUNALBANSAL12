class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> index;
        int mask = 0;
        index[mask] = -1; // Base case: mask 0 is initially at index -1
        int maxLen = 0;

        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            
            if (isVowel(ch)) {
                switch (ch) {
                    case 'a': mask ^= 1; break;
                    case 'e': mask ^= 2; break;
                    case 'i': mask ^= 4; break;
                    case 'o': mask ^= 8; break;
                    case 'u': mask ^= 16; break;
                }
            }

            if (index.find(mask) != index.end()) {
                maxLen = max(maxLen, i - index[mask]);
            } else {
                index[mask] = i;
            }
        }
        
        return maxLen;
    }
};