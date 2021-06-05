class Node {
public:
    unordered_map<char,Node*> m;
    bool is_leaf=false;
public:
    Node(bool is_leaf) {
        this->is_leaf = is_leaf;
    }
    Node(){}
};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(),words.end(),[](string a,string b) {
            return a.length()<b.length();
        });
        vector<string> res;
        Node* root = new Node();
        for(string word:words) {
            if(!word.empty()&&findSubstr(root,word,false)) {
                res.push_back(word);
            }
        }
        return res;
    }
    
    bool findSubstr(Node* root,string s,bool back_root) {
        if(s.empty()) {
            return true;
        }
        Node* node = root;
        for(int i=0;i<s.length();i++) {
            if(node->m.count(s[i])) {
                if(node->m[s[i]]->is_leaf) {
                    // 如果是，则没必要构建字典树了，因为可以由其他string组成，直接返回
                    if(findSubstr(root,s.substr(i+1),true)) {
                        return true;
                    }
                }
            } else {
                if(back_root) {
                    return false;
                }
                // 未在字典树中
                node->m[s[i]] = new Node();
            }
            node = node->m[s[i]];
        }
        if(!back_root)
        node->is_leaf = true;
        return false;
    }
};