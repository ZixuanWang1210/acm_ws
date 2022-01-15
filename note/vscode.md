# 竞赛vscode配置指南



## chapter 1 基础配置

### step 0. 排除风险

- 打开cmd，输入`whoami`。 如果用户名是中文，建议更改用户名为**英文**，或新建一个用户名为英文的用户。
- 所有安装路径推荐填写**无中文**、无空格等**特殊字符**的路径。

### step 1. 安装wingw-w64

- 正常下载速度会比较慢，如下载困难，可使用下方百度云

  ```
  链接：https://pan.baidu.com/s/16Jec-xvAcWZ_LBktd0GsqA 
  提取码：lrgh
  ```

- 解压文件， 这里以解压到C盘根目录为例

- 设置环境变量![image-20211129140943256](https://i.loli.net/2021/11/29/4tHTRdBvcmr9jJo.png)

- 

### step 3. 安装vscode

- 在vscode官网下载安装包，并安装vscode。这一步推荐全部勾选。等待安装完成![image-20211129123514067](https://i.loli.net/2021/11/29/rwb16H27uAlqkNI.png)

- 安装必备插件，全部安装完成后，重打开vscode。

  ![image-20211129124833403](https://i.loli.net/2021/11/29/AhR4ozCMEeUWrdI.png)

  - Chinese (Simplified)
  - C/C++
  - Code Runner

### step 4. 配置vscode

- 在你想的位置新建一个文件夹，作为竞赛工作空间，你的代码将在这里保存运行。**注意** 不要有中文、不要有空格

- 右键`用code打开` 打开这个工作空间，并新建`test.cpp`用于配置测试。

- 按`Ctrl+shitf+P`， 输入settings，点击`打开工作区设置`![image-20211129141408810](https://i.loli.net/2021/11/29/AG1i8OQWcLybz5k.png)

- 将下面内容填充到setting.json 

  - 为使目录变的简洁，编译生成的.exe文件均会被命名为a.exe，如果有新编译的程序，则会自动替换掉原来的。这样文件夹中就不会乱糟糟的了
  - 如果你不想要这个效果，可以修改第76行

- ```json
  {
      "files.associations": {
          "ostream": "cpp",
          "*.tcc": "cpp",
          "atomic": "cpp",
          "bitset": "cpp",
          "chrono": "cpp",
          "complex": "cpp",
          "deque": "cpp",
          "forward_list": "cpp",
          "list": "cpp",
          "string": "cpp",
          "unordered_map": "cpp",
          "unordered_set": "cpp",
          "vector": "cpp",
          "iterator": "cpp",
          "memory_resource": "cpp",
          "optional": "cpp",
          "string_view": "cpp",
          "fstream": "cpp",
          "future": "cpp",
          "istream": "cpp",
          "scoped_allocator": "cpp",
          "shared_mutex": "cpp",
          "sstream": "cpp",
          "streambuf": "cpp",
          "system_error": "cpp",
          "thread": "cpp",
          "functional": "cpp",
          "regex": "cpp",
          "tuple": "cpp",
          "valarray": "cpp",
          "iosfwd": "cpp",
          "iostream": "cpp",
          "random": "cpp",
          "array": "cpp",
          "initializer_list": "cpp",
          "iomanip": "cpp",
          "cctype": "cpp",
          "cfenv": "cpp",
          "charconv": "cpp",
          "cinttypes": "cpp",
          "clocale": "cpp",
          "cmath": "cpp",
          "codecvt": "cpp",
          "condition_variable": "cpp",
          "csetjmp": "cpp",
          "csignal": "cpp",
          "cstdarg": "cpp",
          "cstddef": "cpp",
          "cstdint": "cpp",
          "cstdio": "cpp",
          "cstdlib": "cpp",
          "cstring": "cpp",
          "ctime": "cpp",
          "cuchar": "cpp",
          "cwchar": "cpp",
          "cwctype": "cpp",
          "exception": "cpp",
          "algorithm": "cpp",
          "map": "cpp",
          "memory": "cpp",
          "numeric": "cpp",
          "ratio": "cpp",
          "set": "cpp",
          "type_traits": "cpp",
          "utility": "cpp",
          "limits": "cpp",
          "mutex": "cpp",
          "new": "cpp",
          "stdexcept": "cpp",
          "typeindex": "cpp",
          "typeinfo": "cpp"
      },
      "code-runner.executorMap": {
          "cpp": " cd $dir && g++ $fileName -D LOCAL -o a.exe && .\\a.exe", 
      },
  
  }
  ```

- 设置设置拓展程序

  - 依次点击进入 code runner 的设置。

- ![image-20211129142201345](https://i.loli.net/2021/11/29/vr2UiT4EWKDwftm.png)

  

  - 点击在settings.json中编辑![image-20211129142433452](https://i.loli.net/2021/11/29/QuCfAdiBsGj8klD.png)

  - 将下面配置填入文件

    - **注意**其中第7行和第10行务必根据自己实际情况填写，如果严格跟随本教程，则直接复制即可

    ```json
    {
        "explorer.confirmDelete": false,
        "debug.onTaskErrors": "showErrors",
        "explorer.confirmDragAndDrop": false,
        "code-runner.saveFileBeforeRun": true,
        "code-runner.runInTerminal": true,
        "C_Cpp.default.compilerPath": "C:\\mingw64\\bin\\g++.exe",
        "C_Cpp.default.cppStandard": "c++14",
        "C_Cpp.default.includePath": [
            "C:\\mingw64\\lib"
        ],
        "C_Cpp.default.intelliSenseMode": "gcc-x64",
        "files.autoGuessEncoding": true,
        },
    }
    ```

    

## chapter 2 竞赛优化

## chapter 3 使用技巧 客制化