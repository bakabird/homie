module.exports = class extends think.Model {
  new(id){
    return this.add({
      id,
      lightUp: false
    });
  }
  remove(id){
    return this.where({
      id
    }).delete();
  }
};
