#include <iostream>
#include <string>
using namespace std;

int main() {
    // 字符串的创建和初始化
    string str1 = "Hello";
    string str2("World");
    string str3(5, 'A');  // 创建包含5个'A'的字符串
    
    // 字符串的连接
    string result = str1 + " " + str2;
    cout << "string add result: " << result << endl;
    
    // 字符串的长度
    cout << "str1 length: " << str1.length() << endl;
    cout << "str2 lengrh: " << str2.size() << endl;  // size()和length()等价
    
    // 字符串的访问
    cout << "str1 last cahr: " << str1[0] << endl;
    cout << "str1 last char: " << str1.at(str1.length()-1) << endl;
    
    // 字符串的子串
    string sub = result.substr(0, 5);  // 从位置0开始，取5个字符
    cout << "child string: " << sub << endl;
    
    // 字符串的查找
    size_t pos = result.find("World");
    if (pos != string::npos) {
        cout << "world postion: " << pos << endl;
    }
    
    // 字符串的替换
    result.replace(pos, 5, "C++");
    cout << "replace result: " << result << endl;
    
    // 字符串的比较
    if (str1 == "Hello") {
        cout << "str1 =='Hello'" << endl;
    }
    
    // 字符串的插入
    str1.insert(5, " C++");
    cout << "after insert str1: " << str1 << endl;
    
    // 字符串的删除
    str1.erase(5, 4);  // 从位置5开始删除4个字符
    cout << "after deletestr1: " << str1 << endl;
    
    return 0;
}
