#include<iostream>
#include<stdio.h>

using namespace std;

int count_array(char input[100]){
	int count,de=0;
	while(input[count]!='\0'){
		count++;
		if(input[count]==' '){
			count++;
			de++;
		}
	}	
	count-=de;	
	
	cout<<"number string = "<<count<<"\n";
	return count;
}

void triangle(int *count){
    for(int i=0;i<*count;i++){
		for(int j=0;j<*count-i-1;j++){
			cout<<" ";
		}
		for(int k=0;k<=i;k++){
			if(k==0||k==i||i==*count-1){
				cout<<i+1; 
			}
			else{
				cout<<" ";
			}

		}
		cout<<"\n";
	}
}

void Area(int *count){
	float area;
	area=0.5**count**count;
	printf("\nArea = %.2f\n",area);
}

int main(){
	int count;
	char input[100];
	cout<<"Input String : ";
	scanf("%[^\n]s",&input);
	
	count=count_array(input);
	
	triangle(&count);
	
	Area(&count);
	
	return 0;	
}
