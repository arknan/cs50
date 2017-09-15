#!/usr/bin/env python3

def loader(text_file):
    words = []
    with open(text_file, 'r') as fh:
        for line in fh:
            if line.startswith(';') or line.startswith(' '):
                continue
            else:
                for word in line.split():
                    words.append(word.strip())
    return words

positive_words = loader("positive-words.txt")

for word in positive_words:
    print (word)
