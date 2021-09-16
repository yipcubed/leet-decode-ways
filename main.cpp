#include <algorithm>
#include <climits>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../utils/PrintUtils.hpp"
#include "../utils/VectorUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// https://leetcode.com/problems/check-if-it-is-a-straight-line/
// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() { // NOLINT
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  bool toletter1(string s, int i) { return s[i] >= '1' && s[i] <= '9'; }

  bool toletter2(string s, int i) {
    return (s.size() > i + 1) &&
           (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'));
  }

  int numDecodings(string s) {
    int n = s.size();
    if (s[0] == '0')
      return 0;
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      if (toletter1(s, i - 1)) {
        dp[i] += dp[i - 1];
      }
      if (toletter2(s, i - 2)) {
        dp[i] += dp[i - 2];
      }
      PV2(dp[i], i);
    }
    return dp[n];
  }
};

void test1() {
  cout << boolalpha;
  vector<int> arr{1, 2, 3};

  cout << "2? " << Solution().numDecodings("12") << endl;
  cout << "3? " << Solution().numDecodings("226") << endl;
}

void test2() {}

void test3() {}

// rm -f a.out; g++ -std=c++11 main.cpp ../driver.cpp; ./a.out
