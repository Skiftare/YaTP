function sinx(a){
    if(a == undefined){

        WSH.echo("|      e             f                                  ")
        WSH.echo("|     d  f          e i                                 ")
        WSH.echo("|    n     i       d   n                                ")
        WSH.echo("|   u       n     n     e                               ")
        WSH.echo("|            e   u       d                              ")
        WSH.echo("|             d                                         ")
        WSH.echo("+-------------------------------------------------------")
    }
    else{
        WSH.echo(Math.sin(x));
    }
}

function RLE_code_esc(s){
    res = "";
    n = s.length;
    now = s.charAt(0);
    cnt = 1;
    
    for(i = 1;i<n;i++){
        if(now == s.charAt(i)){
            cnt = cnt+1;
        }
        if(now != s.charAt(i) || i == n-1){
            if(now == '#'){
                while(cnt>0){
                    res = res+"#"+String.fromCharCode(Math.min(cnt, 255))+'#';
                    cnt-=255;
                }
                now = s.charAt(i);
                cnt = 1;
                
            }
            else{
                if(cnt-3<=0){
                    while(cnt>0){
                        res = res+now;
                        cnt=cnt-1;
                    }
                }
                else{
                    while(cnt>0){
                        res = res+"#"+(String.fromCharCode(Math.min(cnt-3, 255)))+now;
                        cnt = (cnt-3)-255;
                    }
                }
                now = s.charAt(i);
                cnt = 1;
            }
        }
    }
    return res;
}
function unpack(cnt, x){
    res = "";
    for(_=0;_<cnt;_++) res+=x;
    return res;
}
function RLE_decode_esc(s){
    res = "";
    i = 0;
    while(i<s.length){
        if(s.charAt(i) != '#') res = res+s.charAt(i);
        else{
            now = s.charAt(i+2);
            cnt = s.charAt(i+1);
            i = i+2;
            if(now == '#') res = res+unpack(cnt.charCodeAt(0),now);
            else res = res+unpack(cnt.charCodeAt(0)+3, now);
        }
        i = i+1;
    }
    return res;
}
function jump_code(s, flag){
    
}
function RLE_code_jump(s){
    //Чтож, будем вспоминать как это писать
    res = "" //Строка ответа
    buf = "";//Строка того, что будет кодироваться 0-флагом (без повтора)
    now = s.charAt(0) //Подозрительный символ, а вдруг он и следующий - одно и то же?
    cnt = 1;
    //
    n = s.length
    for(i = 1;i<s.length;i++){
        //WSH.echo(buf,i,s.charAt(i));
        if(now == s.charAt(i)){
            cnt+=1;
        }
        if(now != s.charAt(i) || i == n-1){
            //WSH.echo(buf)
            // Лень повторять код после выхода из цикла, поэтому заифаем конец строки
            if(cnt == 1 && i!= n-1){
                buf = buf+now;
                now = s.charAt(i);
                //WSH.echo(now)
                //В случае, если дублирования нет просто закидываем символ в 0-флаг строку
            }
          
            else{
                if(i == n-1 && cnt == 1){
                    cnt = 0;
                    buf+=now
                }
                //Так. Тут мы должны сначала всё-таки закодировать 0-флаг, а потом ещё и 1-флагом закодировать повторения
                //Заметим, что у нас не может быть длины 0. А это значит, что можем вычитать 1 при кодировании и прибавлять при декодировании
                //Но сначала всё-таки проверим, что нам хоть есть что кодить
                //WSH.echo(buf)
                if(buf != ""){
                    //WSH.echo(buf);
                    l = buf.length
                    f = 0
                    while(l>0){
                        res = res+String.fromCharCode(128+Math.min(128, l)-1);
                        res=res+buf.slice(f*128, f*128+Math.min(128,l)+1);
                        l-= Math.min(128,l);
                        f+=1;
                    }
                    buf = "";
                    
                }
                while(cnt){
                    res = res+String.fromCharCode(Math.min(128,cnt)-1)+ now;
                    cnt-=Math.min(128,cnt);
                }
                now = s.charAt(i);
                cnt = 1;
            }
        }
    }
    return res;
}
function RLE_decode_jump(s){
    i = 0;
    res = ""
    while(i<s.length){
        flag_check = (s.charAt(i)).charCodeAt(0);
        //WSH.echo(flag_check)
        if(flag_check>=128){
            //Повторение
            flag_check-=127;
            for(j = 0;j<flag_check;j++){
                res+=s.charAt(i+j+1);
            }
            i = i+1+flag_check;
        }
        else{
            flag_check+=1;
            for(j = 0;j<flag_check;j++) {
                res+=s.charAt(i+1);
            }
            i = i+2
        }
    }
    return res;
}
s = "absxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx#12345nnnxyzzzzz#########################################"
//WSH.echo(s)
//WSH.echo(RLE_code_jump(s))
//WSH.echo(RLE_decode_jump(RLE_code_jump(s)))
//WSH.echo(RLE_code_esc(s))
//WSH.echo(RLE_decode_esc(RLE_code_esc(s)))
if(s == RLE_decode_jump(RLE_code_jump(s))){
    WSH.echo("WIN_jump")
}
if(s == RLE_decode_esc(RLE_code_esc(s))){
    WSH.echo("WIN_esc")
}
