#include <stdio.h>
#include <stdlib.h>

// структура вузла списку
struct Book {
    char title[100];
    float price;
    int pages;
    char language[30];
    float weight;
    int year;
    struct Book* next; // вказівник на наступний елемент
};

// функція створення нового вузла
struct Book* createBook(const char* title, float price, int pages,
                        const char* language, float weight, int year) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    if (!newBook) {
        printf("Помилка виділення пам'яті!\n");
        exit(1);
    }

    // копіюємо дані у структуру (посимвольно, без string.h)
    int i = 0;
    while (title[i] != '\0' && i < 99) {
        newBook->title[i] = title[i];
        i++;
    }
    newBook->title[i] = '\0';

    i = 0;
    while (language[i] != '\0' && i < 29) {
        newBook->language[i] = language[i];
        i++;
    }
    newBook->language[i] = '\0';

    newBook->price = price;
    newBook->pages = pages;
    newBook->weight = weight;
    newBook->year = year;
    newBook->next = NULL;

    return newBook;
}

// додавання книги в кінець списку
void appendBook(struct Book** head, struct Book* newBook) {
    if (*head == NULL) {
        *head = newBook;
        return;
    }
    struct Book* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newBook;
}

// виведення списку книг
void printBooks(struct Book* head) {
    struct Book* current = head;
    while (current != NULL) {
        printf("Name: %s\n", current->title);
        printf("Price: %.2f grn\n", current->price);
        printf("Pages: %d\n", current->pages);
        printf("Language: %s\n", current->language);
        printf("Weight: %.2f kg\n", current->weight);
        printf("Year of publication: %d\n", current->year);
        printf("-----------------------------\n");
        current = current->next;
    }
}

int main() {
    struct Book* library = NULL;

    // додаємо кілька книг серії
    appendBook(&library, createBook("Harry Potter and the Philosopher's Stone", 350.0, 223, "English", 0.45, 1997));
    appendBook(&library, createBook("Harry Potter and the Chamber of Secrets", 370.0, 251, "English", 0.48, 1998));
    appendBook(&library, createBook("Harry Potter and the Prisoner of Azkaban", 400.0, 317, "English", 0.55, 1999));
    appendBook(&library, createBook("Harry Potter and the Goblet of Fire", 500.0, 636, "English", 0.85, 2000));

    // вивід усіх книг
    printBooks(library);

    return 0;
}
