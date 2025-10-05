#include <stdio.h>

#define MAX_LEN 1024

int main(void) {
    char s[MAX_LEN];
    char target, repl;
    int i, len = 0, count = 0;

    printf("Write text (max %d symbols):\n", MAX_LEN - 1);

    // Читання рядка посимвольно, поки не \n або EOF
    int c;
    while ((c = getchar()) != '\n' && c != EOF && len < MAX_LEN - 1) {
        s[len++] = (char)c;
    }
    s[len] = '\0'; // додаємо кінець рядка

    printf("What symbol to look for? ");
    target = getchar();
    getchar(); // зчитати '\n'

    printf("Which symbol to replace? ");
    repl = getchar();
    getchar(); // зчитати '\n'

    // Замінюємо всі входження
    for (i = 0; i < len; i++) {
        if (s[i] == target) {
            s[i] = repl;
            count++;
        }
    }

    if (count == 0) {
        printf("Symbol '%c' was not founded.\n", target);
    } else {
        printf("Founded and replaced %d occurrence(s) of the character '%c'.\n", count, target);
        printf("Result:\n%s\n", s);
    }

    return 0;
}
