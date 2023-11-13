#Program in Python with Caesar's method

def encrypt(text,s):
    result = ""
    for i in range(len(text)):
        char = text[i]
        if (char.isupper()):
            result += chr((ord(char) + s-65) % 26 + 65) #for upper letters
        else:
            result += chr((ord(char) + s-97) % 26 + 97) #for lower letters
    return result
    
def decrypt(ciphertext, key):
    result = ''
    for i in range(len(ciphertext)):
        char = ciphertext[i]
        if (char.isupper()):
            result += chr((ord(char) - s-65) % 26 + 65) #for upper letters
        else:
            result += chr((ord(char) - s-97) % 26 + 97)
    return result 
    
text = "Gabriela"
s = 2
ciper = encrypt(text,s)
print ("Key : " + str(s))
print ("The encrypted text, met.Caesar : " + ciper)
print ("The decrypted text : " + decrypt(ciper,s))
