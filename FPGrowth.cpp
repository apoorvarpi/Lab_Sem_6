#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > m;
int total = 0;
int support;

set<int> processLine(string s){
	set <int> mySet;
	int sum=0;
	for(int i=0;s[i]!='\0';i++){
		if(s[i]==' '){
			if(sum!=0)
				mySet.insert(sum);
			sum=0;
		}
		else sum=sum*10+(int)s[i]-(int)'0';
	}
	if(sum) mySet.insert(sum);
	return mySet;
}

map<int,int> reverse(map<int,int> first){
	map<int,int> second;
	map<int,int>::iterator i;
	i = first.begin();
	while(i!=first.end()){
		if(i->second >= support){
			second[i->second] = i->first;
		}
		i++;
	}
	return second;
}

void allot(map<int,int> x){
	map<int,int>::iterator i;
	i = x.end();
	i--;
	while(true){
		m.push_back(make_pair(i->second,i->first));	
		if(i==x.begin()){		
			break;
		}
		i--;
	}
}

int main(){
	int supval = 30;
	string line;
	char *name;
	map<int,int> init,rev;
	name = (char *)malloc(20*sizeof(char));
	cout<<"Enter the name of the file"<<endl;
	cin>>name;
	ifstream File(name);
	if (File.is_open()){
  	while(getline (File,line)){
   		total++;
     	set<int> s = processLine(line);
			while(!s.empty()){
     		int x=*s.begin();
     		s.erase(s.begin());
     		init[x]++;
			}
   	}
   	File.close();
 	}
	else
		cout<<"Unable to open file"<<endl;
	support = total*supval;
	support = support/100;
	cout<<"Total number of transactions = "<<total<<" support = "<<support<<" (30% of total)"<<endl;
	map<int,int>::iterator i;
	i = init.begin();
	while(i!=init.end()){
		if(i->second >= support){
			int x = 0;//dummy operation
		}
		i++;
	}
	rev = reverse(init);
	allot(rev);
	cout<<"Frequency table:"<<endl;
	vector<pair<int,int> >::iterator j;
	j = m.begin();
	while(j!=m.end()){
		cout<<j->first<<"-"<<j->second<<endl;
		j++;
	}
	return 0;
}
