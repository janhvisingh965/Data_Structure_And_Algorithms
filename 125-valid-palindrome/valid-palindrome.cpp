class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";

        for(char c : s){
            if((c >= 'a' && c <= 'z') || 
               (c >= 'A' && c <= 'Z') || 
               (c >= '0' && c <= '9')){

                if(c >= 'A' && c <= 'Z'){
                    c = c + 32;
                }
                t += c;
            }
        }

        int i = 0, j = t.size() - 1;

        while(i < j){
            if(t[i] != t[j]) return false;
            i++;
            j--;
        }

        return true;
    }
};