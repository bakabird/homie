module.exports = class extends think.Model {
  newRoom(){
     return this.add({
      x: 22,
      y: 33
    });
  }
};
