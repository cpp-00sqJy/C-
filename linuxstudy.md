[TOC]

# 一、linux系统编程

# 1、linux基本命令

## 1.1 常见目录

- **/：**根目录，一般根目录下只存放目录，在Linux下有且只有一个根目录。所有的东西都是从这里开始。当你在终端里输入“/home”，你其实是在告诉电脑，先从/（根目录）开始，再进入到home目录。
- **/bin:** **/usr/bin:** 可执行二进制文件的目录，如常用的命令ls、tar、mv、cat等。
- **/boot：**放置linux系统启动时用到的一些文件，如Linux的内核文件：/boot/vmlinuz，系统引导管理器：/boot/grub。
- **/dev：**存放linux系统下的设备文件，访问该目录下某个文件，相当于访问某个设备，常用的是挂载光驱 mount /dev/cdrom /mnt。
- **/etc**：系统配置文件存放的目录，不建议在此目录下存放可执行文件，重要的配置文件有 /etc/inittab、/etc/fstab、/etc/init.d、/etc/X11、/etc/sysconfig、/etc/xinetd.d。
- **/home：**系统默认的用户家目录，新增用户账号时，用户的家目录都存放在此目录下，~表示当前用户的家目录，~edu 表示用户 edu 的家目录。
- **/lib: /usr/lib: /usr/local/lib**系统使用的函数库的目录，程序在执行过程中，需要调用一些额外的参数时需要函数库的协助。
- **/lost+fount：**系统异常产生错误时，会将一些遗失的片段放置于此目录下。
- **/mnt:/media：**光盘默认挂载点，通常光盘挂载于 /mnt/cdrom 下，也不一定，可以选择任意位置进行挂载。
- **/opt：**给主机额外安装软件所摆放的目录。
- **/proc**：此目录的数据都在内存中，如系统核心，外部设备，网络状态，由于数据都存放于内存中，所以不占用磁盘空间，比较重要的目录有 /proc/cpuinfo、/proc/interrupts、/proc/dma、/proc/ioports、/proc/net/* 等。
- **/root：**系统管理员root的家目录。
- **/sbin:/usr/sbin:/usr/local/sbin：**放置系统管理员使用的可执行命令，如fdisk、shutdown、mount 等。与 /bin 不同的是，这几个目录是给系统管理员 root使用的命令，一般用户只能"查看"而不能设置和使用。
- **/tmp\****：**一般用户或正在执行的程序临时存放文件的目录，任何人都可以访问，重要数据不可放置在此目录下。
- **/srv：**服务启动之后需要访问的数据目录，如 www 服务需要访问的网页数据存放在 /srv/www 内。
- **/usr**：应用程序存放目录，/usr/bin 存放应用程序，/usr/share 存放共享数据，/usr/lib 存放不能直接运行的，却是许多程序运行所必需的一些函数库文件。/usr/local: 存放软件升级包。/usr/share/doc: 系统说明文件存放目录。/usr/share/man: 程序说明文件存放目录。
- **/var：**放置系统执行过程中经常变化的文件，如随时更改的日志文件 /var/log，/var/log/message：所有的登录文件存放目录，/var/spool/mail：邮件存放的目录，/var/run:程序或服务启动后，其PID存放在该目录下。

## 1.2 常见命令

 **① ls  **

| **参数** | **含义**                                     |
| -------- | -------------------------------------------- |
| -a       | 显示指定目录下所有子目录与文件，包括隐藏文件 |
| -l       | 以列表方式显示文件的详细信息                 |
| -h       | 配合 -l 以人性化的方式显示文件大小           |

**②touch**

```shell
 touch file(文件名)
```

**③mv**

移动目录或文件夹,也可以给更改文件名

| **选项** | **含义**                                                     |
| -------- | ------------------------------------------------------------ |
| -f       | 禁止交互式操作，如有覆盖也不会给出提示                       |
| -i       | 确认交互方式操作，如果mv操作将导致对已存在的目标文件的覆盖，系统会询问是否重写，要求用户回答以避免误覆盖文件 |
| -v       | 显示移动进度                                                 |

```shell
mv file file2 把file文件重命名为file2

mv file dirs/把file文件移动到dirs文件夹下

mv dir dir2 dir3/把dir dir2目录剪切到dir3文件夹下
```

**④cat**

cat 将文件内容一次性输出到终端。

缺点：终端显示的内容有限，如果文件太长无法全部显示。

示例：

> cat /etc/passwd 查看/etc/passwd内容
>
> cat -n /etc/passwd 查看/etc/passwd内容,对输出的所有行编号
>
> cat -b /etc/passwd 查看/etc/passwd内容并且给非空行编号
>
> cat -A /etc/passwd 等价于 -vET

**⑤tail**

- 从文件尾部向上查看最后 n 行的内容
- 使用方式：tail –n[行数] 文件名
- 如果没有指定行数，默认显示最后10行内容

```shell
tail -f /etc/passwd //实时查看文件
```

**⑥find**

**按文件名查询：使用参数 -name**

**命令：find + 路径 + -name +“文件名”**

示例：find /home -name “a.txt”

**按文件大小查询：使用参数 -size**

命令：find + 路径 + -size + 范围

等于100k的文件:

```shell
 find ~/ -size 100k
```

大于100k的文件: 

```shell
find ~/ -size +100k
```

大于50k, 小于100k的文件:

```shell
find ~/ -size +50k -size -100k
```

**按文件类型查询：使用参数 -type**

命令：find + 路径 + -type + 类型

Ø 普通文件类型用 **f** 表示而不是-

Ø d -> 目录

Ø l -> 符号链接

Ø b -> 块设备文件

Ø c -> 字符设备文件

Ø s -> socket文件，网络套接字

Ø p -> 管道

```shell
find /home -type f
```

**⑦tar**

只负责打包文件,不压缩

```shell
tar -cvf 创建归档文件

tar -xvf 解除归档文件(还原)

tar -tvf 查看归档文件内容
```

**⑧gzip**

 tar与gzip命令结合使用实现文件打包、压缩。

| **选项** | **含义**       |
| -------- | -------------- |
| -d       | 解压           |
| -r       | 压缩所有子目录 |

```shell
touch a //创建普通文件
gzip a //压缩文件

mkdir test //创建目录
//gzip不能直接压缩目录,需先用tar创建归档文件
tar -cvf test.tar test
gzip test.tar
---------------------------
以上不采用,一般采用如下结合方式
---------------------------
tar这个命令并没有压缩的功能，它只是一个打包的命令，但是在tar命令中增加一个选项(-z)可以调用gzip实现了一个压缩的功能，实行一个先打包后压缩的过程。
tar zcvf 压缩包名xxx.tar.gz 文件名.c.c
解压用法:
tar zxvf 压缩包包名
参数	含义
-z	指定压缩包的格式为：file.tar.gz
tar zxvf new.tar.gz
解压到指定目录：
-C （大写字母“C”）
tar -xvf new.tar.gz -C ./test/
```

**⑨bzip2**

- tar与bzip2命令结合使用实现文件打包、压缩(用法和gzip一样)。
- tar只负责打包文件，但不压缩，用bzip2压缩tar打包后的文件，其扩展名一般用xxxx.tar.bz2。
- 在tar命令中增加一个选项(-j)可以调用bzip2实现了一个压缩的功能，实行一个先打包后压缩的过程。
- 压缩用法：tar jcvf 压缩包包名 文件...(tar jcvf bk.tar.bz2 *.c)
- 解压用法：tar jxvf 压缩包包名 (tar jxvf bk.tar.bz2)

```shell
压缩:tar -cjvf xxxx.tar.bz2 test
解压:tar -xjvf xxxx.tar.bz2
```

**⑩zip和unzip**

通过zip压缩文件的目标文件不需要指定扩展名，默认扩展名为zip。

压缩文件：zip -r 目标文件(没有扩展名) 源文件

```shell
压缩:zip xxx(压缩名) xxx(要压缩的文件名)
解压：unzip -d 解压后目录文件 压缩文件
unzip -d test xxx.zip
```

# 2、vim-gcc-动态库静态库

## 2.1 vim使用操作

**①复制粘贴**

| **按键** | **功能**                     |
| :------- | :--------------------------- |
| [n]yy    | 复制从当前行开始的 n 行      |
| p        | 把粘贴板上的内容插入到当前行 |

**②删除**

| **按键**    | **功能**                                                     |
| :---------- | :----------------------------------------------------------- |
| [n]x        | 删除光标后 n 个字符                                          |
| [n]X        | 删除光标前 n 个字符                                          |
| D           | 删除光标所在开始到此行尾的字符                               |
| [n]dd       | 删除从当前行开始的 n 行（准确来讲，是剪切，剪切不粘贴即为删除） |
| dG          | 删除光标所在开始到文件尾的所有字符                           |
| dw          | 删除光标开始位置的字,包含光标所在字符                        |
| d0(0为数字) | 删除光标前本行所有内容,不包含光标所在字符                    |
| dgg         | 删除光标所在开始到文件首行第一个字符开始的所有字符           |

**③可视模式**

| **按键**  | **功能**                                                     |
| :-------- | :----------------------------------------------------------- |
| v         | 按字符移动，选中文本，可配合h、j、k、l选择内容，使用d删除，使用y复制 |
| Shift + v | 行选（以行为单位）选中文本，可配合h、j、k、l选择内容，使用d删除，使用y复制 |
| Ctrl + v  | 列选 选中文本，可配合h、j、k、l选择内容，使用d删除，使用y复制 |

**④替换**

| **按键**         | **功能**                               |
| :--------------- | :------------------------------------- |
| :s/abc/123/      | 光标所在行的第一个abc替换为123         |
| :s/abc/123/g     | 光标所在行的所有abc替换为123           |
| :1,10s/abc/123/g | 将第一行至第10行之间的abc全部替换成123 |
| :%s/abc/123/g    | 当前文件的所有abc替换为123             |
| :%s/abc/123/gc   | 同上，但是每次替换需要用户确认         |
| :1,$s/abc/123/g  | 当前文件的所有abc替换为123             |

**⑤分屏**

| **按键**           | **功能**                       |
| :----------------- | :----------------------------- |
| :sp                | 当前文件水平分屏               |
| :vsp               | 当前文件垂直分屏               |
| : sp 文件名        | 当前文件和另一个文件水平分屏   |
| : vsp 文件名       | 当前文件和另一个文件垂直分屏   |
| ctrl-w-w           | 在多个窗口切换光标             |
| :wall/:wqall/:qall | 保存/保存退出/退出所有分屏窗口 |
| vim -O a.c b.c     | 垂直分屏                       |
| vim -o a.c b.c     | 水平分屏                       |

**⑥配置文件**

局部配置文件（推荐）

> deng@itcast:~/share/2nd$ vim ~/.vimrc

全局配置文件:

> deng@itcast:~/share/2nd$ sudo vim /etc/vim/vimrc

链接分为两种：**静态链接**、**动态链接**。

## 2.2 静态链接和动态链接

**1）静态链接**

静态链接：由链接器在链接时将库的内容加入到可执行程序中。

优点：

- 对运行环境的依赖性较小，具有较好的兼容性

缺点：

- 生成的程序比较大，需要更多的系统资源，在装入内存时会消耗更多的时间
- 库函数有了更新，必须重新编译应用程序

**2）动态链接**

动态链接：连接器在链接时仅仅建立与所需库函数的之间的链接关系，在程序运行时才将所需资源调入可执行程序。

优点：

- 在需要的时候才会调入对应的资源函数
- 简化程序的升级；有着较小的程序体积
- 实现进程之间的资源共享（避免重复拷贝）

缺点：

- 依赖动态库，不能独立运行
- 动态库依赖版本问题严重

**3）静态、动态编译对比**

前面我们编写的应用程序大量用到了标准库函数，系统默认采用动态链接的方式进行编译程序，若想采用静态编译，加入-static参数。

> deng@itcast:~/test$ gcc test.c -o test_share
>
> deng@itcast:~/test$ gcc -static test.c -o test_static

## 2.3 静态库制作和使用

静态库可以认为是一些目标代码的集合，是在可执行程序运行前就已经加入到执行码中，成为执行程序的一部分。

按照习惯,一般以“.a”做为文件后缀名。静态库的命名一般分为三个部分：

- 前缀：lib
- 库名称：自己定义即可
- 后缀：.a

所以最终的静态库的名字应该为：**libxxx.a**

步骤1：将c源文件生成对应的.o文件

> deng@itcast:~/test/3static_lib$ gcc -c add.c -o add.o
> deng@itcast:~/test/3static_lib$ gcc -c sub.c -o sub.o deng@itcast:~/test/3static_lib$ gcc -c mul.c -o mul.o deng@itcast:~/test/3static_lib$ gcc -c div.c -o div.o

步骤2：使用打包工具ar将准备好的.o文件打包为.a文件 libtest.a

> deng@itcast:~/test/3static_lib$ ar -rcs libtest.a add.o sub.o mul.o div.o

**在使用ar工具是时候需要添加参数：rcs**

- r更新
- c创建
- s建立索引

## 2.4 动态库制作和使用

共享库在程序编译时并不会被连接到目标代码中，而是在程序运行是才被载入。不同的应用程序如果调用相同的库，那么在内存里只需要有一份该共享库的实例，规避了空间浪费问题。

动态库在程序运行是才被载入，也解决了静态库对程序的更新、部署和发布页会带来麻烦。用户只需要更新动态库即可，增量更新。

按照习惯,一般以“.so”做为文件后缀名。共享库的命名一般分为三个部分：

- 前缀：lib
- 库名称：自己定义即可
- 后缀：.so

所以最终的动态库的名字应该为：libxxx.so

**1）动态库制作**

步骤一：生成目标文件，此时要加编译选项：-fPIC（fpic）

> deng@itcast:~/test/5share_lib$ gcc -fPIC -c add.c
> deng@itcast:~/test/5share_lib$ gcc -fPIC -c sub.c deng@itcast:~/test/5share_lib$ gcc -fPIC -c mul.c deng@itcast:~/test/5share_lib$ gcc -fPIC -c div.c

参数：-fPIC 创建与地址无关的编译程序（pic，position independent code），是为了能够在多个应用程序间共享。

步骤二：生成共享库，此时要加链接器选项: -shared（指定生成动态链接库）

> deng@itcast:~/test/5share_lib$ gcc -shared add.o sub.o mul.o div.o -o libtest.so

步骤三: 通过nm命令查看对应的函数

> deng@itcast:~/test/5share_lib$ nm libtest.so | grep add 00000000000006b0 T add deng@itcast:~/test/5share_lib$ nm libtest.so | grep sub 00000000000006c4 T sub

 

ldd查看可执行文件的依赖的动态库

> deng@itcast:~/share/3rd/2share_test$ ldd test linux-vdso.so.1 => (0x00007ffcf89d4000) libtest.so => /lib/libtest.so (0x00007f81b5612000) libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f81b5248000) /lib64/ld-linux-x86-64.so.2 (0x00005562d0cff000)

**2）动态库测试**

引用动态库编译成可执行文件（跟静态库方式一样）

> deng@itcast:~/test/6share_test$ gcc test.c -L. -I. -ltest (-I. 大写i -ltest 小写L)

然后运行：./a.out，发现竟然报错了！！！

- 当系统加载可执行代码时候，能够知道其所依赖的库的名字，但是还需要知道绝对路径。此时就需要系统动态载入器(dynamic linker/loader)。
- 对于elf格式的可执行程序，是由ld-linux.so*来完成的，它先后搜索elf文件的 DT_RPATH段 — 环境变量LD_LIBRARY_PATH — /etc/ld.so.cache文件列表 — **/lib/, /usr/lib**目录找到库文件后将其载入内存。

 

**3）如何让系统找到动态库**

- 拷贝自己制作的共享库到/lib或者/usr/lib(不能是/lib64目录)
- 临时设置LD_LIBRARY_PATH：

> export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:库路径

- 永久设置,把export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:库路径，设置到~/.bashrc或者 /etc/profile文件中

  > deng@itcast:~/share/3rd/2share_test$ vim ~/.bashrc
  >
  > 最后一行添加如下内容:
  >
  > export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/deng/share/3rd/2share_test

  使环境变量生效

  > deng@itcast:~/share/3rd/2share_test$ source ~/.bashrc deng@itcast:~/share/3rd/2share_test$ ./test
  > a + b = 20 a - b = 10

- 将其添加到 /etc/ld.so.conf文件中

  编辑/etc/ld.so.conf文件，加入库文件所在目录的路径

  运行sudo ldconfig -v，该命令会重建/etc/ld.so.cache文件

  > deng@itcast:~/share/3rd/2share_test$ sudo vim /etc/ld.so.conf
  >
  > 文件最后添加动态库路径(绝对路径)

  > 使生效
  >
  > deng@itcast:~/share/3rd/2share_test$ sudo ldconfig -v

- 使用符号链接， 但是一定要使用绝对路径

  deng@itcast:~/test/6share_test$ sudo ln -s /home/deng/test/6share_test/libtest.so /lib/libtest.so

# 3、Makefile

## 3.1 Makefile语法规则

**一条规则：**

> 目标：依赖文件列表
>
> 命令列表

Makefile基本规则三要素：

1）目标：

- 通常是要产生的文件名称，目标可以是可执行文件或其它obj文件，也可是一个动作的名称

2）依赖文件：

- 用来输入从而产生目标的文件
- 一个目标通常有几个依赖文件（可以没有）

3）命令：

- make执行的动作，一个规则可以含几个命令（可以没有）
- 有多个命令时，每个命令占一行

## 3.2 Makefile用法

makefile中的函数有很多，在这里给大家介绍两个最常用的。

> 1. wildcard – 查找指定目录下的指定类型的文件
>
> src = $(wildcard *.c) //找到当前目录下所有后缀为.c的文件,赋值给src
>
> 1. patsubst – 匹配替换
>
> obj = $(patsubst %.c,%.o, $(src)) //把src变量里所有后缀为.c的文件替换成.o

```shell

SRC=$(wildcard *.c)
OBJS=$(patsubst %.c, %.o, $(SRC))
TARGET=test
$(TARGET):$(OBJS)
    gcc $(OBJS) -o $(TARGET) 

%.o:%.c
    gcc -c $< -o $@
.PHONY:clean
clean:
    rm -rf $(OBJS) $(TARGET)
```



# 4、进程

```cpp
进程是程序的执行过程,进程是动态的(有生命周期),程序是静态的
```
## 4.1 并行和并发

```cpp
并行:在同一时刻,有多个指令在多个处理器上同时执行
并发:在同一时刻,只能有一条指令执行,但多个进程的指令会快速轮流切换
```
## 4.2 GDB调试多进程

```C++
set follow-fork-mode child (跟踪子进程)
set follow-fork-mode parent(跟踪父进程)
```
## 4.3 孤儿进程

```cpp
父进程结束,子进程仍在运行。
每当有一个孤儿进程,linux内核会为其父进程设置init(1号进程),
init会循环的使用wait()已经退出的孤儿进程
```
## 4.4 僵尸进程

```cpp
子进程结束,父进程未回收其子进程资源,子进程残留资源放入内核中。
```
# 5、进程间通信

## 5.1 无名管道

**管道有如下特点：**

1) 半双工，数据在同一时刻只能在一个方向上流动。

2) 数据只能从管道的一端写入，从另一端读出。

3) 写入管道中的数据遵循先入先出的规则。

4) 管道所传送的数据是无格式的，这要求管道的读出方与写入方必须事先约定好数据的格式，如多少字节算一个消息等。

5) 管道不是普通的文件，不属于某个文件系统，其只存在于**内存**中。

6) 管道在内存中对应一个缓冲区。不同的系统其大小不一定相同。

7) 从管道读数据是一次性操作，数据一旦被读走，它就从管道中被抛弃，释放空间以便写更多的数据。

8) 管道没有名字，只能在具有公共祖先的进程（父进程与子进程，或者两个兄弟进程，具有亲缘关系）之间使用。

​       对于管道特点的理解，我们可以类比现实生活中管子，管子的一端塞东西，管子的另一端取东西。

​       管道是一种特殊类型的文件，在应用层体现为两个打开的文件描述符。

**pipe函数**

```c
#include <unistd.h>
int pipe(int pipefd[2]);
功能：创建无名管道。
参数：
    pipefd : 为 int 型数组的首地址，其存放了管道的文件描述符 pipefd[0]、pipefd[1]。
    
    当一个管道建立时，它会创建两个文件描述符 fd[0] 和 fd[1]。其中 fd[0] 固定用于读管道，而 fd[1] 固定用于写管道。一般文件 I/O的函数都可以用来操作管道(lseek() 除外)。
返回值：
    成功：0
    失败：-1
```

子进程通过无名管道给父进程传递一个字符串数据

```c
int main()
{
    int fd_pipe[2] = { 0 };
    pid_t pid;

    if (pipe(fd_pipe) < 0)
    {// 创建管道
        perror("pipe");
    }
    pid = fork(); // 创建进程
    if (pid == 0)
    { // 子进程
        char buf[] = "I am mike";
        // 往管道写端写数据
        write(fd_pipe[1], buf, strlen(buf));
        _exit(0);
    }
    else if (pid > 0)
    {// 父进程
        wait(NULL); // 等待子进程结束，回收其资源
        char str[50] = { 0 };
        // 从管道里读数据
        read(fd_pipe[0], str, sizeof(str));
        printf("str=[%s]\n", str); // 打印数据
    }
    return 0;
}
```

**读管道：**

Ø 管道中有数据，read返回实际读到的字节数。

Ø 管道中无数据：

u 管道写端被全部关闭，read返回0 (相当于读到文件结尾)

u 写端没有全部被关闭，read阻塞等待(不久的将来可能有数据递达，此时会让出cpu)

**写管道：**

Ø 管道读端全部被关闭， 进程异常终止(也可使用捕捉SIGPIPE信号，使进程终止)

Ø 管道读端没有全部关闭：

u 管道已满，write阻塞。

u 管道未满，write将数据写入，并返回实际写入的字节数。

### 5.11 设置为非阻塞的方法

设置方法：

```shell
//获取原来的flags
int flags = fcntl(fd[0], F_GETFL);
// 设置新的flags
flag |= O_NONBLOCK;
// flags = flags | O_NONBLOCK;
fcntl(fd[0], F_SETFL, flags);
```

结论： 如果写端没有关闭，读端设置为非阻塞， 如果没有数据，直接返回-1。

## 5.2 有名管道

管道，由于没有名字，只能用于亲缘关系的进程间通信。为了克服这个缺点，提出了命名管道（FIFO），也叫有名管道、FIFO文件。

命名管道（FIFO）不同于无名管道之处在于它提供了一个路径名与之关联，以 FIFO 的文件形式存在于文件系统中，这样，即使与 FIFO 的创建进程不存在亲缘关系的进程，只要可以访问该路径，就能够彼此通过 FIFO 相互通信，因此，通过 FIFO 不相关的进程也能交换数据。

 

命名管道（FIFO)和无名管道（pipe）有一些特点是相同的，不一样的地方在于：

1) FIFO 在文件系统中作为一个特殊的文件而存在，但 FIFO 中的内容却存放在**内存**中。

2) 当使用 FIFO 的进程退出后，FIFO 文件将继续保存在文件系统中以便以后使用。

3) FIFO 有名字，不相关的进程可以通过打开命名管道进行通信。

### 5.21 通过命令创建有名管道

```shell
mkfifo fifo
```

### 5.22 通过函数创建有名管道

```c
#include <sys/types.h>
#include <sys/stat.h>
int mkfifo(const char *pathname, mode_t mode);
功能：
    命名管道的创建。
参数：
    pathname : 普通的路径名，也就是创建后 FIFO 的名字。
    mode : 文件的权限，与打开普通文件的 open() 函数中的 mode 参数相同。(0666)
返回值：
    成功：0   状态码
    失败：如果文件已经存在，则会出错且返回 -1。
```

### 5.23 有名管道读写操作

一旦使用mkfifo创建了一个FIFO，就可以使用open打开它，常见的文件I/O函数都可用于fifo。如：close、read、write、unlink等。

FIFO严格遵循先进先出（first in first out），对管道及FIFO的读总是从开始处返回数据，对它们的写则把数据添加到末尾。**它们不支持诸如lseek()等文件定位操作。**

```c
//进行1，写操作
int fd = open("my_fifo", O_WRONLY);  
char send[100] = "Hello Mike";
write(fd, send, strlen(send));
//进程2，读操作
int fd = open("my_fifo", O_RDONLY);//等着只写  
char recv[100] = { 0 };
//读数据，命名管道没数据时会阻塞，有数据时就取出来  
read(fd, recv, sizeof(recv));
printf("read from my_fifo buf=[%s]\n", recv);
```

### 5.24 有名管道注意事项

1) 一个为只读而打开一个管道的进程会阻塞直到另外一个进程为只写打开该管道

   2.一个为只写而打开一个管道的进程会阻塞直到另外一个进程为只读打开该管道

**读管道：**

Ø 管道中有数据，read返回实际读到的字节数。

Ø 管道中无数据：

u 管道写端被全部关闭，read返回0 (相当于读到文件结尾)

u 写端没有全部被关闭，read阻塞等待

**写管道：**

Ø 管道读端全部被关闭， 进程异常终止(也可使用捕捉SIGPIPE信号，使进程终止)

Ø 管道读端没有全部关闭：

u 管道已满，write阻塞。

u 管道未满，write将数据写入，并返回实际写入的字节数。

## 5.3 共享存储映射

### 5.31概述

存储映射I/O (Memory-mapped I/O) 使一个磁盘文件与存储空间中的一个缓冲区相映射。

于是当从缓冲区中取数据，就相当于读文件中的相应字节。于此类似，将数据存入缓冲区，则相应的字节就自动写入文件。这样，就可在不使用read和write函数的情况下，使用地址（指针）完成I/O操作。

共享内存可以说是最有用的进程间通信方式，也是最快的IPC形式, 因为进程可以直接读写内存，而不需要任何数据的拷贝。

```c
1) 第一个参数写成NULL
2) 第二个参数要映射的文件大小 > 0
3) 第三个参数：PROT_READ 、PROT_WRITE
4) 第四个参数：MAP_SHARED 或者 MAP_PRIVATE
5) 第五个参数：打开的文件对应的文件描述符
6) 第六个参数：4k的整数倍，通常为0
void*mmap(void *addr,size_t length,int prot,int flags,int fd, off_t offset);
addr = mmap(NULL,1024,PROT_READ | PROT_WRITE, MAP_SHARED,fd,0);
内存读写操作
memcpy(addr,"1234567890",10);
--------------------------
#include <sys/mman.h>
int munmap(void *addr, size_t length);
功能：
    释放内存映射区
参数：
    addr：使用mmap函数创建的映射区的首地址
    length：映射区的大小
返回值：
    成功：0
    失败：-1
munmap(addr,1024);
注意事项:
1) 创建映射区的过程中，隐含着一次对映射文件的读操作。
2) 当MAP_SHARED时，要求：映射区的权限应 <=文件打开的权限(出于对映射区的保护)。而MAP_PRIVATE则无所谓，因为mmap中的权限是对内存的限制。
3) 映射区的释放与文件关闭无关。只要映射建立成功，文件可以立即关闭。
4) 特别注意，当映射文件大小为0时，不能创建映射区。所以，用于映射的文件必须要有实际大小。mmap使用时常常会出现总线错误，通常是由于共享文件存储空间大小引起的。
5) munmap传入的地址一定是mmap的返回地址。坚决杜绝指针++操作。
6) 如果文件偏移量必须为4K的整数倍。
7) mmap创建映射区出错概率非常高，一定要检查返回值，确保映射区建立成功再进行后续操作。
 
```

### 5.32 共享映射的方式操作文件

```c
 int fd = open("xxx.txt", O_RDWR); //读写文件
    int len = lseek(fd, 0, SEEK_END);   //获取文件大小
    //一个文件映射到内存，ptr指向此内存
    void * ptr = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED)
    {
        perror("mmap error");
        exit(1);
    }
    close(fd); //关闭文件
    char buf[4096];
    printf("buf = %s\n", (char*)ptr); // 从内存中读数据，等价于从文件中读取内容
    strcpy((char*)ptr, "this is a test");//写内容
    int ret = munmap(ptr, len);
    if (ret == -1)
    {
        perror("munmap error");
        exit(1);
    }
```

### 5.33 共享映射实现父子进程通信

```c
 int fd = open("xxx.txt", O_RDWR);// 打开一个文件
    int len = lseek(fd, 0, SEEK_END);//获取文件大小
    // 创建内存映射区
    void *ptr = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED)
    {
        perror("mmap error");
        exit(1);
    }
    close(fd); //关闭文件
    // 创建子进程
    pid_t pid = fork();
    if (pid == 0) //子进程
    {
        sleep(1); //演示，保证父进程先执行
        // 读数据
        printf("%s\n", (char*)ptr);
    }
    else if (pid > 0) //父进程
    {
        // 写数据
        strcpy((char*)ptr, "i am u father!!");
        // 回收子进程资源
        wait(NULL);
    }
    // 释放内存映射区
    int ret = munmap(ptr, len);
    if (ret == -1)
    {
        perror("munmap error");
        exit(1);
    }
```

### 5.34 匿名映射实现父子进程通信

通过使用我们发现，使用映射区来完成文件读写操作十分方便，父子进程间通信也较容易。但缺陷是，每次创建映射区一定要依赖一个文件才能实现。

通常为了建立映射区要open一个temp文件，创建好了再unlink、close掉，比较麻烦。 可以直接使用匿名映射来代替。

其实Linux系统给我们提供了创建匿名映射区的方法，无需依赖一个文件即可创建映射区。同样需要借助标志位参数flags来指定。

使用**MAP_ANONYMOUS (或MAP_ANON)**。

```
int *p = mmap(NULL, 4, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
```

- 4"随意举例，该位置表示映射区大小，可依实际需要填写。
- MAP_ANONYMOUS和MAP_ANON这两个宏是Linux操作系统特有的宏。在类Unix系统中如无该宏定义，可使用如下两步来完成匿名映射区的建立。

```c
// 创建匿名内存映射区
    int len = 4096;
    void *ptr = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0);
    if (ptr == MAP_FAILED)
    {
        perror("mmap error");
        exit(1);
    }
    // 创建子进程
    pid_t pid = fork();
    if (pid > 0) //父进程
    {
        // 写数据
        strcpy((char*)ptr, "hello mike!!");
        // 回收
        wait(NULL);
    }
    else if (pid == 0)//子进程
    {
        sleep(1);
        // 读数据
        printf("%s\n", (char*)ptr);
    }
    // 释放内存映射区
    int ret = munmap(ptr, len);
    if (ret == -1)
    {
        perror("munmap error");
        exit(1);
    }
```



# 6、信号

## 6.1 信号的概念

信号是 Linux 进程间通信的最古老的方式。信号是软件中断，它是在软件层次上对中断机制的一种模拟，是一种异步通信的方式 。信号可以导致一个正在运行的进程被另一个正在运行的异步进程中断，转而处理某一个突发事件。

## 6.2 信号的编号

kill -l 查看编号

| **编号** | **信号**             | **对应事件**                                                 | **默认动作**               |
| :------- | :------------------- | :----------------------------------------------------------- | :------------------------- |
| 1        | SIGHUP               | 用户退出shell时，由该shell启动的所有进程将收到这个信号       | 终止进程                   |
| 2        | **SIGINT**           | 当用户按下了**<Ctrl+C>**组合键时，用户终端向正在运行中的由该终端启动的程序发出此信号 | 终止进程                   |
| 3        | **SIGQUIT**          | 用户按下**<ctrl+\>**组合键时产生该信号，用户终端向正在运行中的由该终端启动的程序发出些信号 | 终止进程                   |
| 4        | SIGILL               | CPU检测到某进程执行了非法指令                                | 终止进程并产生core文件     |
| 5        | SIGTRAP              | 该信号由断点指令或其他 trap指令产生                          | 终止进程并产生core文件     |
| 6        | SIGABRT              | 调用abort函数时产生该信号                                    | 终止进程并产生core文件     |
| 7        | SIGBUS               | 非法访问内存地址，包括内存对齐出错                           | 终止进程并产生core文件     |
| 8        | SIGFPE               | 在发生致命的运算错误时发出。不仅包括浮点运算错误，还包括溢出及除数为0等所有的算法错误 | 终止进程并产生core文件     |
| 9        | SIGKILL              | 无条件终止进程。本信号不能被忽略，处理和阻塞                 | 终止进程，可以杀死任何进程 |
| 10       | SIGUSE1              | 用户定义的信号。即程序员可以在程序中定义并使用该信号         | 终止进程                   |
| 11       | **SIGSEGV**          | 指示进程进行了无效内存访问(段错误)                           | 终止进程并产生core文件     |
| 12       | SIGUSR2              | 另外一个用户自定义信号，程序员可以在程序中定义并使用该信号   | 终止进程                   |
| 13       | **SIGPIPE**          | Broken pipe向一个没有读端的管道写数据                        | 终止进程                   |
| 14       | SIGALRM              | 定时器超时，超时的时间 由系统调用alarm设置                   | 终止进程                   |
| 15       | SIGTERM              | 程序结束信号，与SIGKILL不同的是，该信号可以被阻塞和终止。通常用来要示程序正常退出。执行shell命令Kill时，缺省产生这个信号 | 终止进程                   |
| 16       | SIGSTKFLT            | Linux早期版本出现的信号，现仍保留向后兼容                    | 终止进程                   |
| 17       | **SIGCHLD**          | 子进程结束时，父进程会收到这个信号                           | 忽略这个信号               |
| 18       | SIGCONT              | 如果进程已停止，则使其继续运行                               | 继续/忽略                  |
| 19       | SIGSTOP              | 停止进程的执行。信号不能被忽略，处理和阻塞                   | 为终止进程                 |
| 20       | SIGTSTP              | 停止终端交互进程的运行。按下<ctrl+z>组合键时发出这个信号     | 暂停进程                   |
| 21       | SIGTTIN              | 后台进程读终端控制台                                         | 暂停进程                   |
| 22       | SIGTTOU              | 该信号类似于SIGTTIN，在后台进程要向终端输出数据时发生        | 暂停进程                   |
| 23       | SIGURG               | 套接字上有紧急数据时，向当前正在运行的进程发出些信号，报告有紧急数据到达。如网络带外数据到达 | 忽略该信号                 |
| 24       | SIGXCPU              | 进程执行时间超过了分配给该进程的CPU时间 ，系统产生该信号并发送给该进程 | 终止进程                   |
| 25       | SIGXFSZ              | 超过文件的最大长度设置                                       | 终止进程                   |
| 26       | SIGVTALRM            | 虚拟时钟超时时产生该信号。类似于SIGALRM，但是该信号只计算该进程占用CPU的使用时间 | 终止进程                   |
| 27       | SGIPROF              | 类似于SIGVTALRM，它不公包括该进程占用CPU时间还包括执行系统调用时间 | 终止进程                   |
| 28       | SIGWINCH             | 窗口变化大小时发出                                           | 忽略该信号                 |
| 29       | SIGIO                | 此信号向进程指示发出了一个异步IO事件                         | 忽略该信号                 |
| 30       | SIGPWR               | 关机                                                         | 终止进程                   |
| 31       | SIGSYS               | 无效的系统调用                                               | 终止进程并产生core文件     |
| 34~64    | SIGRTMIN ～ SIGRTMAX | LINUX的实时信号，它们没有固定的含义（可以由用户自定义）      |                            |

## 6.3 信号四要素

每个信号必备4要素，分别是：

1）编号 2）名称 3）事件 4）默认处理动作

可通过**man 7 signal**查看帮助文档获取

在标准信号中，有一些信号是有三个“Value”，第一个值通常对alpha和sparc架构有效，中间值针对x86、arm和其他架构，最后一个应用于mips架构。一个‘-’表示在对应架构上尚未定义该信号。

不同的操作系统定义了不同的系统信号。因此有些信号出现在Unix系统内，也出现在Linux中，而有的信号出现在FreeBSD或Mac OS中却没有出现在Linux下。这里我们只研究Linux系统中的信号。

Action为默认动作：

- Term：终止进程
- Ign： 忽略信号 (默认即时对该种信号忽略操作)
- Core：终止进程，生成Core文件。(查验死亡原因，用于gdb调试)
- Stop：停止（暂停）进程
- Cont：继续运行进程

注意通过man 7 signal命令查看帮助文档，其中可看到 : The signals **SIGKILL** and **SIGSTOP** cannot be caught, blocked, or ignored.

这里特别强调了**9) SIGKILL** **和19) SIGSTOP信号，不允许忽略和捕捉，只能执行默认动作。甚至不能将其设置为阻塞。**

另外需清楚，只有每个信号所对应的事件发生了，该信号才会被递送(但不一定递达)，不应乱发信号！！

 

## 6.4 信号的状态

**1) 产生**

a) 当用户按某些终端键时，将产生信号。

终端上按“Ctrl+c”组合键通常产生中断信号 SIGINT

终端上按“Ctrl+\”键通常产生中断信号 SIGQUIT

终端上按“Ctrl+z”键通常产生中断信号 SIGSTOP 等。

b) 硬件异常将产生信号。

除数为 0，无效的内存访问等。这些情况通常由硬件检测到，并通知内核，然后内核产生适当的信号发送给相应的进程。

c) 软件异常将产生信号。

当检测到某种软件条件已发生(如：定时器alarm)，并将其通知有关进程时，产生信号。

d) 调用系统函数(如：kill、raise、abort)将发送信号。

注意：接收信号进程和发送信号进程的所有者必须相同，或发送信号进程的所有者必须是超级用户。

e) 运行 kill /killall命令将发送信号。

此程序实际上是使用 kill 函数来发送信号。也常用此命令终止一个失控的后台进程。

**2) 未决状态：没有被处理**

**3) 递达状态：信号被处理了**

## 6.5 阻塞信号集和未决信号集

信号的实现手段导致信号有很强的延时性，但对于用户来说，时间非常短，不易察觉。

Linux内核的进程控制块PCB是一个结构体，task_struct, 除了包含进程id，状态，工作目录，用户id，组id，文件描述符表，还包含了信号相关的信息，主要指**阻塞信号集和未决信号集**。

**6.1 阻塞信号集(信号屏蔽字)**

将某些信号加入集合，对他们设置屏蔽，当屏蔽x信号后，再收到该信号，该信号的处理将推后(处理发生在解除屏蔽后)。

**6.2 未决信号集**

信号产生，未决信号集中描述该信号的位立刻翻转为1，表示信号处于未决状态。当信号被处理对应位翻转回为0。这一时刻往往非常短暂。

信号产生后由于某些原因(主要是阻塞)不能抵达。这类信号的集合称之为未决信号集。在屏蔽解除前，信号一直处于未决状态

## 6.6 信号产生函数

### 6.6.1 kill函数

```c
#include <sys/types.h>
#include <signal.h>
int kill(pid_t pid, int sig);
功能：给指定进程发送指定信号(不一定杀死)
参数：
    pid : 取值有 4 种情况 :
        pid > 0:   将信号传送给进程 ID 为pid的进程。
        pid = 0 :  将信号传送给当前进程所在进程组中的所有进程。
        pid = -1 : 将信号传送给系统内所有的进程。
        pid < -1 : 将信号传给指定进程组的所有进程。这个进程组号等于 pid 的绝对值。
    sig : 信号的编号，这里可以填数字编号，也可以填信号的宏定义，可以通过命令 kill - l("l" 为字母)进行相应查看。不推荐直接使用数字，应使用宏名，因为不同操作系统信号编号可能不同，但名称一致。
返回值：
    成功：0
    失败：-1
```

super用户(root)可以发送信号给任意用户，普通用户是不能向系统用户发送信号的。

kill -9 (root用户的pid) 是不可以的。同样，普通用户也不能向其他普通用户发送信号，终止其进程。 只能向自己创建的进程发送信号。

普通用户基本规则是：发送者实际或有效用户ID == 接收者实际或有效用户ID

**参考代码**

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<signal.h>
#include<unistd.h>
int main(void)
{
  pid_t pid = -1;
  pid = fork();
  if(-1 == pid)
  {
    perror("fork");
    return 1;
  } else if(0 == pid){  //子进程
    while(1)
    {
     printf("child process is working now \n");
     sleep(1);
    }
     exit(0);
  }else{ //父进程
    sleep(3);
    printf("子进程不听话,该睡觉了\n");
    kill(pid,15);
    printf("父进程结束了,完成了他的使命\n");
  }
  return 0;
}
```



### 6.6.2 raise函数

```c
#include <signal.h>
int raise(int sig);
功能：给当前进程发送指定信号(自己给自己发)，等价于 kill(getpid(), sig)
参数：
    sig：信号编号
返回值：
    成功：0
    失败：非0值
```

### 6.6.3 abort函数

```c
#include <stdlib.h>
void abort(void);
功能：给自己发送异常终止信号 6) SIGABRT，并产生core文件，等价于kill(getpid(), SIGABRT);
参数：无
返回值：无
```

### 6.6.4 alarm函数(闹钟)

```c
#include <unistd.h>
unsigned int alarm(unsigned int seconds);
功能：
    设置定时器(闹钟)。在指定seconds后，内核会给当前进程发送14）SIGALRM信号。进程收到该信号，默认动作终止。每个进程都有且只有唯一的一个定时器。
    取消定时器alarm(0)，返回旧闹钟余下秒数。
参数：
    seconds：指定的时间，以秒为单位
返回值：
    返回0或剩余的秒数
```

### 6.6.5 setitimer函数(定时器)

```c
#include <sys/time.h>
int setitimer(int which,  const struct itimerval *new_value, struct itimerval *old_value);
功能：
    设置定时器(闹钟)。 可代替alarm函数。精度微秒us，可以实现周期定时。
参数：
    which：指定定时方式
        a) 自然定时：ITIMER_REAL → 14）SIGALRM计算自然时间
        b) 虚拟空间计时(用户空间)：ITIMER_VIRTUAL → 26）SIGVTALRM  只计算进程占用cpu的时间
        c) 运行时计时(用户 + 内核)：ITIMER_PROF → 27）SIGPROF计算占用cpu及执行系统调用的时间
    new_value：struct itimerval, 负责设定timeout时间
        struct itimerval {
            struct timerval it_interval; // 闹钟触发周期
            struct timerval it_value;    // 闹钟触发时间
        };
        struct timeval {
            long tv_sec;            // 秒
            long tv_usec;           // 微秒
        }
        itimerval.it_value： 设定第一次执行function所延迟的秒数 
        itimerval.it_interval：  设定以后每几秒执行function
    old_value： 存放旧的timeout值，一般指定为NULL
返回值：
    成功：0
    失败：-1
```

## 6.7 信号捕捉

### 6.71 信号处理方式

一个进程收到一个信号的时候，可以用如下方法进行处理：

1）执行系统默认动作

对大多数信号来说，系统默认动作是用来终止该进程。

2）忽略此信号(丢弃)

接收到此信号后没有任何动作。

3）执行自定义信号处理函数(捕获)

用用户定义的信号处理函数处理该信号。

【注意】：SIGKILL 和 SIGSTOP 不能更改信号的处理方式，因为它们向用户提供了一种使进程终止的可靠方法。

### 6.72 signal函数

```c
#include <signal.h>
typedef void(*sighandler_t)(int);
sighandler_t signal(int signum, sighandler_t handler);
功能：
    注册信号处理函数（不可用于 SIGKILL、SIGSTOP 信号），即确定收到信号后处理函数的入口地址。此函数不会阻塞。
参数：
    signum：信号的编号，这里可以填数字编号，也可以填信号的宏定义，可以通过命令 kill - l("l" 为字母)进行相应查看。
    handler : 取值有 3 种情况：
          SIG_IGN：忽略该信号
          SIG_DFL：执行系统默认动作
          信号处理函数名：自定义信号处理函数，如：func
          回调函数的定义如下：
            void func(int signo)
            {
                // signo 为触发的信号，为 signal() 第一个参数的值
            }
返回值：
    成功：第一次返回 NULL，下一次返回此信号上一次注册的信号处理函数的地址。如果需要使用此返回值，必须在前面先声明此函数指针的类型。
    失败：返回 SIG_ERR
```

该函数由ANSI定义，由于历史原因在不同版本的Unix和不同版本的Linux中可能有不同的行为。因此应该尽量避免使用它，取而代之使用sigaction函数。

### 6.73 sigaction函数

```c
#include <signal.h>
int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
功能：
    检查或修改指定信号的设置（或同时执行这两种操作）。
参数：
    signum：要操作的信号。
    act：   要设置的对信号的新处理方式（传入参数）。
    oldact：原来对信号的处理方式（传出参数）。
    如果 act 指针非空，则要改变指定信号的处理方式（设置），如果 oldact 指针非空，则系统将此前指定信号的处理方式存入 oldact。
返回值：
    成功：0
    失败：-1
```

**struct sigaction结构体**

```c
struct sigaction {
    void(*sa_handler)(int); //旧的信号处理函数指针
    void(*sa_sigaction)(int, siginfo_t *, void *); //新的信号处理函数指针
    sigset_t   sa_mask;      //信号阻塞集
    int        sa_flags;     //信号处理的方式
    void(*sa_restorer)(void); //已弃用
};
```

1) sa_handler、sa_sigaction：信号处理函数指针，和 signal() 里的函数指针用法一样，应根据情况给sa_sigaction、sa_handler 两者之一赋值，其取值如下：

a) SIG_IGN：忽略该信号

b) SIG_DFL：执行系统默认动作

c) 处理函数名：自定义信号处理函数

2) sa_mask：信号阻塞集，在信号处理函数执行过程中，临时屏蔽指定的信号。

3) sa_flags：用于指定信号处理的行为，通常设置为0，表使用默认属性。它可以是一下值的“按位或”组合：

Ø SA_RESTART：使被信号打断的系统调用自动重新发起（已经废弃）

Ø SA_NOCLDSTOP：使父进程在它的子进程暂停或继续运行时不会收到 SIGCHLD 信号。

Ø SA_NOCLDWAIT：使父进程在它的子进程退出时不会收到 SIGCHLD 信号，这时子进程如果退出也不会成为僵尸进程。

Ø SA_NODEFER：使对信号的屏蔽无效，即在信号处理函数执行期间仍能发出这个信号。

Ø SA_RESETHAND：信号处理之后重新设置为默认的处理方式。

Ø SA_SIGINFO：使用 sa_sigaction 成员而不是 sa_handler 作为信号处理函数

**信號處理函數**

```c
void(*sa_sigaction)(int signum, siginfo_t *info, void *context);
参数说明：
    signum：信号的编号。
    info：记录信号发送进程信息的结构体。
    context：可以赋给指向 ucontext_t 类型的一个对象的指针，以引用在传递信号时被中断的接收进程或线程的上下文。
```

参考代码

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
void fun(int signum)
{
   printf("捕捉到的信号: %d\n",signum);
}
void fun1(int signum,siginfo_t *info,void *context)
{
   printf("捕捉到的信号: %d\n",signum);
}
int main()
{
    int ret = -1;
#if 0
    struct sigaction act;
    act.sa_handler = fun;
    act.sa_flags = 0;
#else  
    struct sigaction act;
    act.sa_sigaction = fun1;
    act.sa_flags = SA_SIGINFO;
#endif   
    ret = sigaction(SIGINT,&act,NULL);
    if(0!=ret)
    {
      perror("sigaction");
      return 1;
    }  
    while(1)
    {
       getchar();
    }
     return 0;
}
```

### 6.74 sigqueue 函数(了解)

```c
#include <signal.h>
int sigqueue(pid_t pid, int sig, const union sigval value);
功能：
    给指定进程发送信号。
参数：
    pid : 进程号。
    sig : 信号的编号。
    value : 通过信号传递的参数。
        union sigval 类型如下：
            union sigval
            {
                int   sival_int;
                void *sival_ptr;
            };
返回值：
    成功：0
    失败：-1
```



## 6.8 信号集

### 6.81 信号集概述

在PCB中有两个非常重要的信号集。一个称之为“阻塞信号集”，另一个称之为“未决信号集”。

这两个信号集都是内核使用**位图机制**来实现的。但操作系统不允许我们直接对其进行位操作。而需自定义另外一个集合，借助信号集操作函数来对PCB中的这两个信号集进行修改。

### 6.82 自定义信号集函数

```c
#include <signal.h>  
int sigemptyset(sigset_t *set);       //将set集合置空
int sigfillset(sigset_t *set)；          //将所有信号加入set集合
int sigaddset(sigset_t *set, int signo);  //将signo信号加入到set集合
int sigdelset(sigset_t *set, int signo);   //从set集合中移除signo信号
int sigismember(const sigset_t *set, int signo); //判断信号是否存在
```

除sigismember外，其余操作函数中的set均为传出参数。sigset_t类型的本质是位图。但不应该直接使用位操作，而应该使用上述函数，保证跨系统操作有效。

參考代码:

```c
int main()
{
    sigset_t set;   // 定义一个信号集变量
    int ret = 0;
    sigemptyset(&set); // 清空信号集的内容
    // 判断 SIGINT 是否在信号集 set 里
    // 在返回 1， 不在返回 0
    ret = sigismember(&set, SIGINT);
    if (ret == 0)
    {
        printf("SIGINT is not a member of set \nret = %d\n", ret);
    }
    sigaddset(&set, SIGINT); // 把 SIGINT 添加到信号集 set
    sigaddset(&set, SIGQUIT);// 把 SIGQUIT 添加到信号集 set
    // 判断 SIGINT 是否在信号集 set 里
    // 在返回 1， 不在返回 0
    ret = sigismember(&set, SIGINT);
    if (ret == 1)
    {
        printf("SIGINT is a member of set \nret = %d\n", ret);
    }
    sigdelset(&set, SIGQUIT); // 把 SIGQUIT 从信号集 set 移除
    // 判断 SIGQUIT 是否在信号集 set 里
    // 在返回 1， 不在返回 0
    ret = sigismember(&set, SIGQUIT);
    if (ret == 0)
    {
        printf("SIGQUIT is not a member of set \nret = %d\n", ret);
    }
    return 0;
}
```

### 6.83 sigprocmask函数

信号阻塞集也称信号屏蔽集、信号掩码。每个进程都有一个阻塞集，创建子进程时子进程将继承父进程的阻塞集。信号阻塞集用来描述哪些信号递送到该进程的时候被阻塞（在信号发生时记住它，直到进程准备好时再将信号通知进程）。

所谓阻塞并不是禁止传送信号, 而是暂缓信号的传送。若将被阻塞的信号从信号阻塞集中删除，且对应的信号在被阻塞时发生了，进程将会收到相应的信号。

我们可以通过 sigprocmask() 修改当前的信号掩码来改变信号的阻塞情况。

```c
#include <signal.h>
int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);
功能：
    检查或修改信号阻塞集，根据 how 指定的方法对进程的阻塞集合进行修改，新的信号阻塞集由 set 指定，而原先的信号阻塞集合由 oldset 保存。
参数：
    how : 信号阻塞集合的修改方法，有 3 种情况：
        SIG_BLOCK：向信号阻塞集合中添加 set 信号集，新的信号掩码是set和旧信号掩码的并集。相当于 mask = mask|set。
        SIG_UNBLOCK：从信号阻塞集合中删除 set 信号集，从当前信号掩码中去除 set 中的信号。相当于 mask = mask & ~ set。
        SIG_SETMASK：将信号阻塞集合设为 set 信号集，相当于原来信号阻塞集的内容清空，然后按照 set 中的信号重新设置信号阻塞集。相当于mask = set。
    set : 要操作的信号集地址。
        若 set 为 NULL，则不改变信号阻塞集合，函数只把当前信号阻塞集合保存到 oldset 中。
    oldset : 保存原先信号阻塞集地址
返回值：
    成功：0，
    失败：-1，失败时错误代码只可能是 EINVAL，表示参数 how 不合法。
```

参考代码

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
void fun1(int signo)
{
  printf("捕捉到信號:%d\n",signo);
}
void fun2(int signo)
{
  printf("捕捉到信號:%d\n",signo);
}
int main(void)
{
   signal(SIGINT,fun1);
   signal(SIGQUIT,fun2);
   sigset_t set;
   sigset_t oldset;
   printf("按下任意鍵阻塞信號2....\n");
   getchar();
   sigemptyset(&set);
   sigemptyset(&oldset);
   sigaddset(&set,SIGINT);
   //阻塞信號
   int ret = sigprocmask(SIG_BLOCK,&set,&oldset);
   if(0!=ret)
   { 
     perror("sigprocmask");
     return 1;  
   }
   printf("阻塞信號2成功....\n");
   printf("按下任意鍵解除阻塞信號....\n");
   getchar();
   //解除信號
   ret = sigprocmask(SIG_SETMASK,&oldset,NULL);
   if(0!=ret)
   {
     perror("sigpromask");
     return 1;
   }else{
   printf("解除阻塞成功....\n");
   }
    return 0; 
}
```



### 6.84 sigpending函数

```c
#include <signal.h>
int sigpending(sigset_t *set);
功能：读取当前进程的未决信号集
参数：
    set：未决信号集
返回值：
    成功：0
    失败：-1
```

### 6.85 不可冲入、可重入函数

如果有一个函数不幸被设计成为这样：那么不同任务调用这个函数时可能修改其他任务调用这个函数的数据，从而导致不可预料的后果。这样的函数是不安全的函数，也叫不可重入函数。

 

满足下列条件的函数多数是不可重入（不安全）的：

- 函数体内使用了静态的数据结构；
- 函数体内调用了malloc() 或者 free() 函数(谨慎使用堆)；
- 函数体内调用了标准 I/O 函数。

 

相反，肯定有一个安全的函数，这个安全的函数又叫可重入函数。那么什么是可重入函数呢？所谓可重入是指一个可以被多个任务调用的过程，任务在调用时不必担心数据是否会出错。

 

保证函数的可重入性的方法：

- 在写函数时候尽量使用局部变量（例如寄存器、栈中的变量）；
- 对于要使用的全局变量要加以保护（如采取关中断、信号量等互斥方法），这样构成的函数就一定是一个可重入的函数。

Linux常见的可重入函数：

![image-20220720173153202](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220720173153202.png)

## 6.9 SIGCHLD信号

### 6.9.1 SIGCHLD信号产生的条件

1) 子进程终止时

2) 子进程接收到SIGSTOP信号停止时

3) 子进程处在停止态，接受到SIGCONT后唤醒时

### 6.9.2 如何避免僵尸进程

1) 最简单的方法，父进程通过 wait() 和 waitpid() 等函数等待子进程结束，但是，这会导致父进程挂起。

2) 如果父进程要处理的事情很多，不能够挂起，通过 signal() 函数人为处理信号 SIGCHLD ， 只要有子进程退出自动调用指定好的回调函数，因为子进程结束后， 父进程会收到该信号 SIGCHLD ，可以在其回调函数里调用 wait() 或 waitpid() 回收。

参考代码

```c
void sig_child(int signo)
{
    pid_t  pid;
    //处理僵尸进程, -1 代表等待任意一个子进程, WNOHANG代表不阻塞
    while ((pid = waitpid(-1, NULL, WNOHANG)) > 0)
    {
        printf("child %d terminated.\n", pid);
    }
}
int main()
{
    pid_t pid;
    // 创建捕捉子进程退出信号
    // 只要子进程退出，触发SIGCHLD，自动调用sig_child()
    signal(SIGCHLD, sig_child);
    pid = fork();   // 创建进程
    if (pid < 0)
    { // 出错
        perror("fork error:");
        exit(1);
    }
    else if (pid == 0)
    { // 子进程
        printf("I am child process,pid id %d.I am exiting.\n", getpid());
        exit(0);
    }
    else if (pid > 0)
    { // 父进程
        sleep(2);   // 保证子进程先运行
        printf("I am father, i am exited\n\n");
        system("ps -ef | grep defunct"); // 查看有没有僵尸进程
    }
    return 0;
}
```

​     3.如果父进程不关心子进程什么时候结束，那么可以用signal（SIGCHLD, SIG_IGN）通知内核，自己对子进程的结束不感兴趣，父进程忽略此信号，那么子进程结束后，内核会回收， 并不再给父进程发送信号。

參考代碼

```c
int main()
{
    pid_t pid;
    // 忽略子进程退出信号的信号
    // 那么子进程结束后，内核会回收， 并不再给父进程发送信号
    signal(SIGCHLD, SIG_IGN);
    pid = fork();   // 创建进程
    if (pid < 0)
    { // 出错
        perror("fork error:");
        exit(1);
    }
    else if (pid == 0)
    { // 子进程
        printf("I am child process,pid id %d.I am exiting.\n", getpid());
        exit(0);
    }
    else if (pid > 0)
    { // 父进程
        sleep(2);   // 保证子进程先运行
        printf("I am father, i am exited\n\n");
        system("ps -ef | grep defunct"); // 查看有没有僵尸进程
    }
    return 0;
}
```



# 7、守护进程(重点)

### 7.1 守护进程介绍

守护进程（Daemon Process），也就是通常说的 Daemon 进程（精灵进程），是 Linux 中的后台服务进程。它是一个生存期较长的进程，通常独立于控制终端并且周期性地执行某种任务或等待处理某些发生的事件。一般采用以d结尾的名字。

守护进程是个特殊的孤儿进程，这种进程脱离终端，为什么要脱离终端呢？之所以脱离于终端是为了避免进程被任何终端所产生的信息所打断，其在执行过程中的信息也不在任何终端上显示。由于在 Linux 中，每一个系统与用户进行交流的界面称为终端，每一个从此终端开始运行的进程都会依附于这个终端，这个终端就称为这些进程的控制终端，当控制终端被关闭时，相应的进程都会自动关闭。

Linux 的大多数服务器就是用守护进程实现的。比如，Internet 服务器 inetd，Web 服务器 httpd 等。

### 7.2 守护进程模型

1) 创建子进程，父进程退出(必须)

- 所有工作在子进程中进行形式上脱离了控制终端

2) 在子进程中创建新会话(必须)

- setsid()函数
- 使子进程完全独立出来，脱离控制

3) 改变当前目录为根目录(不是必须)

- chdir()函数
- 防止占用可卸载的文件系统
- 也可以换成其它路径

4) 重设文件权限掩码(不是必须)

- umask()函数
- 防止继承的文件创建屏蔽字拒绝某些权限
- 增加守护进程灵活性

5) 关闭文件描述符(不是必须)

- 继承的打开文件不会用到，浪费系统资源，无法卸载

6) 开始执行守护进程核心工作(必须)

​       守护进程退出处理程序模型

### 7.3 守护进程参考代码

写一个守护进程, 每隔1s获取当前时间年月日时分秒以及在/home/niuzi/log文件夹中创建当前时间名字的文件。

```c
/*
* time_t rawtime;
* time ( &rawtime  ); --- 获取时间，以秒计，从1970年1月一日起算，存于rawtime
* localtime ( &rawtime  ); //转为当地时间，tm 时间结构
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#define SIZE 64
int main(void)
{
   char file_name[SIZE];
   int ret = -1;
   pid_t pid = -1;
   time_t t = -1;
   struct tm * pT = NULL;
   //创建子进程
   pid = fork();
   if(-1 == pid)
   {
     perror("fork");
     return 1;
   }
   //父进程退出
   if(pid>0)
   {
     exit(0);
   }
   //子进程创建新会话
   pid = setsid();
   if(-1 == pid)
   {
     perror("setsid");
     return 1;
   }
   //改变目录为当前目录
   ret = chdir("/");
   if(-1 == ret)
   {
     perror("chidr");
     return 1;
   }
   //重设文件权限掩码
   umask(0);
   //关闭文件描述符
   close(STDIN_FILENO);
   close(STDOUT_FILENO);
   close(STDERR_FILENO);
   //守护进程核心代码
   while(1)
    {
       t = time(NULL);
       pT = localtime(&t);
       if(NULL == pT)
       {
         printf("localtime failed...\n");
         return 1;
       }
       memset(file_name,0,SIZE);
       sprintf(file_name,"%s%d%d%d%d%d%d.log","touch /home/niuzi/log/",pT->tm_year +1900,
       pT->tm_mon+1,pT->tm_mday,pT->tm_hour,pT->tm_min,pT->tm_sec);
       printf("file_name %s\n",file_name);
       system(file_name);
       sleep(1);

    }

    return 0;
}
```

# 8、线程简介

## 8.1 线程概念

在许多经典的操作系统教科书中，总是把进程定义为程序的执行实例，它并不执行什么, 只是维护应用程序所需的各种资源，而线程则是真正的执行实体。

所以，线程是轻量级的进程（LWP：light weight process），在Linux环境下线程的本质仍是进程。

为了让进程完成一定的工作，进程必须至少包含一个线程。

进程，直观点说，保存在硬盘上的程序运行以后，会在内存空间里形成一个独立的内存体，这个内存体有自己的地址空间，有自己的堆，上级挂靠单位是操作系统。操作系统会以进程为单位，分配系统资源，所以我们也说，**进程是CPU分配资源的最小单位**。

线程存在与进程当中(进程可以认为是线程的容器)，是操作系统调度执行的最小单位。说通俗点，线程就是干活的。

进程是具有一定独立功能的程序关于某个数据集合上的一次运行活动，进程是系统进行资源分配和调度的一个独立单位。

线程是进程的一个实体，是 CPU 调度和分派的基本单位，它是比进程更小的能独立运行的基本单位。线程自己基本上不拥有系统资源，只拥有一点在运行中必不可少的资源（如程序计数器，一组寄存器和栈），但是它可与同属一个进程的其他的线程共享进程所拥有的全部资源。

如果说进程是一个资源管家，负责从主人那里要资源的话，那么线程就是干活的苦力。一个管家必须完成一项工作，就需要最少一个苦力，也就是说，一个进程最少包含一个线程，也可以包含多个线程。苦力要干活，就需要依托于管家，所以说一个线程，必须属于某一个进程。

进程有自己的地址空间，线程使用进程的地址空间，也就是说，进程里的资源，线程都是有权访问的，比如说堆啊，栈啊，静态存储区什么的。

> 进程是操作系统分配资源的最小单位
>
> 线程是操作系统调度的最小单位

## 8.2 线程常用操作

### 8.21 获取线程号

```c
#include <pthread.h>
pthread_t pthread_self(void);
功能：
    获取线程号。
参数：
    无
返回值：
    调用线程的线程 ID 
```

### 8.22 判断线程号是否相等

```c
int pthread_equal(pthread_t t1, pthread_t t2);
功能：
    判断线程号 t1 和 t2 是否相等。为了方便移植，尽量使用函数来比较线程 ID。
参数：
    t1，t2：待判断的线程号。
返回值：
    相等：非 0
    不相等：0
```

参考程序:

```c
int main()
{
    pthread_t thread_id;
    thread_id = pthread_self(); // 返回调用线程的线程ID
    printf("Thread ID = %lu \n", thread_id);
    if (0 != pthread_equal(thread_id, pthread_self()))
    {
        printf("Equal!\n");
    }
    else
    {
        printf("Not equal!\n");
    }
    return 0;
}
```

【注意】线程函数的程序在 pthread 库中，故链接时要加上参数 -lpthread。

### 8.23 线程的创建

```c
#include <pthread.h>
int pthread_create(pthread_t *thread,const pthread_attr_t *attr,
            void *(*start_routine)(void *),
            void *arg );
功能：
    创建一个线程。
参数：
    thread：线程标识符地址。
    attr：线程属性结构体地址，通常设置为 NULL。
    start_routine：线程函数的入口地址。
    arg：传给线程函数的参数。
返回值：
    成功：0
    失败：非 0
```

```c
// 回调函数
void *thread_fun(void * arg)
{
    sleep(1);
    int num = *((int *)arg);
    printf("int the new thread: num = %d\n", num);
    return NULL;
}
int main()
{
    pthread_t tid;
    int test = 100;
    // 返回错误号
    int ret = pthread_create(&tid, NULL, thread_fun, (void *)&test);
    if (ret != 0)
    {
        printf("error number: %d\n", ret);
        // 根据错误号打印错误信息
        printf("error information: %s\n", strerror(ret));
    }
    while (1);
    return 0;
}
```

在一个线程中调用pthread_create()创建新的线程后，当前线程从pthread_create()返回继续往下执行，而新的线程所执行的代码由我们传给pthread_create的函数指针start_routine决定。

由于pthread_create的错误码不保存在errno中，因此不能直接用perror()打印错误信息，可以先用strerror()把错误码转换成错误信息再打印。

### 8.24 线程资源回收

使用函数pthread_join函数回收

fflush(stdout)刷新缓冲区

```c
#include <pthread.h>
int pthread_join(pthread_t thread, void **retval);
功能：
    等待线程结束（此函数会阻塞），并回收线程资源，类似进程的 wait() 函数。如果线程已经结束，那么该函数会立即返回。
参数：
    thread：被等待的线程号。
    retval：用来存储线程退出状态的指针的地址。
返回值：
    成功：0
    失败：非 0
-----------------------------------------------------------------------------------------
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<unistd.h> 
#include<pthread.h> 
 
void * fun(void*arg) 
{ 
  for(int i = 0;i<5;i++)
  {
    printf("fun thread do working %d\n",i);
    sleep(1); 
 }      
  return (void *)0x03;
}
int main(void)
{
    int ret = -1;
    void *retp =NULL;
    pthread_t tid = -1;
    ret = pthread_create(&tid,NULL,fun,NULL);   
    if(0!=ret)
   {
    printf("pthread create failed...\n");
    return 1;
   }           
    printf("main thread running....\n");
    ret = pthread_join(tid,&retp);
    if(0!=ret)
   {
    printf("pthread_join failed...\n");
    return 1;
   }  
    printf("retp: %p\n",retp);
    printf("main thread exit......\n");
     return 0;
}
1) 如果thread线程通过return返回，retval所指向的单元里存放的是thread线程函数的返回值。
2) 如果thread线程被别的线程调用pthread_cancel异常终止掉，retval所指向的单元里存放的是常数PTHREAD_CANCELED。
3) 如果thread线程是自己调用pthread_exit终止的，retval所指向的单元存放的是传给pthread_exit的参数。
```

### 8.25 线程分离

线程可以被置为detach状态，这样的线程一旦终止就立刻回收它占用的所有资源，而不保留终止状态。不能对一个已经处于detach状态的线程调用pthread_join，这样的调用将返回EINVAL错误。也就是说，如果已经对一个线程调用了pthread_detach就不能再调用pthread_join了。

pthread_detach函数：

```c
#include <pthread.h>
int pthread_detach(pthread_t thread);
功能：
    使调用线程与当前进程分离，分离后不代表此线程不依赖与当前进程，线程分离的目的是将线程资源的回收工作交由系统自动来完成，也就是说当被分离的线程结束之后，系统会自动回收它的资源。所以，此函数不会阻塞。
参数：
    thread：线程号。
返回值：
    成功：0
    失败：非0
//參考程序
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
void * fun(void*arg)
{
  for(int i = 0;i<5;i++)
 {
   printf("thread do working %d\n",i);
   sleep(1);
 }
  return NULL;
}
int main(void)
{
   int ret = -1;
   pthread_t tid = -1;
   ret = pthread_create(&tid,NULL,fun,NULL);
   if(0!=ret)
   {
    printf("pthread create failed.....\n");
    return 1;
   }
    printf("main thread tid =%lu\n",pthread_self());

    ret = pthread_detach(tid);
   if(0!=ret)
   {
    printf("pthread detach failed");
    return 1;
   }
    ret = pthread_join(tid,NULL);
   if(0!=ret)
   {
    printf("pthread join failed\n");
   }else
   {
    printf("pthread join success\n");
   }
   printf("按下任意键 线程退出..\n");
   getchar();
   return 0;
}
```

### 8.26 线程退出

线程从执行函数中返回。

线程调用pthread_exit退出线程。

线程可以被同一进程中的其它线程取消。

 pthread_exit函数

```c
#include <pthread.h>
void pthread_exit(void *retval);
功能：
    退出调用线程。一个进程中的多个线程是共享该进程的数据段，因此，通常线程退出后所占用的资源并不会释放。
参数：
    retval：存储线程退出状态的指针。
返回值：无  
```

pthread_cancel函数

```c
#include <pthread.h>
​
int pthread_cancel(pthread_t thread);
功能：
    杀死(取消)线程
参数：
    thread : 目标线程ID。
返回值：
    成功：0
    失败：出错编号
```

### 8.27 线程属性初始化和销毁

```c
#include <pthread.h>
int pthread_attr_init(pthread_attr_t *attr);
功能：
    初始化线程属性函数，注意：应先初始化线程属性，再pthread_create创建线程
参数：
    attr：线程属性结构体
返回值：
    成功：0
    失败：错误号
int pthread_attr_destroy(pthread_attr_t *attr);
功能：
    销毁线程属性所占用的资源函数
参数：
    attr：线程属性结构体
返回值：
    成功：0
    失败：错误号
```

### 8.28 线程分离状态

线程的分离状态决定一个线程以什么样的方式来终止自己。

- 非分离状态：线程的默认属性是非分离状态，这种情况下，原有的线程等待创建的线程结束。只有当pthread_join()函数返回时，创建的线程才算终止，才能释放自己占用的系统资源。
- 分离状态：分离线程没有被其他的线程所等待，自己运行结束了，线程也就终止了，马上释放系统资源。应该根据自己的需要，选择适当的分离状态。

相关函数：

```c
#include <pthread.h>
int pthread_attr_setdetachstate(pthread_attr_t *attr, int detachstate);
功能：设置线程分离状态
参数：
    attr：已初始化的线程属性
    detachstate：    分离状态
        PTHREAD_CREATE_DETACHED（分离线程）
        PTHREAD_CREATE_JOINABLE（非分离线程）
返回值：
    成功：0
    失败：非0
int pthread_attr_getdetachstate(const pthread_attr_t *attr, int *detachstate);
功能：获取线程分离状态
参数：
    attr：已初始化的线程属性
    detachstate：    分离状态
        PTHREAD_CREATE_DETACHED（分离线程）
        PTHREAD _CREATE_JOINABLE（非分离线程）
返回值：
    成功：0
    失败：非0
```

參考代码:

```c
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<unistd.h> 
#include<pthread.h> 
void * fun(void *arg) 
{ 
         
   for(int i = 0;i<5;i++) 
   { 
     printf("pthread do working %d\n",i); 
     sleep(1); 
   }             
     return NULL; 
} 
int main(void) 
{ 
        int ret = -1; 
        pthread_t tid = -1; 
        pthread_attr_t attr; 
        ret = pthread_attr_init(&attr); 
        if(0!=ret) 
       { 
         printf("pthread attr init failed....\n"); 
         return 1; 
       } 
         printf("pthread attr init success...\n"); 
         
        ret =pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);  
        if(0!=ret) 
        { 
         printf("pthread attr setdetachstate failed..\n"); 
         return 1; 
        }
        ret = pthread_create(&tid,&attr,fun,NULL);      
        if(0!=ret)
        {
         printf("pthread create failed....\n");
         return 1;
        }
        ret = pthread_join(tid,NULL);
        if(0!=ret)
        {
          printf("當前綫程為分離狀態....\n");
        }else
        {
          printf("當前綫程為未分離狀態....\n");
        }
        ret = pthread_attr_destroy(&attr);
        if(0!=ret)
        {
          printf("pthread destory failed....\n");
          return 1;
        }
        printf("pthread destory success...\n");
        printf("按下人任意鍵退出...\n");
        getchar();
        return 0;
}

```

## 8.3 线程同步

### 8.31互斥锁

#### 同步和互斥

互斥:是指散步在不同任务之间的若干程序片断，当某个任务运行其中一个程序片段时，其它任务就不能运行它们之中的任一程序片段，只能等到该任务运行完这个程序片段后才可以运行。最基本的场景就是：一个公共资源同一时刻只能被一个进程或线程使用，多个进程或线程不能同时使用公共资源。

同步:是指散步在不同任务之间的若干程序片断，它们的运行必须严格按照规定的某种先后次序来运行，这种先后次序依赖于要完成的特定的任务。最基本的场景就是：两个或两个以上的进程或线程在运行过程中协同步调，按预定的先后次序运行。比如 A 任务的运行依赖于 B 任务产生的数据。

### 8.32 互斥锁函数和代码实现

互斥锁初始化函数pthread_mutex_init()

```c
#include <pthread.h>
int pthread_mutex_init(pthread_mutex_t *restrict mutex,
    const pthread_mutexattr_t *restrict attr);
功能：
    初始化一个互斥锁。
参数：
    mutex：互斥锁地址。类型是 pthread_mutex_t 。
    attr：设置互斥量的属性，通常可采用默认属性，即可将 attr 设为 NULL。
    可以使用宏 PTHREAD_MUTEX_INITIALIZER 静态初始化互斥锁，比如：
    pthread_mutex_t  mutex = PTHREAD_MUTEX_INITIALIZER;
这种方法等价于使用 NULL 指定的 attr 参数调用 pthread_mutex_init() 来完成动态初始化，不同之处在于 PTHREAD_MUTEX_INITIALIZER 宏不进行错误检查。
返回值：
    成功：0，成功申请的锁默认是打开的。
    失败：非 0 错误码
    restrict，C语言中的一种类型限定符（Type Qualifiers），用于告诉编译器，对象已经被指针所引用，不能通过除该指针外所有其他直接或间接的方式修改该对象的内容。
```

互斥锁上锁函数pthread_mutex_lock()

```C
#include <pthread.h>
int pthread_mutex_lock(pthread_mutex_t *mutex);
功能：
    对互斥锁上锁，若互斥锁已经上锁，则调用者阻塞，直到互斥锁解锁后再上锁。
参数：
    mutex：互斥锁地址。
返回值：
    成功：0
    失败：非 0 错误码
int pthread_mutex_trylock(pthread_mutex_t *mutex);
  调用该函数时，若互斥锁未加锁，则上锁，返回 0；
  若互斥锁已加锁，则函数直接返回失败，即 EBUSY。
```

互斥锁解锁函数pthread_mutex_unlock()

```c
#include <pthread.h>
int pthread_mutex_unlock(pthread_mutex_t *mutex);
功能：
    对指定的互斥锁解锁。
参数：
    mutex：互斥锁地址。
返回值：
    成功：0
    失败：非0错误码
```

互斥锁销毁函数pthread_mutex_destory()

```c
#include <pthread.h>
int pthread_mutex_destroy(pthread_mutex_t *mutex);
功能：
    销毁指定的一个互斥锁。互斥锁在使用完毕后，必须要对互斥锁进行销毁，以释放资源。
参数：
    mutex：互斥锁地址。
返回值：
    成功：0
    失败：非 0 错误码
```

相关测试代码:

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
pthread_mutex_t mutex;
void *fun1(void * arg)
{
   pthread_mutex_lock(&mutex);
   for(int i = 'A';i<='Z';i++)
  {
     putchar(i);
     fflush(stdout);
     usleep(100000);
  }
   pthread_mutex_unlock(&mutex);
   return NULL;
}
void *fun2(void * arg)
{
   pthread_mutex_lock(&mutex);
   for(int i = 'a';i<='z';i++)
  {
     putchar(i);
     fflush(stdout);
     usleep(100000);
  }
   pthread_mutex_unlock(&mutex);
   return NULL;
}
int main(void)
{
   pthread_t tid1 = -1;
   pthread_t tid2 = -1;
   int ret = -1;
   ret = pthread_mutex_init(&mutex,NULL);
   if(0!=ret)
   {
    printf("pthread mutex init failed....\n");
    return 1;
   }
   printf("互斥锁初始化成功...\n");
   pthread_create(&tid1,NULL,fun1,NULL);
   pthread_create(&tid2,NULL,fun2,NULL);
   pthread_join(tid1,NULL);
   pthread_join(tid2,NULL);
   printf("\n");
   printf("main thread exit.....\n");
   printf("互斥锁销毁成功...\n");
   return 0;
}
```

### 8.33 死锁

死锁是指两个或两个以上的进程在执行过程中，由于竞争资源或者由于彼此通信而造成的一种阻塞的现象，若无外力作用，它们都将无法推进下去。此时称系统处于死锁状态或系统产生了死锁，这些永远在互相等待的进程称为死锁进程。

### 8.34 读写锁

当有一个线程已经持有互斥锁时，互斥锁将所有试图进入临界区的线程都阻塞住。但是考虑一种情形，当前持有互斥锁的线程只是要读访问共享资源，而同时有其它几个线程也想读取这个共享资源，但是由于互斥锁的排它性，所有其它线程都无法获取锁，也就无法读访问共享资源了，但是实际上多个线程同时读访问共享资源并不会导致问题。

在对数据的读写操作中，更多的是读操作，写操作较少，例如对数据库数据的读写应用。为了满足当前能够允许多个读出，但只允许一个写入的需求，线程提供了**读写锁**来实现。

 

读写锁的特点如下：

1）如果有其它线程读数据，则允许其它线程执行读操作，但不允许写操作。

2）如果有其它线程写数据，则其它线程都不允许读、写操作。



读写锁分为读锁和写锁，规则如下：

1）如果某线程申请了读锁，其它线程可以再申请读锁，但不能申请写锁。

2）如果某线程申请了写锁，其它线程不能申请读锁，也不能申请写锁。



POSIX 定义的读写锁的数据类型是： pthread_rwlock_t。

**pthread_rwlock_init()函数**

```c
#include <pthread.h>
int pthread_rwlock_init(pthread_rwlock_t *restrict rwlock,
    const pthread_rwlockattr_t *restrict attr);
功能：
    用来初始化 rwlock 所指向的读写锁。
参数：
    rwlock：指向要初始化的读写锁指针。
    attr：读写锁的属性指针。如果 attr 为 NULL 则会使用默认的属性初始化读写锁，否则使用指定的 attr 初始化读写锁。
    可以使用宏 PTHREAD_RWLOCK_INITIALIZER 静态初始化读写锁，比如：
    pthread_rwlock_t my_rwlock = PTHREAD_RWLOCK_INITIALIZER;
    这种方法等价于使用 NULL 指定的 attr 参数调用 pthread_rwlock_init() 来完成动态初始化，不同之处在于PTHREAD_RWLOCK_INITIALIZER 宏不进行错误检查。
返回值：
    成功：0，读写锁的状态将成为已初始化和已解锁。
    失败：非 0 错误码。
```

**pthread_rwlock_destroy()函数**

```c
#include <pthread.h>
int pthread_rwlock_destroy(pthread_rwlock_t *rwlock);
功能：
    用于销毁一个读写锁，并释放所有相关联的资源（所谓的所有指的是由 pthread_rwlock_init() 自动申请的资源） 。
参数：
    rwlock：读写锁指针。
返回值：
    成功：0
    失败：非 0 错误码
```

**pthread_rwlock_rdlock()函数**

```c
#include <pthread.h>
int pthread_rwlock_rdlock(pthread_rwlock_t *rwlock);
功能：
    以阻塞方式在读写锁上获取读锁（读锁定）。
    如果没有写者持有该锁，并且没有写者阻塞在该锁上，则调用线程会获取读锁。
    如果调用线程未获取读锁，则它将阻塞直到它获取了该锁。一个线程可以在一个读写锁上多次执行读锁定。
    线程可以成功调用 pthread_rwlock_rdlock() 函数 n 次，但是之后该线程必须调用 pthread_rwlock_unlock() 函数 n 次才能解除锁定。
参数：
    rwlock：读写锁指针。
返回值：
    成功：0
    失败：非 0 错误码
int pthread_rwlock_tryrdlock(pthread_rwlock_t *rwlock);
  用于尝试以非阻塞的方式来在读写锁上获取读锁。
  如果有任何的写者持有该锁或有写者阻塞在该读写锁上，则立即失败返回。
```

**pthread_rwlock_wrlock()函数**

```c
#include <pthread.h>
int pthread_rwlock_wrlock(pthread_rwlock_t *rwlock);
功能：
    在读写锁上获取写锁（写锁定）。
    如果没有写者持有该锁，并且没有写者读者持有该锁，则调用线程会获取写锁。
    如果调用线程未获取写锁，则它将阻塞直到它获取了该锁。
参数：
    rwlock：读写锁指针。
返回值：
    成功：0
    失败：非 0 错误码
int pthread_rwlock_trywrlock(pthread_rwlock_t *rwlock);
   用于尝试以非阻塞的方式来在读写锁上获取写锁。
  如果有任何的读者或写者持有该锁，则立即失败返回。
```

**pthread_rwlock_unlock()函数**

```c
#include <pthread.h>
int pthread_rwlock_unlock(pthread_rwlock_t *rwlock);
功能：
    无论是读锁或写锁，都可以通过此函数解锁。
参数：
    rwlock：读写锁指针。
返回值：
    成功：0
    失败：非 0 错误码
```

参考代码:

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>
int num = 0;
pthread_rwlock_t rwlock;
void * read_lock(void * arg)
{
     int index = (int)(long)arg;
     while(1)
     {
        pthread_rwlock_rdlock(&rwlock);
        printf("线程%d 读取num值 = %d\n",index,num);
        pthread_rwlock_unlock(&rwlock);
        sleep(random() % 3 +1);
     }
}
void * write_lock(void * arg)
{
     int index = (int)(long)arg;
     while(1)
     {
        pthread_rwlock_wrlock(&rwlock);
        num++;
        printf("线程%d 修改num值 = %d\n",index,num);
        pthread_rwlock_unlock(&rwlock);
        sleep(random() % 3 +1);
     }
}
int main(void)
{
   int ret = -1;
   pthread_t tid[8];
   srandom(getpid());
   ret=pthread_rwlock_init(&rwlock,NULL);
   if(0!=ret)
   {
    printf("pthread lock init falied...\n");
    return 1;
   }
   for(int i = 1; i<9;i++)
   {
       if(i<6)
       {
          pthread_create(&tid[i],NULL,read_lock,(void *)(long)i);
       }else{
          pthread_create(&tid[i],NULL,write_lock,(void *)(long)i);
       }
   }
   for(int j = 1;j<9;j++)
   {
      pthread_join(tid[j],NULL);
   }
   pthread_rwlock_destroy(&rwlock);
   return 0;
}
```

### 8.35 条件变量

与互斥锁不同，条件变量是用来等待而不是用来上锁的，**条件变量本身不是锁**！

条件变量用来自动阻塞一个线程，直到某特殊情况发生为止。通常条件变量和互斥锁同时使用。

条件变量的两个动作：

- 条件不满, 阻塞线程
- 当条件满足, 通知阻塞的线程开始工作

条件变量的类型: pthread_cond_t。

**pthread_cond_init()函数**

```c
#include <pthread.h>
int pthread_cond_init(pthread_cond_t *restrict cond,
    const pthread_condattr_t *restrict attr);
功能：
    初始化一个条件变量
参数：
    cond：指向要初始化的条件变量指针。
    attr：条件变量属性，通常为默认值，传NULL即可
        也可以使用静态初始化的方法，初始化条件变量：
        pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
返回值：
    成功：0
    失败：非0错误号
```

**pthread_cond_destroy()函数**

```c
#include <pthread.h>
int pthread_cond_destroy(pthread_cond_t *cond);
功能：
    销毁一个条件变量
参数：
    cond：指向要初始化的条件变量指针
返回值：
    成功：0
    失败：非0错误号
```

**pthread_cond_wait()函数**

```c
#include <pthread.h>
int pthread_cond_wait(pthread_cond_t *restrict cond,
    pthread_mutex_t *restrict mutex);
功能：
    阻塞等待一个条件变量
    a) 阻塞等待条件变量cond（参1）满足
    b) 释放已掌握的互斥锁（解锁互斥量）相当于pthread_mutex_unlock(&mutex);
            a) b) 两步为一个原子操作。
    c) 当被唤醒，pthread_cond_wait函数返回时，解除阻塞并重新申请获取互斥锁pthread_mutex_lock(&mutex);
参数：
    cond：指向要初始化的条件变量指针
    mutex：互斥锁
返回值：
    成功：0
    失败：非0错误号
int pthread_cond_timedwait(pthread_cond_t *restrict cond,
    pthread_mutex_t *restrict mutex,
    const struct
                           .*restrict abstime);
功能：
    限时等待一个条件变量
参数：
    cond：指向要初始化的条件变量指针
    mutex：互斥锁
    abstime：绝对时间
返回值：
    成功：0
    失败：非0错误号
```

abstime补充说明：

```c
struct timespec {
    time_t tv_sec;      /* seconds */ // 秒
    long   tv_nsec; /* nanosecondes*/ // 纳秒
}
time_t cur = time(NULL);        //获取当前时间。
struct timespec t;              //定义timespec 结构体变量t
t.tv_sec = cur + 1;             // 定时1秒
pthread_cond_timedwait(&cond, &t);
```

**pthread_cond_signal()函数**

唤醒至阻塞在条件变量上的线程

```c
#include <pthread.h>
int pthread_cond_signal(pthread_cond_t *cond);
功能：
    唤醒至少一个阻塞在条件变量上的线程
参数：
    cond：指向要初始化的条件变量指针
返回值：
    成功：0
    失败：非0错误号
int pthread_cond_broadcast(pthread_cond_t *cond);
功能：
    唤醒全部阻塞在条件变量上的线程
参数：
    cond：指向要初始化的条件变量指针
返回值：
    成功：0
    失败：非0错误号
```

参考代码:

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
pthread_mutex_t mutex;
pthread_cond_t cond;
int flag = 0;
void * fun1(void * arg)
{   
    while(1)
    { 
      pthread_mutex_lock(&mutex);
      flag = 1;
      pthread_mutex_unlock(&mutex);
      pthread_cond_signal(&cond);
      sleep(2);
    }
   return NULL;
}
void * fun2(void * arg)
{
     while(1)
     {
       pthread_mutex_lock(&mutex);
       if(0==flag)
       {
        pthread_cond_wait(&cond,&mutex);
       }
       flag = 0;
       printf("线程2因为条件满足,开始运行......\n");
       pthread_mutex_unlock(&mutex);
     }
   return NULL;
}
int main(void)
{
   int ret = -1;
   pthread_t tid1, tid2;
   pthread_mutex_init(&mutex,NULL);
   pthread_cond_init(&cond,NULL);
   pthread_create(&tid1,NULL,fun1,NULL);
   pthread_create(&tid2,NULL,fun2,NULL);

   ret = pthread_join(tid1,NULL);
   if(0!=ret)
   {
    printf("pthread_join1 failded.....\n");
    return 1;
   }
   ret = pthread_join(tid2,NULL);
   if(0!=ret)
   {
    printf("pthread_join2 failded.....\n");
    return 1;
   }
   pthread_mutex_destroy(&mutex);
   pthread_cond_destroy(&cond);
   return 0;
}
```

### 8.34 生产者消费者条件变量模型

参考代码:

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
typedef struct _node_t
{
    int data;
    struct _node_t * next;
}node_t;
node_t *head=NULL;
pthread_mutex_t mutex;
pthread_cond_t cond;
void *producer(void *arg)
{
  while(1)
  {
    pthread_mutex_lock(&mutex);
    node_t *node = (node_t *)malloc(sizeof(node_t));
    if(NULL==node)
    {
      printf("node malloc failed...\n");
      break;
    }
    memset(node,0,sizeof(node_t));
    node->data = random()%100 + 1;
    node->next = NULL;

    node->next = head;
    head = node;
    printf("生产产品编号为:%d\n",node->data);
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&cond);
    sleep(random()%3 + 1);
  }
  pthread_exit(NULL);
}
void *customer(void *arg)
{
  while(1)
 {
   pthread_mutex_lock(&mutex);
   node_t *temp = NULL;
   if(NULL==head)
   {
     pthread_cond_wait(&cond,&mutex);
   }else
   {
     temp = head;
     head = head->next;
     printf("消费的编号为:%d\n",temp->data);
     free(temp);
   }
   pthread_mutex_unlock(&mutex);
 }
  pthread_exit(NULL);
}
int main(void)
{
  srandom(getpid());
  int ret = -1;
  pthread_t tid1,tid2;
  ret =  pthread_mutex_init(&mutex,NULL);
  if(0!=ret)
  {
   printf("mutex init failed....\n");
   return 1;
  }
  ret = pthread_cond_init(&cond,NULL);
  if(0!=ret)
  {
   printf("cond init failed.....\n");
   return 1;
  }
  pthread_create(&tid1,NULL,producer,NULL);
  pthread_create(&tid2,NULL,customer,NULL);
  pthread_join(tid1,NULL);
  pthread_join(tid2,NULL);
  return 0;
}

```

### 8.35 信号量

信号量广泛用于进程或线程间的同步和互斥，信号量本质上是一个非负的整数计数器，它被用来控制对公共资源的访问。

编程时可根据操作信号量值的结果判断是否对公共资源具有访问的权限，当信号量值大于 0 时，则可以访问，否则将阻塞。

PV 原语是对信号量的操作，一次 P 操作使信号量减１，一次 V 操作使信号量加１。

信号量主要用于进程或线程间的同步和互斥这两种典型情况。

信号量数据类型为：sem_t

**sem_init()函数**:

```c
#include <semaphore.h>
int sem_init(sem_t *sem, int pshared, unsigned int value);
功能：
    创建一个信号量并初始化它的值。一个无名信号量在被使用前必须先初始化。
参数：
    sem：信号量的地址。
    pshared：等于 0，信号量在线程间共享（常用）；不等于0，信号量在进程间共享。
    value：信号量的初始值。
返回值：
    成功：0
    失败： - 1
```

**sem_destroy()函数**:

```c
#include <semaphore.h>
int sem_destroy(sem_t *sem);
功能：
    删除 sem 标识的信号量。
参数：
    sem：信号量地址。
返回值：
    成功：0
    失败： - 1
```

**sem_wait()函数 ------信号量P操作(减一)**:

```c
#include <semaphore.h>
int sem_wait(sem_t *sem);
功能：
    将信号量的值减 1。操作前，先检查信号量（sem）的值是否为 0，若信号量为 0，此函数会阻塞，直到信号量大于 0 时才进行减 1 操作。
参数：
    sem：信号量的地址。
返回值：
    成功：0
    失败： - 1
int sem_trywait(sem_t *sem);
   以非阻塞的方式来对信号量进行减 1 操作。
   若操作前，信号量的值等于 0，则对信号量的操作失败，函数立即返回。
int sem_timedwait(sem_t *sem, const struct timespec *abs_timeout);
   限时尝试将信号量的值减 1
   abs_timeout：绝对时间
```

**sem_post()函数 -------信号量V操作(加一)**

```c
#include <semaphore.h>
int sem_post(sem_t *sem);
功能：
    将信号量的值加 1 并发出信号唤醒等待线程（sem_wait()）。
参数：
    sem：信号量的地址。
返回值：
    成功：0
    失败：-1
```

# 二、linux网络编程

# 1、网络基础

**① 网卡**

​    网络适配器 :作用 收发数据mac地址 

​    作用: 用来标识一块网卡  6个字节 物理地址

**② ip**

ip用来标识一台主机 逻辑地址

iPv4  :  ip地址是4字节 32位

ipv6:   128位  16字节

子网id  ip中被子网掩码中1连续覆盖的位

主机id  ip中被子网掩码中0连续覆盖的位

192.168.1.2/24  192.168.1.2/255.255.255.0

网段地址: 192.168.1.0 广播地址: 192.168.1.255
子网掩码 netmask: 用来区分子网id 和主机id

**③ 端口**

作用: 用来标识应用程序(进程)

port: 2个字节 0-65535

0-1023 知名端口

自定义端口 1024 - 65535

netstat

**④ OSI七层模型**

物理层: 双绞线接口类型, 光纤的传输速率等等

数据链路层: mac 负责收发数据

网络层: ip 给两台主机提供路径选择

传输层: port 区分数据递送到哪一个应用程序

会话层: 建立建立

表示层: 解码

 应用层

TCP/IP四层模型

![](C:\Users\Administrator\Desktop\1657783507056.jpg)

**⑤ 协议**

规定了数据传输的方式和格式

应用层协议: 

FTP: 文件传输协议

HTTP: 超文本传输协议

NFS: 网络文件系统

传输层协议:

TCP:  传输控制协议

UDP: 用户数据报协议

网络层:

IP:英特网互联协议

ICMP: 英特网控制报文协议 ping

IGMP: 英特网组管理协议

链路层协议:

ARP: 地址解析协议 通过ip找mac地址

RARP: 反向地址解析协议 通过mac找ip

**⑥ 网络设计模式**

B/S browser/ server

C/S cilent/server 
c/s 性能较好 客户端容易篡改数据  开发周期较长

b/s 性能低  客户端安全 开发周期短

# 2、Tcp和socket

## 2.1 TCP

传输控制协议

特点:  出错重传 每次发送数据对方都会回ACK, 可靠

 tcp是抽象打电话的模型

建立连接 使用连接  关闭连接

## 2.2 网络字节序

 网络字节序默认为大端

小端: 低位存低地址,高位存高地址

 大端: 低位存高地址,高位存低地址

**uint32_t htonl(uint32_t hostlong)函数**

```c
#include <arpa/inet.h>
uint32_t htonl(uint32_t hostlong);
功能：    
    将主机字节序转为网络字节序 ---->IP地址。
参数：    
    hostlong：4个字节的主机字节序。
返回值：    
    返回大端数据
```

**uint16_t htons(uint16_t hostshort)函数**

```c
#include <arpa/inet.h>
uint16_t htons(uint16_t hostshort);
功能：    
    将主机字节序转为网络字节序 ---->端口。
参数：    
    hostshort：2个字节的主机字节序。
返回值：    
    返回大端数据
```

**uint32_t ntohl(uint32_t netlong)函数**

```c
#include <arpa/inet.h>
uint32_t ntohl(uint32_t netlong);
功能：    
    将网络字节序转为主机字节序 ---->IP地址。
参数：    
    hostlong：4个字节的网络字节序。
返回值：    
    返回对应的主机字节序数据
```

**uint16_t ntohs(uint16_t netshort)函数**

```c
#include <arpa/inet.h>
uint16_t ntohs(uint16_t netshort);
功能：    
    将网络字节序转为主机字节序 ---->端口。
参数：    
    netshort：2个字节的网络字节序。
返回值：    
    返回对应的主机字节序数据
```

**点分十进制串转换:**

 **int inet_pton(int af, const char *src, void *dst)函数**

```c
#include <arpa/inet.h>
int inet_pton(int af, const char *src, void *dst);
功能: 将点分十进制串 转成32位网络大端的数据("192.168.1.2"  ==> )
参数:
    af : 
        AF_INET         IPV4
        AF_INET6        IPV6
    src: 点分十进制串的首地址 
    dst : 32位网络数据的地址 
成功返回1
```

**const char *inet_ntop(int af, const void *src,char *dst, socklen_t size)函数**

```c
#include <arpa/inet.h>
const char *inet_ntop(int af, const void *src, char *dst, socklen_t size);
功能: 将32位大端的网络数据转成点分十进制串
参数:
    af : AF_INET
    src : 32位大端的网络数 地址
    dst : 存储点分十进制串 地址
    size : 存储点分制串数组的大小  
返回值: 存储点分制串数组首地址
```

参考代码:

```c
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
int main(void)
{
  char buf[]="192.168.1.2";
  unsigned int num = 0 ;
  //将点分十进制串 转成32位网络大端的数据
  inet_pton(AF_INET,buf,&num);
  unsigned char *p = (unsigned char *)&num;
  printf("%d %d %d %d\n",*p,*(p+1),*(p+2),*(p+3));
  char buff[16]="";
  //将32位大端的网络数据转成点分十进制串
  printf("%s\n",inet_ntop(AF_INET,&num,buff,16));
  return 0;
}
```

# 3、套接字

## 3.1 ipv4套接字结构体

```c
struct sockaddr_in {
      sa_family_t    sin_family; /* address family: AF_INET */
      in_port_t      sin_port;   /* port in network byte order */
      struct in_addr sin_addr;   /* internet address */
};
 /* Internet address. */
 struct in_addr {
        uint32_t     s_addr;     /* address in network byte order */
 };
sin_family: 协议  AF_INET
sin_portL端口
sin_addr  ip地址
```

## 3.2 ipv6套接结构体

```c
struct sockaddr_in6 {
    unsigned short int sin6_family;        /* AF_INET6 */
    __be16 sin6_port;                  /* Transport layer port # */
    __be32 sin6_flowinfo;              /* IPv6 flow information */
    struct in6_addr sin6_addr;         /* IPv6 address */
    __u32 sin6_scope_id;               /* scope id (new in RFC2553) */
};

struct in6_addr {
    union {
        __u8 u6_addr8[16];
        __be16 u6_addr16[8];
        __be32 u6_addr32[4];
    } in6_u;
    #define s6_addr        in6_u.u6_addr8
    #define s6_addr16      in6_u.u6_addr16
    #define s6_addr32     in6_u.u6_addr32
};
#define UNIX_PATH_MAX 108
    struct sockaddr_un {
    __kernel_sa_family_t sun_family;   /* AF_UNIX */
    char sun_path[UNIX_PATH_MAX]; /* pathname */
};
```

## 3.3 通用套接字结构体

```c
struct sockaddr {
    sa_family_t sa_family;     /* address family, AF_xxx */
    char sa_data[14];          /* 14 bytes of protocol address */
};
```

## 3.4 创建套接字API

```c
#include <sys/socket.h>
int socket(int domain, int type, int protocol);
创建套接字
参数:
domain:AF_INET
type: SOCK_STREAM 流式套接字 用于tcp通信
protocol: 0
成功返回文件描述符,失败返回-1
```

## 3.5 Tcp客户端连接服务器

```c
#include <sys/socket.h>
 int connect(intsockfd , const struct sockaddr *addr,
                   socklen_t addrlen);
功能: 连接服务器
sockfd:  socket套接字
addr:  ipv4套接字结构体的地址
addrlen: ipv4套接字结构体的长度
```

**TCP客户端参考代码**

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
int main(void)
{
  //创建套接字
  int Sock_fd;
  Sock_fd = socket(AF_INET,SOCK_STREAM,0);
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(8080);
  inet_pton(AF_INET,"192.168.3.114",&addr.sin_addr.s_addr);
  //连接服务器
  connect(Sock_fd,(struct sockaddr *)&addr,sizeof(addr));
  //读写数据
  char buf[1024] = "";
  while(1)
  {
    int n = read(STDIN_FILENO,buf,sizeof(buf)); 
    //发送数据给服务器
    write(Sock_fd,buf,n);
    n = read(Sock_fd,buf,sizeof(buf));
    write(STDOUT_FILENO,buf,n);
    printf("\n");
  } 
   close(Sock_fd);
   return 0;
}
```

## 3.6 Tcp服务器

Tcp服务器通信步骤

- 创建套接字 socket
- 绑定 bind
- 监听 listen
- 提取 accept
- 读写
- 关闭 

### 3.61 bind绑定函数

 **int bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen)；**

```c
给套接字绑定固定的端口和ip
#include <sys/socket.h>
  int bind(int sockfd, const struct sockaddr *addr,
                socklen_t addrlen);
sockfd: 套接字
addr: ipv4套接字结构体地址
addrlen: ipv4套接字结构体的大小
返回值:
成功返回0 失败返回-1;
```

### 3.62 listen监听

**int listen(int sockfd, int backlog);**

```c
#include <sys/socket.h>
int listen(int sockfd, int backlog);
参数:
    sockfd : 套接字
    backlog :  已完成连接队列和未完成连接队里数之和的最大值  128
返回值:
成功返回0 失败返回-1;
```

### 3.63 accept提取连接

**int accept(int socket, struct sockaddr *restrict address, socklen_t *restrict address_len);**

```c
#include <sys/socket.h>
 int accept(int socket, struct sockaddr *restrict address,
           socklen_t *restrict address_len);
如果连接队列没有新的连接,accept会阻塞
功能: 从已完成连接队列提取新的连接
参数:
    socket : 套接字
    address : 获取的客户端的的ip和端口信息  iPv4套接字结构体地址
    address_len: iPv4套接字结构体的大小的地址
socklen_t len = sizeof(struct sockaddr );
返回值:  新的已连接套接字的文件描述符
```

Tcp服务器参考代码

```c
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
int main(void)
{
   //创建套接字
   int sock_fd = socket(AF_INET,SOCK_STREAM,0);
   //绑定
   struct sockaddr_in addr;
   addr.sin_family = AF_INET;
   addr.sin_port = htons(8000);
   addr.sin_addr.s_addr = INADDR_ANY;
   int ret = bind(sock_fd,(struct sockaddr *)&addr,sizeof(addr));
   if(ret<0)
   {
     perror("");
     return 1;
   }
   //监听 
   listen(sock_fd,128);
   //提取 
   struct sockaddr_in address;
   socklen_t len = sizeof(address);
   int newSock_fd = accept(sock_fd,(struct sockaddr *)&address,&len);
   char ip[16] = "";
   printf("新客户端连接成功,IP地址为:%s,端口号为:%d\n",inet_ntop(AF_INET,
           &address.sin_addr.s_addr,ip,16),ntohs(addr.sin_port));
   //读写数据
   char buf[1024] = "";
   while(1)
   {
     bzero(buf,sizeof(buf));
     int n = read(STDIN_FILENO,buf,sizeof(buf));
     write(newSock_fd,buf,n);
     n = read(newSock_fd,buf,sizeof(buf));
     printf("%s\n",buf);

   }
   //关闭
   close(sock_fd);
   close(newSock_fd);
   return 0;
}
```

## 3.7 Tcp三次握手

 **mss最大报文长度: 一般出现在三次握手的前两次,用来告知对方发送数据的最大长度MTU: 最大传输单元 网卡**
 **滑动窗口每一次读取数据之后,回ack报文,报文中会携带当前缓冲区大小,用来告知对方**

**seq 序号   ack 确认序列号**

**确认序列号的含义:**

1、确认收到对方的报文

2、期望下一次对方的序列号为我的确认序列号

**确认序列号等于**

对方发送过来的序列号+标志位长度SYN(1)+数据长度

**三次握手**

1. 客户端发送一个带SYN标志的TCP报文到服务器。这是三次握手过程中的段1。

客户端发出段1，SYN位表示连接请求。序号是1000，这个序号在网络通讯中用作临时的地址，每发一个数据字节，这个序号要加1，这样在接收端可以根据序号排出数据包的正确顺序，也可以发现丢包的情况，另外，规定SYN位和FIN位也要占一个序号，这次虽然没发数据，但是由于发了SYN位，因此下次再发送应该用序号1001。mss表示最大段尺寸，如果一个段太大，封装成帧后超过了链路层的最大帧长度，就必须在IP层分片，为了避免这种情况，客户端声明自己的最大段尺寸，建议服务器端发来的段不要超过这个长度。

2. 服务器端回应客户端，是三次握手中的第2个报文段，同时带ACK标志和SYN标志。它表示对刚才客户端SYN的回应；同时又发送SYN给客户端，询问客户端是否准备好进行数据通讯。

服务器发出段2，也带有SYN位，同时置ACK位表示确认，确认序号是1001，表示“我接收到序号1000及其以前所有的段，请你下次发送序号为1001的段”，也就是应答了客户端的连接请求，同时也给客户端发出一个连接请求，同时声明最大尺寸为1024。

3. 客户必须再次回应服务器端一个ACK报文，这是报文段3。

客户端发出段3，对服务器的连接请求进行应答，确认序号是8001。在这个过程中，客户端和服务器分别给对方发了连接请求，也应答了对方的连接请求，其中服务器的请求和应答在一个段中发出，因此一共有三个段用于建立连接，称为“三方握手（three-way-handshake）”。在建立连接的同时，双方协商了一些信息，例如双方发送序号的初始值、最大段尺寸等。

**数据传输过程**

1. 客户端发出段4，包含从序号1001开始的20个字节数据。

2. 服务器发出段5，确认序号为1021，对序号为1001-1020的数据表示确认收到，同时请求发送序号1021开始的数据，服务器在应答的同时也向客户端发送从序号8001开始的10个字节数据，这称为piggyback。

3. 客户端发出段6，对服务器发来的序号为8001-8010的数据表示确认收到，请求发送序号8011开始的数据。

在数据传输过程中，ACK和确认序号是非常重要的，应用程序交给TCP协议发送的数据会暂存在TCP层的发送缓冲区中，发出数据包给对方之后，只有收到对方应答的ACK段才知道该数据包确实发到了对方，可以从发送缓冲区中释放掉了，如果因为网络故障丢失了数据包或者丢失了对方发回的ACK段，经过等待超时后TCP协议自动将发送缓冲区中的数据包重发。

## 3.8 Tcp四次挥手

由于TCP连接是全双工的，因此每个方向都必须单独进行关闭。这原则是当一方完成它的数据发送任务后就能发送一个FIN来终止这个方向的连接。收到一个 FIN只意味着这一方向上没有数据流动，一个TCP连接在收到一个FIN后仍能发送数据。首先进行关闭的一方将执行主动关闭，而另一方执行被动关闭。

1. 客户端发出段7，FIN位表示关闭连接的请求。

2. 服务器发出段8，应答客户端的关闭连接请求。

3. 服务器发出段9，其中也包含FIN位，向客户端发送关闭连接请求。

4. 客户端发出段10，应答服务器的关闭连接请求。

## 3.9 多进程实现并发服务器

- 创建套接字
- 绑定
- 监听
- while(1){
- 提取连接
- fork创建子进程
- 子进程中,关闭旧套接字,服务客户端
- 父进程关闭新套接字,回收子进程的资源
- }

参考代码

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include"wrap.h"
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>
void free_process(int signum)
{
    pid_t pid;
    while((pid = waitpid(-1,NULL,WNOHANG))>0)
    {
       printf("chile %d terminated.\n",pid);
    }
}
int main(void)
{
   sigset_t set;
   sigemptyset(&set);
   sigaddset(&set,SIGCHLD);
   sigprocmask(SIG_BLOCK,&set,NULL);

  //创建套接字 绑定
  int Sock_fd = 0;
  Sock_fd = tcp4bind(8008,NULL);
  //监听
  Listen(Sock_fd,128);
  //提取
  //回射
  struct sockaddr_in ClientAddr;
  socklen_t len = sizeof(ClientAddr);
  while(1)
  {
    char IP[16]="";
    int newSock_fd = Accept(Sock_fd,(struct sockaddr *)&ClientAddr,&len);
    printf("new client connect success, IP =%s , port = %d\n",inet_ntop(AF_INET,&ClientAddr.sin_addr.s_addr,
           IP,16),ntohs(ClientAddr.sin_port));
    pid_t pid;
    pid = fork();
    if(pid<0)
    {
      perror("");
      exit(0);
    }else if(0 == pid){
      close(Sock_fd);
      while(1)
     {
      char buf[1024]="";
      int n = read(newSock_fd,buf,sizeof(buf));
      if(n<0)
      {
        perror("");
        close(newSock_fd);
        exit(0);
      }else if(0==n){
        printf("client close\n");
        close(newSock_fd);
        exit(0);
      }else{
        printf("%s\n",buf);
        write(newSock_fd,buf,n);
       // exit(0);
      }
     }
      }else{
        close(newSock_fd);
        //回收
        struct sigaction act;
        act.sa_handler = free_process;
        sigemptyset(&act.sa_mask);
        act.sa_flags = 0;
        sigaction(SIGCHLD,&act,NULL);
        sigprocmask(SIG_UNBLOCK,&set,NULL);
      }
  }
  //关闭
       return 0;
}
```

# 4、线程版服务器

参考代码

```c
#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
#include "wrap.h"
//子线程回调函数结构体参数
typedef struct cliInfo
{
     int newSock_fd;
     struct sockaddr_in address;

}Clientinfo;
//主线程
int main(int arg,char*argv[])
{
     if(arg < 2)
     {
          printf("argc < 2 ??? \n ./a.out 8008\n");
          return 0;
     }   
     //线程属性初始化
     pthread_attr_t attr;
     pthread_attr_init(&attr);
     //设置线程分离状态
     pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
     short port = atoi(argv[1]);
     //创建套接字+绑定
     int Sock_fd = tcp4bind(port, NULL);
     //监听套接字   使套接字处于等待连接队列 
     Listen(Sock_fd,128);
     struct sockaddr_in address;
     socklen_t address_len = sizeof(address);
     Clientinfo *cinfo;
     while(1)
     {
        //提取客户端连接  返回创建新的套接字文件描述符
        int newSock_fd = Accept(Sock_fd,(struct sockaddr *)&address,&address_len);
        pthread_t tid; 
        //将属性创建在堆区 防止子线程覆盖数据
        cinfo = malloc(sizeof(Clientinfo));
        cinfo->newSock_fd = newSock_fd;
        cinfo->address = address;
        pthread_create(&tid,&attr,client_fun,cinfo);
     }
      return 0;
}    
//创建线程回调函数
void *client_fun(void * arg)
{
   Clientinfo * CINFO = (Clientinfo *)arg;
   char ip[16]="";
   printf("客户端连接成功 IP = %s, port = %d \n",inet_ntop(AF_INET,&(CINFO->address.sin_addr.s_addr),ip,16),
         ntohs(CINFO->address.sin_port) );
   while(1)
   {
     char buf[1024]= "";
     int count = 0;
     count = read(CINFO->newSock_fd,buf,sizeof(buf));
     if(count<0)
     {
       perror("read");
       break;
     }
     else if(count==0)
     {
       printf("client close\n");
       break;
     }
     else
     {
       printf("%s\n",buf);
       write(CINFO->newSock_fd,buf,count);
     }
}
    //关闭套接字
    close(CINFO->newSock_fd);
    //释放堆区数据
    free(CINFO);
}
```

## 4.1 TCP状态转换图

![image-20220722155424374](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220722155424374.png)

## 4.2 半关闭

当TCP链接中A发送FIN请求关闭，B端回应ACK后（A端进入FIN_WAIT_2状态），B没有立即发送FIN给A时，A方处在半链接状态，此时A可以接收B发送的数据，但是A已不能再向B发送数据。

从程序的角度，可以使用API来控制实现半连接状态。

```c
#include <sys/socket.h>
int shutdown(int sockfd, int how);
sockfd: 需要关闭的socket的描述符
how:	允许为shutdown操作选择以下几种方式:
	SHUT_RD(0)：	关闭sockfd上的读功能，此选项将不允许sockfd进行读操作。
					该套接字不再接收数据，任何当前在套接字接受缓冲区的数据将被无声的丢弃掉。
	SHUT_WR(1):		关闭sockfd的写功能，此选项将不允许sockfd进行写操作。进程不能在对此套接字发出写操作。
	SHUT_RDWR(2):	关闭sockfd的读写功能。相当于调用shutdown两次：首先是以SHUT_RD,然后以SHUT_WR。
```

使用close中止一个连接，但它只是减少描述符的引用计数，并不直接关闭连接，只有当描述符的引用计数为0时才关闭连接。

**shutdown****不考虑描述符的引用计数，直接关闭描述符**。也可选择中止一个方向的连接，只中止读或只中止写。

注意:

1. 如果有多个进程共享一个套接字，close每被调用一次，计数减1，直到计数为0时，也就是所用进程都调用了close，套接字将被释放。 

2. 在多进程中如果一个进程调用了shutdown(sfd, SHUT_RDWR)后，其它的进程将无法进行通信。但，如果一个进程close(sfd)将不会影响到其它进程。

**2MSL**

2MSL (Maximum Segment Lifetime) TIME_WAIT状态的存在有两个理由：

（1）**让4次握手关闭流程更加可靠**；4次握手的最后一个ACK是是由主动关闭方发送出去的，若这个ACK丢失，被动关闭方会再次发一个FIN过来。若主动关闭方能够保持一个2MSL的TIME_WAIT状态，则有更大的机会让丢失的ACK被再次发送出去。

## 4.3 心跳包

3 心跳包如果对方异常断开,本机检测不到,一直等待,浪费资源需要设置tcp的保持连接,作用就是每隔一定的时间间隔发送探测分节,如果连续发送多个探测分节对方还未回,就将次连接断开

int keepAlive = 1;

setsockopt(listenfd, SOL_SOCKET, SO_KEEPALIVE, (void*)&keepAlive, sizeof(keepAlive));
心跳包: 最小粒度

乒乓包: 携带比较多的数据的心跳包

## 4.4 设置端口复用

```c
int opt = 1;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
```

注意: 程序中设置某个端口重新使用,在这之前的其他网络程序将不能使用这个端口

## 4.5 多路IO转接

多路IO转接(多路IO复用): 内核监听多个文件描述符的属性(读写缓冲区)变化如果某个文件描述符的读缓冲区变化了,这个时候就是可以读了,将这个事件告知应用层

select epoll poll

windwos  使用select  select跨平台

poll 少用

epoll  linux 

**select函数API**

```c
#include <sys/select.h>
 /* According to earlier standards */
       #include <sys/time.h>
       #include <sys/types.h>
       #include <unistd.h>
       int select(int nfds, fd_set *readfds, fd_set *writefds,
                  fd_set *exceptfds, struct timeval *timeout);
功能: 监听多个文件描述符的属性变化(读,写,异常)
       void FD_CLR(int fd, fd_set *set);
       int  FD_ISSET(int fd, fd_set *set);
       void FD_SET(int fd, fd_set *set);
       void FD_ZERO(fd_set *set);
参数:
    nfds  : 最大文件描述符+1
    readfds : 需要监听的读的文件描述符存放集合
    writefds :需要监听的写的文件描述符存放集合   NULL
    exceptfds : 需要监听的异常的文件描述符存放集合  NULL
    timeout: 多长时间监听一次   固定的时间,限时等待   NULL 永久监听
    struct timeval {
               long    tv_sec;         /* seconds */ 秒
               long    tv_usec;        /* microseconds */微妙
           };
返回值: 返回的是变化的文件描述符的个数
注意: 变化的文件描述符会存在监听的集合中,未变化的文件描述符会从集合中删除
select 的优缺点
优点: 跨平台
缺点:
文件描述符1024的限制   由于 FD_SETSIZE的限制
只是返回变化的文件描述符的个数,具体哪个那个变化需要遍历
每次都需要将需要监听的文件描述集合由应用层符拷贝到内核
大量并发,少了活跃,select效率低

假设现在 4-1023个文件描述符需要监听,但是5-1000这些文件描述符关闭了?
假设现在 4-1023个文件描述符需要监听,但是只有 5,1002 发来消息- 无解
```

参考代码:

```c
#include "cpp_wrap.h"
#include <sys/select.h>
#include <string.h>
using namespace wsq;

int main()
{
	cppWrap wraps;

	std::cout << "等待客户端连接...." << std::endl;

	int lfd = wraps.tcpBind_(NULL, 8888);

	wraps.Listen_(lfd);

	int maxfd = lfd;

	fd_set newset, oldset;
	FD_ZERO(&newset);
	FD_ZERO(&oldset);

	FD_SET(lfd, &oldset);

	while (1)
	{
		newset = oldset;
		int n = select(maxfd + 1, &newset, NULL, NULL, NULL);
		if (n < 0)
		{
			perror("select");
			break;
		}
		else if (n == 0)
		{
			continue;
		}
		else
		{
			if (FD_ISSET(lfd, &newset))
			{
				int cfd = wraps.Accept_();

				FD_SET(cfd, &oldset);
				if (cfd > maxfd)
				{
					maxfd = cfd;
				}
				if (--n == 0)
				{
					continue;
				}
			}
			else
			{
				for (int i = lfd + 1; i <= maxfd; i++)
				{
					if (FD_ISSET(i, &newset))
					{
						char buf[1500];
						memset(buf, 0, sizeof(buf));
						ssize_t n = wraps.Read_(i, buf, sizeof(buf));
						if (n < 0)
						{
							perror("read");
							if (i == maxfd)
							{
								wraps.closeFd(i);
								FD_CLR(i, &oldset);
								//maxfd--;
							}
							else
							{
								wraps.closeFd(i);
								dup2(maxfd, i);
								wraps.closeFd(maxfd);
								FD_CLR(maxfd, &oldset);
								maxfd--;
							}
							
						}
						else if (n == 0)
						{
							std::cout << "client close.." << std::endl;
							if (i == maxfd)
							{
								wraps.closeFd(i);
								FD_CLR(i, &oldset);
								
							}
							else
							{
								wraps.closeFd(i);
								dup2(maxfd, i);
								wraps.closeFd(maxfd);
								FD_CLR(maxfd, &oldset);
								maxfd--;
							}
						}
						else
						{
							std::cout << "[read]:" << buf << std::endl;
							wraps.Write_(i, buf, strlen(buf));
						}
					}
				}
			}
		}

	}
	return 0;
}

```

## 4.6 poll API

```c
#include <poll.h>
 int poll(struct pollfd *fds, nfds_t nfds, int timeout);
功能: 监听多个文件描述符的属性变化
参数:
    fds : 监听的数组的首元素地址
    nfds: 数组有效元素的最大下标+1
    timeout : 超时时间 -1是永久监听 >=0 限时等待

数组元素:
struct pollfd
            struct pollfd {
               int   fd;         /* file descriptor */ 需要监听的文件描述符
               short events;     /* requested events */需要监听文件描述符什么事件  EPOLLIN 读事件   EPOLLOUT写事件
               short revents;    /* returned events */ 返回监听到的事件    EPOLLIN 读事件   EPOLLOUT写事
           };

3 poll相对与sellect的优缺点
优点:
没有文件描述符1024的限制
请求和返回是分离的

缺点和select一样:
每次都需要将需要监听的文件描述符从应用层拷贝到内核
每次都需要将数组中的元素遍历一遍才知道那个变化了
大量并发,少量活跃效率低
```

## 4.7 epoll API

```c
 epollAPI
 a> 创建红黑树
    #include <sys/epoll.h>
      int epoll_create(int size);
    参数:
    size :  监听的文件描述符的上限,  2.6版本之后写1即可,
    返回:  返回树的句柄
b>  上树  下树 修改节点
    epoll_ctl
#include <sys/epoll.h>
int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);
参数:
    epfd : 树的句柄
    op : EPOLL_CTL_ADD 上树   EPOLL_CTL_DEL 下树 EPOLL_CTL_MOD 修改
    fd : 上树,下树的文件描述符
    event :   上树的节点
    typedef union epoll_data {
               void        *ptr;
               int          fd;
               uint32_t     u32;
               uint64_t     u64;
           } epoll_data_t;

           struct epoll_event {
               uint32_t     events;      /* Epoll events */  需要监听的事件
               epoll_data_t data;        /* User data variable */ 需要监听的文件描述符
           };

将cfd上树
int epfd =  epoll_create(1);
struct epoll_event ev;
ev. data.fd = cfd;
ev.events = EPOLLIN;
epoll_ctl(epfd, EPOLL_CTL_ADD,cfd, &ev);

c> 监听
    #include <sys/epoll.h>

       int epoll_wait(int epfd, struct epoll_event *events,
                      int maxevents, int timeout);
    功能: 监听树上文件描述符的变化
    epfd : 树的句柄
    events : 接收变化的节点的数组的首地址
    maxevents :  数组元素的个数
    timeout : -1 永久监听  大于等于0 限时等待
返回值: 返回的是变化的文件描述符个数

```

参考代码

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/epoll.h>
#include "wrap.h"
#include<fcntl.h>
int main(void)
{

      //创建套接字 绑定
   int lfd = tcp4bind(8000,NULL);
      //监听
   Listen(lfd,128);
      //创建树
   int epfd = epoll_create(1);
      //上树
   struct epoll_event ev,evs[1024];
   ev.data.fd = lfd;
   ev.events = EPOLLIN;
   epoll_ctl(epfd,EPOLL_CTL_ADD,lfd,&ev);
      //监听
   while(1)
   {
     int n = epoll_wait(epfd,evs,1024,-1);
     printf("epoll_wait...\n");
     if(n<0)
     {
        perror("epoll_wait");
        break;
     }else if(0==n)
     {
        continue;
     }else
     {
       for(int i = 0 ; i < n ; i++)
       {
          if(evs[i].data.fd == lfd && evs[i].events & EPOLLIN)
          {
             struct sockaddr_in addr;
             char ip[16]="";
             socklen_t len = sizeof(addr);
             int cfd = Accept(lfd,(struct sockaddr*)&addr,&len);
             printf("new client connect ip = %s , port = %d \n",inet_ntop(AF_INET,&addr.sin_addr.s_addr,ip,16),
                    ntohs(addr.sin_port));
             //设置cfd为非阻塞
             int flags = fcntl(cfd,F_GETFL);
             flags |= O_NONBLOCK;
             fcntl(cfd,F_SETFL,flags);
             ev.data.fd = cfd;
             ev.events = EPOLLIN | EPOLLET;
             epoll_ctl(epfd,EPOLL_CTL_ADD,cfd,&ev);
          }else if(evs[i].events & EPOLLIN)
          {
            while(1)
            {
             char buf[1024]="";
             int ret = read(evs[i].data.fd,buf,sizeof(buf));
             if(ret<0)
             {
               if(errno == EAGAIN)
               {
                   break;
               }
               perror("read");
               epoll_ctl(epfd,EPOLL_CTL_DEL,evs[i].data.fd,&evs[i]);
               break;
             }else if(0==ret)
             {
               printf("client close \n");
               close(evs[i].data.fd);
               epoll_ctl(epfd,EPOLL_CTL_DEL,evs[i].data.fd,&evs[i]);
               break;
             }else
             {
               printf("%s\n",buf);
               write(evs[i].data.fd,buf,sizeof(buf));
             }
           }
         }
        }
      }
    }
      return 0;
}
```

## 4.8 epoll反应堆

文件描述符  事件  回调函数 封装在一起结构体来封装

## 4.9 线程池

线程池,事先创建几个线程,,不停取任务,如果没有任务休眠,省去了不停的创建线程销毁销毁线程的事件和资源
注意: 线程池 处理的任务,所需要处理的时间必须很短
一个锁两个条件变量循环队列

# 5、UDP通信

## 5.1 udp通信流程

```c
udp通信流程
服务器: 创建报式套接字 绑定 读写 关闭
客户端:   创建报式套接字 读写  关闭
发数据:
ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
                      const struct sockaddr *dest_addr, socklen_t addrlen);

dest_addr: 目的地的地址信息
addrlen: 结构体大小
收数据:
  ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
                        struct sockaddr *src_addr, socklen_t *addrlen);

src_addr: 对方的地址信息
addrlen: 结构体大小的地址
```

## 5.2 创建报式套接字

```c
创建报式套接字
socket
int socket(int domain, int type, int protocol);
参数:
    domain : AF_INET
    type :SOCK_DGRAM
    protocol :0
```

**udp服务器和客户端参考代码**

```c
//服务器
#include<stdio.h>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
     //创建套接字
     int fd = socket(AF_INET,SOCK_DGRAM,0);
     //绑定
     struct sockaddr_in udpserver;
     udpserver.sin_family = AF_INET;
     udpserver.sin_port = htons(8888);
     udpserver. sin_addr.s_addr = inet_addr("127.0.0.1");
     bind(fd,(struct sockaddr*)&udpserver,sizeof(udpserver));
     //读写 
     char buf[1500]="";
     struct sockaddr_in udpclient;
     socklen_t len = sizeof(udpclient);
     while(1)
     {
        memset(buf,0,sizeof(buf));
        int n = recvfrom(fd,buf,sizeof(buf),0,(struct sockaddr *)&udpclient,&len);
        if(n<0)
        {
          perror("recvform");
          break;
        }
        else
        {
          printf("%s\n",buf);
          sendto(fd,buf,n,0,(struct sockaddr*)&udpclient,len);
        }
     }
     //关闭
     close(fd);

     return 0;
}
------------------------------------------------------------------------------------------------------------
 //客户端
 #include<stdio.h>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
     //创建套接字
     int fd = socket(AF_INET,SOCK_DGRAM,0);
     //绑定
     struct sockaddr_in udpclient;
     udpclient.sin_family = AF_INET;
     udpclient.sin_port = htons(9000);
     udpclient. sin_addr.s_addr = inet_addr("127.0.0.1");
     bind(fd,(struct sockaddr*)&udpclient,sizeof(udpclient));
     //读写 
     char buf[1500]="";
     struct sockaddr_in udpserver;
     socklen_t len = sizeof(udpserver);

     struct sockaddr_in dstaddr;
     dstaddr.sin_family = AF_INET;
     dstaddr.sin_port = htons(8888);
     dstaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
     int n = 0;
     while(1)
     {
        n = read(STDIN_FILENO,buf,sizeof(buf));
        sendto(fd,buf,n,0,(struct sockaddr*)&dstaddr,sizeof(dstaddr));
        memset(buf,0,sizeof(buf));
        int n = recvfrom(fd,buf,sizeof(buf),0,NULL,NULL);
        if(n<0)
        {
          perror("recvform");

        }
        else
        {
          printf("%s\n",buf);
        }
     }
     //关闭
     close(fd);
     return 0;
}
    
```

## 5.3 本地套接字

```c
创建本地套接字
绑定
监听
提取
读写
关闭

创建本地套接字用于tcp通信
int socket(int domain, int type, int protocol);
参数:
    domain : AF_UNIX
    type :SOCK_STREAM
    protocol : 0

绑定
int bind(int sockfd, const struct sockaddr *addr,
                socklen_t addrlen);

sockfd: 本地套接字
addr:  本地套接字结构体地址
struct sockaddr_un {
               sa_family_t sun_family;               /* AF_UNIX */
               char        sun_path[108];            /* pathname *///文件的路径名
           };
addrlen: sockaddr_un大小 


提取
int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);

addr: struct sockaddr_un 结构体地址


需要注意的点:
客户端可以隐式绑定,但是服务器不可以
绑定指定文件时m,这个文件必须不存在,如果存在绑定失败
```

### 5.31 本地套接字TCP服务器

**参考代码**

```c
#include<stdio.h>
#include<fcntl.h>
#include<stddef.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(void)
{
     unlink("sock.s");
     int lfd = socket(AF_UNIX,SOCK_STREAM,0);
     struct sockaddr_un myaddr;
     myaddr.sun_family = AF_UNIX;
     strcpy(myaddr.sun_path,"sock.s");
     int len = offsetof(struct sockaddr_un,sun_path)+strlen(myaddr.sun_path);
     bind(lfd,(struct sockaddr *)&myaddr,len);
     listen(lfd,128);

     struct sockaddr_un cliaddr;
     socklen_t len1 = sizeof(cliaddr);
     int cfd = accept(lfd,(struct sockaddr*)&cliaddr,&len);
     printf("new client file = %s\n",cliaddr.sun_path);

     char buf[1500]="";
     while(1)
     {
        int n = recv(cfd,buf,sizeof(buf),0);
        if(n<=0)
        {
           printf("err or client close\n");
           break;
        }else
        {
           printf("%s\n",buf);
           send(cfd,buf,n,0);
        }
     }
     close(lfd);
     close(cfd);
     return 0;
}
```

### 5.32 本地套接字TCP客户端

**参考代码**

```c
#include<stdio.h>
#include<fcntl.h>
#include<stddef.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
{
     unlink("sock.c");
     int cfd = socket(AF_UNIX,SOCK_STREAM,0);
     struct sockaddr_un myaddr;
     myaddr.sun_family = AF_UNIX;
     strcpy(myaddr.sun_path,"sock.c");
     int len = offsetof(struct sockaddr_un,sun_path)+strlen(myaddr.sun_path);
     if(bind(cfd,(struct sockaddr *)&myaddr,len)<0)
     {
        perror("bind");
        return 0;
     }  
     //连接
     struct sockaddr_un seraddr;
     seraddr.sun_family = AF_UNIX;
     strcpy(seraddr.sun_path,"sock.s");
     connect(cfd,(struct sockaddr*)&seraddr,sizeof(seraddr));
     

     char buf[1500]="";
     while(1)
     {
        int n = read(STDIN_FILENO,buf,sizeof(buf));
        send(cfd,buf,n,0);
        memset(buf,0,sizeof(buf));
        n = recv(cfd,buf,sizeof(buf),0);
        if(n<=0)
        {
           printf("err or client close\n");
           break;
        }else
        {
           printf("%s\n",buf);
        }  
     }  
     close(cfd);
     return 0;
}
```

# 6、libevent

## 6.1 介绍

网络的事件库

跨平台,支持多种多路io复用

核心: 以事件驱动(触发),回调

## 6.2 libevent的使用

```c
创建event_base根节点

struct event_base *event_base_new(void);
返回值值就是event_base根节点地址

释放根节点

void event_base_free(struct event_base *);

循环监听


int event_base_dispatch(struct event_base *base);
相当于 while(1){epoll_wait}循环监听

退出循环监听
int event_base_loopexit(struct event_base *base, const struct timeval *tv); //等待固定时间之后退出
    int event_base_loopbreak(struct event_base *base);//立即退出
```

## 6.3 libevent -API

```c
 初始化上树节点

struct event *event_new(struct event_base *base, evutil_socket_t fd, short events, event_callback_fn cb, void *arg);
参数:

base: event_base根节点
fd: 上树的文件描述符
events: 监听的事件
   #define  EV_TIMEOUT         0x01   //超时事件
#define  EV_READ                  0x02 //读事件
#define  EV_WRITE                0x04  //写事件
#define  EV_SIGNAL              0x08     //信号事件
#define  EV_PERSIST              0x10   //周期性触发
        #define  EV_ET      
cb: 回调函数
typedef void (*event_callback_fn)(evutil_socket_t fd, short events, void *arg);
arg: 传给回调函数的参数
返回值: 初始化好的节点的地址

 节点上树

int event_add(struct event *ev, const struct timeval *timeout);

ev: 上树节点的地址
timeout: NULL  永久监听  固定时间 限时等待

 下树

int event_del(struct event *ev);
ev: 下树节点的地址

 释放节点

void event_free(struct event *ev);

```

## 6.4 libevent编写tcp服务器流程

创建套接字

绑定

监听

创建event_base根节点

初始化上树节点 lfd

上树

循环监听

收尾

**参考代码:**

```c
#include<stdio.h>
#include"event.h"
#include"wrap.h"

#define _MAX_CLIENT_ 1024
typedef struct FdEventMap{
    int fd;
    struct event *ev;
}FdEvent;

FdEvent mFdEvents[_MAX_CLIENT_];

void initEventArray()
{
    for(int i = 0; i < _MAX_CLIENT_; i++)
    {
       mFdEvents[i].fd = -1;
       mFdEvents[i].ev = NULL;
    }
}
struct event *getEventByFd(int cfd)
{
    int i;
    for(i = 0; i < _MAX_CLIENT_; i++)
    {
       if(cfd == mFdEvents[i].fd)
       {
          return mFdEvents[i].ev;
       }
    }

    return NULL;
}
int addEvent(int cfd,struct event *ev)
{
   int i ;
   for( i = 0; i < _MAX_CLIENT_; i++)
   {
       if(mFdEvents[i].fd < 0)
       {
           break;
       }
   }

   if(i == _MAX_CLIENT_)
   {
       printf("too many clients...\n");
       return -1;
   }
   mFdEvents[i].fd = cfd;
   mFdEvents[i].ev = ev;

   return 0;
}
void cfdcb(int fd,short events,void *arg)
{
   char buf[1500]="";
   int n = Read(fd,buf,sizeof(buf));
   if(n<=0)
   {
      printf("client close\n");
      //下树
      event_del(getEventByFd(fd));
   }
   else
   {
      printf("%s\n",buf);
      Write(fd,buf,n);
   }
}

void lfdcb(int fd,short events,void *arg)
{
    struct event_base * base = (struct event_base *)arg;
    int cfd = Accept(fd,NULL,NULL);
    struct event *ev = event_new(base,cfd,EV_READ | EV_PERSIST,cfdcb,NULL);
    event_add(ev,NULL);
    addEvent(cfd,ev);
}

int main(void)
{
    //创建套接字
    //绑定
    int lfd = tcp4bind(9999,NULL);
    //监听
    Listen(lfd,128);
    //初始化事件数组
    initEventArray();
    //创建event_base根节点
    struct event_base * base = event_base_new();
    //初始化上树节点
    struct event *ev = event_new(base,lfd,EV_READ | EV_PERSIST,lfdcb,base);
    //上树
    event_add(ev,NULL);
    //循环监听
    event_base_dispatch(base);
    //收尾
    close(lfd);
    event_base_free(base);
    return 0;
}
```

## 6.5 bufferevent -API

```c
bufferevent事件的API
 创建新的节点

struct bufferevent *bufferevent_socket_new(struct event_base *base, evutil_socket_t fd, int options);

参数: 
    base  : event_base 根节点
    fd: 要初始化上树的文件描述符
    options : 
           BEV_OPT_CLOSE_ON_FREE   -- 释放bufferevent自动关闭底层接口   
         BEV_OPT_THREADSAFE      -- 使bufferevent能够在多线程下是安全的    
返回值:
   新建节点的地址

设置节点的回调
释放bufferevent
void bufferevent_setcb(struct bufferevent *bufev,
    bufferevent_data_cb readcb, bufferevent_data_cb writecb,
bufferevent_event_cb eventcb, void *cbarg);

参数:
    bufev : 新建的节点的地址
    readcb : 读回调
    writecb : 写回调
    eventcb : 异常回调
    cbarg: 传给回调函数的参数

    typedef void (*bufferevent_data_cb)(struct bufferevent *bev, void *ctx);// 读写回调
    typedef void (*bufferevent_event_cb)(struct bufferevent *bev, short what, void *ctx);//事件回调

BEV_EVENT_EOF, 对方关闭连接
BEV_EVENT_ERROR，出错
BEV_EVENT_TIMEOUT,超时
BEV_EVENT_CONNECTED 建立连接成功

让事件使能
int bufferevent_enable(struct bufferevent *bufev, short event);//EV_READ  EV_WRITE
int bufferevent_disable(struct bufferevent *bufev, short event);//EV_READ  EV_WRITE

发送数据
int bufferevent_write(struct bufferevent *bufev, const void *data, size_t size);
    bufferevent_write是将data的数据写到bufferevent的写缓冲区

接收数据
size_t bufferevent_read(struct bufferevent *bufev, void *data, size_t size);
    bufferevent_read 是将bufferevent的读缓冲区数据读到data中，同时将读到的数据从bufferevent的读缓冲清除。


连接侦听器
创建套接字 绑定 监听  提取

struct evconnlistener *evconnlistener_new_bind(struct event_base *base,
    evconnlistener_cb cb, void *ptr, unsigned flags, int backlog,
const struct sockaddr *sa, int socklen);
参数: 
    base : base根节点
    cb : 提取cfd后调用的回调
    ptr : 传给回调的参数
    flags : 
    
        LEV_OPT_LEAVE_SOCKETS_BLOCKING   文件描述符为阻塞的
         LEV_OPT_CLOSE_ON_FREE            关闭时自动释放
         LEV_OPT_REUSEABLE                端口复用
         LEV_OPT_THREADSAFE               分配锁，线程安全
backlog : -1
sa : 绑定的地址信息
socklen : sa的大小
返回值: 连接侦听器的地址
回调
typedef void (*evconnlistener_cb)(struct evconnlistener *evl, evutil_socket_t fd, struct sockaddr *cliaddr, int socklen, void *ptr);
参数:
    evl :  链接侦听器的地址
    fd :  cfd
    cliaddr: 客户端的地址信息
    ptr:  evconnlistener_new_bind传过来的参数


创建套接字 连接服务器
struct bufferevent *bufferevent_socket_new(struct event_base *base,-1, int options);

int bufferevent_socket_connect(struct bufferevent *bev, struct sockaddr *serv, int socklen);
bev: 新建的节点
serv: 服务器的地址信息

socklen: serv长度

```

