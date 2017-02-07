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
	cout<<"Enter the regular expression ending with '#' with aplhabet size 2 (a,b)"<<endl;
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
			s.push_back('@');//dummy variable for star
		last=ch;
	}
	n = s.size();
	//Building a prefix expression
	s.push_back('(');
	stack<char> A;
	vector<char> prefix;
	A.push(')');
	for(int i=0;i<=n;i++){
		ch=s[i];
		if(ch=='a'||ch=='b')
			prefix.push_back(ch);
		else if(ch!='#')
			A.push(ch);
	}
	for(int i=0;i<prefix.size();i++)
		cout<<prefix[i];
	cout<<endl;
	//Contructing the tree using shunting yard algorithm
	                                         
	return 0;
}
	
