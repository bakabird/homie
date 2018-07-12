<?php
    echo "Request Test...\n";
    $url="http://127.0.0.1:8360";
    $testarray =array(
        //1.0
    array("/room/new","x=1&y=2&name=pei","{\"errno\":0}"),
    array("/room/new","","{\"errno\":1001}"),
    array("/room/new","x=1&name=pei","{\"errno\":1001}"),
    array("/room/new","y=2&name=pei","{\"errno\":1001}"),
    array("/room/new","x=1&y=2","{\"errno\":0}"),
    //1.1
    array("/room/newEntry","x=1&y=2&name=pei","{\"errno\":0}"),
    array("/room/newEntry","","{\"errno\":1001}"),
    array("/room/newEntry","x=1&name=pei","{\"errno\":1001}"),
    array("/room/newEntry","y=2&name=pei","{\"errno\":1001}"),
    array("/room/newEntry","x=1&y=2","{\"errno\":0}"),
    //1.2
    array("/room/del","roomId=2","{\"errno\":0}"),
    array("/room/del","","{\"errno\":1001}"),
    array("/room/del","room=1","{\"errno\":1001}"),
    array("/room/del","roomId=-1","{\"errno\":1002}"),
    //1.3
    array("/room/info","roomId=1","{\"errno\":0}"),
    array("/room/info","","{\"errno\":1001}"),
    array("/room/info","room=1","{\"errno\":1001}"),
    array("/room/info","roomId=-1","{\"errno\":1002}"),
    //1.4        
    array("/room/update","roomId=0&x=1&y=1&name=a","{\"errno\":0}"),
    array("/room/update","","{\"errno\":1001}"),
    array("/room/update","roomId=0&y=1&name=a","{\"errno\":0}"),
    array("/room/update","roomId=0&x=1&name=a","{\"errno\":0}"),
    array("/room/update","roomId=0&x=1&y=1","{\"errno\":0}"),
    array("/room/update","x=1&y=1&name=a","{\"errno\":1001}"),
    array("/room/update","roomId=-1&x=1&y=1&name=a","{\"errno\":1002}"),

    //2.0
    array("/eleEqp/new","eleType=light","{\"errno\":0}"),
    array("/eleEqp/new","eleType=light","{\"errno\":0}"),
    array("/eleEqp/new","","{\"errno\":1001}"),
    array("/eleEqp/new","name=light","{\"errno\":1001}"),
    array("/eleEqp/new","eleType=pppp","{\"errno\":1002}"),
    //2.1
    array("/eleEqp/update","eid=1","{\"errno\":0}"),
    array("/eleEqp/update","","{\"errno\":1001}"),
    array("/eleEqp/update","id=1","{\"errno\":1001}"),
    array("/eleEqp/update","eid=-1","{\"errno\":1002}"),
    //2.2
    array("/eleEqp/del","eid=2","{\"errno\":0}"),
    array("/eleEqp/del","","{\"errno\":1001}"),
    array("/eleEqp/del","id=1","{\"errno\":1001}"),
    array("/eleEqp/del","eid=-1","{\"errno\":1002}"),
    //3.0
    array("/light/now","eid=1","{\"errno\":0}"),
    array("/light/now","","{\"errno\":1001}"),
    array("/light/now","id=-1","{\"errno\":1001}"),
    array("/light/now","eid=-1","{\"errno\":1002}"),
    //3.1
    array("/light/update","eid=1&lightUp=true","{\"errno\":0}"),
    array("/light/update","","{\"errno\":1001}"),
    array("/light/update","eid=1=true","{\"errno\":1001}"),
    array("/light/update","lightUp=true","{\"errno\":1001}"),
    array("/light/update","eid=-1&lightUp=true","{\"errno\":1002}"),
    array("/light/update","eid=1&lightUp=uck","{\"errno\":1002}"),
    );
    $testname=array(
        "1.0->add room","1.2->add nwe entryroom","1.2->delete room","1.3->look up room","1.4->update room",
        "2.0->create equipment","2.1->update equi-info","2.2->delete equipment",
        "3.0->look up light","3.1->update light status",
    );
    $nameposi=0;
    for($i=0;$i<count($testarray);$i++){
        if($i==0) echo "\n".$testname[$nameposi++].":\n";
        if($i>0&&strcmp($testarray[$i][0],$testarray[$i-1][0])!=0) echo "\n".$testname[$nameposi++].":\n";
        
        $e=new testExample($testarray[$i][0],$testarray[$i][1],$testarray[$i][2]);
        $e->exec_Example();
        if($e->error_compare()==1) echo "ok    ";
        else echo "error ";

        printf("example%d:%s\n",$i,$testarray[$i][1]);
        sleep(1);
    }
    
?>

<?php
    class testExample{
        public $url;
        public $testquery;
        public $expect;
        public $requestresult;
        function __construct($a,$b,$c) {
            $u="http://127.0.0.1:8360";
            $this->url=$u.$a;
            $this->testquery=$b;
            $this->expect=$c;
        }
        function exec_Example(){
            $this->requestresult=send_post($this->url,$this->testquery);

        }
        function error_compare(){
            $array1=json_decode($this->requestresult,true);
            $array2=json_decode($this->expect,true);
            //var_dump($array1);
            //var_dump($array2);
            //printf("array1error:%d array2error:%d\n",$array1['errno'],$array2['errno']);
            if($array1['errno']==$array2['errno']) return 1;
            else return $array2['errno'];
        }
        function str_compare(){
            $s1=$this->requestresult;
            $s2=$this->expect;
            $s1=str_replace(' ','',$s1);
            $s1=str_replace('\n','',$s1);
            $s2=str_replace(' ','',$s2);
            $s2=str_replace('\n','',$s2);
            echo $s1."\n";
            echo $s2;
            return strcasecmp($s1,$s2);
        }
    }
    function send_post($url, $post_string) {
        $opts = array(
            'http' => array(
              'method' => 'POST',
              'header' => 'Content-type:application/x-www-form-urlencoded',
              'content' => $post_string,
              'timeout' => 15 * 60
            )
          );
          
          $context = stream_context_create($opts);
          // Open the file using the HTTP headers set above
          //print_r( $opts);
          $file = file_get_contents($url, false, $context);
        return $file;
    }
    function content_check($str){
        $array=json_decode($str, true,512);
        //var_dump($array);
        if($array['errno']!=0) return $array['errno'];

        return 0 ;
    }

    function test_func($array,$url){
        $deter=true;
        for($i=0;$i<count($array);$i++){
            $content=send_post($url, $array[$i]);
            if(content_check($content)!=0) {$deter=false;break;}
        }
        return $deter;

    }

?>