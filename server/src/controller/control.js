const Base = require('./base.js');
const isDev = think.env === 'development';

module.exports = class extends Base {
  async heyAction(){
    return this.success();
  }
  echoAction(){
    if(isDev) console.log(this.post());

    const re = {};
    re.req = this.ctx.request;
    re.post = this.post();

    return this.success(re);
  }
  modeSwitchAction(){
    const aimMode = this.post('aimMode')
    CURMODE = aimMode;
    this.success(CURMODE)
    this.WSBC('modeSwitch',CURMODE)
  }
  async allRoomAction(){
    return this.success(await this.model('room').all())
  }
  async flashAction(){
    await this.model('roomsEleEquipment').delete();
    await this.model('light').delete();
    await this.model('eleEquipment').delete();
    await this.model('room').delete()
    await this.model('room').add({
      id: 0,
      name: '室外',
      x: 0,
      y: 0,
      entry: false
    })
    this.WSBC('roomChange')
  }
  async allEleEqpAction(){
    const rlt = []
    const allEles = await this.model('eleEquipment').select();
    const allEle_Room = await this.model('roomsEleEquipment').select();
    // console.log(allEles)
    // console.log(allEle_Room)
    
    allEles.map(a => {
      rlt.push({
        eid: a.id,
        eleType: a.type,
        name: a.name
      })
    })
    allEle_Room.map(a => {
      rlt.map(i => {
        if(a.eid === i.eid){
          i.setOn = a.rid
        }
      })
    })

    return this.success(rlt)
  }
};
