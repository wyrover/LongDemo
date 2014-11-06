这是一个Qt5的小Demo，引用了Openssl，Boost，Jsoncpp，Tinyxml2等库。


Boost，Openssl库的引入：
1.到Boost，Openssl的官网下载库的源码压缩文件，然后解压到当前目录的上一级目录下并重命名为boost，openssl。
2.每个Qt工程都会有一个XXX.pro文件。在用到这两个库的工程中添加
``INCLUDEPATH += ../../boost/
INCLUDEPATH += ../../openssl/include/``

然后在代码中就可以使用这两个库了。

用MinGW编译Boost
1：进入boost目录下面 执行 bootstrap gcc

2: 执行b2"toolset=gcc"  install
