class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int len = n + m - 1;

        string word(len, '?');
        vector<bool> locked(len, false);

        // Step 1: Apply all 'T'
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] == '?' || word[i + j] == str2[j]) {
                        word[i + j] = str2[j];
                        locked[i + j] = true;
                    } else {
                        return "";
                    }
                }
            }
        }

        // Step 2: Fill remaining positions greedily
        for (int i = 0; i < len; i++) {
            if (word[i] == '?') {
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;

                    bool valid = true;

                    // Only check windows that include index i
                    int start = max(0, i - m + 1);
                    int end = min(i, n - 1);

                    for (int k = start; k <= end; k++) {
                        bool match = true;
                        for (int j = 0; j < m; j++) {
                            if (word[k + j] != '?' && word[k + j] != str2[j]) {
                                match = false;
                                break;
                            }
                        }

                        if (str1[k] == 'T' && !match) {
                            valid = false;
                            break;
                        }

                        if (str1[k] == 'F') {
                            bool fullMatch = true;
                            for (int j = 0; j < m; j++) {
                                if (word[k + j] != str2[j]) {
                                    fullMatch = false;
                                    break;
                                }
                            }
                            if (fullMatch) {
                                valid = false;
                                break;
                            }
                        }
                    }

                    if (valid) break;
                }
            }
        }

        // Final check
        for (int i = 0; i < n; i++) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (word[i + j] != str2[j]) {
                    match = false;
                    break;
                }
            }

            if (str1[i] == 'T' && !match) return "";
            if (str1[i] == 'F' && match) return "";
        }

        return word;
    }
};