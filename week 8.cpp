#include<iostream>
#include<stdio.h>

using namespace std;

char input[100];
char ch[100];
int num[100]={0};

void check_num(int count){
	int i=0;
	while(input[i]!='\0'){
		for(int j=0;j<count;j++){
			if(input[i]==ch[j]){
				num[j]++;
				break;
			}
		}
		i++;
	}
}

void put_ch(char input[100],int *count){
	bool pass=false;
	int i=0;
	while(input[i]!='\0'){
		for(int j=0;j<*count;j++){
			if(input[i]==ch[j]){
				pass=true;
				break;
			}
		}
		
		if(pass==false){
			ch[*count]=input[i];
			*count+=1;
		}
		
		pass=false;
		i++;
	}
	check_num(*count);
}

void print(char input[100],int *count){
	cout<<"\nString : \""<<input<<"\" : "<<endl<<endl;
	for(int i=0;i<*count;i++){
		cout<<"  \'"<<ch[i]<<"\' -> "<<num[i]<<" charater"<<endl;
	}
}

int main(){
	int count=0;
	
	cout<<"INPUT STRING : ";
	scanf("%[^\n]s",&input);
	
	put_ch(input,&count);
	
	print(input,&count);
	
	return 0;
}
