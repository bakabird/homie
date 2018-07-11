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
  // 房间
  // room
  homieDb.run(`CREATE TABLE room (
    id    INTEGER      PRIMARY KEY
                       NOT NULL,
    x     INT          NOT NULL,
    y     INT          NOT NULL,
    entry BLOB         NOT NULL,
    name  VARCHAR (15) NOT NULL
  );`);

  // 电器
  // eleType
  homieDb.run(`CREATE TABLE eleType (
    type VARCHAR (10) PRIMARY KEY
                      NOT NULL,
    seq  INTEGER
  );`)
  homieDb.run(`INSERT INTO eleType VALUES ("light",1)`)
  // eleEquipment
  homieDb.run(`CREATE TABLE eleEquipment (
    id   INTEGER      PRIMARY KEY
                      NOT NULL,
    name VARCHAR (15) NOT NULL,
    type VARCHAR (10) NOT NULL
                      REFERENCES eleType(type)
  );`);

  // 电灯
  // light
  homieDb.run(`CREATE TABLE light (
    id      INTEGER PRIMARY KEY
                    NOT NULL
                    REFERENCES eleEquipment (id),
    lightUp BLOB    NOT NULL
  );`);

  // 房间内电器
  // roomsEleEquipment
  homieDb.run(`CREATE TABLE roomsEleEquipment (
    rid INTEGER NOT NULL
                REFERENCES room (id),
    eid INTEGER NOT NULL
                REFERENCES eleEquipment (id),
    PRIMARY KEY (rid,eid)); 
  );`);
  
  // 往房间表中添加一个室外房间
  homieDb.run(`INSERT INTO room VALUES (0, 0, 0, 0, '室外')`)
  
});

