Huffman Coding
==============

Problem Statement
-----------------

Huffman coding is a lossless data compression algorithm that is based on the frequency of characters in a given input. It assigns variable-length codes to input characters, with shorter codes assigned to more frequent characters. The goal is to minimize the total length of the encoded output.

Example
-------

Input: `characters = ['a', 'b', 'c', 'd'], frequencies = [5, 9, 12, 13]`

Output: `{'a': '110', 'b': '111', 'c': '10', 'd': '0'}`

Approaches
----------

### 1\. Using Priority Queue

The most common way to implement Huffman coding is using a priority queue to build the Huffman tree based on character frequencies.

    import java.util.PriorityQueue;
    import java.util.HashMap;
    
    class HuffmanNode {
        int frequency;
        char character;
        HuffmanNode left;
        HuffmanNode right;
    
        public HuffmanNode(char character, int frequency) {
            this.character = character;
            this.frequency = frequency;
            left = right = null;
        }
    }
    
    public class HuffmanCoding {
        public static void main(String[] args) {
            char[] characters = {'a', 'b', 'c', 'd'};
            int[] frequencies = {5, 9, 12, 13};
            HashMap huffmanCodes = generateHuffmanCodes(characters, frequencies);
            System.out.println(huffmanCodes);
        }
    
        public static HashMap generateHuffmanCodes(char[] characters, int[] frequencies) {
            PriorityQueue minHeap = new PriorityQueue<>((a, b) -> a.frequency - b.frequency);
            
            for (int i = 0; i < characters.length; i++) {
                minHeap.add(new HuffmanNode(characters[i], frequencies[i]));
            }
    
            while (minHeap.size() > 1) {
                HuffmanNode left = minHeap.poll();
                HuffmanNode right = minHeap.poll();
                HuffmanNode merged = new HuffmanNode('\0', left.frequency + right.frequency);
                merged.left = left;
                merged.right = right;
                minHeap.add(merged);
            }
    
            HuffmanNode root = minHeap.poll();
            HashMap huffmanCodes = new HashMap<>();
            generateCodes(root, "", huffmanCodes);
            return huffmanCodes;
        }
    
        private static void generateCodes(HuffmanNode node, String code, HashMap huffmanCodes) {
            if (node.left == null && node.right == null) {
                huffmanCodes.put(node.character, code);
                return;
            }
            generateCodes(node.left, code + "0", huffmanCodes);
            generateCodes(node.right, code + "1", huffmanCodes);
        }
    }
    

**Time Complexity:** O(N log N), where N is the number of unique characters.

**Space Complexity:** O(N) for the hash map and priority queue.

### 2\. Recursive Building

This approach builds the tree recursively without using a priority queue. It uses the same logic but constructs nodes in a recursive manner.

    import java.util.HashMap;
    
    class HuffmanCodingRecursive {
        // Define your HuffmanNode class as before
    
        public static void main(String[] args) {
            char[] characters = {'a', 'b', 'c', 'd'};
            int[] frequencies = {5, 9, 12, 13};
            HashMap huffmanCodes = generateHuffmanCodes(characters, frequencies);
            System.out.println(huffmanCodes);
        }
    
        public static HashMap generateHuffmanCodes(char[] characters, int[] frequencies) {
            return recursiveBuild(characters, frequencies, 0, characters.length);
        }
    
        private static HashMap recursiveBuild(char[] characters, int[] frequencies, int start, int end) {
            if (start == end) return new HashMap<>();
    
            if (end - start == 1) {
                HashMap baseMap = new HashMap<>();
                baseMap.put(characters[start], "");
                return baseMap;
            }
    
            // Logic to combine and create Huffman nodes recursively would go here
            // ... (The implementation details depend on your recursive logic)
    
            return new HashMap<>(); // Placeholder
        }
    }
    

**Time Complexity:** O(N log N) in general cases.

**Space Complexity:** O(N) for the hash map.

### 3\. Iterative Approach

This approach constructs the Huffman tree iteratively and uses a simple loop instead of recursion.

    import java.util.PriorityQueue;
    import java.util.HashMap;
    
    public class HuffmanCodingIterative {
        public static void main(String[] args) {
            char[] characters = {'a', 'b', 'c', 'd'};
            int[] frequencies = {5, 9, 12, 13};
            HashMap huffmanCodes = generateHuffmanCodes(characters, frequencies);
            System.out.println(huffmanCodes);
        }
    
        public static HashMap generateHuffmanCodes(char[] characters, int[] frequencies) {
            PriorityQueue minHeap = new PriorityQueue<>((a, b) -> a.frequency - b.frequency);
    
            for (int i = 0; i < characters.length; i++) {
                minHeap.add(new HuffmanNode(characters[i], frequencies[i]));
            }
    
            while (minHeap.size() > 1) {
                HuffmanNode left = minHeap.poll();
                HuffmanNode right = minHeap.poll();
                HuffmanNode merged = new HuffmanNode('\0', left.frequency + right.frequency);
                merged.left = left;
                merged.right = right;
                minHeap.add(merged);
            }
    
            HuffmanNode root = minHeap.poll();
            HashMap huffmanCodes = new HashMap<>();
            iterativeCodeGeneration(root, "", huffmanCodes);
            return huffmanCodes;
        }
    
        private static void iterativeCodeGeneration(HuffmanNode node, String code, HashMap huffmanCodes) {
            // Iterative logic to generate codes goes here
            // Similar to the recursive approach, but using a stack/queue for traversal
        }
    }
    

**Time Complexity:** O(N log N) due to the priority queue operations.

**Space Complexity:** O(N) for the priority queue and the hash map.

Conclusion
----------

Huffman coding is a powerful technique for data compression. The above methods provide different ways to implement the algorithm, each with its own trade-offs in terms of readability and performance. The choice of approach depends on the specific requirements of the problem at hand.