const Base = require('./base.js');
const _ = require('lodash')

module.exports = class extends Base {
  async newAction(){
    const eleType = this.post('eleType')
    if(eleType == 'light'){
      const name = think.isEmpty(this.post('name')) ? `电器${(await this.model('eleEquipment').count()) + 1}` : this.post('name')
      const setOn = think.isEmpty(this.post('setOn')) ? -1 : this.post('setOn')

      // setOn 的置是否合法
      console.log(think.isEmpty( await this.model('room').checkRoom(setOn) ),setOn)
      console.log(setOn != -1 && think.isEmpty( await this.model('room').checkRoom(setOn) ))
      if( setOn != -1 && think.isEmpty( await this.model('room').checkRoom(setOn) ) ){
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
};
