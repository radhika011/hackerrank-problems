
/*
Jesse loves cookies and wants the sweetness of some cookies to be greater than value . To do this, two cookies with the least sweetness are repeatedly mixed. This creates a special combined cookie with:

sweetness = Least sweet cookie +2*  2nd least sweet cookie).

This occurs until all the cookies have a sweetness .

Given the sweetness of a number of cookies, determine the minimum number of operations required. If it is not possible, return .


*/



int cookies(int k, vector<int> A) {
 priority_queue<int,vector<int>,greater<int>> q;
    for(int i:A){
        q.push(i);
    }
    int ops = 0;
    while(q.size()!=1){
       int cookie1 = q.top();
        q.pop();
        if(cookie1>=k) break;
        int cookie2 = q.top();
        q.pop();
        int newCookie = cookie1+(2*cookie2);
        q.push(newCookie);
        ops++;
    }
    if(q.size()==1&&q.top()<k) return -1;
    return ops;
}
