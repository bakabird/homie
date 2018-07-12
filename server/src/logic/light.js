module.exports = class extends think.Logic {
  nowAction(){
    this.allowMethods = "post"
    this.rules = {
      eid: {
        required: true,
        int: true
      }
    }
  }
  updateAction(){
    this.allowMethods = 'post'
    this.rules = {
      eid: {
        required: true,
        int: true
      },
      lightUp: {
        required: true,
        boolean: true
      }
    }
  }
  allAction(){
    this.allowMethods = "get"
  }
};
