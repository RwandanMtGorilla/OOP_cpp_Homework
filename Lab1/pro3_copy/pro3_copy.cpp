#include <iostream>
#include <fstream>
#include <string>


int main() {
    std::string line;
    std::ifstream inputFile("../pro2_rand/pro_rand.cpp");  
    std::ofstream outputFile("copy.cpp");

    if (!inputFile.is_open()) {
        std::cerr << "Failed open pro_rand.cpp" << std::endl;
        return 1;
    }
    if (!outputFile.is_open()) {
        std::cerr << "Failed input copy.cpp" << std::endl;
        return 1;
    }

    int lineN = 0;
    while (getline(inputFile, line)) {
        ++lineN;
        outputFile << lineN << ": " << line << std::endl;  // 写入
        std::cout << lineN << ": " << line << std::endl;   // 显示
    }
    inputFile.close();
    outputFile.close();

    std::cout << "accomplished" << std::endl;

    return 0;
}
