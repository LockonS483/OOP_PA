#include "std_lib_facilities.h"

int main(){
	vector<string> v;

	//Input
	cout << "Type in words: " << endl;
	for(string temp; cin >> temp; ){
		v.push_back(temp);
	}

	for(string s : v){
		cout << s << " ";
	}
	cout << endl;

	sort(v);
	int i=0;
	string prev = v[i];
	int count = 0;
	while(i<v.size()){
		if(v[i] == prev){
			count++;
		}else{
			cout << prev << ": " << count << endl;
			count=1;
			prev=v[i];
		}
		i++;
	}
	cout << prev << ": " << count << endl;

	return 0;
}