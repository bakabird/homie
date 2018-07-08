const Base = require('./base.js');
const _ = require('lodash')

module.exports = class extends Base {
  async newAction() {
    const x = this.post('x')
    const y = this.post('y')
    const defaultName = `房间${(await this.model('room').RoomNum()) + 1}`
    const rlt = await this.model('room').newRoom(x, y, defaultName)
    this.success({
      roomId: rlt
    })
    return true
  }
  async infoAction() {
    const roomId = this.post('roomId')
    const roomInfo = await this.model('room').checkRoom(roomId)
    const rlt = think.isEmpty(roomInfo) ? false : roomInfo;
    console.log(rlt)
    if (rlt == false) {
      this.fail(1002, "invalid roomId")
      return false
    } else {
      this.success(rlt)
      return true
    }
  }
  async delAction() {
    const roomId = this.post('roomId')
    console.log(1)
    const exist = await this.model('room').checkRoom(roomId)
    console.log(1)
    const rlt = think.isEmpty(exist) ? false : await this.model('room').delRoom(roomId);
    console.log(1)
    console.log(rlt)
    if (rlt == false) {
      console.log(1)
      this.fail(1002, "invalid roomId")
      return false
    } else {
      console.log(1)
      this.success()
      return true
    }
  }
  async updateAction() {
    const model = this.model('room')
    const {
      roomId
    } = this.post()
    const news = _.pick(this.post(), ['x', 'y', 'name'])
    const exist = await model.checkRoom(roomId)
    if (think.isEmpty(exist)) {
      this.fail(1002, "invalid roomId")
      return false
    }
    if (!think.isEmpty(news)) {
      await model.where({ id: roomId }).update(news)
      this.success(await model.checkRoom(roomId))
      return true
    } else {
      this.success(await model.checkRoom(roomId))
      return false
    }
  }
  __after() {
    this.WSBC('roomChange')
  }
};
