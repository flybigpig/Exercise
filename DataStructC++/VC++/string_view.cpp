#include <iostream>
#include <string_view>
#include <string>


using namespace std;
/**
 * 演示string_view的使用
 * string_view提供了一个字符串的只读视图，不会进行内存分配
 * 主要用于提高性能，避免不必要的字符串拷贝
 */

int main() {
    // 1. 基本使用
    std::string str = "Hello World";
    std::string_view sv = str;
    std::cout << "string_view content: " << sv << std::endl;

    // 2. 子串操作
    std::string_view sv2 = sv.substr(0, 5);  // "Hello"
    std::cout << "substring: " << sv2 << std::endl;

    // 3. 与const char*比较
    const char* cstr = "Test String";
    std::string_view sv3(cstr);
    std::cout << "from const char*: " << sv3 << std::endl;

    // 4. 不会进行内存分配的操作
    std::string_view sv4 = "Direct Init";
    std::cout << "length: " << sv4.length() << std::endl;
    std::cout << "is empty: " << std::boolalpha << sv4.empty() << std::endl;

    // 5. 移除前缀和后缀
    std::string_view sv5 = "  trimmed  ";
    sv5.remove_prefix(2);  // 移除前导空格
    sv5.remove_suffix(2);  // 移除尾部空格
    std::cout << "after trim: [" << sv5 << "]" << std::endl;

    // 6. 与std::string的转换
    std::string str2 = std::string(sv);
    std::cout << "converted to string: " << str2 << std::endl;

    return 0;
}
