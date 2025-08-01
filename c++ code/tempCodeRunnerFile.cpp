int adjacentRob(vector<int> &houses,int s,int e){
    if(s>e){
        return 0;
    }
    //recurisve call
    int option1=houses[s]+adjacentRob(houses, s+2,e);
    int option2=0+adjacentRob(houses,s+1,e);
    int ans=max(option1,option2);
    return ans;
}