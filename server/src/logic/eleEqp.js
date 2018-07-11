module.exports = class extends think.Logic {
  newAction(){
    this.allowMethods = "post"
    this.rules = {
      eleType: {
        required: true,
        string: true,
        length: {
          max: 10
        }
      },
      name: {
        string: true,
        length: {
          max: 14
        }
      },
      setUp: {
        int: {
          min: 0
        }
      }
    }
  }
  updateAction(){
    this.allowMethods = "post"
    this.rules = {
      eid: {
        required: true,
        length: {
          max: 10
        }
      },
      name: {
        string: true,
        length: {
          max: 14
        }
      },
      setUp: {
        int: {
          min: 0
        }
      }
    }
  }
};
