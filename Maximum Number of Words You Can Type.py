
###

#There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.

#Given a string text of words separated by a single space (no leading or trailing spaces) and a string brokenLetters of all distinct letter keys that are broken, return the number of words in text you can fully type using this keyboard.

###

class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        words = text.split(' ')
        allowed = 0
        for word in words:
            flag = True
            for key in brokenLetters:
                if key in word:
                    flag = False
            if flag:
                allowed+=1
        return allowed
