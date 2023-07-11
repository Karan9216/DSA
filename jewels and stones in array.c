#include <stdio.h>

int numJewelsInStones(char *J, char *S) {
    int jewelCount = 0;
    
    // Loop through each stone in S
    for (int i = 0; S[i] != '\0'; i++) {
        // Check if the stone is a jewel
        for (int j = 0; J[j] != '\0'; j++) {
            if (S[i] == J[j]) {
                jewelCount++;
                break;
            }
        }
    }
    
    return jewelCount;
}

int main() {
    char jewels[] = "aA";
    char stones[] = "aAAbbbb";
    
    int count = numJewelsInStones(jewels, stones);
    
    printf("Number of jewels: %d\n", count);
    
    return 0;
}
