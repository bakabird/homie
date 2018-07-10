module.exports = class extends think.Logic {
  heyAction(){
    this.allowMethods = "get"
  }
  echoAction(){

  }
  modeSwitchAction(){
    this.allowMethods = "post"
    this.rules = {
      aimMode: {
        required: true,
        int: {min: 0, max: 1},
      }
    }
  }
  allRoomAction(){
    this.allowMethods = "get"
  }
};
