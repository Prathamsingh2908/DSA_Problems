class Solution {
public:
    string reverseWords(string s) {
       vector<string> words;
       string word ="";

       for(int i=0; i< s.size(); i++){
        if(s[i] != ' '){
            word += s[i];   //making the word
        }
        else{
            if(!word.empty()){
                words.push_back(word);  //push the made word
                word = "";  //reset the word
            }
        }
       }
       //for last word
       if(!word.empty()){
            words.push_back(word);
       }
        //reversing the word
       reverse(words.begin(), words.end());

       string result = "";
       for(int i = 0;i < words.size(); i++){
        result += words[i];
            if(i != words.size() - 1){
                result += " ";
            }
       }
        return result;
    }
};