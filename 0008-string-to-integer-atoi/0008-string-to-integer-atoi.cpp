class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        int sign = 1;
        int result = 0;

        // skip whitespace
        while(i < n && s[i] == ' '){
            i++;
        }
        //check for sign
        if(i<n && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-')
                sign = -1;
            i++;
        }
        //read digits
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
        
            if(result> INT_MAX / 10 || (result == INT_MAX / 10 && digit >7)){
                if(sign ==1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
            result = result * 10 + digit;
            i++;
        }
        return sign * result;
    }
};