// invoked in master
const fs = require('fs')
const sqlite3 = require('sqlite3').verbose()
const path = require('path')
// 确认需要的数据库存在
fs.mkdirSync(path.join(think.ROOT_PATH, 'runtime/sqlite/'))
const db = new sqlite3.Database(path.join(think.ROOT_PATH, 'runtime/sqlite/homie'));
// 确认需要的数据表存在
// 房间数据库