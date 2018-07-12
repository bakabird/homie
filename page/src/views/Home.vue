<template>
  <div class="home">
      <h2 class='RoomNum'>房间数量:{{ roomNum }}</h2>
      <div class='RoomTitle' v-for='room in rooms' :key='room.name'>
        <h3>[{{room.id}}]{{room.name}} ({{room.x}},{{room.y}})</h3>
        <div class='RoomInfo'>
          <template v-if='elesOnRoom[room.id]'>
            <div   v-for="ele in elesOnRoom[room.id]" :key="`ele_${ele.eid}`">
               [{{ele.eid}}] {{ele.eleType == 'light' ? '灯' : '其他'}} 
               <template v-if="ele.eleType == 'light' && ele.lightUp == 1">
                <div class="light_on"></div>
               </template>
               <template v-else-if="ele.eleType == 'light' && ele.lightUp == 0">
                <div class="light_off"></div>
               </template>
            </div>
          </template>
        </div>
      </div>
  </div>
</template>

<script>
// @ is an alias to /src
import axios from "axios";

export default {
  name: "home",
  data() {
    return {
      rooms: [],
      eles: {}
    };
  },
  computed: {
    roomNum() {
      return this.rooms.length;
    },
    elesOnRoom() {
      const rlt = {};
      for(let i in this.eles) {
        const e = this.eles[i]
        if(!rlt[e.setOn]){
          rlt[e.setOn] = [];
        }
        rlt[e.setOn].push(e)
      }
      return rlt;
    }
  },
  components: {},
  methods:{
    async fetchRooms(){
      try {
        const response = await axios.get(this.$serverHost() + "control/allRoom");
        console.log(response);
        if (response.data.errno != 0) throw new Error(response.data.errmsg);
        this.rooms = response.data.data;
      } catch (error) {
        console.error(error);
      }
    },
    async fetchEleEqps(){
      try {
        // eles
        const response_eles = await axios.get(this.$serverHost() + "control/allEleEqp");
        console.log(response_eles);
        if (response_eles.data.errno != 0) throw new Error(response_eles.data.errmsg);
        const eles = response_eles.data.data;
        // eleRooms
        const response_lights = await axios.get(this.$serverHost() + "light/all");
        console.log(response_lights);
        if (response_lights.data.errno != 0) throw new Error(response_lights.data.errmsg);
        const lights = response_lights.data.data;

        const newEles = {};

        eles.map(e => {
          newEles[e.eid] = e
        })
        lights.map(a => {
          newEles[a.eid].lightUp = a.lightUp
        })

        this.eles = newEles
      } catch (error) {
        console.error(error);
      }
    },
  },
  socket: {
    // Prefix for event names
    // prefix: "/counter/",

    // If you set `namespace`, it will create a new socket connection to the namespace instead of `/`
    // namespace: "/counter",
    events: {
      // Similar as this.$socket.on("changed", (msg) => { ... });
      // If you set `prefix` to `/counter/`, the event name will be `/counter/changed`
      //
      opend(msg) {
        console.log(msg);
      },
      roomChange(){
        this.fetchRooms()
      }
    }
  },
  mounted() {
    this.fetchRooms()
    this.fetchEleEqps()
  }
  
};
</script>
<style scoped>
.home {
  padding: 0 50px;
}
.RoomNum {
  text-align: left;
}
.RoomTitle {
  text-align: left;
  margin-left: 2em;
}
.RoomInfo{
  margin-left: 2em;
}
.light_off{
  width: 20px;
  height: 20px;
  border-radius: 20px;
  background: green;
}
.light_on{
  width: 20px;
  height: 20px;
  border-radius: 20px;
  background: greenyellow;
}
</style>
