class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map <string, vector<string>> dict;
        vector<string> result;
        for (vector<string>::iterator it = strs.begin(); it != strs.end(); ++it) {
            string key = *it;
            sort(key.begin(), key.end());
            if (dict.count(key) == 0) {
                dict[key] = vector<string>();
            }
            dict[key].push_back(*it);
        }
        for (map<string, vector<string>>::iterator it = dict.begin(); it != dict.end(); ++it) {
            if ((*it).second.size() > 1) {
                result.insert(result.end(), (*it).second.begin(), (*it).second.end());
            }
        }
        return result;
    }
};