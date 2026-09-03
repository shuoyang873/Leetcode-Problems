/*
74. 搜索二维矩阵
尝试过
中等
相关标签
premium lock icon
相关企业
给你一个满足下述两条属性的 m x n 整数矩阵：

每行中的整数从左到右按非严格递增顺序排列。
每行的第一个整数大于前一行的最后一个整数。
给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。

你必须编写一个时间复杂度为 O(log(m * n)) 的解决方案。

 

示例 1：


输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
输出：true
示例 2：


输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
输出：false
 

提示：

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {             //这道题采用两次二分查找，这个可以根据题目的描述猜到，因为二分查找的时间复杂度是log n，那么两次二分查找的时间复杂度就是log n +log m=log nm，所以可以知道要用两次二分查找
        auto it=upper_bound(matrix.begin(),matrix.end(),target,[](const int b,const vector<int>&a){return b<a[0];});           //这边的upper_bound用的很简洁，首先明确，upper_bound找到的是有序元素里面第一个不符合条件的元素的位置，可以理解为找到右边界，而lower_bound找到的是左边界

        /*upper_bound的使用有几个注意点，
        1、upper_bound和lower_bound返回的是迭代器，所以前面的数据类型要使用auto；
        2、upper_bound里面的几个参数，首先就是vector的起始和结尾，用.begin()和.end()，然后就是要找的目标值target，
        接着就是Lambda表达式，！！！！！
        重点：1、表达式前面要先加一个[]，然后里面的数据都要用const，
        2、然后就是第一个数据是要找到target，第二个数据是容器里面的元素，比如说这个二维数组vector<vector<int>>容器里面，每一个元素是vector<int>，所以里面要使用vector<int>,
        3、最后，就是要在{}里面写上比较的规则，
        以这道题为例，我们要找到的是第一个大于target的行首元素，那么我们就要写return target<a[0]，这样当运行到true的时候就会自动返回该行的迭代器，
        简单来说，return 里面写的就是自己想要得到的东西*/
        if(it==matrix.begin()){               //这版要注意特殊判断一下迭代器是否是在第一行，如果是在第一行，那么说明一开始的元素就已经大于target，那么target肯定不存在于二维数组中
            return false;
        }
        it--;                                //反之，如果找到了第一个大于target的行，那么说明target可能存在于他的上面那一行，让迭代器--
        return binary_search(it->begin(),it->end(),target);           //最后在这一行里面直接使用c++的algorithm头文件里面自带的binary_search来查找target是否存在于该行，如果存在，直接返回true，反之，返回false
        //这里还有一个要注意的点就是这里的迭代器，要使用的是->，而不可以用.begin(),.end(),迭代器就是指针，指针就只能用->
    }
};