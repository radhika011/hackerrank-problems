/*

Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.

The canonical path should have the following format:

The path starts with a single slash '/'.
Any two directories are separated by a single slash '/'.
The path does not end with a trailing '/'.
The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
Return the simplified canonical path.




*/




class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        string ans = "";
        string curr = "";
        stack<string> st;
        vector<string> seq;
        path+="/";
        for(int i = 0;i<n+1;i++){
            char ch = path[i];
            //cout<<ch<<endl;
            if(ch=='/'){
                if(curr=="."){
                    curr="";
                    continue;
                }
                if(curr==".."){
                    if(!st.empty()) st.pop();
                    curr="";
                    continue;
                }
                if(curr!="") st.push(curr); 
                curr="";
                continue;
            }
            curr.push_back(ch);
            //cout<<curr<<endl;
            
        }
        
        while(!st.empty()){
            string curr = "/"+st.top();
            ans.insert(0,curr);
            st.pop();
        }
        if(ans=="") ans+="/";
        return ans;
    }
};
