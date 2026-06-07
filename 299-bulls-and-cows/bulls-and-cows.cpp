class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        vector<int> sec(10,0);
        vector<int> gue(10,0);
        for(int i = 0;i<secret.length();i++){
            if(secret[i]==guess[i]){
                bulls++;
            }
            else{
                sec[secret[i]-'0']++;
                gue[guess[i]-'0']++;

            }
        }
        for(int d = 0;d<10;d++){
            cows = cows + min(sec[d],gue[d]);

        }
        return to_string(bulls)+"A" + to_string(cows)+"B";

        
    }
};