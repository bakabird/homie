module.exports = class extends think.Logic {
  heyAction(){
    this.allowMethods = "get"
  }
  echoAction(){

  }
  allRoomAction(){
    this.allowMethods = "get"
  }
};
