#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));    // ini
    int n;
    std::cout << "input n: ";
    std::cin >> n;

    std::vector<int> nums;
    // sum nums
    for (int i = 0; i < n; i++) {
        int rnd_num = 100 + rand() % 301;  
        nums.push_back(rnd_num);
    }
    double sum = 0;  // 和
    for (int num : nums) {
        sum += num;  // 总和
    }
    double mean = sum / n;  //均值
    double variance_sum = 0;  // 方差和
    for (int num : nums) {
        variance_sum += (num - mean) * (num - mean);
    }
    double variance = variance_sum / n;  
    std::cout << "随机数: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << "\n均值: " << mean << "\n方差: " << variance << std::endl;

    return 0;
}
