class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> edits (word2.length() + 1, vector<int> (word1.length()+1, 0));

        for(int i = 0 ; i < word2.length()+1; i++){
            for(int j = 0 ; j < word1.length()+1; j++){
                edits[0][j] = j;
            }
        edits[i][0] = i;
        }

        for(int i = 1 ; i < word2.length()+1; i++)
            for(int j = 1 ; j < word1.length()+1; j++){
                if(word2[i-1] == word1[j-1]){
                    edits[i][j] = edits[i-1][j-1];
                } else {
                    edits[i][j] = 1 + min(edits[i-1][j-1], min(edits[i-1][j], edits[i][j-1]));
                }
            }
        return edits[word2.length()][word1.length()];

    }
};

// O(nm) time | O(nm) space
