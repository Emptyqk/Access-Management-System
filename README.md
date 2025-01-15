## 代码构成

1 文件管理

![img](file:///C:/Users/76742/AppData/Local/Temp/msohtmlclip1/01/clip_image001.png)

com.txt储存小区的卡信息及出入时间。

A.txt储存A楼的门卡信息及出入时间。

B.txt储存B楼的门卡信息及出入时间。

dooor.cpp为代码。



2 变量基本信息

![img](file:///C:/Users/76742/AppData/Local/Temp/msohtmlclip1/01/clip_image003.jpg)

3 功能图

![img](file:///C:/Users/76742/AppData/Local/Temp/msohtmlclip1/01/clip_image005.jpg)

4 流程图

![img](file:///C:/Users/76742/AppData/Local/Temp/msohtmlclip1/01/clip_image007.jpg)

![img](file:///C:/Users/76742/AppData/Local/Temp/msohtmlclip1/01/clip_image009.jpg)![img](file:///C:/Users/76742/AppData/Local/Temp/msohtmlclip1/01/clip_image011.jpg)

5 功能概述

管理员端：

用户卡登记，用户卡注销，用户卡信息修改，用户注册记录，查询进入小区/楼记录。

用户端：输入卡号进入小区，输入卡号进入楼。



 

 

 

## 系统需求分析

1 功能需求

用户验证：用户需要通过输入卡号来验证身份。系统需要根据卡号查找对应的用户信息。

![img](file:///C:/Users/76742/AppData/Local/Temp/msohtmlclip1/01/clip_image013.jpg)

 

门禁控制：系统需要根据用户的身份验证结果，控制门禁的开关。成功验证的用户可以打开相应的楼门。

![img](file:///C:/Users/76742/AppData/Local/Temp/msohtmlclip1/01/clip_image015.jpg)

 

用户管理：管理员可以添加、删除和修改用户信息。管理员可以查看用户的详细信息。

![img](file:///C:/Users/76742/AppData/Local/Temp/msohtmlclip1/01/clip_image017.jpg)

 

 

时间记录：系统需要记录用户开门的时间。时间记录可以用于后续的查询和统计。

![img](file:///C:/Users/76742/AppData/Local/Temp/msohtmlclip1/01/clip_image019.jpg)

![img](file:///C:/Users/76742/AppData/Local/Temp/msohtmlclip1/01/clip_image021.jpg)

 

错误处理：系统需要对用户输入的错误信息进行提示。错误处理友好，引导用户重新输入。

![img](file:///C:/Users/76742/AppData/Local/Temp/msohtmlclip1/01/clip_image023.jpg)

 

2 用户角色分析

普通用户：可以通过输入卡号打开楼门。可以查看自己的开门记录。

![img](file:///C:/Users/76742/AppData/Local/Temp/msohtmlclip1/01/clip_image025.jpg)

 

管理员：可以管理用户信息，包括添加、删除和修改用户。可以查看所有用户的信息和开门记录。

![img](file:///C:/Users/76742/AppData/Local/Temp/msohtmlclip1/01/clip_image027.jpg)

 



 

## 功能展示

1 模块设计

分为用户端与管理员端，通过身份认证登录。

用户：

用户输入卡号进入小区门。

![img](file:///C:/Users/76742/AppData/Local/Temp/msohtmlclip1/01/clip_image030.jpg)

用户的2项功能。

![img](file:///C:/Users/76742/AppData/Local/Temp/msohtmlclip1/01/clip_image032.jpg)

管理员：

主菜单，选择管理员身份，输入密码验证是否是管理员，密码输入次数不能超过3次，否则会退出系统。

![img](file:///C:/Users/76742/AppData/Local/Temp/msohtmlclip1/01/clip_image033.jpg)

1登记用户卡，增加门卡的两种类型。

![img](file:///C:/Users/76742/AppData/Local/Temp/msohtmlclip1/01/clip_image034.jpg)

2删除功能

![img](file:///C:/Users/76742/AppData/Local/Temp/msohtmlclip1/01/clip_image035.png)

  3显示功能

![img](file:///C:/Users/76742/AppData/Local/Temp/msohtmlclip1/01/clip_image037.jpg)

4小区/楼门开放时间记录（新->早）

![img](file:///C:/Users/76742/AppData/Local/Temp/msohtmlclip1/01/clip_image039.jpg)

![img](file:///C:/Users/76742/AppData/Local/Temp/msohtmlclip1/01/clip_image041.jpg)

 

5修改功能

![img](file:///C:/Users/76742/AppData/Local/Temp/msohtmlclip1/01/clip_image043.jpg)

![img](file:///C:/Users/76742/AppData/Local/Temp/msohtmlclip1/01/clip_image045.jpg)

 

## 系统优化与改进

### 出现问题

![img](file:///C:/Users/76742/AppData/Local/Temp/msohtmlclip1/01/clip_image054.jpg)

![img](file:///C:/Users/76742/AppData/Local/Temp/msohtmlclip1/01/clip_image055.jpg)

用于存放数据的文件表无法正常显示汉字，只能显示乱码。

 

### 优化改进

1. 乱码问题：

增加头文件 conio.h 方便了汉字字符的输入输出。

修改后：

![img](file:///C:/Users/76742/AppData/Local/Temp/msohtmlclip1/01/clip_image056.jpg)

 

2. 跳转问题

return返回上一级，但由于实际工作中上一级不一定是菜单，所以直接改成了访问菜单函数。

![img](file:///C:/Users/76742/AppData/Local/Temp/msohtmlclip1/01/clip_image058.jpg)

![img](file:///C:/Users/76742/AppData/Local/Temp/msohtmlclip1/01/clip_image060.jpg)

 

## 总结与心得

这个项目是一个门禁管理系统，主要功能包括管理员登录、用户登录和退出系统。管理员可以进行用户更新、删除、显示登记用户、修改用户信息、时间排序等操作；用户可以通过输入卡号打开小区门、选择楼门并开门。系统还提供了清空登记、查询开门时间等功能。

以下是项目的主要特点和功能：

* 管理员功能：

密码验证：管理员需要输入正确的密码才能登录。

用户管理：管理员可以更新、删除用户信息，显示登记用户列表，以及修改用户信息。

时间排序：管理员可以对用户信息按照时间进行排序。

清空登记：管理员可以清空小区或楼门的登记信息。

* 用户功能：

门禁控制：用户可以通过输入卡号打开小区门，选择楼门并开门。

查询开门时间：用户可以查询自己的开门时间。

* 文件操作：

数据存储：用户和管理员的信息分别存储在不同的文件中，包括小区门、A楼门和B楼门的信息。

文件读写：系统提供了文件读取和写入的功能，确保数据的持久化和更新。