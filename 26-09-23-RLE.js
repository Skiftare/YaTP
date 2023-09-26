function RLE_code(s){
    ans = "";
    cnt = 1;
    now = s.charAt(0);
    for(i = 1;i<s.length;i++){
        if(now == s.charAt(i)){
            cnt+=1;
        }
        else{
            ans = ans + "#("+cnt.toString()+")"+now;
            cnt = 1;
            now = s.charAt(i);
        }
    }
    ans +="#("+cnt.toString()+")"+now;
    return ans;
}
function unpack(i, c){
    ans = "";
    for(j = 0;j<i;j++) ans+=c;
    return ans;
}
function RLE_decode(s){
    ans = "";
    flag_open_sk = 0;
    flag_close_sk = 0;
    need_to = "";
    n = 0;
    for(i = 1;i<s.length;i++){
        if(s.charAt(i) == '('){
            flag_open_sk = 1;
        }
        else if(flag_open_sk && s.charAt(i) != ')')
            n = n*10+((s.charAt(i) - '0'));
            
        
        if(s.charAt(i) == ')'){
            need_to = s.charAt(i+1);
            i++;
            ans=ans+unpack(n,need_to)
            flag_open_sk = 0
            n = 0
        }
    }
    return ans;
}
