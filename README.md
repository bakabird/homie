# Homie

帮助智能家居系统设计者进行快速原型产出。

## 将server打包成一个可执行程序

### Mac Os

0. clone本项目
1. 在你的本地安装[LTS版本的node](https://nodejs.org/zh-cn/download/)
2. 进入server并安装依赖 `cd server && npm i --registry=https://registry.npm.taobao.org/`
3. 使用makeself完成打包，在项目根目录执行如下命令`./tool/makeself-2.4.0/makeself.sh server/ homie_server_mac great node_mac production.js`
4. 在根目录得到homie_server_mac，执行等待其完整开启后，访问 `http://localhost:8360/` 确认服务器成功开启。

### Win

0. clone本项目
1. 在你的本地安装[LTS版本的node](https://nodejs.org/zh-cn/download/)
2. 进入server并安装依赖 `cd server && npm i --registry=https://registry.npm.taobao.org/`
3. ...待续...