const Base = require('./base.js');
const isDev = think.env === 'development';

module.exports = class extends Base {
  heyAction(){
    this.success();
  }
  echoAction(){
    if(isDev) console.log(this.post());
    this.success(this.post());
  }
};
