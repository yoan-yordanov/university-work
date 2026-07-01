#include <iostream>
#include <vector>

std::vector<int> maxLengthVector(const std::vector<int>& A) {
    std::vector<int> dp(A.size(), 1);
    for (int i = 1; i < A.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (A[j] < A[i]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }
    return dp;
}

int main() {
    std::vector<int> numbers = { 1, 2, 0, 4, 3, 5, 7, 2 };
    std::vector<int> maxLengths = maxLengthVector(numbers);
    int max = -1;
    for (int len : maxLengths) {
        max = std::max(max, len);
        std::cout << len << ' ';
    } std::cout << '\n';
    std::cout << "max length: " << max << '\n';
    return 0;
}