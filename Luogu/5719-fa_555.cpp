#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  int N, K;

  std::cin >> N >> K;
  std::vector<int> v(N, 0);
  std::iota(v.begin(), v.end(), 1);

  std::function<bool(int)> isDivisible = [&](int x) { return x % K == 0; };
  std::function<bool(int)> notDivisible = [&](int x) { return x % K != 0; };

  std::cout << std::fixed << std::setprecision(1);

  std::cout << std::accumulate(v.begin(), v.end(), 0,
                               [&](const int &lhs, const int &rhs) {
                                 return isDivisible(rhs) ? lhs + rhs : lhs;
                               }) /
                   static_cast<double>(
                       std::count_if(v.begin(), v.end(), isDivisible))
            << ' ';

  std::cout << std::accumulate(v.begin(), v.end(), 0,
                               [&](const int &lhs, const int &rhs) {
                                 return notDivisible(rhs) ? lhs + rhs : lhs;
                               }) /
                   static_cast<double>(
                       std::count_if(v.begin(), v.end(), notDivisible))
            << '\n';

  return 0;
}
