import Vue from 'vue'
import App from './App.vue'
import router from './router'
import VueWebsocket from "vue-websocket";
import store from './store'
import util from './util'


Vue.config.productionTip = false
Vue.use(util)
Vue.use( VueWebsocket,  `ws://${location.host}` );

new Vue({
  router,
  store,
  render: h => h(App)
}).$mount('#app')

