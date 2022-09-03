# simple-calculator
这个简单的计算器例子来自《从零开始Qt可视化 程序设计基础教程》
1.学到了qt Widget中static的使用经验，不用在类内使用static的widget，因为static的widget会在QApplication之前构建，不符合Qt的构建顺序，正常顺序下，QApplication应该优先构建。
2.qt的类中的对象通信可以用信号槽机制，类中的成员对象发出信号，类的对象接受信号并处理。

