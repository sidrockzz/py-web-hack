#!/usr/bin/env python
# coding: utf-8

# In[1]:


def encrypt(text,s):
    result=""
    for i in range(len(text)):
        char = text[i]
        if(char.isupper()):
            result += chr((ord(char) + s-65) % 26 + 65)
        else:
            result += chr((ord(char) + s - 97) % 26 + 97)
        return result


# In[ ]:


text = input()
s = 4
print("Plain Text:",text)
print("Shift Pattern:",s)
print("Encrypted data:",encrypt(text,s))


# <b> Brute Force Technique </b>
# <b> The hacking or decrypting the caesar cipher </b>

# In[ ]:


message = 'GIEWIVrGMTLIVrHIQS' #encrypted message
LETTERS = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

for key in range(len(LETTERS)):
    translated = ''
    for symbol in message:
        if symbol in LETTERS:
            num = LETTERS.find(symbol)
            num = num - key
            if num < 0:
                num = num + len(LETTERS)
                translated = translated + LETTERS[num]
            else:
                translated = translated + symbol
print('Hacking key #%s: %s' % (key, translated))


# In[ ]:




