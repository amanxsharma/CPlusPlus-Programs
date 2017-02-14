//Create a decimal zip out of two numbers for eg.
//if A = 1234 and B = 98 then decimal zip = 192834


int solution(int A, int B) {
    // write your code in C++14 (g++ 6.2.0)
    int i=0, j=0,lenA,lenB; 
    int arrayA[100000000];
    int arrayB[100000000];
    int r,decimal_zip=0,mult_fact=1;

    while(A){
        r = A % 10;
        A = A / 10;
        arrayA[i] = r;
        i++;
    }
   
    while(B){
        r = B % 10;
        B = B / 10;
        arrayB[j] = r;
        j++;
    }
   //for(;i>=0;i--){
//cout<<arrayA[0]<<endl;
   //}
   
    
    lenA=i;
    lenB=j;

    if(lenA>=lenB){
        for(;j>=0;j--){
            decimal_zip = (decimal_zip*100) + (arrayA[i] * 10) + arrayB[j];
            //cout<<decimal_zip<<endl;
            //decimal_zip = decimal_zip * 100;
            i--;
        }
        for(;i>=0;i--){
            //cout<<decimal_zip<<endl;
            decimal_zip = (decimal_zip*10) + arrayA[i];
            
        }
    }
    
    if(lenA<lenB){
        for(;i>=0;i--){
            decimal_zip = (decimal_zip*100) + (arrayA[i] * 10) + arrayB[j];
            //cout<<decimal_zip;
            //decimal_zip = decimal_zip * 100;
            j--;
        }
        for(;j>=0;j--){
            decimal_zip = decimal_zip*10 + arrayB[j];
        }
    }
return decimal_zip;
    
}