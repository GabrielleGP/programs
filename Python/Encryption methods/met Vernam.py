#Program in Python with Vernam's method

def Textcript(string, key): 
	cipher_text = [] 
	for i in range(len(string)): 
		x = (ord(string[i]) + ord(key[i])) % 26
		x += ord('A') #convert to alphabet (ASCII)
		cipher_text.append(chr(x)) 
	return("" . join(cipher_text))

def decrypt(ciphertext, key):
    
	plaintext = [] 
	for i in range(len(ciphertext)): 
		x = (ord(ciphertext[i]) - ord(key[i])) % 26
		x += ord('A') #convert to alphabet (ASCII)
		plaintext.append(chr(x)) 
	return("" . join(plaintext))

string = "GABRIELA"
key = "VERNAMEN"
encrypted_text = Textcript(string,key) 
print("The encrypted text:", encrypted_text) 
print("Original/Decrypted :", decrypt(encrypted_text,key)) 
