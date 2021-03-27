//leetcode medium: longest palindromic substring

string longestPalindrome(string s) {
        if(s.length() < 1)
            return "";

        int start = 0 , end = 0;
        for(int center = 0 ; center < s.length() ; center++)
        {
            int len1 = expandAroundCenter(s, center , center);
            int len2 = expandAroundCenter(s, center , center+1);
            int len = max(len1, len2);
            if(len > end - start)
            {
                start = center - (len - 1)/ 2 ;
                end = center + len/2;
            }
        }
        return s.substr(start, end-start+1);
    }

int expandAroundCenter(string s, int l ,int r)
    {
        while(l>=0 && r<s.size() && (s[l] == s[r])){
                l--;  r++;
        }
        return r - l - 1;
    }

//Time complexity : O(n^2). Since expanding a palindrome around its center could take O(n) time.
//Space complexity : O(1)
