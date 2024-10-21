#include <iostream>
#include <vector>

class ChangeMaking {
  public:
    ChangeMaking(float& cuantity);
    void GreedyAlgorithm();
    void ImprovedGreedyAlgorithm();
    void GreedyAlgorithmWithBanknotes();
    float Search();
    void CheckRepeatedCoins(float& coin);

    void MostFrequentCoin();

    friend std::ostream& operator<<(std::ostream& os, const ChangeMaking& change_making);
  private:
    float cuantity_;
    float sum_;
    std::vector<float> coins_;
    std::vector<float> solution_;
    std::vector<int> coins_number_;
    int most_frequent_coin_;
    int total_coins_;
};
