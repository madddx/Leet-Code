class Solution(object):
    def isValid(self, word):
        """
        :type word: str
        :rtype: bool
        """
        if len(word) < 3:
            return False

        if not word.isalnum():  # Only digits and English letters allowed
            return False

        vowels = set('aeiouAEIOU')
        has_vowel = False
        has_consonant = False

        for ch in word:
            if ch.isalpha():
                if ch in vowels:
                    has_vowel = True
                else:
                    has_consonant = True

        return has_vowel and has_consonant
