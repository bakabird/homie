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
  async now(id){
    return await this.where({
      id
    }).field('lightUp').find()
  }
  switchOn(id){
    return this.where({
      id
    }).update({
      lightUp: true
    })
  }
  switchOff(id){
    return this.where({
      id
    }).update({
      lightUp: false
    })
  }
  all(){
    return this.select();
  }
};
