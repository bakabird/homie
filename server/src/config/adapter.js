const fileCache = require('think-cache-file');
const nunjucks = require('think-view-nunjucks');
const fileSession = require('think-session-file');
const mysql = require('think-model-mysql');
const socketio = require('think-websocket-socket.io');
const sqlite = require('think-model-sqlite');
const {Console, File, DateFile} = require('think-logger3');
const path = require('path');
const isDev = think.env === 'development';

/**
 * cache adapter config
 * @type {Object}
 */
exports.cache = {
  type: 'file',
  common: {
    timeout: 24 * 60 * 60 * 1000 // millisecond
  },
  file: {
    handle: fileCache,
    cachePath: path.join(think.ROOT_PATH, 'runtime/cache'), // absoulte path is necessarily required
    pathDepth: 1,
    gcInterval: 24 * 60 * 60 * 1000 // gc interval
  }
};

/**
 * model adapter config
 * @type {Object}
 */
// exports.model = {
//   type: 'mysql',
//   common: {
//     logConnect: isDev,
//     logSql: isDev,
//     logger: msg => think.logger.info(msg)
//   },
//   mysql: {
//     handle: mysql,
//     database: '',
//     prefix: 'think_',
//     encoding: 'utf8',
//     host: '127.0.0.1',
//     port: '',
//     user: 'root',
//     password: 'root',
//     dateStrings: true
//   }
// };


exports.model = {
  type: 'sqlite',
  sqlite: {
    handle: sqlite, // Adapter handle
    path: path.join(think.ROOT_PATH, 'runtime/sqlite'), // sqlite 保存的目录
    database: 'homie', // 数据库名
    connectionLimit: 5, // 连接池的连接个数，默认为 1
    prefix: '', // 数据表前缀，如果一个数据库里有多个项目，那项目之间的数据表可以通过前缀来区分
  }
}
/**
 * session adapter config
 * @type {Object}
 */
exports.session = {
  type: 'file',
  common: {
    cookie: {
      name: 'thinkjs'
      // keys: ['werwer', 'werwer'],
      // signed: true
    }
  },
  file: {
    handle: fileSession,
    sessionPath: path.join(think.ROOT_PATH, 'runtime/session')
  }
};

/**
 * view adapter config
 * @type {Object}
 */
exports.view = {
  type: 'nunjucks',
  common: {
    viewPath: path.join(think.ROOT_PATH, 'view'),
    sep: '_',
    extname: '.html'
  },
  nunjucks: {
    handle: nunjucks
  }
};

/**
 * logger adapter config
 * @type {Object}
 */
exports.logger = {
  type: isDev ? 'console' : 'dateFile',
  console: {
    handle: Console
  },
  file: {
    handle: File,
    backups: 10, // max chunk number
    absolute: true,
    maxLogSize: 50 * 1024, // 50M
    filename: path.join(think.ROOT_PATH, 'logs/app.log')
  },
  dateFile: {
    handle: DateFile,
    level: 'ALL',
    absolute: true,
    pattern: '-yyyy-MM-dd',
    alwaysIncludePattern: true,
    filename: path.join(think.ROOT_PATH, 'logs/app.log')
  }
};


exports.websocket = {
  type: 'socketio',
  common: {
    // common config
    // origins: '*:*'
  },
  socketio: {
    handle: socketio,
    // allowOrigin: '127.0.0.1:45123',  // 默认所有的域名都允许访问
    // allowOrigin: isDev ? null : '127.0.0.1:8360',  // 默认所有的域名都允许访问
    path: '/socket.io',             // 默认 '/socket.io'
    adapter: null,                  // 默认无 adapter
    messages: [{
      open: '/websocket/open',       // 建立连接时处理对应到 websocket Controller 下的 open Action
      close: '/websocket/close',     // 关闭连接时处理的 Action
      // login: '/websocket/login',     // 登陆 事件处理的 Action
      // logout: '/websocket/logout',   // 登出 事件处理的 Action
      // check: '/websocket/check'      // 检查登陆情况 事件处理的 Action
    }]
  }
}