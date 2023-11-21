##Common Sorting Algorithms Summary

**Quick Sort （快速排序）**
- Unstable
- Space: O(n log n)
- Time: Best & Average O(n log n); Worst O(n^2) -> 选择到最小最大数作为pivot
- Non-Adaptive
- In-place

快速排序尤其适用于对大数据的排序。就是指以一个数为基准（pivot），将序列中的其他数往它两边“扔”。
以从小到大排序为例，比它小的都“扔”到它的左边，比它大的都“扔”到它的右边，然后左右两边再分别重复这个操作，
不停地分，直至分到每一个分区的基准数的左边或者右边都只剩一个数为止。这时排序也就完成了。

过程涉及到**递归**。

<https://c.biancheng.net/view/198.html>
<https://cgi.cse.unsw.edu.au/~cs2521/23T3/lectures/slides/week02wed-quicksort.pdf>

**Merge Sort （归并排序）**
- Stable
- Spaces: O(n) -> 和原数组相同长度的辅助array
- Time: O(n log n)
- Non-Adaptive
- Not In-place

把数组分成两半， 将两个有序的数列合并成一个大的有序的序列。

分解：将数组从中间分成两半，如果数组有奇数个元素，则一个子数组将多出一个元素。
递归排序：递归地将这两半数组分别排序。
合并：将排序好的两半合并成一个排序好的整体。

过程涉及到**递归**。

<https://www.dotcpp.com/course/164>
<https://cgi.cse.unsw.edu.au/~cs2521/23T3/lectures/slides/week02mon-mergesort.pdf>

**Selection Sort （选择排序）**
- Unstable
- Spaces: O(1)
- Time: O(n^2)
- Non-Adaptive
- In-place

设置两个记录i和j，i自数组第一个元素开始，j自i+1个元素开始。
接着j遍历整个数组，选出整个数组最小的值，并让这个最小的值和i的位置交换
（如果i选择的元素是最小的则不需要交换），我们称这个过程为一趟选择排序。
i选中下一个元素(i++)，重复进行每一趟选择排序。
持续上述步骤，使得i到达n-1处，即完成排序。

<https://www.dotcpp.com/course/160>
<https://cgi.cse.unsw.edu.au/~cs2521/23T3/lectures/slides/week02mon-sorting-intro.pdf>

**Insection Sort （插入排序）**
- Stable
- Spaces: O(1)
- Time: Best O(n) -> already sorted; Average && Worst O(n^2)
- Adaptive
- In-place

每次从无序表中取出第一个元素，把它插入到有序表的合适位置，使有序表仍然有序。
第一趟比较前两个数，然后把第二个数按大小插入到有序表中；
第二趟把第三个数据与前两个数从后向前扫描，把第三个数按大小插入到有序表中；
依次进行下去，进行了(n-1)趟扫描以后就完成了整个排序过程。

有两层loop组成。外层循环标识并决定待比较的数值。内层循环为待比较数值确定其最终位置。

<https://www.dotcpp.com/course/161>
<https://cgi.cse.unsw.edu.au/~cs2521/23T3/lectures/slides/week02mon-sorting-intro.pdf>

**Shell Sort （哈希排序）**
- Unstable
- Spaces: O(1)
- Time(depends on the code): Best O(n log n) -> partial sorted; Worst O(n^2)
- Adaptive
- In-place

将相距一定间隔的多个元素组成一个子序列，对每个子序列进行插入排序。
随着间隔的逐渐减少，最后当间隔为1时，整个数据合成一个序列，并进行最后一次插入排序。

<https://www.dotcpp.com/course/162>
<https://cgi.cse.unsw.edu.au/~cs2521/23T3/lectures/slides/week02mon-sorting-intro.pdf>

过程涉及到**三层嵌套**。

**Bubble Sort （冒泡排序）**
- Stable
- Spaces: O(1)
- Time: Best O(n) -> already sorted; Average && Worst O(n^2)
- Adaptive
- In-place

从第一个元素开始逐个比较相邻的元素。如果第一个比第二个大（a[1]>a[2]），就交换他们两个。
对每一对相邻元素做同样的工作，从开始第一对到结尾的最后一对。
此时在这一点，最后的元素应该会是最大的数，我们也称呼一遍这样的操作为：一趟冒泡排序。
针对所有的元素重复以上的步骤，每一趟冒泡排序的最大值已放在最后，下一次操作则不需要将此最大值纳入计算计算。
持续对每次对越来越少的元素，重复上面的步骤，直到没有任何一对数字需要比较，即完成冒泡排序。

如此，每一次排序结尾，总有一个最大的数被放在了最后。

<https://www.dotcpp.com/course/159>
<https://cgi.cse.unsw.edu.au/~cs2521/23T3/lectures/slides/week02mon-sorting-intro.pdf>



