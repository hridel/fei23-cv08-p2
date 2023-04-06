#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
    char name[50];
    int age;
    struct person *next;
} Person;

Person *allocate_memory() {
    Person *person = (Person *) malloc(sizeof(Person));
    if (person == NULL) {
        printf("Chyba pri alokovani pameti\n");
        exit(1);
    }
    return person;
}

void read_person(Person *person) {
    printf("Zadej jmeno: ");
    scanf("%s", person->name);

    printf("Zadej vek: ");
    scanf("%d", &person->age);
}

Person *find_oldest(Person *head) {
    Person *oldest = head;
    Person *current = head->next;

    while (current != NULL) {
        if (current->age > oldest->age) {
            oldest = current;
        }
        current = current->next;
    }

    return oldest;
}

Person *find_youngest(Person *head) {
    Person *youngest = head;
    Person *current = head->next;

    while (current != NULL) {
        if (current->age < youngest->age) {
            youngest = current;
        }
        current = current->next;
    }

    return youngest;
}

void free_memory(Person *head) {
    Person *current = head;

    while (current != NULL) {
        Person *next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Person *head = NULL;
    Person *current = NULL;

    int count;
    printf("Zadej pocet osob: ");
    scanf("%d", &count);

    // Pridani osob do seznamu
    for (int i = 0; i < count; i++) {
        Person *person = allocate_memory();
        read_person(person);
        person->next = NULL;

        if (head == NULL) {
            head = person;
        } else {
            current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = person;
        }
    }

    // Vyhledani nejstarsi a nejmladsi osoby
    Person *oldest = find_oldest(head);
    Person *youngest = find_youngest(head);

    // Vypsani vysledku
    printf("Nejstarsi osoba je: %s (%d let)\n", oldest->name, oldest->age);
    printf("Nejmladsi osoba je: %s (%d let)\n", youngest->name, youngest->age);

    // Uvolneni pameti alokovane pro seznam
    free_memory(head);

    return 0;
}

/*
 * Funkce allocate_memory() alokuje paměť pro novou osobu a vrátí ukazatel na ni. Pokud dojde k chybě při alokaci paměti, funkce vypíše chybovou hlášku a program skončí.

 * Funkce read_person() slouží k načtení jmena a věku osoby z klávesnice a uložení do předané struktury Person.

 * Funkce find_oldest() a find_youngest() procházejí seznam osob a hledají nejstarší a nejmladší osobu podle věku
 */