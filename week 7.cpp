#include<iostream>

using namespace std;

int row,colum;

void set_position(char *ch,int a,int b){
	if(a==1||b==1||a==row||b==colum){
		*ch='X';
	}
	else if((a+b)%2==0){
		*ch='*';
	}
	else if((a+b)%2==1){
		*ch='+';
	}
}

void Draw(char *ch){
	cout<<*ch;
}

int main(){
	
	cout<<"Input Row : ";
	cin>>row;
	cout<<"Input Colum : ";
	cin>>colum;
	
	char array[row][colum];
	
	for(int i=1;i<=row;i++){
		for(int j=1;j<=colum;j++){
			set_position(&array[i][j],i,j);
		}
	}
	
	for(int i=1;i<=row;i++){
		for(int j=1;j<=colum;j++){
			Draw(&array[i][j]);
		}
		cout<<endl;
	}
	
	return 0;
}
