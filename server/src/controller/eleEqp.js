const Base = require('./base.js');
const _ = require('lodash')

module.exports = class extends Base {
  async newAction(){
    const eleType = this.post('eleType')
    if(eleType == 'light'){
      const name = think.isEmpty(this.post('name')) ? `电器${(await this.model('eleEquipment').count()) + 1}` : this.post('name')
      const setOn = think.isEmpty(this.post('setOn')) ? 0 : this.post('setOn')

      // setOn 的置是否合法
      console.log(think.isEmpty( await this.model('room').checkRoom(setOn) ),setOn)
      console.log(setOn != 0 && think.isEmpty( await this.model('room').checkRoom(setOn) ))
      if( setOn != 0 && think.isEmpty( await this.model('room').checkRoom(setOn) ) ){
        this.fail(1002,'invalid setOn')
        return
      }

      // 建一个灯 并且完成安置
      const eid = await this.model('eleEquipment').add({ name })
      await this.model('light').newLight(eid)
      await this.model('roomsEleEquipment').add({
        rid: setOn,
        eid
      })

      this.success({
        eid
      })
    }else{
      this.fail(1002,'invalid eleType');
    }
  }
  async updateAction(){
    const {
      eid, name, setOn
    } = this.post();
    const model = this.model('eleEquipment');

    const eqp = await model.checkEleEquipment(eid)
    if(think.isEmpty(eqp)) {
      this.fail(1002,'invalid eid')
      return false
    }

    if(!think.isEmpty(name)){
      await model.where({ id: eid }).update({ name })
    }else if(!think.isEmpty(setOn)){
      // 先检查setOn
      if( setOn != 0 && think.isEmpty( await this.model('room').checkRoom(setOn) ) ){
        this.fail(1002,'invalid setOn')
        return false
      }

      // 执行setOn修改
      await this.model('roomsEleEquipment').where({eid: eid}).update({
        rid: setOn
      })
    }

    this.success({
      eid,
      
    })
    return true

  }
};
