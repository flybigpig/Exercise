#include <iostream>
#include <unordered_map>
// C++11 引入了无序容器 std::unordered_map 和 std::unordered_set，它们基于哈希表，提供了更快的查找性能。
int main() {
    std::unordered_map<int, std::string> map;
    map[1] = "One";
    map[2] = "Two";
    map[3] = "Three";

    for (const auto& pair : map) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}