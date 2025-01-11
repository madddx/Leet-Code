class Solution {
public:
    bool canConstruct(string s, int k) {

        // If the size of s is less than k, it's not possible to construct k palindromes
        if (s.size() < k) {
            return false;
        }

        // Array to store the frequency of each letter in the string
        int letterCount[26] = {0};
        // Count the frequency of each character in s
        for (char& c : s) {
            ++letterCount[c - 'a'];
        }

        // Variable to keep track of the number of characters with odd frequency
        // (which determines how many palindromes can be made)
        int oddCount = 0;
        // Check the letter frequencies
        for (int count : letterCount) {
            // If the count is odd, increment oddCount
            oddCount += count & 1;
        }

        // A palindrome can accommodate one odd count character (the middle one), so if there
        // are more odd count characters than k, it's not possible to create k palindromes.
        // hence, we return whether the oddCount is less than or equal to k.
        return oddCount <= k;
    }
};
