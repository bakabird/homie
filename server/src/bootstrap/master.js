// invoked in master
require('./common.js')

const fs = require('fs');
const sqlite3 = require('sqlite3').verbose();
const path = require('path');

// 保证数据库干净
const rtPath = path.join(think.ROOT_PATH, 'runtime/')
const sqlPath = path.join(think.ROOT_PATH, 'runtime/sqlite/')
const dbPath = path.join(think.ROOT_PATH, 'runtime/sqlite/homie.sqlite')

const createDirIfNotExist = (path) => {
  if (!fs.existsSync(path)) {
    fs.mkdirSync(path);
  }
}
const rmFileIfExist = (path) => {
  if(fs.existsSync(path)){
    fs.unlinkSync(path)
  }
}

createDirIfNotExist(rtPath)
createDirIfNotExist(sqlPath)
rmFileIfExist(dbPath)

const homieDb = new sqlite3.Database(dbPath);

// 确认需要的数据表存在
homieDb.serialize(function () {
  // 房间数据表
  homieDb.run(`CREATE TABLE room (
    id    INTEGER      PRIMARY KEY
                       NOT NULL,
    x     INT          NOT NULL,
    y     INT          NOT NULL,
    entry BLOB         NOT NULL,
    name  VARCHAR (15) NOT NULL
  );`);
  // homieDb.each("SELECT rowid AS id, info FROM lorem", function(err, row) {
  //     console.log(row.id + ": " + row.info);
  // });
});

