//leetcode medium: group anagrams
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        unordered_map<string, vector<string> > anagrams;
        vector<int> counter(26, 0);
        for(auto word: strs)
        {
           // string sortedWord = word;
           // sort(sortedWord.begin(), sortedWord.end());

            fill(counter.begin(), counter.end(), 0);
            
            for(char c: word)
                counter[c-'a']++;

            string hash;

            for(int i = 0 ; i < 26 ; i++ )
                hash += string(counter[i], i +'a');

            anagrams[hash].push_back(word);

        }

        for(auto it : anagrams)
            ans.push_back(it.second);

        return ans;
    }
};
//Time Complexity: O(NK), where N is the length of strs, and K is the maximum length of a string in strs.
//Counting each string is linear in the size of the string, and we count every string.
//Space Complexity: O(NK).
