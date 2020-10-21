#include<iostream>
#include<string>

using namespace std;

int output[100];

void OUTPUT(int *x){
	cout<<" Final Out : ";
	if(*x>0){
		for(int i=*x-1;i>=0;i--){
		    cout<<output[i];
	    }
	}
}

void calculation(int *x,int limit){
	bool pass=false;
	while(pass!=true){
		int count=0,space=0,Again=0;
		string input="\0";
		cout<<"Input String : ";
		if(*x==0){
			cin.ignore();
		}

		getline(cin,input);
		while(input[count]!='\0'){
			if(input[count]==input[count+1]&&input[count]!=' '){
				Again++;
			}
			if(input[count]!=input[count+1]&&input[count]==input[count-1]&&input[count]!=' '){
				Again++;
			}
			
			count++;
			while(input[count]==' '){
				count++;
				space++;
			}
		}
		
		cout<<"\nCount String : "<<count-space;
		cout<<"\nCount Space : "<<space;
		if(Again>1){
			cout<<"\nCount Again Character : "<<Again;
		}
		else{
			cout<<"\nDon't have Again Character ";
		}

		
		cout<<"\n\n";
		
		if(Again>limit){
			pass=true;
		}
		else{
			cout<<"- Input Again -\n";
		}
		
		output[*x]=Again;
		*x+=1;
	}
}

int main(){
	int limit,x=0;
	cout<<"Input Limit Again Character : ";
	cin>>limit;
	
	calculation(&x,limit);
	
	OUTPUT(&x);
	
	return 0;
}
