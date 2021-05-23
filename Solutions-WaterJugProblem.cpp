#include <bits/stdc++.h>
using namespace std;
class nodes{
	public: 
		pair<int,int> pairStates;
//		int first;
//		int second;
		string stringPairStates;
};

//state1 and state2 parameter values are coming from the main method
string makestring(int state1,int state2){
	std::stringstream out1;
	std::stringstream out2;
	string state1String,state2String,fullStateString;
    out1 << state1;
    state1String = out1.str();
    out2 << state2;
    state2String = out2.str();
    fullStateString = "("+state1String+","+state2String+")";
    return fullStateString;
}
int main()
{
    ios::sync_with_stdio(false);
    
    //pair<int,int> cap,ini,final;
    nodes capacity,initial,final;
    //Input initial states
    initial.pairStates.first=0,initial.pairStates.second=0;
    initial.stringPairStates = makestring(initial.pairStates.first,initial.pairStates.second);
    //Input the capacities of two jugs
    cout<<"Enter the capacities of 2 jugs\n";
    cin>>capacity.pairStates.first>>capacity.pairStates.second;
    //input goal state
    cout<<"Enter the required water Volumes of 2 jugs\n";
    cin>>final.pairStates.first>>final.pairStates.second;
    //Using BFS to find all possible solutions
    queue<nodes> basicQueue;
    basicQueue.push(initial);
    nodes jug;
    while(!basicQueue.empty()){
    	//Base case
    	jug = basicQueue.front();
    	if(jug.pairStates.first == final.pairStates.first && jug.pairStates.second == final.pairStates.second){
    		cout<<jug.stringPairStates<<endl;
	  		return 0;
    	}
    	nodes temp = jug;
    	//Fill 1st Jug
    	if(jug.pairStates.first<capacity.pairStates.first){
			temp.pairStates = make_pair(capacity.pairStates.first,jug.pairStates.second);
			temp.stringPairStates = jug.stringPairStates + makestring(temp.pairStates.first,temp.pairStates.second);
			basicQueue.push(temp);
    	}
    	//Fill 2nd Jug
    	if(jug.pairStates.second<capacity.pairStates.second){
			temp.pairStates = make_pair(jug.pairStates.first,capacity.pairStates.second);
			temp.stringPairStates = jug.stringPairStates + makestring(temp.pairStates.first,temp.pairStates.second);
			basicQueue.push(temp);
    	}
    	//Empty 1st Jug
    	if(jug.pairStates.first>0){
			temp.pairStates = make_pair(0,jug.pairStates.second);
			temp.stringPairStates = jug.stringPairStates + makestring(temp.pairStates.first,temp.pairStates.second);
			basicQueue.push(temp);
    	}
    	//Empty 2nd Jug
    	if(jug.pairStates.second>0){
			temp.pairStates = make_pair(jug.pairStates.first,0);
			temp.stringPairStates = jug.stringPairStates + makestring(temp.pairStates.first,temp.pairStates.second);
			basicQueue.push(temp);
    	}
    	//Pour from 1st jug to 2nd until its full
    	if(jug.pairStates.first>0 && (jug.pairStates.first+jug.pairStates.second)>=capacity.pairStates.second){
    		temp.pairStates = make_pair((jug.pairStates.first-(capacity.pairStates.second-jug.pairStates.second)),capacity.pairStates.second);
    		temp.stringPairStates = jug.stringPairStates + makestring(temp.pairStates.first,temp.pairStates.second);
    		basicQueue.push(temp);
    	}
    	//Pour from 2nd jug to 1st until its full
    	if(jug.pairStates.second>0 && (jug.pairStates.first+jug.pairStates.second)>=capacity.pairStates.first){
    		temp.pairStates = make_pair(capacity.pairStates.first,(jug.pairStates.second-(capacity.pairStates.first-jug.pairStates.first)));
    		temp.stringPairStates = jug.stringPairStates + makestring(temp.pairStates.first,temp.pairStates.second);
    		basicQueue.push(temp);
    	}
    	//Pour all water from 1st to 2nd
    	if(jug.pairStates.first>0 && (jug.pairStates.first+jug.pairStates.second)<=capacity.pairStates.second){
    		temp.pairStates = make_pair(0,jug.pairStates.first+jug.pairStates.second);
    		temp.stringPairStates = jug.stringPairStates + makestring(temp.pairStates.first,temp.pairStates.second);
    		basicQueue.push(temp);
    	}
    	//Pour from 2nd jug to 1st until its full
    	if(jug.pairStates.second>0 && (jug.pairStates.first+jug.pairStates.second)<=capacity.pairStates.first){
    		temp.pairStates = make_pair(jug.pairStates.first+jug.pairStates.second,0);
    		temp.stringPairStates = jug.stringPairStates + makestring(temp.pairStates.first,temp.pairStates.second);
    		basicQueue.push(temp);
    	}
    	basicQueue.pop();
    }
	return 0;
}
