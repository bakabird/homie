const Base = require('./base.js');

module.exports = class extends Base {
  async newAction(){
    const x = this.post('x')
    const y = this.post('y')
    const rlt = await this.model('room').newRoom(x,y)
    console.log(rlt)
    this.success({
      roomId: rlt
    })
  }
  async delAction(){
    const roomId = this.post('roomId')
    const exist = await this.model('room').checkRoom(roomId)
    const rlt = think.isEmpty(exist) ? false : await this.model('room').delRoom(roomId);
    console.log(rlt)
    if(rlt == false) this.fail(1002,"invalid roomId")
    else this.success()
  }
};
