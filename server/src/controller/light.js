const Base = require('./base.js');

module.exports = class extends Base {
  async nowAction(){
    const eid = this.post('eid')

    // 检查
    // 检查 eid
    const eqp = await this.model('eleEquipment').checkEleEquipment(eid)
    if(think.isEmpty(eqp)) {
      this.fail(1002,'invalid eid')
      return false
    }
    // 检查 eleType
    if(eqp.type != 'light'){
      this.fail(1002,'not light eid')
      return false
    }

    // 执行
    this.success(await this.model('light').now(eid))
    return true
  }
  async updateAction(){
    const {
      eid, lightUp
    } = this.post();

    // 检查
    // 检查 eid
    const eqp = await this.model('eleEquipment').checkEleEquipment(eid)
    if(think.isEmpty(eqp)) {
      this.fail(1002,'invalid eid')
      return false
    }
    // 检查 eleType
    if(eqp.type != 'light'){
      this.fail(1002,'not light eid')
      return false
    }

    // 执行
    if(lightUp) await this.model('light').switchOn(eid)
    else        await this.model('light').switchOff(eid)

    // 返回 
    this.success(await this.model('light').now(eid))
    return true
  }
  async allAction(){
    const lightState = await this.model('light').all();
    const rlt = []
    lightState.map(a => {
      rlt.push({
        eid: a.id,
        lightUp: a.lightUp
      })
    })
    this.success(rlt)
    return false;
  }
  __after(){
    this.WSBC('lightChange')
  }
};
