#include<stdio.h>
#include<conio.h>
int fact(int n){
	if(n==1)
	  return 1;
	else
	   return (n*fact(n-1));
}
int main(){
	float v=0,p,xp,x[10],fx[10],fd[10],h,s;
	int n,i,j,k;
	printf("Enter number of point:\n");
	scanf("%d",&n);
	printf("Enter value at which interpolated value is needed:\n");
	scanf("%f",&xp);
	for(i=0;i<n;i++){
		printf("Enter value at x and fx at i=%d\n",i);
		scanf("%f%f",&x[i],&fx[i]);
	}
	h=x[1]-x[0];
	s=(xp-x[0])/h;
	for(i=0;i<n;i++){
	   fd[i]=fx[i];
    }
	for(i=0;i<n;i++){
	    for(j=n-1;j>i;j--){
		   fd[j]=(fd[j]-fd[j-1]);
	    } 
	}
	v=fd[0];
    for(i=0;i<n;i++){
    	p=1;
    	for(k=1;k<=i;k++){
		  p=p*(s-k+1);
        } 
        v=v+(fd[i]*p)/fact(i);
	}
	printf("Interpolated value=%f",v);
	getch();
	return 0;
}
