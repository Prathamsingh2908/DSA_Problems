class Solution {
public:
    int expand(string s, int right, int left){
        while(left>=0 && right<= s.size() && s[right] == s[left]){
            left--;
            right++;
        }
        return (right-left-1);
    }
    string longestPalindrome(string s) {
        int n = s.size();
        if(n < 2) return s;

        int start = 0, maxLen = 0;

        for(int i = 0; i<n; i++){
            int oddLen = expand(s,i,i);
            int evenLen = expand(s,i,i+1);

            int len = max(oddLen, evenLen);
            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }
        return s.substr(start,maxLen);
    }
};