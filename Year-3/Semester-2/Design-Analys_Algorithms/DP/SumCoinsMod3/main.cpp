#include <iostream>
#include <vector>

std::vector<std::vector<int>> maxSumMod3(const std::vector<int>& C) {
    std::vector<std::vector<int>> dp(3, std::vector<int>(C.size(), -INT_MAX));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < C.size(); ++j) {
            if (C[j] % 3 == i) {
                dp[i][j] = C[j];
            }
        }
    }
    std::cout << "log";
    for (int i = 1; i < C.size(); ++i) {
        if (C[i] % 3 == 0) {
            dp[0][i] = std::max(dp[0][i], dp[0][i-1] + C[i]);
            dp[1][i] = std::max(dp[1][i], dp[1][i-1] + C[i]);
            dp[2][i] = std::max(dp[2][i], dp[2][i-1] + C[i]);
        }
        else if (C[i] % 3 == 1) {
            dp[0][i] = std::max(dp[0][i], dp[2][i-1] + C[i]);
            dp[1][i] = std::max(dp[1][i], dp[0][i-1] + C[i]);
            dp[2][i] = std::max(dp[2][i], dp[1][i-1] + C[i]);
        }
        else {
            dp[0][i] = std::max(dp[0][i], dp[1][i-1] + C[i]);
            dp[1][i] = std::max(dp[1][i], dp[2][i-1] + C[i]);
            dp[2][i] = std::max(dp[2][i], dp[0][i-1] + C[i]);
        }
    }
    return dp;
}

int main() {
    std::vector<int> bows = {1, 4, 10, 12, 3, 7, 1 };
    auto dp = maxSumMod3(bows);
    for (int i = 0; i < dp.size(); ++i) {
        for (int j : dp[i]) {
            std::cout << j << ' '; 
        } std::cout << '\n';
    }
    return 0;
}