1: ﻿#include <iostream>
2: #include <vector>
3: #include <ctime>
4: #include <cstdlib>
5: 
6: int main() {
7:     srand(static_cast<unsigned int>(time(nullptr)));    // ini
8:     int n;
9:     std::cout << "input n: ";
10:     std::cin >> n;
11: 
12:     std::vector<int> nums;
13:     // sum nums
14:     for (int i = 0; i < n; i++) {
15:         int rnd_num = 100 + rand() % 301;  
16:         nums.push_back(rnd_num);
17:     }
18:     double sum = 0;  // 和
19:     for (int num : nums) {
20:         sum += num;  // 总和
21:     }
22:     double mean = sum / n;  //均值
23:     double variance_sum = 0;  // 方差和
24:     for (int num : nums) {
25:         variance_sum += (num - mean) * (num - mean);
26:     }
27:     double variance = variance_sum / n;  
28:     std::cout << "随机数: ";
29:     for (int num : nums) {
30:         std::cout << num << " ";
31:     }
32:     std::cout << "\n均值: " << mean << "\n方差: " << variance << std::endl;
33: 
34:     return 0;
35: }
