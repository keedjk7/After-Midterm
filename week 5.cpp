#include<iostream>

using namespace std;

char input[100];

void RUN(int *count,int *number,int *character,int *upper,int *smaller,int *space ,int *special){
	//cout<<input;
	while(input[*count]!='\0'){
		
		if(input[*count]>='0'&&input[*count]<='9'){
			*number+=1;
		}
		else if((input[*count]>='a'&&input[*count]<='z')||(input[*count]>='A'&&input[*count]<='Z')){
			*character+=1;
			if(input[*count]>='a'&&input[*count]<='z'){
				*smaller+=1;
			}
			else{
				*upper+=1;
			}
		}
		else if(input[*count]==' '){
			*space+=1;
		}
		else{
			*special+=1;
		}
		*count+=1;
	}
	
}

int OUTPUT(int *count,int *number,int *character,int *upper,int *smaller,int *space ,int *special){
	cout<<"Count String           : "<<*count<<endl;
	cout<<"Count Number String    : "<<*number<<endl;
	cout<<"Count Character        : "<<*character<<endl;
	cout<<"  - Smaller : "<<*smaller<<endl;
	cout<<"  - Upper   : "<<*upper<<endl;
	cout<<"Count Space            : "<<*space<<endl;
	cout<<"Count Special Charcter : "<<*special<<endl;
}

int main(){
	
	cout<<"INPUT : ";
	cin.getline(input,100);
	
	int count=0,number=0,character=0,smaller=0,upper=0,special=0,space=0;
	
	RUN(&count,&number,&character,&upper,&smaller,&space,&special);
	
	OUTPUT(&count,&number,&character,&upper,&smaller,&space,&special);
	
}
