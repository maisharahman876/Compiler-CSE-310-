//if else 
int max(int a,int b)
{
	if(a>=b)
	return a;
	else
	return b;
}
int main(){
	int a,c,i,j,d,e[4] ; 
	j=0;
	c=(2&&3)*6; //c=6
	i=10;
	if(c>(i%3))
	j=15;
	if((c==6)&&(i!=10))
	j=2;
	else
	j++;
	a=max(c,j);
	printf(a);
	return 0;
}

