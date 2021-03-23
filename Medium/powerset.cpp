//leetcode medium: subsets

vector<vector<int>> subsets(vector<int>& nums) {
     vector<vector<int>> powerSet = {{}};
    for(int ele : nums)
    {
        int length = powerSet.size();
        for(int i = 0 ; i < length ; i++)
        {
            vector<int> currentSet = powerSet[i];
            currentSet.push_back(ele);
            powerSet.push_back(currentSet);
        }
    }
    return powerSet;
}

// O(n*2^n) time | O(n*2^n) space
