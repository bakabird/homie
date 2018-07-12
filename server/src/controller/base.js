module.exports = class extends think.Controller {
  __before() {

  }
  WSBC(event,msg = ""){
    for(let i in WSLIST){
      WSLIST[i].io.emit(event,msg)
      console.log(`[notice ${i}]:`,event)
    }
  }
};
