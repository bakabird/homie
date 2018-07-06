module.exports = class extends think.Logic {
  newAction(){
    this.allowMethods = 'post'
    this.rules = {
      x: {
        required: true,
        int: true
      },
      y: {
        required: true,
        int: true
      }
    }
  }
  delAction(){
    this.allowMethods = 'post'
    this.rules = {
      roomId: {
        required: true,
        int: true
      }
    }
  }
};
