#include<bits/stdc++.h>
using namespace std;

struct Item{
	int p,wt;
};

int n=4,m=5;
int P[5][6];
Item a[4];
int x[4]={0};

bool cmp(Item x, Item y){
	return x.p>y.p;
}

int chk(int maxprofit,int i){
	for(int j=m;j>=0;j--){ 
		if(P[i][j]==maxprofit) 
			return 0;
		}
	return 1;	
}

void solution(){
	int maxprofit=P[n][m],i=n;
    	while(i>=0 && maxprofit>0){
		if(chk(maxprofit,i)==1){  
			cout<<"\nConsidering item "<<i+1<<" with profit "<<a[i].p<<endl;
			maxprofit-=a[i].p;
			x[++i]=1;
		}
		i--;
	}
}
double knapsack(){
	for (int i=0;i<=n;i++){
    	for (int w=0;w<=m;w++){
       		if (i==0 || w==0)  
				P[i][w] = 0; 
       		else if (a[i-1].wt<=w)  
			   P[i][w] = max((P[i-1][w]) ,(P[i-1][w-a[i-1].wt] + a[i-1].p )); 
        	else 
				P[i][w] = P[i-1][w]; 
		}
	}
	solution() ;  
 	cout<<"\nSolution matrix is ";
 	for(int i=1;i<=n;i++) 
		cout<<x[i]<<" ";
 	cout<<"\nMax profit is "<<P[n][m];
}

int main(){
	cout<<"Enter Weight and profit:\n";
	for(int i=0;i<n;i++){
		cout<<"Enter Weight and profit of item: "<<i+1<<"   ";
		cin>>a[i].wt>>a[i].p;	
	}
	knapsack();
}
