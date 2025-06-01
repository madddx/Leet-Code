class Solution {
public:
    long long distributeCandies(int n, int limit) {
        // Total number of non-negative solutions to x + y + z = n
        auto totalSolutions = [](int n) -> long long {
            return n < 0 ? 0 : 1LL * (n + 2) * (n + 1) / 2;
        };

        // Subtract solutions where any variable exceeds limit
        long long total = totalSolutions(n);

        // Subtract cases where one variable > limit
        total -= 3 * totalSolutions(n - limit - 1);

        // Add back cases where two variables > limit
        total += 3 * totalSolutions(n - 2 * limit - 2);

        // Subtract cases where all three variables > limit (usually zero)
        total -= totalSolutions(n - 3 * limit - 3);

        return total;
    }
};
