// 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*'
// 的正则表达式匹配。

// '.' 匹配任意单个字符
// '*' 匹配零个或多个前面的那一个元素
// 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

// 示例 1：

// 输入：s = "aa", p = "a"
// 输出：false
// 解释："a" 无法匹配 "aa" 整个字符串。
// 示例 2:

// 输入：s = "aa", p = "a*"
// 输出：true
// 解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是
// 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。 示例 3：

// 输入：s = "ab", p = ".*"
// 输出：true
// 解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。

// 提示：

// 1 <= s.length <= 20
// 1 <= p.length <= 20
// s 只包含从 a-z 的小写字母。
// p 只包含从 a-z 的小写字母，以及字符 . 和 *。
// 保证每次出现字符 * 时，前面都匹配到有效的字符

#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isMatch(string s, string p) {
    int m = s.length();
    int n = p.length();

    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));

    dp[0][0] = true;
    // 边界状态初始化
    for (int i = 1; i <= m; ++i) {
      dp[i][0] = false;
    }

    for (int j = 1; j <= n; ++j) {
      if (j == 1)
        dp[0][j] = false;
      else if (p[j - 1] == '*')
        dp[0][j] = dp[0][j - 2];
      else
        dp[0][j] = false;
    }
    // 计算所有 DP 值
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (p[j - 1] != '*') {
          dp[i][j] = s[i - 1] == p[j - 1] || p[j - 1] == '.' ? dp[i - 1][j - 1]
                                                             : false;
        } else {
          if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
            dp[i][j] = dp[i - 1][j] | dp[i][j - 2];

          } else
            dp[i][j] = dp[i][j - 2];
        }
      }
    }
    return dp[m][n];
  }
};