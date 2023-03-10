## 分析

### 设计要求

1. 有系统欢迎界面。
2. 登录需要输入账号、密码登录，三次输入错误关闭系统。
3. 用户登录可以进行购票、退票、航班信息查询操作，查询航班号，查询某个站点的航班。
4. 管理员登录可以进行航班管理：增删航班、购票、退票、查询。

### 技术要求

1. C 基础
2. 文件 IO
3. 数据结构（链表，保存用户数据）
4. 算法（二分查找法）

## 设计

### 功能结构

**管理员**

- 航班管理：增加、删除、修改、查询航班信息。
- 用户管理：修改用户信息、删除用户，增加管理员账号，删除管理员账号。

**用户**

- 登录：输入账号、密码登录，没有账号密码可选择注册。
- 查看航班信息：查看所有航班列表。
- 购票、退票。

### 界面设计

1. 字符界面。
2. 初始界面提供注册、登录功能选择。
3. 不同用户登录显示不同界面，提示不同的操作。
4. 给出适当的操作提示。
5. 界面干净、整洁。

### 数据结构设计

5. admin.dat 保存管理员信息。（账号、密码、名字）
6. user.dat 保存用户信息（账号、密码、名字、购票信息）
7. aircraft.dat 航班信息（航班号、卖出票数、票价）

### 流程

```mermaid
flowchart TB
    st(start)
    ed(end)
    init{{读入}}

```

## 测试


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

- src 项目源代码 和 Makefile
- include 头文件
- etc 配置文件
- static 静态库源码和 Makefile
- dynamic 动态库源码和 Makefile
- bin 可执行的二进制文件
- docs 项目文档
- lib 静态库和动态库
- Makefile 