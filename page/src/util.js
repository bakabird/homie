const util = {}
util.install = function (Vue, options) {
    Vue.prototype.$isDev = function () {
      return location.origin === "http://localhost:8080"
    };
    Vue.prototype.$serverHost = function () {
      return Vue.prototype.$isDev() ? 'http://127.0.0.1:8360/' : "/"
    };
}

export default util;