module.exports = class extends think.Model {
  newLight(id){
    return this.add({
      id,
      lightUp: false
    });
  }
};
