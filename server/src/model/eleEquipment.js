module.exports = class extends think.Model {
  checkEleEquipment(eid){
    return this.where({id: eid}).find()
  }
};
