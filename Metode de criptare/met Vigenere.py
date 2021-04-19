
#Programul in Python cu metoda Vigenere
def generarecheie(string, key): 
	key = list(key) 
	if len(string) == len(key): 
		return(key) 
	else: 
		for i in range(len(string) - len(key)): 
			key.append(key[i % len(key)]) 
	return("" . join(key)) 
	
def Textcript(string, key): 
	cipher_text = [] 
	for i in range(len(string)): 
		x = (ord(string[i]) + ord(key[i])) % 26
		x += ord('A') 
		cipher_text.append(chr(x)) 
	return("" . join(cipher_text))

def decrypt(ciphertext, key):
    key_length = len(key)
    key_as_int = [ord(i) for i in key]
    ciphertext_int = [ord(i) for i in ciphertext]
    plaintext = ''
    for i in range(len(ciphertext_int)):
        value = (ciphertext_int[i] - key_as_int[i % key_length]) % 26
        plaintext += chr(value + 65)
    return plaintext

string = "GABRIELA"
key = "GABI"
key = generarecheie(string, key) 
text_criptat = Textcript(string,key) 
print("Text criptat :", text_criptat) 
print("Original/Decriptat :", decrypt(text_criptat,key)) 

