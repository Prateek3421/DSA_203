#include <stdio.h>
#include <string.h>

#define MAX 100

void searchWord(char grid[MAX][MAX], int m, int n, char word[]) {
    int wordLen = strlen(word);
    int found = 0;

    // Horizontal search (left to right)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= n - wordLen; j++) {
            int k;
            for (k = 0; k < wordLen; k++) {
                if (grid[i][j + k] != word[k])
                    break;
            }
            if (k == wordLen) {
                printf("Start: (%d, %d) End: (%d, %d)\n", i, j, i, j + wordLen - 1);
                found = 1;
            }
        }
    }

    // Vertical search (top to bottom)
    for (int j = 0; j < n; j++) {
        for (int i = 0; i <= m - wordLen; i++) {
            int k;
            for (k = 0; k < wordLen; k++) {
                if (grid[i + k][j] != word[k])
                    break;
            }
            if (k == wordLen) {
                printf("Start: (%d, %d) End: (%d, %d)\n", i, j, i + wordLen - 1, j);
                found = 1;
            }
        }
    }

    if (!found)
        printf("Word not found\n");
}

int main() {
    int m, n;
    char grid[MAX][MAX], word[MAX];

    printf("Enter number of rows (m): ");
    scanf("%d", &m);
    printf("Enter number of columns (n): ");
    scanf("%d", &n);

    printf("Enter the grid row by row (uppercase letters, no spaces):\n");
    for (int i = 0; i < m; i++) {
        scanf("%s", grid[i]);
        if (strlen(grid[i]) != n) {
            printf("Error: Each row must have exactly %d letters.\n", n);
            return 1;
        }
    }

    printf("Enter the word to search: ");
    scanf("%s", word);

    // Convert to uppercase (optional)
    for (int i = 0; word[i]; i++) {
        if (word[i] >= 'a' && word[i] <= 'z')
            word[i] -= 32;
    }

    printf("\nGrid:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%c ", grid[i][j]);
        printf("\n");
    }

    printf("\nOccurrences:\n");
    searchWord(grid, m, n, word);

    return 0;
}
