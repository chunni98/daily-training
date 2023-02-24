## 1 设计要求

1. 有系统欢迎界面。
2. 管理员登录需要输入账号、密码登录，三次输入错误关闭系统。
3. 有航班信息管理功能（某站至某站航班增删改查）。
5. 有乘客信息管理功能（增删改查）。

## 2 分析

1. 需要用到的技术：C 语言基础、文件 IO、数据结构的使用（链表保存飞机票信息），简单查询算法（二分查找）
2. 3 个文件：航班信息.dat、乘客信息.dat、管理员信息.dat。

## 3 设计

### 3.2 约定

1. 每架飞机最多有 30 名乘客。（`const int32_t PASSENGER_MAX = 30`)
2. 

### 3.1 数据组织形式

**（1）航班信息**

1. 航班编号（唯一）：`char flight_num[30];`
2. 航班起点：`char flight_number_start[100]`。
3. 航班终点：`char flight_number_end[100]`。
4. 机票价格：`float flight_price`。
5. 航班乘客：`char ticket_num[30]`

**（2）机票信息**

1. 机票编号（唯一）：`char ticket__num[30]`
2. 航班编号：`char ticket_flight_num[30]`
3. 乘客姓名：`char ticket_passenger_name[30]`


结构体设计如下：

```c
typedef struct{
    
}flight_info_t;

```

### 3.2 流程图

## 4 目录结构
