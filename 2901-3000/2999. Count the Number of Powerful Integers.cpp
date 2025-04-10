class Solution {
    #define ll long long
    ll dp[17][2];

    // Compare suffix numerically
    bool checkSubtract(string& fin, ll& finish_digits, string& s, int& limit) {
        if (finish_digits < s.size()) return false;

        string suffix_of_fin = fin.substr(finish_digits - s.size());
        bool subtract = stoll(suffix_of_fin) < stoll(s);

        for (int i = 0; subtract == true && i < finish_digits - s.size(); ++i) {
            if ((fin[i] - '0') > limit) {
                subtract = false;
                break;
            }
        }
        return subtract;
    }

    //Digit DP
    ll countValidNumbers(string& number, ll curr_idx, ll& max_digits, bool is_tight, int& limit, string& s) {
        if (curr_idx == max_digits) return 1; // A valid sequence has been formed
        if (dp[curr_idx][is_tight] != -1) return dp[curr_idx][is_tight];

        ll low = 0, high;

        if (curr_idx >= (max_digits - s.size())) {
            ll idx = curr_idx - (max_digits - s.size());
            low = high = s[idx] - '0';
        } else {
            high = is_tight ? min<ll>(limit, number[curr_idx] - '0') : limit;
        }

        ll count = 0;
        for (ll digit = low; digit <= high; ++digit) {
            bool new_tight = is_tight && (digit == number[curr_idx] - '0');
            count += countValidNumbers(number, curr_idx + 1, max_digits, new_tight, limit, s);
        }

        return dp[curr_idx][is_tight] = count;
    }

public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        ll suffix_number = stoll(s);
        string fin = to_string(finish);
        string beg = to_string(start - 1);

        ll finish_digits = fin.size();
        ll start_digits = (start <= 1) ? 0 : beg.size();

        // Finish
        memset(dp, -1, sizeof(dp));
        ll one_to_finish = 0;
        if (finish >= suffix_number) {
            one_to_finish = countValidNumbers(fin, 0, finish_digits, true, limit, s);
            if (checkSubtract(fin, finish_digits, s, limit))
                one_to_finish--;
        }

        // Start - 1
        memset(dp, -1, sizeof(dp));
        ll one_to_start = 0;
        if (suffix_number < start && start > 1) {
            one_to_start = countValidNumbers(beg, 0, start_digits, true, limit, s);
            if (checkSubtract(beg, start_digits, s, limit))
                one_to_start--;
        }

        return one_to_finish - one_to_start;
    }
};

/*
//JAVA
import java.util.Arrays;

class Solution {
    long[][] dp;

    // Compare suffix numerically
    boolean checkSubtract(String fin, long finish_digits, String s, int limit) {
        if (finish_digits < s.length()) return false;

        String suffix_of_fin = fin.substring((int)(finish_digits - s.length()));
        boolean subtract = Long.parseLong(suffix_of_fin) < Long.parseLong(s);

        for (int i = 0; subtract == true && i < finish_digits - s.length(); ++i) {
            if ((fin.charAt(i) - '0') > limit) {
                subtract = false;
                break;
            }
        }
        return subtract;
    }

    // Digit DP
    long countValidNumbers(String number, int curr_idx, long max_digits, boolean is_tight, int limit, String s) {
        if (curr_idx == max_digits) return 1; // A valid sequence has been formed
        if (dp[curr_idx][is_tight ? 1 : 0] != -1) return dp[curr_idx][is_tight ? 1 : 0];

        long low = 0, high;

        if (curr_idx >= (max_digits - s.length())) {
            int idx = curr_idx - (int)(max_digits - s.length());
            low = high = s.charAt(idx) - '0';
        } else {
            high = is_tight ? Math.min(limit, number.charAt(curr_idx) - '0') : limit;
        }

        long count = 0;
        for (long digit = low; digit <= high; ++digit) {
            boolean new_tight = is_tight && (digit == number.charAt(curr_idx) - '0');
            count += countValidNumbers(number, curr_idx + 1, max_digits, new_tight, limit, s);
        }

        dp[curr_idx][is_tight ? 1 : 0] = count;
        return count;
    }

    public long numberOfPowerfulInt(long start, long finish, int limit, String s) {
        long suffix_number = Long.parseLong(s);
        String fin = Long.toString(finish);
        String beg = Long.toString(start - 1);

        long finish_digits = fin.length();
        long start_digits = (start <= 1) ? 0 : beg.length();

        // Finish
        dp = new long[17][2];
        for (long[] row : dp) Arrays.fill(row, -1);
        long one_to_finish = 0;
        if (finish >= suffix_number) {
            one_to_finish = countValidNumbers(fin, 0, finish_digits, true, limit, s);
            if (checkSubtract(fin, finish_digits, s, limit))
                one_to_finish--;
        }

        // Start - 1
        dp = new long[17][2];
        for (long[] row : dp) Arrays.fill(row, -1);
        long one_to_start = 0;
        if (suffix_number < start && start > 1) {
            one_to_start = countValidNumbers(beg, 0, start_digits, true, limit, s);
            if (checkSubtract(beg, start_digits, s, limit))
                one_to_start--;
        }

        return one_to_finish - one_to_start;
    }
}

#Python
class Solution:
    def checkSubtract(self, fin: str, finish_digits: int, s: str, limit: int) -> bool:
        if finish_digits < len(s):
            return False
        
        suffix_of_fin = fin[finish_digits - len(s):]
        subtract = int(suffix_of_fin) < int(s)
        
        for i in range(finish_digits - len(s)):
            if int(fin[i]) > limit:
                subtract = False
                break
        return subtract
    
    def countValidNumbers(self, number: str, curr_idx: int, max_digits: int, is_tight: bool, limit: int, s: str, dp: list) -> int:
        if curr_idx == max_digits:
            return 1
        if dp[curr_idx][1 if is_tight else 0] != -1:
            return dp[curr_idx][1 if is_tight else 0]
        
        if curr_idx >= (max_digits - len(s)):
            idx = curr_idx - (max_digits - len(s))
            low = high = int(s[idx])
        else:
            high = min(limit, int(number[curr_idx])) if is_tight else limit
            low = 0
        
        count = 0
        for digit in range(low, high + 1):
            new_tight = is_tight and (digit == int(number[curr_idx]))
            count += self.countValidNumbers(number, curr_idx + 1, max_digits, new_tight, limit, s, dp)
        
        dp[curr_idx][1 if is_tight else 0] = count
        return count
    
    def numberOfPowerfulInt(self, start: int, finish: int, limit: int, s: str) -> int:
        suffix_number = int(s)
        fin = str(finish)
        beg = str(start - 1)
        
        finish_digits = len(fin)
        start_digits = 0 if start <= 1 else len(beg)
        
        # Finish
        dp = [[-1 for _ in range(2)] for _ in range(17)]
        one_to_finish = 0
        if finish >= suffix_number:
            one_to_finish = self.countValidNumbers(fin, 0, finish_digits, True, limit, s, dp)
            if self.checkSubtract(fin, finish_digits, s, limit):
                one_to_finish -= 1
        
        # Start - 1
        dp = [[-1 for _ in range(2)] for _ in range(17)]
        one_to_start = 0
        if suffix_number < start and start > 1:
            one_to_start = self.countValidNumbers(beg, 0, start_digits, True, limit, s, dp)
            if self.checkSubtract(beg, start_digits, s, limit):
                one_to_start -= 1
        
        return one_to_finish - one_to_start
*/
