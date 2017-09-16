# Spatial-data-analysis-system
## 该程序的主要功能有： 
* 分别从Point.txt 、Line.txt 、 Rect.txt读入所有数据（ Point 对象, Rect 对象, Line 对象）， 保存在 vector 中， 通过调用 GetCount()输出 Point、 Rect、 Line 对象个数<br>
* 任意给一个 Point 对象，找出所有和该对象成员变量 des相同的 Rect 对象(即Point 的变量 des 和 Rect 的变量 des 相同)， 输出所有的 Rect 对象到屏幕；任意给一个Rect 对象，找出所有和该对象的 des 相同的 Point 对象，输出所有的 Point 对象到屏幕 <br>
* 遍历存储 Rect 的vector， 找出面积最小和最大的 Rect， 将最小和最大的 Rect 写入到文件 Rect_data.txt；遍历存储 Line 的结构(vector 或 List)， 找出长度最小和最大的 Line，将最小和最大的 Rect 写入到文件 Line_data.txt。<br>
* 任意给出两个 Point 和 Rect 对象， 演示 operator+和operator<的功能  <br>
* 求解两个Point之间的距离；求解两个Rect之间的距离(最近的两点之间的距离)；求解两个Line之间的距离(最近的两点之间的距离)；求解 Point 对象和 Rect 对象之间的距离(最近的两点之间的距离)； 求解 Point 对象和Line 对象之间的距离(最近的两点之间的距离)。<br>
* 将数据写入到文件， 格式为<br>
  Point: ID (x, y) des<br>
  Rect: ID (x1, y1) (x2, y2) des<br>
  Line: ID (x1, y1) (x2, y2) len<br>
  * 将所有 Point 对象的字符串变量 des 变成小写， 按坐标排序后写入到 Point2.txt； <br>
  * 将 Rect 对象按照 des(字符串排序)，写入到 Rect2.txt；<br>
  * 将 Line 对象按照 len 递增数序排序，写入到文件 Line2.txt <br>
