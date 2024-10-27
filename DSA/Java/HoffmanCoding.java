import java.util.*;

class Node {
    int frequency;
    char character;
    Node left, right;

    Node(char character, int frequency) {
        this.character = character;
        this.frequency = frequency;
        left = right = null;
    }
}

class HuffmanCoding {
    private static Node root;

    // Comparator to sort nodes based on frequency
    private static class NodeComparator implements Comparator<Node> {
        public int compare(Node n1, Node n2) {
            return n1.frequency - n2.frequency;
        }
    }

    // Build the Huffman Tree
    private static void buildHuffmanTree(String text) {
        Map<Character, Integer> frequencyMap = new HashMap<>();
        for (char c : text.toCharArray()) {
            frequencyMap.put(c, frequencyMap.getOrDefault(c, 0) + 1);
        }

        PriorityQueue<Node> priorityQueue = new PriorityQueue<>(new NodeComparator());
        for (Map.Entry<Character, Integer> entry : frequencyMap.entrySet()) {
            priorityQueue.add(new Node(entry.getKey(), entry.getValue()));
        }

        while (priorityQueue.size() > 1) {
            Node left = priorityQueue.poll();
            Node right = priorityQueue.poll();
            Node newNode = new Node('\0', left.frequency + right.frequency);
            newNode.left = left;
            newNode.right = right;
            priorityQueue.add(newNode);
        }

        root = priorityQueue.poll();
    }

    // Generate the Huffman codes
    private static void generateCodes(Node node, String code, Map<Character, String> huffmanCode) {
        if (node == null) return;

        if (node.left == null && node.right == null) {
            huffmanCode.put(node.character, code);
        }

        generateCodes(node.left, code + "0", huffmanCode);
        generateCodes(node.right, code + "1", huffmanCode);
    }

    // Encode the input text
    public static String encode(String text) {
        buildHuffmanTree(text);
        Map<Character, String> huffmanCode = new HashMap<>();
        generateCodes(root, "", huffmanCode);

        StringBuilder encodedText = new StringBuilder();
        for (char c : text.toCharArray()) {
            encodedText.append(huffmanCode.get(c));
        }

        return encodedText.toString();
    }

    // Decode the encoded text
    public static String decode(String encodedText) {
        StringBuilder decodedText = new StringBuilder();
        Node currentNode = root;

        for (char bit : encodedText.toCharArray()) {
            currentNode = (bit == '0') ? currentNode.left : currentNode.right;

            if (currentNode.left == null && currentNode.right == null) {
                decodedText.append(currentNode.character);
                currentNode = root;
            }
        }

        return decodedText.toString();
    }

    public static void main(String[] args) {
        String text = "hello huffman";
        System.out.println("Original Text: " + text);

        String encodedText = encode(text);
        System.out.println("Encoded Text: " + encodedText);

        String decodedText = decode(encodedText);
        System.out.println("Decoded Text: " + decodedText);
    }
}
