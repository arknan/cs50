import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""
        self.positives = loader("positive-words.txt")
        self.negatives = loader("negative-words.txt")


    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""
        tokenizer = nltk.tokenize.TweetTokenizer()
        tokens = tokenizer.tokenize(text)
        score = 0
        for word in tokens:
            word = word.lower()
            if word in self.positives:
                score += 1
            elif word in self.negatives:
                score -= 1
            else :
                continue
        return score

def loader(text_file):
    words = []
    with open(text_file, 'r') as fh:
        for line in fh:
            if line.startswith(';') or line.startswith(' '):
                continue
            else :
                for word in line.split():
                    words.append(word)
    return words
