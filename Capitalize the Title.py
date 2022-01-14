class Solution:
    def capitalizeTitle(self, title: str) -> str:
       
        words = title.split()
        newList = list()
        for word in words:
            if len(word)==1 or len(word)==2:
                word = word.lower()
                newList.append(word)
                continue
            curr = word[0].upper()
            word = curr+word[1:].lower()
            newList.append(word)
        return str(' '.join(newList))
