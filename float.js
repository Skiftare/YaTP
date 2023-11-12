function count(ss, needToCnt){
    sum = 0;
    for(i = 0;i<ss.length;i++){
        if(ss.charAt(i) == needToCnt){
            sum++;
        }
    }
    return sum;
}
function createFloat(aa){
    a = aa;
    ans = [];
    for(i = 0;i<23;i++){
        ans[i] = 0;
    }
    if(typeof(a) != "number"){
        WSH.echo("income isnt number")
        for(i = 0;i<8;i++){
            ans[i+1] = 1;
        }
        ans[20] = 1;
    }
    if(isNaN(a)){
        WSH.echo("income is +- NaN")
        if(a<0){
            ans[0] = 1;
        }
        for(i = 0;i<8;i++){
            ans[i+1] = 1;
        }
        ans[20] = 1;
    }
    if(a == Infinity){
        WSH.echo("income is +inf")
        for(i = 0;i<8;i++){
            ans[i+1] = 1;
        }
        return ans;
    }
    if(a == -Infinity){
        ans[0] = 1;
        WSH.echo("income is -inf")
        for(i = 0;i<8;i++){
            ans[i+1] = 1;
        }
        return ans;
    }
    if(a < 0){
        ans[0] = 1;
        a*=-1;
    }
    else if(a>0){
        ans[0] = 0;
    }
    integerPart = Number(String(a).split('.')[0])
    floatPart = Number('0.' + String(a).split('.')[1])
    bitsOfIntegerPart = (integerPart >>> 0).toString(2);
    tempPointer = bitsOfIntegerPart.length - 1;
    p = 0;
    if(bitsOfIntegerPart != "0"){
        bitsOfFloatPart = "";
        while(tempPointer != 0){
            bitsOfFloatPart = bitsOfIntegerPart.charAt(tempPointer)+bitsOfFloatPart;
            tempPointer--;
            p++;
        }
        while (floatPart > 0 && bitsOfFloatPart.length < 24) {
            floatPart *= 2;
            bit = Math.floor(floatPart);
            bitsOfFloatPart += bit;
            floatPart -= bit;
        }
        while(bitsOfFloatPart.length < 24){
            bitsOfFloatPart += "0"
        }
    }
    else{
        flag = false;
        while(floatPart > 0 && bitsOfFloatPart.length < 24){
            floatPart *= 2;
            bit = Math.floor(floatPart);
            floatPart -= bit;
            if(bit == 1 || flag){
                if(flag){
                    bitsOfFloatPart += bit;
                }
                flag = true;
            }
            else{
                p--;
            }
        }
        while(bitsOfFloatPart.length < 24){
            bitsOfFloatPart += "0"
        }
    }
    p+=127;
    if(p <= 0 || p>= 255){
        if(p<= 0){
            return ans;
        }
        for(i = 0;i<8;i++){
            ans[i+1] = 1;
        }
        return ans;
    }
    bitsOfP = (p >>> 0).toString(2);
    while(bitsOfP.length < 8){
        bitsOfP = "0" + bitsOfP;
    }
    for(i = 0;i<8;i++){
        ans[i+1] = bitsOfP.charCodeAt(i) - 48;
    }
    for(i = 0;i<23;i++){
        ans[i+9] = bitsOfFloatPart.charCodeAt(i) - 48;
    }
    return ans; 
}
function parseFloat(mas){
    sign = Math.pow(-1, mas[0]);
    p = 0;
    for(i = 0;i<8;i++){
        p = p + mas[i+1]*(Math.pow(2, 7-i));
    }
    p-=127;
    mantiss = 1;
    for(i = 0;i<23;i++){
        mantiss+=mas[i+9]*(Math.pow(2, -i-1));
    }
    return sign * mantiss * Math.pow(2, p);
}
function sumFloats(float1, float2){
    sign1 = float1[0];
    sign2 = float2[0];
    exponent1 = parseInt(float1.slice(1, 9).join(''), 2);
    exponent2 = parseInt(float2.slice(1, 9).join(''), 2);
    mantissa1 = '1' + float1.slice(9).join('');
    mantissa2 = '1' + float2.slice(9).join('');
    result = [];
    for(i = 0;i<32;i++){
        result[i] = 0;
    }
    if(count(mantissa1,'1') >= 2 && exponent1 == 255 ){
        return float1;
    }
    if(count(mantissa2,'1') >= 2 && exponent2 == 255 ){
        return float2;
    }
    if(count(mantissa1,'1') == 1 && exponent1 == 255){
        if(count(mantissa2,'1') == 1 && exponent2 == 255 && sign1 != sign2){
            float1[20] = 1;
        }
        return float1;
    }
    if(count(mantissa2,'1') == 1 && exponent2 == 255){
        if(count(mantissa1,'1') == 1 && exponent1 == 255 && sign1 != sign2){
            float2[20] = 1;
        }
        return float2;
    }
    if(sign1 != sign2){
        if(sign1 == 0){
            return sumFloats(float2, float1);
        }
        if(exponent1 < exponent2){
            while(exponent1 != exponent2){
                exponent1++;
                mantissa1= '0'+ mantissa1;
            }
        }
        if(exponent1 > exponent2){
            while(exponent1 != exponent2){
                exponent2++;
                mantissa2 = '0' + mantissa2
                
            }
        }
        for(i = 0;i<24;i++){
            if(mantissa1.charAt(i) == '1' && mantissa2.charAt(i) == '0'){
                float1[0] = 0;
                float2[0] = 1;
                res = sumFloats(float2, float1);
                res[0]^= 1;
                return res;
            }
            else if(mantissa1.charAt(i) == '0' && mantissa2.charAt(i) == '1'){
                break;
            }
        }
        mind = 0;
        resultMantiss = "";
        for(i = 23;i>=0;i--){
            d1 = mantissa1.charCodeAt(i) - 48;
            d2 = mantissa2.charCodeAt(i) - 48;
            subs = d2-d1+mind;
            if (subs >= 0) {
                resultMantiss = subs.toString() + resultMantiss;
                mind = 0;
            } else {
                resultMantiss = (subs + 2).toString() + resultMantiss;
                mind = -1;
            }
        }
        if(mind == -1){
            resultMantiss = '1'+resultMantiss;
            result[0] = 1;
            
        }
        clearMantiss = "";
        flag = false;
        for(i = 0;i<resultMantiss.length;i++){
            if(resultMantiss.charAt(i) == '1' || flag){
                if(flag){
                    clearMantiss = clearMantiss+resultMantiss.charAt(i);
                }
                flag = true;
            }
            else{
                exponent1--;
            }
        }
        while(clearMantiss.length<24){
            clearMantiss = clearMantiss+'0';
        }
        bitsOfExponent = (exponent1 >>> 0).toString(2);
        while(bitsOfExponent.length < 8){
            bitsOfExponent = "0" + bitsOfExponent;
        }
        for(i = 0;i<8;i++){
            result[i+1] = bitsOfExponent.charCodeAt(i) - 48;
        }
        for(i = 0;i<23;i++){
            result[i+9] = clearMantiss.charCodeAt(i) - 48;
        }
        return result;
    }
    else{
        flag = true;
        //Выравниваем степени
        if(exponent1 < exponent2){
            while(exponent1 != exponent2){
                exponent1++;
                mantissa1= '0'+ mantissa1;
            }
        }
        if(exponent1 > exponent2){
            while(exponent1 != exponent2){
                exponent2++;
                mantissa2 = '0' + mantissa2
            }
        }
        resultMantiss = "";
        mind = 0;
        for(i = 23;i>=0;i--){
            if(mantissa1.charCodeAt(i) - 48 + mantissa2.charCodeAt(i)- 48+ mind >= 2){
                resultMantiss = ((mantissa1.charCodeAt(i) - 48 + mantissa2.charCodeAt(i)- 48+ mind)%2).toString() + resultMantiss;
                mind = 1;
            }
            else{
                resultMantiss = ((mantissa1.charCodeAt(i) - 48 + mantissa2.charCodeAt(i)- 48+ mind)%2).toString() + resultMantiss
                mind = 0;
            }
        }
        if(mind == 1){
            resultMantiss = '1'+resultMantiss
        }
        clearMantiss = "";
        flag = false;
        for(i = 0;i<resultMantiss.length;i++){
            if(resultMantiss.charAt(i) == '1' || flag){
                if(flag){
                    clearMantiss = clearMantiss+resultMantiss.charAt(i);
                }
                flag = true;
            }
            else{
                exponent--;
            }
        }
        while(clearMantiss.length<24){
            clearMantiss = clearMantiss+'0';
        }
        
        bitsOfExponent = (exponent1 >>> 0).toString(2);
        result[0] = sign1;
        while(bitsOfExponent.length < 8){
            bitsOfExponent = "0" + bitsOfExponent;
        }
        for(i = 0;i<8;i++){
            result[i+1] = bitsOfExponent.charCodeAt(i) - 48;
        }
        for(i = 0;i<23;i++){
            result[i+9] = clearMantiss.charCodeAt(i) - 48;
        }
        return result;
        
    }
}
q = (sumFloats(createFloat(-146.34), createFloat(4.25)))
WSH.echo(parseFloat(q))
WSH.echo(q)
WSH.echo(createFloat(-142.09))
