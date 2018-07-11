module.exports = class extends think.Model {
  checkEleEquipment(eid){
    return this.where({id: eid}).find()
  }
  new(name, type){
    return this.add({ name, type })
  }
  updateName(id, name){
    return this.where({ id }).update({ name })
  }
};
