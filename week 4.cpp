#include<iostream>

using namespace std;

bool prime_number(int *input){
	bool check_out,check_prime;
	int number=*input,count_prime=0,sum=0;
	while(number>1){
		check_out=false;
		check_prime=false;
		for(int i=2;i<=number;i++){
			if(i>=4){
				for(int j=2;j<=i/2;j++){
					
					if(i%j==0){
						check_prime=true;
						break;
					}
					else{
						if(number%i==0){
						   cout<<i<<" ";
						   count_prime++;
						   sum+=i;
					       number/=i;
						   check_out=true;
						   break;
				        }   
					}
				}
			}
			else{
				if(check_prime!=true&&number%i==0){
					cout<<i<<" ";
					count_prime++;
					sum+=i;
					number/=i;
					check_out=true;
					break;
				}
			}
			if(check_out==true){
				break;
			}
		}
	}
	
	cout<<endl<<"Sum = "<<sum<<endl;
	
	if(count_prime%2==0&&sum%2==0){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	bool pass=false;
	int keep[100];
	int input,count=0;
	while(pass!=true){
		cout<<"Input Number : ";
		cin>>input;
		if(input<2){
			cout<<"Out Of Range !\n";
		}
		else{
		   pass=prime_number(&input);
		}
		
		keep[count]=input;
		
		count++;
	}
	cout<<endl;
	for(int i=0;i<count;i++){
		cout<<keep[i]<<" ";
	}
}
