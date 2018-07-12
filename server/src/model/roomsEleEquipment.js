module.exports = class extends think.Model {
  async setOnOfEid(eid){
    return ( await this.where({
      eid
    }).field('rid').find() ).rid
  }
  updateSetOn(eid, rid){
    return this.where({ eid }).update({
      rid
    })
  }
  remove(eid){
    return this.where({ eid }).delete();
  }
  all(){
    return this.select();
  }
};
