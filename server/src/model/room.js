module.exports = class extends think.Model {
  newRoom(x,y,name){
    return this.add({
      x,
      y,
      name,
      entry: false
    });
  }
  checkRoom(roomId){
    return this.where({id: roomId}).find()
  }
  delRoom(roomId){
    return this.where({id: roomId}).delete()
  }
  RoomNum(){
    return this.count();
  }
  all(){
    return this.select();
  }
};
