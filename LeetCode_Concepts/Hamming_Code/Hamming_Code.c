#include <stdio.h>
#include <math.h>

int calculateParityBits(int dataBits) {
    int parityBits = 0;
    while ((1 << parityBits) < (dataBits + parityBits + 1)) {
        parityBits++;
    }
    return parityBits;
}

void insertParityBits(int data[], int dataBits, int code[], int totalBits) {
    int dataPos = 0;

    // Insert data and initialize parity bits to 0
    for (int i = 1; i <= totalBits; i++) {
        if ((i & (i - 1)) == 0) {
            code[i - 1] = 0; // Parity bit positions (power of 2)
        } else {
            code[i - 1] = data[dataPos++];
        }
    }
}

void calculateParityValues(int code[], int totalBits) {
    // Set parity bits by checking relevant positions
    for (int i = 0; (1 << i) <= totalBits; i++) {
        int parityPos = (1 << i) - 1;
        int parity = 0;
        
        for (int j = 1; j <= totalBits; j++) {
            if (j & (parityPos + 1)) {
                parity ^= code[j - 1];
            }
        }
        code[parityPos] = parity;
    }
}

int checkHammingCode(int code[], int totalBits) {
    int errorPos = 0;

    // Check parity bits for error detection
    for (int i = 0; (1 << i) <= totalBits; i++) {
        int parityPos = (1 << i) - 1;
        int parity = 0;

        for (int j = 1; j <= totalBits; j++) {
            if (j & (parityPos + 1)) {
                parity ^= code[j - 1];
            }
        }
        if (parity != 0) {
            errorPos += (parityPos + 1);
        }
    }

    return errorPos;
}

int main() {
    int dataBits;

    printf("Enter the number of data bits: ");
    scanf("%d", &dataBits);

    int data[dataBits];
    printf("Enter the data bits (0 or 1): ");
    for (int i = 0; i < dataBits; i++) {
        scanf("%d", &data[i]);
    }

    int parityBits = calculateParityBits(dataBits);
    int totalBits = dataBits + parityBits;

    int code[totalBits];
    insertParityBits(data, dataBits, code, totalBits);
    calculateParityValues(code, totalBits);

    printf("Generated Hamming Code: ");
    for (int i = 0; i < totalBits; i++) {
        printf("%d ", code[i]);
    }

    // Introduce error (optional)
    code[3] ^= 1; // Flip a bit for testing

    int errorPos = checkHammingCode(code, totalBits);
    if (errorPos == 0) {
        printf("\nNo error detected.\n");
    } else {
        printf("\nError detected at position: %d\n", errorPos);
        code[errorPos - 1] ^= 1; // Correct the error
        printf("Corrected Hamming Code: ");
        for (int i = 0; i < totalBits; i++) {
            printf("%d ", code[i]);
        }
        printf("\n");
    }
}






