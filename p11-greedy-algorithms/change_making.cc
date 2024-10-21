#include "change_making.h"


ChangeMaking::ChangeMaking(float& cuantity) {
  cuantity_ = cuantity;
  sum_ = 0.0;
  coins_ = {2.0, 1.0, 0.5, 0.2, 0.1, 0.05, 0.02, 0.01};
  solution_ = {};
  coins_number_ = {};
  total_coins_ = 0;
  most_frequent_coin_ = 0;
}

void ChangeMaking::GreedyAlgorithm() {
  while (sum_ != cuantity_) {
    float v = Search();
    if (v == -1) {
      break;
    } else {
      sum_ += v;
      CheckRepeatedCoins(v);
    }
  }
  MostFrequentCoin();
}


float ChangeMaking::Search() {
  for (unsigned int index = 0; index < coins_.size(); index++) {
    if (sum_ + coins_[index] <= cuantity_) {
      return coins_[index];
    }
  }
  return -1;
}

void ChangeMaking::ImprovedGreedyAlgorithm() {
  for (unsigned int index = 0 ; index < coins_.size(); index++) {
    int c = (cuantity_ - sum_) / coins_[index];
    if (c > 0) {
      solution_.push_back(coins_[index]);
      coins_number_.push_back(c);
      sum_ += coins_[index] * c;
      total_coins_ += c;
    }
  }
  MostFrequentCoin();
}

void ChangeMaking::GreedyAlgorithmWithBanknotes() {
  coins_.insert(coins_.begin(), {500.0, 200.0, 100.0, 50.0, 20.0, 10.0, 5.0});
  GreedyAlgorithm();
}

void ChangeMaking::CheckRepeatedCoins(float& coin) {
  if (solution_.empty()) {
    solution_.push_back(coin);
    coins_number_.push_back(1);
    total_coins_++;
  } else {
    for (unsigned int index = 0; index < solution_.size(); index++) {
      if (solution_[index] == coin) {
        coins_number_[index]++;
        total_coins_++;
        return;
      }
    }
    solution_.push_back(coin);
    coins_number_.push_back(1);
    total_coins_++;
  }
}

void ChangeMaking::MostFrequentCoin() {
  int max = 0;
  for (unsigned int index = 0; index < coins_number_.size(); index++) {
    if (coins_number_[index] > max) {
      max = coins_number_[index];
      most_frequent_coin_ = index;
    }
  }
}

std::ostream& operator<<(std::ostream& os, const ChangeMaking& change_making) {
  os << "Solution: ";
  for (unsigned int index = 0; index < change_making.solution_.size(); index++) {
    os << change_making.coins_number_[index] << "x" << change_making.solution_[index] << "$ ";
  }
  os << std::endl;
  os << "Total coins: " << change_making.total_coins_ << std::endl;
  os << "Most frecuent coin: " << change_making.solution_[change_making.most_frequent_coin_] << "$" << std::endl;
  return os;
}

