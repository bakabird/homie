const view = require('think-view');
const model = require('think-model');
const cache = require('think-cache');
const websocket = require('think-websocket');
const session = require('think-session');

module.exports = [
  view, // make application support view
  websocket(think.app),
  model(think.app),
  cache,
  session,
];
