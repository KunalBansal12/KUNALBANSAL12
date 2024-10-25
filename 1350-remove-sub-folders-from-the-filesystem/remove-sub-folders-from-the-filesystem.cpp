// trie struct
struct Trie {
    Trie* links[27];
    bool isEnd = 0; // 26 letters + 1 for '/'
    Trie() { memset(links, 0, sizeof(links)); }

    // Insert folder into trie returning pos for last '/'
    int insert(string_view path) {
        Trie* node = this;
        int sz = path.size(), pos = 0;
        for (int i = 0; i < sz; i++) {
            if (node->isEnd && path[i] == '/')
                return -1; // is a subfolder of some other path
            char c = path[i];
            int idx = (c == '/') ? 26 : c - 'a'; // Use 26 for '/'
            if (idx == 26)
                pos = i;
            if (!node->links[idx])
                node->links[idx] = new Trie();
            node = node->links[idx];
        }
        node->isEnd = 1;
        //    cout<<pos<<endl;
        return pos;
    }

    // Check if this folder is a subfolder of an already inserted folder
    bool isSubfolder(string_view path, int pos) {
        if (pos == 0)
            return 0; // Each folder name is unique.
        Trie* node = this;
        for (int i = 0; i < pos; i++) {
            char c = path[i];
            int idx = (c == '/') ? 26 : c - 'a';
            node = node->links[idx];
            // it is a subfolder
            if (path[i + 1] == '/' && node->isEnd)
                return 1;
        }
        return 0;
    }
};

class Solution {
    using info = pair<string_view, int>;

public:
    Trie trie;
    vector<string> removeSubfolders(vector<string>& folder) {
        // 1st pass: Insert all folder paths into the trie
        int n = folder.size(), i = 0;
        vector<info> inTrie;
        for (string_view path : folder) {
            int slash = trie.insert(path);
            if (slash != -1)
                inTrie.emplace_back(path, slash);
        }
 
        vector<string> ans;

        // 2nd pass: Check each folder in Trie to see if it's a subfolder
        for (auto& [path, slash] : inTrie) {
            if (!trie.isSubfolder(path, slash))
                ans.push_back(string(path));
        }

        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();