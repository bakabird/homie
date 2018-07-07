const Base = require('./base.js');
const _ = require('lodash')

module.exports = class extends Base {
  async newAction(){
    const x = this.post('x')
    const y = this.post('y')
    const defaultName = `房间${ (await this.model('room').RoomNum()) + 1 }`
    const rlt = await this.model('room').newRoom(x,y,defaultName)
    console.log(rlt)
    this.success({
      roomId: rlt
    })
  }
  async infoAction(){
    const roomId = this.post('roomId')
    const roomInfo = await this.model('room').checkRoom(roomId)
    const rlt = think.isEmpty(roomInfo) ? false : roomInfo;
    console.log(rlt)
    if(rlt == false) this.fail(1002,"invalid roomId")
    else this.success(rlt)
  }
  async delAction(){
    const roomId = this.post('roomId')
    const exist = await this.model('room').checkRoom(roomId)
    const rlt = think.isEmpty(exist) ? false : await this.model('room').delRoom(roomId);
    console.log(rlt)
    if(rlt == false) this.fail(1002,"invalid roomId")
    else this.success()
  }
  async updateAction(){
    const model = this.model('room')
    const {
      roomId
    } = this.post()
    const news = _.pick(this.post(),['x','y','name'])
    const exist = await model.checkRoom(roomId)
    if(think.isEmpty(exist)) this.fail(1002,"invalid roomId")
    if(!think.isEmpty(news)) await model.where({ id: roomId }).update(news)
    this.success(await model.checkRoom(roomId))
  }
};
