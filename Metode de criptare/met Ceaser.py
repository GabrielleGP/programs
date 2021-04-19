#Programul in Python cu metoda lui Cezar
def encrypt(text,s):
    result = ""
    for i in range(len(text)):
        char = text[i]
        if (char.isupper()):
            result += chr((ord(char) + s-65) % 26 + 65) #pentru litere upper
        else:
            result += chr((ord(char) + s-97) % 26 + 97) #pentru litere lower
    return result
    
def decrypt(ciphertext, key):
    result = ''
    for i in range(len(ciphertext)):
        char = ciphertext[i]
        if (char.isupper()):
            result += chr((ord(char) - s-65) % 26 + 65) #pentru litere upper
        else:
            result += chr((ord(char) - s-97) % 26 + 97)
    return result 
    
text = "Gabriela"
s = 2
ciper = encrypt(text,s)
print ("Cheia : " + str(s))
print ("Textul criptat, met.Cezar : " + ciper)
print ("Textul decriptat : " + decrypt(ciper,s))
