const Base = require('./base.js');
const isDev = think.env === 'development';

module.exports = class extends Base {
  heyAction(){
    this.success();
  }
  echoAction(){
    if(isDev) console.log(this.post());

    const re = {};
    re.req = this.ctx.request;
    re.post = this.post();

    this.success(re);
  }
};
