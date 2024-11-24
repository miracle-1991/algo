//
// Created by Xiaolong Ji on 2024/10/20.
//
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if (arr.empty() || k <= 0) { return vector<int>{};} // 预防空输入或者无效参数
        if (k >= arr.size()) { return arr; } // 预防超出边界的参数
        int start = 0;
        int end = arr.size();
        while (true) { // 不断执行分割最后得到分割位置为k的过程其实就是一个二分查找的过程
            int position = partition(arr, start, end);
            if (position == k) {
                return vector<int>(arr.begin(), arr.begin() + k); // 使用一个vector初始化另外一个vector
            } else if (position < k) {
                start = position + 1; // 如果分割后的位置位于目标位置的左边，这个时候只分割右边就行了
            } else {
                end = position; // 否则就分割左边
            }
        }
        return vector<int>{};
    }
private:
    // partition 是快速排序的核心函数，输入一个数组和范围（左开右闭），输出这次分割的结果，分割的结果是一个索引值，索引的左边和右边分别不大于和大于该位置的值
    int partition(vector<int>& arr, int start, int end) {
        int flag = arr[start]; // better use random to select value in range [start, end)
        int i = start + 1; // start位置是参考值， 需要将其他位置的值与start位置的值进行比较，分割成两个部分
        int j = end - 1; // end是右边界，无法达到
        while (i <= j) { // 分割的基本过程类似于双指针，左右分别右两个指针，向中间聚拢，左指针指向的值都是不大于参考值的值，右指针指向的值都是大于参考值的值
            while (arr[i] <= flag && i < end) { i++; } // 移动左指针，直到找到一个大于参考值的值，该值需要放到右侧。移动的过程中注意边界，否则左指针会超出右边界
            while (arr[j] > flag && j > start) { j--; } // 移动右指针，直到找到一个小于等于参考值的值，该值需要放到左侧。移动的过程中同样注意边界
            if (i < j) { // 交换左右两个指针的位置，注意这里不要用<=，因为交换相同的元素没有任何意义
                swap(arr, i, j);
            }
        }
        swap(arr, start, j); // 退出循环时，左指针指向的是第一个大于参考值的位置，右指针指向的是第一个小于等于参考值的位置，因为要保证左侧的值都小于等于参考值，所以交换j与start,将右指针这个小于等于参考值的值移到最左边, 此时j左边的一定都是小于等于arr[j]的，右侧一定是大于arr[j]的
        return j; // 上一行已经保证arr[j]左右两侧的值分别是小于等于/大于a[j]的值，所以这次分割后的结果就是j索引
    }
    void swap(vector<int>& arr, int left, int right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }
};

void PrintVector(const vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\t";
    }
    cout << endl;
}

int main() {
    /* 设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。
     * 示例：
     * 输入： arr = [1,3,5,7,2,4,6,8], k = 4
     * 输出： [1,2,3,4]
     * */
    Solution s;
    vector<int> test = {1,3,5,7,2,4,6,8};
    vector<int> result = s.smallestK(test, 4);
    PrintVector(result);
}