#include <vector>
#include <iostream>
#include <algorithm>

void maxStockProfit(std::vector<double> v) {
  double min_value = std::numeric_limits<double>::max();
  double max_profit = 0;
  for (auto& item : v) {
    min_value = std::min(min_value, item);
    max_profit = std::max(max_profit, item - min_value);
  }
  std::cout << "Min value is " << min_value << " Max profit is " << max_profit << std::endl;
}

int main() {
  std::vector<double>prices = {4, 1, 2, 3, 4, 5, 2, 0, 2, 4, 8};
  for (auto& thing : prices) {
    std::cout << thing << " ";
  }
  std::cout << std::endl;
  maxStockProfit(prices);
}
