**4 完全平方数**

```py
# 算法：完全平方数的实现
# 作者：shachi
# 时间：2023-02-17 15:04

# input: 无
# output: 完全平方数

for i in range(10万):
    if i + 100 是完全平方数 and i + 168 是完全平方数:
        print i
```
**5 输入某年某月某日，判断这一天是这一年的第几天**

```py
# 算法：根据年月日得出是一年中第几天
# 作者：shachi
# 时间：2023-02-20 14:41

# input: year,month,day，is_leap_year(year) 判断是否闰年
# output: 总天数 days

months = (31,28,31,30,31,30,31,31,30,31,30,31)
days = 0

i = 0
while i < month - 1:
    days += month[i]
    i += 1

days += day;

if month > 1 and is_leap_year(year):
    days += 1

print(days)

```