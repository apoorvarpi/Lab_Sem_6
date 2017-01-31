#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct state{
	char val;
	int left,right;
	bool binary;
	bool nullable;
	vector<char> firstpos,lastpos;
};

int main(){
	cout<<"Enter number of elements in alphabet"<<endl;
	int n;
	cin>>n;
	cout<<"Enter the regular expression ending with '#'"<<endl;
	vector<char> s;
	char ch,last='.';
	while(1){
		cin>>ch;
		if((ch=='a'||ch=='b')&&(last=='a'||last=='b'))
			s.push_back('.'); //Dummy variable for conactenation
		if(ch=='#')
			break;
		s.push_back(ch);
		if(ch=='*')
			s.push_back('@');
		last=ch;
	}
	n = s.size();
	//Building a prefix expression
	
	//Contructing the tree using shunting yard algorithm
	
	return 0;
}
	
