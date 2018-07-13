const Base = require('./base.js');
const _ = require('lodash')

module.exports = class extends Base {
  async newAction(){
    const eleType = this.post('eleType')

    // console.log(await this.model('eleType').select())
    // console.log(await this.model('eleType').where({
    //   type: eleType
    // }).find())
    // console.log(await this.model('eleType').has(eleType))
    if(await this.model('eleType').has(eleType)){
      const name = think.isEmpty(this.post('name')) ? `电器${(await this.model('eleEquipment').max('id')) + 1}` : this.post('name')
      const setOn = think.isEmpty(this.post('setOn')) ? 0 : this.post('setOn')

      // setOn 的置是否合法
      // console.log(think.isEmpty( await this.model('room').checkRoom(setOn) ),setOn)
      // console.log(setOn != 0 && think.isEmpty( await this.model('room').checkRoom(setOn) ))
      if( setOn != 0 && think.isEmpty( await this.model('room').checkRoom(setOn) ) ){
        this.fail(1002,'invalid setOn')
        return
      }else{
        // 建一个电器 并且 完成安置
        const eid = await this.model('eleEquipment').new(name ,eleType)

        // 向对应的电器表进行创建
        switch(eleType){
          case 'light':
            await this.model('light').new(eid)
            break;
          default:
            break;
        }

        // 完成电器的安置
        await this.model('roomsEleEquipment').add({
          rid: setOn,
          eid
        })

        this.success({
          eid
        })
        return true
      }
    }else{
      this.fail(1002,'invalid eleType');
      return false
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

    // --- 检查 ---
    // 先检查setOn
    if(!think.isEmpty(setOn) && setOn != 0 && think.isEmpty( await this.model('room').checkRoom(setOn) ) ){
      this.fail(1002,'invalid setOn')
      return false
    }

    // --- 执行 ---
    if(!think.isEmpty(name)){
      await model.updateName(eid,name)
    }
    if(!think.isEmpty(setOn)){
      await this.model('roomsEleEquipment').updateSetOn(eid, setOn)
    }

    const curEqp = await model.checkEleEquipment(eid)
    this.success(Object.assign( {
      eid: curEqp.id,
      name: curEqp.name,
      eleType: curEqp.type
    } , {
      setOn:  await this.model('roomsEleEquipment').setOnOfEid(eid)
    }) )
    return true

  }
  async delAction(){
    const eid = this.post('eid')

    // 检查
    const eqp = await this.model('eleEquipment').checkEleEquipment(eid)
    if(think.isEmpty(eqp)) {
      this.fail(1002,'invalid eid')
      return false
    }

    // 删掉外键依赖
    // 删掉电器种类表中实体
    const eleType = eqp.type
    switch(eleType){
      case 'light':
        // 从灯表中删掉实体
        await this.model('light').remove(eid)
        break;
      default:
        break;
    }
    // 删掉房间内电器
    await this.model('roomsEleEquipment').remove(eid)

    // 删掉实体
    // 删掉电器
    await this.model('eleEquipment').remove(eid)

    this.success();
    return true
  }
  __after(){
    this.WSBC('elesChange')
  }
};
