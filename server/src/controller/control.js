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
  }
  async allRoomAction(){
    return this.success(await this.model('room').all())
  }
  async flashAction(){
    await this.model('room').delete()
    this.WSBC('roomChange')
  }
};
