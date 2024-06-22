#include <stdio.h>
#include <string.h>
#include <ctype.h>
void preprocessMessage(char message[], char processed[]) {
    int len = strlen(message);
    int pidx = 0;

    for (int i = 0; i < len; i++) {
        char current = toupper(message[i]);
        if (isalpha(current)) {
            if (current == 'J') {
                processed[pidx++] = 'I'; 
            } else {
                processed[pidx++] = current;
            }
        }
    }
    processed[pidx] = '\0';
}

void encryptPlayfair(char message[], char matrix[][5], char ciphertext[]) {
    int len = strlen(message);
    int cidx = 0;

    for (int i = 0; i < len; i += 2) {
        char a = message[i];
        char b = (message[i + 1] == '\0') ? 'X' : message[i + 1];

        int r1, c1, r2, c2;
   
        for (int r = 0; r < 5; r++) {
            for (int c = 0; c < 5; c++) {
                if (matrix[r][c] == a) {
                    r1 = r;
                    c1 = c;
                }
                if (matrix[r][c] == b) {
                    r2 = r;
                    c2 = c;
                }
            }
        }

        if (r1 == r2) {
    
            ciphertext[cidx++] = matrix[r1][(c1 + 1) % 5];
            ciphertext[cidx++] = matrix[r2][(c2 + 1) % 5];
        } else if (c1 == c2) {
          
            ciphertext[cidx++] = matrix[(r1 + 1) % 5][c1];
            ciphertext[cidx++] = matrix[(r2 + 1) % 5][c2];
        } else {
         
            ciphertext[cidx++] = matrix[r1][c2];
            ciphertext[cidx++] = matrix[r2][c1];
        }
    }
    ciphertext[cidx] = '\0';
}

int main() {
    char message[] = "Must see you over Cadogan West. Coming at once";
    char processedMessage[1000];
    char ciphertext[1000];

    char matrix[5][5] = {
        {'M', 'F', 'H', 'I', 'K'},
        {'U', 'N', 'O', 'P', 'Q'},
        {'Z', 'V', 'W', 'X', 'Y'},
        {'E', 'L', 'A', 'R', 'G'},
        {'D', 'S', 'T', 'B', 'C'}
    };
    preprocessMessage(message, processedMessage);

    encryptPlayfair(processedMessage, matrix, ciphertext);

    printf("Encrypted Message:\n%s\n", ciphertext);

    return 0;
}
OUTPUT :

Encrypted Message:
QLNNYZOYKSKOQZZYCFZWDPQZAKKUOZPYRLYOUIVWZDTNFOZCPYPZ
