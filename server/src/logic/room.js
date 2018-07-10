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
      },
      name: {
        string: true
      }
    }
  }
  newEntryAction(){
    this.allowMethods = 'post'
    this.rules = {
      x: {
        required: true,
        int: true
      },
      y: {
        required: true,
        int: true
      },
      name: {
        string: true
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
  infoAction(){
    this.allowMethods = 'post'
    this.rules = {
      roomId: {
        required: true,
        int: true
      }
    }
  }
  updateAction(){
    this.allowMethods = 'post'
    this.rules = {
      roomId: {
        required: true,
        int: true
      },
      x: {
        int: true
      },
      y: {
        int: true
      },
      name: {
        string: true,
        length: {
          max: 14
        }
      },
    }
  }
};
