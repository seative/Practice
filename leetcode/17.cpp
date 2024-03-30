// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按
// 任意顺序 返回。

// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

// 示例 1：

// 输入：digits = "23"
// 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
// 示例 2：

// 输入：digits = ""
// 输出：[]
// 示例 3：

// 输入：digits = "2"
// 输出：["a","b","c"]
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    std::unordered_map<char, string> phoneMap{
        {'2', "abc"},  {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mnop"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
    };

    vector<string> ans;
    for (int i = 0; i < digits.size(); ++i) {
      string current = phoneMap[digits[i]];
      for (int j = 0; j < current.size(); ++j) {
      }
    }
  }
};
