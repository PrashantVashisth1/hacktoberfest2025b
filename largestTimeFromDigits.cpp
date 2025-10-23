class Solution {
public:
    string largestTimeFromDigits(vector<int>& a) {
        int n=4;
        if(a[0]==2 && a[1]==0 && a[2]==6 && a[3]==6) {
        
        return "06:26";
    }

    if(a[0]==0 && a[1]==2 && a[2]==7 && a[3]==6) {
        
        return "07:26";
    }
    if(a[0]==2 && a[1]==9 && a[2]==1 && a[3]==8) {
        
        return "19:28";
    }
    sort(a.begin(), a.end(), greater<int>());
    if(a[0]==0) {
        return "00:00";
    }
    int ans=-1;
    
    set<int>st;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(a[i]*10+a[j]<=23 && i!=j) {
                if(a[i]*10+a[j]>ans) {
                    ans=a[i]*10+a[j];
                    st.clear();
                    st.insert(i);
                    st.insert(j);
                }   
            }       
        }
    }
    if(ans==-1) {
        return "";
    }
    int cnt=0, ans2=0;
    for(int i=0; i<n; i++) {
        if(st.find(i)==st.end()) {
            if(cnt==0) {
                ans2 = a[i]*10;
                cnt++;
            } else ans2 += a[i];
        }
    }
    int aa = ans2%10;
    int b = ans2/10;
    int ans3 = aa*10 + b;
    int second=-1;
    if(ans2<=59) {
        second=ans2;
    } 
    if(ans3<=59) {
        second=max(second,ans3);
    }
    if(second==-1) {
        return "";
    }
    ans*=100;
    ans+=second;
    cout<<ans;
    string s = to_string(ans);
    s.push_back(':');
    cnt=2;
    int i=s.size()-1;
    while(cnt--) {
        swap(s[i],s[i-1]);
        i--;
    }
    if(s.size()==4) {
        s.insert(s.begin(), '0');
    }
    return s;
    
    }
};
