class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 1) return encodedText;

        int n = encodedText.size();
        int cols = n / rows;

        string result = "";

        // start from each column of first row
        for (int start = 0; start < cols; start++) {
            int r = 0, c = start;

            while (r < rows && c < cols) {
                result += encodedText[r * cols + c];
                r++;
                c++;
            }
        }

        // remove trailing spaces
        while (!result.empty() && result.back() == ' ')
            result.pop_back();

        return result;
    }
};