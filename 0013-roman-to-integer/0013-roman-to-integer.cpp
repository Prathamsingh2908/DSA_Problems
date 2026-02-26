
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int result = 0;
        for(int i=0; i<s.size(); i++){
            if(i< s.length() - 1 && m[s[i]] < m[s[i+1]]){
                result -= m[s[i]]; //subtract
            }
            else{
                result += m[s[i]];//add
            }
        }
        return result;
    }
};