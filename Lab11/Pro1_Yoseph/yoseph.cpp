#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <iterator>

template <typename Container>
void solveJosephusProblem(int n, int m) {
    Container people;
    for (int i = 1; i <= n; ++i) {
        people.push_back(i);
    }

    auto it = people.begin();
    while (!people.empty()) {
        for (int count = 1; count < m; ++count) {
            ++it;
            if (it == people.end()) {
                it = people.begin();
            }
        }
        std::cout << *it << " ";
        it = people.erase(it);
        if (it == people.end()) {
            it = people.begin();
        }
    }
    std::cout << std::endl;
}

int main() {
    int n, m;
    std::cout << "Input n,m: ";
    std::cin >> n >> m;
    // Example usage with different container types
    std::cout << "Using vector: ";
    solveJosephusProblem<std::vector<int>>(n, m);

    std::cout << "Using deque: ";
    solveJosephusProblem<std::deque<int>>(n, m);

    std::cout << "Using list: ";
    solveJosephusProblem<std::list<int>>(n, m);

    return 0;
}
