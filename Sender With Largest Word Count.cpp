/*
You have a chat log of n messages. You are given two string arrays messages and senders where messages[i] is a message sent by senders[i].

A message is list of words that are separated by a single space with no leading or trailing spaces. The word count of a sender is the total number of words sent by the sender. Note that a sender may send more than one message.

Return the sender with the largest word count. If there is more than one sender with the largest word count, return the one with the lexicographically largest name.

Note:

Uppercase letters come before lowercase letters in lexicographical order.
"Alice" and "alice" are distinct.



*/








class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n = messages.size();
        unordered_map<string,int> counts;
        string ans = "";
        int maximum = INT_MIN;
        for(int i =0;i<n;i++){
            string message = messages[i];
            string sender = senders[i];
            int word_count = 0;
            for(int j = 0;j<message.size();j++){
                if(message[j]==' '){
                    word_count++;
                }
            }
            word_count++;
            counts[sender]+=word_count;
            maximum = max(maximum,counts[sender]);
        }
        vector<string> maxs;
        for(auto it = counts.begin();it!=counts.end();it++){
            if(it->second==maximum){
                maxs.push_back(it->first);
            }
        }
        sort(maxs.begin(),maxs.end());
        return maxs[maxs.size()-1];
    }
};
