"""
Practical 10

Write a function that takes a sentence as input from the user and calculates 
the frequency of each letter. Use a variable of dictionary type to maintain the count.

Written by Chirag Wadhwa for the University of Delhi
"""

def frequencies():
	freq = dict()
	sentence = input('Enter a Sentence: ')
	for letter in sentence:
		if not letter.isalpha():
			continue
		if letter not in freq:
			freq[letter] = 1
		else:
			freq[letter] += 1
	print('Frequencies: ')
	for letter in freq:
		print(f'{letter} => {freq[letter]}')
if __name__ == "__main__":
	frequencies()

