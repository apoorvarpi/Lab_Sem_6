//-1 is null;
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int> > m;
map<int,int> Flist;
int total = 0;
int support,number = 1;
char *name;

struct node{
	int name;
	int count;
}arr[100];

bool matrix[100][100];

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
			number++;
		}
		i++;
	}
	return second;
}

void allot(map<int,int> x){
	map<int,int>::iterator i;
	i = x.end();
	i--;
	int k = number;
	while(true){
		m.push_back(make_pair(i->second,i->first));
		Flist[i->second] = k;
		k--;
		if(i==x.begin()){		
			break;
		}
		i--;
	}
}

void create_nodes(){
	string line;
	ifstream File(name);
	if (File.is_open()){
  	while(getline (File,line)){
   		total++;
     	set<int> s = processLine(line);
			set<int> elements;
			int count = 0;
			vector<int> set;
			while(!s.empty()){
     		int x=*s.begin();
     		s.erase(s.begin());
				if(Flist[x]>0)
					elements.insert(x);
				count++;
			}
			//sorting
   	}
   	File.close();
 	}
	else
		cout<<"Unable to open file"<<endl;
}

int main(){
	int supval = 30;
	string line;
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
	rev = reverse(init);
	allot(rev);
	cout<<"Frequency table:"<<endl;
	vector<pair<int,int> >::iterator j;
	j = m.begin();
	while(j!=m.end()){
		cout<<j->first<<"-"<<j->second<<endl;
		j++;
	}
	create_nodes();
	return 0;
}
