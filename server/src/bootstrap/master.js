// invoked in master
const fs = require('fs');
const sqlite3 = require('sqlite3').verbose();
const path = require('path');

// 确认需要的数据库存在
const sqlPath = path.join(think.ROOT_PATH, 'runtime/sqlite/');
if(!fs.existsSync(sqlPath)){
  fs.mkdirSync(sqlPath);
}
const homieDb = new sqlite3.Database(path.join(think.ROOT_PATH, 'runtime/sqlite/homie.sqlite'));

// 确认需要的数据表存在
homieDb.serialize(function() {
  // 房间数据表
  homieDb.run(`create table if not exists room (
    id integer primary key not null,
    x int,
    y int
  )`);
  // homieDb.each("SELECT rowid AS id, info FROM lorem", function(err, row) {
  //     console.log(row.id + ": " + row.info);
  // });
});

