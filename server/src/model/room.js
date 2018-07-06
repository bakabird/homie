module.exports = class extends think.Model {
  newRoom(x,y){
    return this.add({
      x, y
    });
  }
  checkRoom(roomId){
    return this.select({id: roomId});
  }
  delRoom(roomId){
    return this.where({id: roomId}).delete()
  }
};
