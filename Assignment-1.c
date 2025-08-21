#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tab {
    int pageID;
    char url[100];
    struct Tab* prev;
    struct Tab* next;
} Tab;

Tab* head = NULL;   // first tab
Tab* current = NULL; // current active tab
int pageCounter = 1;

// Create a new tab node
Tab* createTab(char url[]) {
    Tab* newTab = (Tab*)malloc(sizeof(Tab));
    newTab->pageID = pageCounter++;
    strcpy(newTab->url, url);
    newTab->prev = newTab->next = NULL;
    return newTab;
}

// Visit a new page
void visitNewPage() {
    char url[100];
    printf("Enter URL: ");
    scanf("%s", url);

    Tab* newTab = createTab(url);

    if (head == NULL) {
        head = newTab;
        current = newTab;
    } else {
        current->next = newTab;
        newTab->prev = current;
        current = newTab;
    }
    printf("Visited: [%d] %s\n", current->pageID, current->url);
}

// Go forward
void goForward() {
    if (current != NULL && current->next != NULL) {
        current = current->next;
        printf("Moved forward to [%d] %s\n", current->pageID, current->url);
    } else {
        printf("No next tab available!\n");
    }
}

// Go back
void goBack() {
    if (current != NULL && current->prev != NULL) {
        current = current->prev;
        printf("Moved back to [%d] %s\n", current->pageID, current->url);
    } else {
        printf("No previous tab available!\n");
    }
}

// Show current tab
void showCurrent() {
    if (current != NULL)
        printf("Current Tab: [%d] %s\n", current->pageID, current->url);
    else
        printf("No tabs open!\n");
}

// Close current tab
void closeCurrentTab() {
    if (current == NULL) {
        printf("No tab to close!\n");
        return;
    }

    Tab* temp = current;

    if (current->prev != NULL)
        current->prev->next = current->next;
    else
        head = current->next; // if closing head

    if (current->next != NULL)
        current->next->prev = current->prev;

    if (current->next != NULL)
        current = current->next;
    else
        current = current->prev;

    printf("Closed Tab [%d] %s\n", temp->pageID, temp->url);
    free(temp);
}

// Show history
void showHistory() {
    Tab* temp = head;
    if (temp == NULL) {
        printf("No history available!\n");
        return;
    }
    printf("\nBrowser History:\n");
    while (temp != NULL) {
        printf("[%d] %s\n", temp->pageID, temp->url);
        temp = temp->next;
    }
    printf("\n");
}

// Menu
int main() {
    int choice;
    do {
        printf("\n===== Browser Menu =====\n");
        printf("1. Visit a new page\n");
        printf("2. Go back\n");
        printf("3. Go forward\n");
        printf("4. Show current tab\n");
        printf("5. Close current tab\n");
        printf("6. Show history\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: visitNewPage(); break;
            case 2: goBack(); break;
            case 3: goForward(); break;
            case 4: showCurrent(); break;
            case 5: closeCurrentTab(); break;
            case 6: showHistory(); break;
            case 7: printf("Exiting browser...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 7);

    return 0;
}
