class Solution {
public:
    
    int getWaviness(int num) {
        string s = to_string(num);

        if (s.length() < 3) {
            return 0;
        }

        int waviness = 0;

        for (int i = 1; i < s.length() - 1; i++) {

            // Peak
            if (s[i] > s[i - 1] && s[i] > s[i + 1]) {
                waviness++;
            }

            // Valley
            else if (s[i] < s[i - 1] && s[i] < s[i + 1]) {
                waviness++;
            }
        }

        return waviness;
    }

    int totalWaviness(int num1, int num2) {
        int total = 0;

        for (int num = num1; num <= num2; num++) {
            total += getWaviness(num);
        }

        return total;
    }
};