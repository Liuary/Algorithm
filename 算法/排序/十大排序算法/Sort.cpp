// 参考资料:
// https://www.cnblogs.com/SeaSky0606/p/4559990.html
// https://blog.csdn.net/zhangsy_csdn/article/details/91483600
// https://www.bilibili.com/video/BV1Eb41147dK?from=search&seid=17028087413122947333
// 最佳用时是指个人默写该算法代码的速度……

#include <bits\stdc++.h>

#define DEBUG 1

#if DEBUG
#define print(args) std::cout << args
#define println(args) std::cout << args << std::endl
#else
#define print(args)
#define println(args)
#endif

using namespace std;

void printArray(int *arr, int len)
{
    for (int i = 0; i < len; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/**
 * 函数名: 冒泡排序
 * 时间复杂度: O(n^2)
 * 稳定性: 稳定
 * 最佳用时: 00:48.49
 * 备注: 从前往后判断两个相邻元素大小，大者后移，循环n次，最终从小大大排序
 * */
void bubbleSort(int *arr, int len)
{
    for (int i = 0; i < len; ++i)
    {
        for (int j = 1; j < len - i; ++j)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
}

/**
 * 函数名: 选择排序
 * 时间复杂度: O(n^2)
 * 稳定性: 不稳定
 * 最佳用时: 00:53.65
 * 备注: 获取一趟中的最大值，将这个值和每趟最末尾元素交换，index是最大元素的下标
 * */
void selectSort(int *arr, int len)
{
    for (int i = 0; i < len; ++i)
    {
        int index = 0, j = 1;
        for (; j < len - i; ++j)
        {
            if (arr[index] < arr[j])
            {
                index = j;
            }
        }
        swap(arr[index], arr[j - 1]);
    }
}

/**
 * 函数名: 插入排序
 * 时间复杂度: O(n^2)
 * 稳定性: 稳定
 * 最佳用时: 00:41.48
 * 备注: 判断当前位置和前面元素大小，小于则与前面元素交换位置
 * */
void insertSort(int *arr, int len)
{
    for (int i = 1; i < len; ++i)
    {
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; --j)
        {
            swap(arr[j], arr[j - 1]);
        }
    }
}

/**
 * 函数名: 希尔排序
 * 时间复杂度: O(nlog2n)
 * 稳定性: 不稳定
 * 最佳用时: 01:06.10
 * 备注: 以插入排序为基础，但是增加步长，这里设置步长为3
 * */
void shellSort(int *arr, int len)
{
    for (int step = len / 3; step > 0; step /= 3)
    {
        for (int i = 1; i < len; i += step)
        {
            for (int j = i; j > 0 && arr[j] < arr[j - step]; j -= step)
            {
                swap(arr[j], arr[j - step]);
            }
        }
    }
}

/**
 * 函数名: 归并排序
 * 时间复杂度: O(nlog2n)
 * 稳定性: 稳定
 * 最佳用时: 02:43.10
 * 备注: 递归拆分数组并排序，最终合并，其中left和right分别是起点和终点，左闭右开，temp是辅助存储的相同大小数组
 * */
void mergeSort(int *arr, int left, int right, int *temp)
{
    if (left + 1 >= right)
    {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid, temp);
    mergeSort(arr, mid, right, temp);
    for (int i = left, x = left, y = mid; i < right;)
    {
        if (y < right && x < mid && arr[x] < arr[y] || y > right)
        {
            temp[i++] = arr[x++];
        }
        else
        {
            temp[i++] = arr[y++];
        }
    }

    for (int i = left; i < right; ++i)
    {
        arr[i] = temp[i];
    }
}

/**
 * 函数名: 快速排序
 * 时间复杂度: O(nlog2n)
 * 稳定性: 不稳定
 * 最佳用时: 1:52.98
 * 备注: 1 - 在这段代码中，i是一个标记点，比i小的都在i左边，比i大的都在i右边，最终i对应的元素是末位元素
 * 备注: 2 - 即用末位元素作为标记点。排序完成之后，使用递归对子排序进行相同操作，最终不可再分时，排序完成
 * */
void quickSort(int *arr, int left, int right)
{
    if (left + 1 >= right - 1)
    {
        return;
    }
    int i = left - 1;
    for (int j = left; j < right - 1; ++j)
    {
        if (arr[j] < arr[right - 1])
        {
            swap(arr[++i], arr[j]);
        }
    }
    swap(arr[++i], arr[right - 1]);
    quickSort(arr, left, i);
    quickSort(arr, i + 1, right);
}

// 下面两个函数都是堆排序需要用到的
void heapify(int *arr, int len, int index)
{
    if (index >= len)
    {
        return ;
    }
    int max = index;
    int c1 = index * 2 + 1;
    int c2 = c1 + 1;
    if (c1 < len && arr[c1] > arr[max])
    {
        max = c1;
    }
    if (c2 < len && arr[c2] > arr[max])
    {
        max = c2;
    }
    if (max != index)
    {
        swap(arr[max], arr[index]);
        heapify(arr, len, max);
    }
}

void buildHeap(int *arr, int len)
{
    int lastNode = len - 1;
    int parent = (lastNode - 1) / 2;
    for (int i = parent; i >= 0; --i)
    {
        heapify(arr, len, i);
    }
}

/**
 * 函数名: 堆排序
 * 时间复杂度: O(nlog2n)
 * 稳定性: 不稳定
 * 最佳用时: 
 * 备注: 1 - https://www.bilibili.com/video/BV1Eb41147dK?from=search&seid=17028087413122947333
 * 备注: 2 - 需要用到buildHeap先构建好堆，过程中需要heapify保证父节点大于子节点，最终将堆顶元素和数组最后的值交换并重新heapify
 * 备注: 3 - 去掉数组最末尾的值重复上述操作，最终实现数组排序
 * */
void heapSort(int *arr, int len)
{
    buildHeap(arr, len);
    for (int i = len; i > 0; --i)
    {
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}

/**
 * 函数名: 计数排序
 * 时间复杂度: O(n + k)
 * 稳定性: 稳定
 * 最佳用时: 
 * 备注: 需要大量额外空间，用额外空间的下标作为计数的容器，记录原始数组对应下标数据出现的次数，最后将数据写入到原始数组
 * */
void countSort(int *arr, int len)
{
    int max = arr[0];
    for (int i = 1; i < len; ++i)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    int *temp = new int[max + 1];
    for (int i = 0; i < max + 1; ++i)
    {
        temp[i] = 0;
    }
    for (int i = 0; i < len; ++i)
    {
        temp[arr[i]]++;
    }
    for (int i = 0, j = 0; i < max + 1 && j < len; ++i)
    {
        while (temp[i] > 0)
        {
            arr[j++] = i;
            temp[i]--;
        }
    }
}

/**
 * 函数名: 桶排序
 * 时间复杂度: 
 * 稳定性: 
 * 最佳用时: 
 * 备注: 1 - https://www.bilibili.com/video/BV1A4411N7cG?from=search&seid=522678023390689622
 * 备注: 2 - 桶排序使用较少，原理是将数组数据范围中的数据划分为多个桶，将数据分配到桶里，各个桶单独排序，最后统一输出
 * */

/**
 * 函数名: 基数排序
 * 时间复杂度: 
 * 稳定性: 
 * 最佳用时: 
 * 备注: 1 - https://www.bilibili.com/video/BV1UJ411h7Yg?from=search&seid=5246154955251731078
 * 备注: 2 - 基数排序基于桶排序，需要十个桶（十进制，其它进制对应进制数的桶），从最低位（个位）网上依次入桶，
 * 备注: 3 - 然后再倒序放回原数组，接着从最低位到最高位，所有位数都完成后，倒序取出就是从小到大的序列
 * */

int main(int argc, char const *argv[])
{

    int arr[] = {18, 7, 4, 2, 9, 4, 12, 6, 1, 5};

    int len = sizeof(arr) / sizeof(arr[0]);

    // bubbleSort(arr, len);

    // selectSort(arr, len);

    // insertSort(arr, len);

    // shellSort(arr, len);

    // int T[10];
    // mergeSort(arr, 0, len, T);

    // quickSort(arr, 0, len);

    // heapSort(arr, len);

    countSort(arr, len);

    printArray(arr, len);

    system("pause");
    return 0;
}
