# 滑动窗口滤波 （aka*）滑动均值滤波 #

**Refer to ：[https://blog.csdn.net/qq_37662088/article/details/125084985](https://blog.csdn.net/qq_37662088/article/details/125084985)**

1. 定义：滑动平均滤波就是把连续取得的N个采样值看成一个队列，队列的长度固定为N，每次采样得到一个新数据放到队尾，并丢掉原来队首的一次数据，把队列中的N个数据进行平均运算，就可以获得新的滤波结果。
其实也是一种均值滤波，不同的是：均值滤波会使输出频率减少，而滑动窗口不会。比如，原始数据是6hz，而均值滤波是每2个取平均，那么它的输出频率将变成3hz。

2. 算法过程（图文）
前提：一组数据，大小排序，且去除明显无效的数据
过程：指定宽度的滑块向右滑动，计算最右端和最左端的差值，此差值应小于预设阈值（否则丢弃），找出差值最小的（指定宽度）个数据然后求平均输出。
应用场景：测距算法，勘察压力，
优缺点：

**Refer to ：[https://zhuanlan.zhihu.com/p/55295423](https://zhuanlan.zhihu.com/p/55295423)**

3. 窗口大小选择：

如果x轴附近的噪点数量（一上一下）比较多，那么窗口大小就应该大一些，反之，小一些。但是过大又会出现过拟合的现象，所以可以多取几个值，然后对比一下，选择一个最好的即可。

4. 效果图：

![](file:///C:/Users/dgbuaa/Desktop/test/Project2/%E6%8A%98%E7%BA%BF%E5%9B%BE.png)

![](file:///C:/Users/dgbuaa/Desktop/test/Project2/050.png)

5. 更多参考：[https://www.cnblogs.com/jieruishu/p/9680627.html](https://www.cnblogs.com/jieruishu/p/9680627.html)