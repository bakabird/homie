const Base = require('./base.js');

module.exports = class extends Base {
  openAction() {
    this.emit('opend', CURMODE)
    WSLIST[this.websocket.id] = {
      io: this.websocket
    }
    return
  }
  closeAction(){
    this.broadcast('death', 'There is a new client out successfully!')
    delete WSLIST[this.websocket.id]
    return
  }
};
