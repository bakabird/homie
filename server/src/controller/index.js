const Base = require('./base.js');

module.exports = class extends Base {
  indexAction() {
    return this.display();
  }
  async roomAction(){
    const rlt = await this.model('room').newRoom();
    this.success();
  }
};
