class Solution {
public:
    string countAndSay(int n) {
        string curr = "1";
        
        for (int t = 1; t < n; t++) {  // repeat n-1 times
            string next = "";
            
            for (int i = 0; i < curr.length(); i++) {
                char ch = curr[i];
                int count = 1;
                
                while (i < curr.length() - 1 && curr[i] == curr[i + 1]) {
                    count++;
                    i++;
                }
                
                next += to_string(count) + ch;
            }
            
            curr = next;
        }
        
        return curr;
    }
};