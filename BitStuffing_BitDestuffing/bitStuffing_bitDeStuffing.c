#include <stdio.h>
#include <string.h>

int count = 0; // Global count of stuffed bits

// Function to perform bit stuffing
void bitStuffing(const char *bitStream, const char *flag, char *stuffedStream, int bitsToStuff) {
    int flag_len = strlen(flag);
    int bit_len = strlen(bitStream);
    int j = 0;

    for (int i = 0; i < bit_len; i++) {
        stuffedStream[j++] = bitStream[i];
        if (i >= flag_len - 1) {
            int match = 1;
            for (int k = 0; k < flag_len; k++) {
                if (bitStream[i - (flag_len - 1) + k] != flag[k]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                for (int b = 0; b < bitsToStuff; b++) {
                    stuffedStream[j++] = '0'; 
                }
                count++;
            }
        }
    }
    stuffedStream[j] = '\0'; // Null-terminate the stuffed stream
}

// Function to perform bit de-stuffing
void bitDeStuffing(const char *stuffedStream, const char *flag, char *deStuffedStream, int bitsToDeStuff) {
    int flag_len = strlen(flag);
    int stuffed_len = strlen(stuffedStream);
    int j = 0;

    for (int i = 0; i < stuffed_len; i++) {
        deStuffedStream[j++] = stuffedStream[i];
        if (i >= flag_len - 1) {
            int match = 1;
            for (int k = 0; k < flag_len; k++) {
                if (stuffedStream[i - (flag_len - 1) + k] != flag[k]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                i += bitsToDeStuff; // Skip the stuffed bits
            }
        }
    }
    deStuffedStream[j] = '\0'; // Null-terminate the de-stuffed stream
}

int main() {
    int bits, frameCount, size;
    char bitStream[100] = {0};  // Initialize to zero
    char stuffedStream[200] = {0};  // Initialize to zero
    char deStuffedStream[100] = {0}; // Initialize to zero
    int bitsToStuff;

    printf("Enter number of bits in bitStream: ");
    scanf("%d", &bits);

    printf("Enter bits (as a single string): ");
    scanf("%s", bitStream);

    printf("Enter number of bits to stuff (1 or 2): ");
    scanf("%d", &bitsToStuff);

    char flag[] = "11111";
    bitStuffing(bitStream, flag, stuffedStream, bitsToStuff);

    printf("Bit stream:\n%s\n", bitStream);
    printf("Stuffed bit stream:\n%s\n", stuffedStream);

    // Compute the number of frames
    int stuffedBits = strlen(stuffedStream);
    printf("Enter the size of the frame: ");
    scanf("%d", &size);

    frameCount = stuffedBits / size;
    if (stuffedBits % size != 0) frameCount++;
    
    printf("Number of frames (Fixed Size) after Bit Stuffing: %d\n", frameCount);
    printf("Number of stuffed frames (Variable Size) after Bit Stuffing: %d\n", count);

    // Perform bit de-stuffing
    bitDeStuffing(stuffedStream, flag, deStuffedStream, bitsToStuff);
    printf("De-stuffed bit stream:\n%s\n", deStuffedStream);
    
    return 0;
}
