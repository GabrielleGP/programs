#Programul in Python cu metoda Vernam

def Textcript(string, key): 
	cipher_text = [] 
	for i in range(len(string)): 
		x = (ord(string[i]) + ord(key[i])) % 26
		x += ord('A') #convertim in alfabet(ASCII)
		cipher_text.append(chr(x)) 
	return("" . join(cipher_text))

def decrypt(ciphertext, key):
    
	plaintext = [] 
	for i in range(len(ciphertext)): 
		x = (ord(ciphertext[i]) - ord(key[i])) % 26
		x += ord('A') #convertim in alfabet(ASCII)
		plaintext.append(chr(x)) 
	return("" . join(plaintext))

string = "GABRIELA"
key = "VERNAMEN"
text_criptat = Textcript(string,key) 
print("Text criptat :", text_criptat) 
print("Original/Decriptat :", decrypt(text_criptat,key)) 
