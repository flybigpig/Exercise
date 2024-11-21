#include <iostream>
#include <string>
using namespace std;

int main() {
    // 字符串声明和初始化
    string str1 = "Hello";
    string str2("World");
    string str3(5, '*');  // 创建包含5个*的字符串

    // 字符串连接
    string result = str1 + " " + str2;  // Hello World
    cout << "连接后的字符串: " << result << endl;

    // 字符串长度
    cout << "字符串长度: " << result.length() << endl;

    // 字符串比较
    if (str1 == "Hello") {
        cout << "str1等于Hello" << endl;
    }

    // 字符串查找
    size_t pos = result.find("World");
    if (pos != string::npos) {
        cout << "找到World,位置在: " << pos << endl;
    }

    // 字符串截取
    string sub = result.substr(0, 5);  // 从位置0开始截取5个字符
    cout << "截取的子串: " << sub << endl;

    // 字符操作
    char ch = 'A';
    cout << "字符: " << ch << endl;
    cout << "转为小写: " << (char)tolower(ch) << endl;
    cout << "是否为字母: " << (isalpha(ch) ? "是" : "否") << endl;
    
    // 字符串修改
    result[0] = 'h';  // 修改第一个字符
    cout << "修改后的字符串: " << result << endl;

    // 字符串插入和删除
    result.insert(5, "!");
    cout << "插入后的字符串: " << result << endl;
    
    result.erase(5, 1);
    cout << "删除后的字符串: " << result << endl;

    return 0;
}
