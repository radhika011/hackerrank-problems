class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        ls = s.split(' ')
        prev = -1
        flag = True
        for i in ls:
            
            if(i.isdigit()):
                i = int(i)
                if(prev>=i):
                    #print(prev,i,flag)
                    flag = False
                    #print(prev,i,flag)
                    break
                prev = i
        return flag
        
