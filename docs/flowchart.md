**1 十进制转十六进制**

```mermaid
flowchart TB
    A(开始) --> B[/十进制数 num/] --> C{{"余数r = 0\n0-F 字符数组 arr\n计数器 i = 0\n结果数组ans"}}
    C --> D{num ==0 ?} -- no --> E["r = num % 16\nans[i] = arr[r]"] --> F[num = num / 16] --> G[i++]
    G --> D -- yes --> H["ans[i] = '\0'"] ---> I[/ans 逆序输出/] --> J(结束)
```

**2 1234组成的无重复数字三位数**

```mermaid
flowchart TB
    A(开始)
    A --> B{{i=0,j=0,k=0,count = 0}}
    B --> B1[i==1]
    B1 --> C{i<5?} -- yes -->j=1-->D
    C -- no --->Y[/输出 count/]---> Z(结束)
    D{j<5?} -- yes -->k=1--> F1
    D -- no --> i++ --> C
    F1{k<5?} -- no --> j++ --> D
    F1 -- yes --> F2{"ijk\n互不相同?"}
    F2 --yes--> G["打印 i * 100 + j* 10 + k\ncount++"]
     H[k++] --> F1
    G --> H
```
**3利润计算**

```mermaid
flowchart TB
    St(开始)
    Input1[/利润 profit/]
    Proc1{{"奖金 bonus\nbonus1=10*0.1\nbonus2=bonus1+10*0.075\nbonus3=bonus2+10*0.03\nbonus4=bonus3+20*0.015\nbonus5=bonus4+40*0.015"}}
    Choose1{profit==?} 
    Proc2["profit = bonus * 0.1"]
    Proc3["profit = bonus1 + (bonus - 10) * 0.75"]
    Proc4["profit = bonus2 + (bonus - 20) * 0.05"]
    Proc5["Profit=bonus3+(bonus-40)*0.03"]
    Proc6["Profit=bonus4+(bonus-60)*0.015"]
    Proc7["Profit=bonus5+(bonus-100)*0.001"]
    St --> Proc1 --> Input1
    Input1 --> Choose1
    Choose1 -- <=10万 --> Proc2
    Choose1 -- <=20万 --> Proc3
    Choose1 -- <=40万 --> Proc4
    Choose1 -- <=60万 --> Proc5
    Choose1 -- <=100万 --> Proc6
    Choose1 -- else --> Proc7
    




```