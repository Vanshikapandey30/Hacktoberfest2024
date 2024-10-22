def encrypt_caesar(plaintext, shift):
    encrypted_text = ""
    for char in plaintext:
        # Encrypt uppercase letters
        if char.isupper():
            encrypted_text += chr((ord(char) + shift - 65) % 26 + 65)
        # Encrypt lowercase letters
        elif char.islower():
            encrypted_text += chr((ord(char) + shift - 97) % 26 + 97)
        else:
            # Leave non-alphabetic characters as they are
            encrypted_text += char
    return encrypted_text

# Example usage:
plaintext = "Hello World!"
shift = 3  # Shift value
encrypted = encrypt_caesar(plaintext, shift)
print(f"Encrypted Text: {encrypted}")
