const Base = require('./base.js');

module.exports = class extends Base {
  heyAction(){
    this.allowMethods = "get"
  }
};
