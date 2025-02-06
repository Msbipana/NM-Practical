#include<stdio.h>
#include<conio.h>
int main(){
	float v=0,p,xv,x[10],fx[10],a[10];
	int n,i,j;
	printf("Input number of data:\n");
	scanf("%d",&n);
	printf("Enter value at x:\n");
	scanf("%f",&xv);
	for(i=0;i<n;i++){
		printf("Enter value at x and fx at i=%d\n",i);
		scanf("%f%f",&x[i],&fx[i]);
	}
	for(i=0;i<n;i++)
	   a[i]=fx[i];
	for(i=0;i<n;i++){
	    for(j=n-1;j>i;j--)
			a[j]=(a[j]-a[j-1])/(x[j]-x[j-1-i]);
	}
	v=0;
    for(i=0;i<n;i++){
    	p=1;
    	for(j=0;j<i-1;j++)
    	   p=p*(xv-x[j]);
    	   v=v+a[i]*p;
	}
	printf("Interpolated value=%f",v);
	getch();
	return 0;
}
