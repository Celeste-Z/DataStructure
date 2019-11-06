# DataStructure
Here are some demos to help you understand and apply data structures better

1.SortCompare.c:Calculate the actual time, number of comparisons, and number of moves of insertion sort, quicksort, and merge sort
计算插入排序、快速排序、归并排序三种排序方式的实际花费时间、比较次数、移动次数
1)生成随机数组（调用srand(),time(),rand()函数）；
2)定义全局变量记录比较次数与移动次数；
3)建立插入排序、快速排序、归并排序函数，并在排序过程中计算比较次数、移动次数；
4)利用clock()函数，建立searchtime()函数，实现计时功能；
5)调用以上函数，最终得出三种排序方式的实际花费时间、比较次数、移动次数。

2.MazeSolving.c:Find and output the path of custom random maze
查找并输出自定义随机迷宫的路径
1）生成随机迷宫（调用srand(),time(),rand()函数，用1表示障碍，0表示通路），并输出；
2）利用栈进行迷宫求解：以深度优先的方式，从起始位置开始，顺时针进行判断是否可行。如果可行，则入栈并且标记；否则，将栈顶位置归为起始状态，并退栈。直至到达终点，输出栈中全部元素，即为所求路径；
3）如果迷宫无解，则返回0，并打印迷宫无解。

3.GoProblem.c:Generate a random go board, calculate the number of pieces, the position of pieces and the amount of liberty
生成随机围棋盘，计算各块棋子数、块内棋子位置和气
1）生成随机棋盘（调用srand(),time(),rand()函数，用1表白子，2表黑子，0表无子），并输出；
2）再利用实验二深度优先索引遍历计算出棋数与气，按从左到右、从上至下查找棋块，找到则入栈，顺时针寻找没有计算过的相邻棋子，找到则入栈，如果没有则退栈，直至栈为空，则找完一整个块，并输出各块棋子数和位置。找到所有块后，再以同样的方法计算气，将其输出；
调用相关函数，完成实验过程。

Enjoy yourself!
