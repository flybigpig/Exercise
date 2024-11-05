#include <iostream>
#include <vector>
#include <algorithm>

// 命名空间
using namespace  std;
int main() {
    cout << "Hello, World!" << std::endl;
    return 0;
}



// 贪心算法示例：活动选择问题
#include <iostream>
#include <vector>
#include <algorithm>

struct Activity {
    int start;
    int finish;
};

bool activityCompare(Activity s1, Activity s2) {
    return (s1.finish < s2.finish);
}

void printMaxActivities(std::vector<Activity>& activities) {
    // 按活动结束时间排序
    std::sort(activities.begin(), activities.end(), activityCompare);

    std::cout << "Selected activities are: " << std::endl;

    // 第一个活动总是被选中
    int i = 0;
    std::cout << "(" << activities[i].start << ", " << activities[i].finish << "), ";

    // 考虑其余的活动
    for (int j = 1; j < activities.size(); j++) {
        // 如果这个活动的开始时间大于等于上一个被选中活动的结束时间，则选中它
        if (activities[j].start >= activities[i].finish) {
            std::cout << "(" << activities[j].start << ", " << activities[j].finish << "), ";
            i = j;
        }
    }
    std::cout << std::endl;
}



int add(int a, int b) {
    return a + b;
}


void sortVector(std::vector<int>& vec) {
    std::sort(vec.begin(), vec.end());
}


void arraySort(int arr[], int size) {
    std::sort(arr, arr + size);
}

void quickSort(std::vector<int>& vec, int low, int high) {
    if (low < high) {
        int pi = partition(vec, low, high);

        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}

int partition(std::vector<int>& vec, int low, int high) {
    int pivot = vec[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (vec[j] < pivot) {
            i++;
            std::swap(vec[i], vec[j]);
        }
    }
    std::swap(vec[i + 1], vec[high]);
    return (i + 1);
}
