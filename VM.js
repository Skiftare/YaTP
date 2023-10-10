
function VM(){
    mas = [];
    for(i = 0;i<100;i++){
        mas[i] = 0;
    
    }
    //Это факториал и он работает
    //var program = ", [->+>+<<]>>[-<<+>>]< [->+>+<<]>>[-<<+>>]<< >>+!<!<<[->>[>[->+>+<<]>>[-<<+>>]<<<-] <[-]<>>>[-]> [-<+>] <<<<  [->+>+<<]>>[-<<+>>]<<>[->+<]<] >>>.";
    
    //Это gcd и он работает
    var program = ",>>>>>,[<<<<<? Начинаем вычитать >>>>>[-<+<+>>]<<[->>+<<] > [-<<<<->>>>] <<<<! >>>>>[-<+<+>>]<<[->>+<<] > [-<<<<+>>>>] >[-<+>]<<<<<[->>>>>+<<<<<]>>>>[-<<<<+>>>>]>]<<<<<."
    //f.close();
    p = 0; 
    for(i = 0;i<program.length;i++){
        c = program.charAt(i);
        if(c == ',') {
        mas[p] = WScript.StdIn.ReadLine();

        }
        if(c == '.') {WSH.echo(mas[p])}
        if(c == '-') {mas[p] -=1;}
        if(c == '+') {mas[p] +=1;}
        if(c == '<'){
        if(p>0) p-=1;
        else WSH.echo("memory error", i, program.charAt(i-1),program.charAt(i+1) )
    }
        if(c == '>') p+=1;
        if(c == ']'){
        
        if(mas[p] != 0){
            met_open = 0;
            
            while(1){
                i-=1;
                if(i<0){
                    WSH.eco(-1);
                    break;
                }
                else{
                    if(program.charAt(i) == '[') met_open-=1;
                    if(program.charAt(i) == ']') met_open+=1;
                }
                if(met_open<0) break;
                
            }
            
        }
    }
        if(c == '['){

            if(mas[p] == 0){
                met_open = 0;
                while(1){
                    i+=1;
                    if(program.charAt(i) == '[') met_open+=1;
                    if(program.charAt(i) == ']') met_open-=1;
                    if(met_open<0) break;

                }

            }

        }
        if(c == '?') {
            if(mas[p] < 0){
                met_open = 0;
                while(1){
                    i+=1;
                    if(program.charAt(i) == '!') met_open-=1;
                    if(program.charAt(i) == '?') met_open+=1;

                    if(met_open<0) break;

                }
            }
        }
        if(c == '!'){
            if(mas[p]>=0){
                met_open = 0;
                while(1){
                    i-=1;
                    if(program.charAt(i) == '!') met_open+=1;
                    if(program.charAt(i) == '?') met_open-=1;
                    if(met_open<0) break;
                }
            }
        }
        if(  c == ';'){
            WSH.echo(mas)
            WSH.echo(p)
        }
    }
    
}
