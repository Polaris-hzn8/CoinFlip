# Qt项目管理

---

在Qt项目框架中通常用pri文件来管理项目，

一般创建Qt项目工程时都是直接把项目所有的、头文件、源文件和资源文件等全放入pro中。这样只几个文件的小项可能就会觉得没有什么，但是几十几百个文件的中大型项目当中，再有树形文件结构的时就会感到很杂乱，这时pri文件的作用就尤为重要了。

简单来说pri文件就是把pro文件中的一部分放到pri文件中进行管理，类似头文件进行分块管理分担pro文件的部分压力，这样一来pro文件就不会很臃肿。

### 1.通用规则

1. 除了极小的微型demo级别项目外，其余项目建议用pri分门别类不同文件夹存放代码文件，方便统一管理和查找。
2. 同类型功能的类建议统一放在一起，如果该目录下代码文件数量过多，也建议拆分多个目录存放。
3. 比如就3-5个界面的项目，统一搞个form.pri存放这些界面，而当项目越来越大，界面可能也需要按照功能划分，比如系统配置的窗体放在一个目录下，日志管理的窗体放在一个目录下。
4. 很多通用功能，多个项目都会用到，可以考虑封装成pri形式的模块，俗称轮子，不断完善这些轮子，多个项目共享该模块，一旦遇到BUG修复，只需要更改一个地方就行。
5. 项目如果还更大或者项目组人员分配不同功能，可以考虑插件形式，插件一般会用到两种，一种是普通动态库形式的插件，必须和主程序放在一起；一种是Qt机制的插件，放在指定的目录。

### 2.全局配置文件

全局配置文件管理类 appconfig.h 用来读写对应项目的配置文件。

1. 格式可以是ini、xml、json等，小项目建议ini，怎么方便怎么来，相当于将配置文件的值映射到全局变量。
2. 配置文件如果配置项较多建议分组存储方便查找，而不是全部放在一个大分组中。
3. 读配置文件的时候可以判断配置文件是否存在、配置项是否缺失等情况，有问题则重新生成配置文件，避免恶意删除配置文件导致程序运行异常。
4. 读配置文件的时候可以填入默认值（qt配置文件类QSettings的value方法的第二个参数，set.value("Hardware", App::Hardware)），避免初始时候读取不到节点而导致配置项值不符合预期值类型。
5. 读配置文件完成后可以重新判断配置项的值是否符合要求，对值进行过滤和矫正，防止人为打开配置文件修改后填入了异常的值，比如定时器的间隔为0，要重新纠正设定为合法的值。
6. 带中文的初始值用QString::fromUtf8包起来，比如QString::fromUtf8("管理员")。
7. 带中文的配置项要设置配置文件编码为 utf-8，set.setIniCodec("utf-8")。

### 3.全局变量

全局变量管理类 appdata.h 用来设置项目中用到的所有全局变量。

1. 比如当前用户/系统是否锁定等，这样可以在任意的编码位置使用该变量进行判断处理。
2. 可以将UI界面中的导航栏宽高、按钮大小、图标大小等变量放在这，系统启动后判断分辨率等来设定不同的值。

### 4.全局事件中转处理

全局事件中转处理类 appevent.h 用来中转系统中各种跨多个UI以及多个类的事件。

1. 此类必须是全局单例类，便于全局统一使用。
2. 比如类a的父类是b，类b的父类是c，现在有个信号要发给类d，在没有事件中转处理的情况下的做法是将a信号发给b，b再发给c，c再发给d，如果父类嵌套层级越多越复杂，代码越难管理。
3. 将类a的信号发给appevent类，然后类d直接关联appevent类进行处理就行。
4. 项目越大，会越发现事件中转处理的必要性，代码清晰，管理方便。

### 5.全局程序初始化

全局程序初始化类 appinit.h 用来做一些程序启动后的初始化处理。

1. 读取配置文件。
2. 设置全局字体。
3. 设置全局样式表，建议先读取通用的样式表，然后将额外的样式表内容加到后面一起设置。
4. 设置项目编码。
5. 设置翻译文件，可以加载多个，包括qt内置的qt_zh_CN.qm，用户自己的翻译文件等。
6. 初始化随机数种子。
7. 新建项目中需要的目录，防止没有目录无法保存文件到目录。
8. 初始化数据库，包括打开数据库，载入基础数据比如用户表、设备表等。
9. 启动日志输出类用来启动日志服务。
10. 启动运行时间记录类用来记录每次软件运行开始时间和结束时间。
11. 关联全局事件过滤器处理自定义无边框UI拖动、全局按键处理等。

### 6.全局通用类

1. 调试日志输出类 savelog.h 用来启动日志服务，可以将日志输出到文件或者网络打印输出。
2. 运行时间记录类 saveruntime.h 用来记录每次软件运行开始时间和结束时间。
3. 图形字体类 iconfont.h 用来设置图形字体图标。





