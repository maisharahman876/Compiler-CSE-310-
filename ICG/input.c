int main(){
    int a,b,c[3];
    a=1*(2+3)%3; //a=2
    b= 1<5;		//b=1
    c[0]=2;
    if(a && b)
        c[0]++;
    else
        c[1]=c[0]; //c[1]=2
    printf(a);
    printf(b);
}