def decode(message_file):
    # Read the contents of the file and extract number-word pairs
    with open(message_file, 'r') as file:
        lines = file.readlines()

    number_word_pairs = {}
    for line in lines:
        parts = line.strip().split()
        number = int(parts[0])
        word = ' '.join(parts[1:])
        number_word_pairs[number] = word

    # Retrieve the words corresponding to the end numbers of each line in the pyramid
    end_numbers = []
    decoded_words = []
    current_number = 1

    while current_number in number_word_pairs:
        end_numbers.append(current_number)
        decoded_words.append(number_word_pairs[current_number])
        current_number += len(end_numbers) + 1

    # Return the decoded message by joining the words
    decoded_message = ' '.join(decoded_words)
    return decoded_message

# Example usage:
decoded_message = decode('coding_qual_input.txt')
print(decoded_message)
