module.exports = class extends think.Model {
  async has(type){
    return !think.isEmpty(await this.where({ type }).find())
  }
};
