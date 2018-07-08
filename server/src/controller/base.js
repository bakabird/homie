module.exports = class extends think.Controller {
  __before() {

  }
  WSBC(event){
    for(let i in WSLIST){
      setTimeout(()=>{
        WSLIST[i].io.emit(event)
        console.log(`[notice ${i}]:`,event)
      },300)
    }
  }
};
