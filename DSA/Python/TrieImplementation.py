class TrieNode:
    def __init__(self):
        """Initialize a trie node with an empty character map and word end flag"""
        self.children = {}  # Map characters to TrieNodes
        self.is_end = False
        self.word_count = 0  # Count of words sharing this prefix
        self.word = None  # Store complete word at end nodes

class Trie:
    def __init__(self):
        """Initialize an empty trie with a root node"""
        self.root = TrieNode()
        self.total_words = 0
    
    def insert(self, word):
        """Insert a word into the trie"""
        node = self.root
        
        # Traverse the trie, creating nodes as needed
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
            node.word_count += 1
        
        # Mark the end of the word
        node.is_end = True
        node.word = word
        self.total_words += 1
    
    def search(self, word):
        """Search for a complete word in the trie"""
        node = self._traverse(word)
        return node is not None and node.is_end
    
    def starts_with(self, prefix):
        """Check if any word in the trie starts with the given prefix"""
        node = self._traverse(prefix)
        return node is not None
    
    def _traverse(self, chars):
        """Helper method to traverse the trie to the end of the given chars"""
        node = self.root
        for char in chars:
            if char not in node.children:
                return None
            node = node.children[char]
        return node
    
    def count_prefix(self, prefix):
        """Count how many words start with the given prefix"""
        node = self._traverse(prefix)
        return node.word_count if node else 0
    
    def get_words_with_prefix(self, prefix):
        """Get all words that start with the given prefix"""
        node = self._traverse(prefix)
        if not node:
            return []
        
        words = []
        self._collect_words(node, words)
        return words
    
    def _collect_words(self, node, words):
        """Helper method to collect all words under a node"""
        if node.is_end:
            words.append(node.word)
        
        for child in node.children.values():
            self._collect_words(child, words)
    
    def delete(self, word):
        """Delete a word from the trie"""
        if not word:
            return False
        
        return self._delete_recursive(self.root, word, 0)
    
    def _delete_recursive(self, node, word, depth):
        """Helper method for recursive deletion"""
        if depth == len(word):
            if not node.is_end:
                return False
            
            node.is_end = False
            node.word = None
            self.total_words -= 1
            return len(node.children) == 0
        
        char = word[depth]
        if char not in node.children:
            return False
        
        should_delete_child = self._delete_recursive(node.children[char], word, depth + 1)
        
        if should_delete_child:
            del node.children[char]
            node.word_count -= 1
            return len(node.children) == 0
        
        node.word_count -= 1
        return False
    
    def autocomplete(self, prefix, max_suggestions=5):
        """Get autocomplete suggestions for a prefix"""
        node = self._traverse(prefix)
        if not node:
            return []
        
        suggestions = []
        self._collect_words(node, suggestions)
        return suggestions[:max_suggestions]
    
    def longest_common_prefix(self):
        """Find the longest common prefix among all words"""
        if not self.root.children:
            return ""
        
        prefix = []
        node = self.root
        
        while len(node.children) == 1 and not node.is_end:
            char = list(node.children.keys())[0]
            prefix.append(char)
            node = node.children[char]
        
        return "".join(prefix)
    
    def contains_pattern(self, pattern):
        """
        Search for a pattern with wildcards (.)
        Example: 'c.t' would match 'cat', 'cot', etc.
        """
        def search_pattern(node, pattern, index):
            if index == len(pattern):
                return node.is_end
            
            char = pattern[index]
            
            if char == '.':
                return any(search_pattern(child, pattern, index + 1)
                         for child in node.children.values())
            
            if char in node.children:
                return search_pattern(node.children[char], pattern, index + 1)
            
            return False
        
        return search_pattern(self.root, pattern, 0)
    
    def get_size(self):
        """Get the total number of words in the trie"""
        return self.total_words
        
        
# Create a new trie
trie = Trie()

# Insert some words
words = ["cat", "car", "cart", "dog", "deer", "deal"]
for word in words:
    trie.insert(word)

# Search for words
print("Is 'cat' in trie?", trie.search("cat"))  # True
print("Is 'cart' in trie?", trie.search("cart"))  # True
print("Is 'cap' in trie?", trie.search("cap"))  # False

# Check prefixes
print("Words with prefix 'ca':", trie.get_words_with_prefix("ca"))  # ['cat', 'car', 'cart']
print("Count of words with prefix 'de':", trie.count_prefix("de"))  # 2

# Autocomplete
print("Autocomplete 'ca':", trie.autocomplete("ca"))  # ['cat', 'car', 'cart']

# Pattern matching
print("Words matching 'c.t':", trie.contains_pattern("c.t"))  # True (matches 'cat')

# Delete a word
trie.delete("cat")
print("After deleting 'cat':")
print("Is 'cat' in trie?", trie.search("cat"))  # False
print("Words with prefix 'ca':", trie.get_words_with_prefix("ca"))  # ['car', 'cart']

# Find longest common prefix
print("Longest common prefix:", trie.longest_common_prefix())

# Get total words
print("Total words in trie:", trie.get_size())
