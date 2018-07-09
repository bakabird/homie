# Homie

[【github】](https://github.com/bakabird/homie)

帮助智能家居系统设计者快速产出原型。

## 使用工具版本
* Qt 5.11.0
* node  8.11.3(LTS)

## 文档

腾讯文档链接如下，需要编辑权限时请进入并进行申请；使用的设计图均放在[Presson](http://www.processon.com/team/invite/5b38ea4ce4b06bb4a4269980/uUYTdM54)小组中(密码另寻)；另有[node服务器数据相关服务的接口文档以及数据库设计文档](http://www.bakabird.top:25020/)。

0. [总汇总](https://docs.qq.com/sheet/BJSnlo2XeUgf4w40Yl3AXIKQ46Hest1VElQP1me8sv2zny1i39gZHO1XUM0V1rntt74Hy4DV0)
1. [软件设计说明](https://docs.qq.com/doc/BJSnlo2XeUgf4zj9sU0XNxIy2bKRP147tP8H0)
2. [测试计划](https://docs.qq.com/doc/BJSnlo2XeUgf4qiHVU0PBpNv3qdYkf4VbpPT3)
3. [项目开发计划](https://docs.qq.com/doc/BJSnlo2XeUgf4vIuq43tUlWr1WO1810H685u0)
4. [需求规格说明](https://docs.qq.com/doc/BJSnlo2XeUgf4dYngl0i8UyL2c5Bf93o8uYZ2)

### 注意事项

#### QT程序开发

1. 开发过程为了方便调试，请注释掉Qt中有关node服务器相关的程序，自行使用命令行工具来启动node服务器程序。
2. Qt有关node服务器相关的程序仅在最后发布程序的时候使用。

#### node服务器程序

1. node服务器程序放在项目根目录的server目录中，请自行安装LTS版的node运行。
2. 每次从github拉取（pull）新的代码，都请进入server目录，执行`npm run up`更新依赖。
