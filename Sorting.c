#include <stdio.h>
#include <string.h>

struct Employee {
    char name[20];
    char designation[20];
    int id;
};

void accept(struct Employee E[], int n);
void display(struct Employee E[], int n);
void bubblesorting(struct Employee E[], int n);
void selectionsorting(struct Employee E[], int n);
void insertion_sorting(struct Employee E[], int n);
void shell_sorting(struct Employee E[], int n);
void quick_sorting(struct Employee E[], int low, int high);
void merge_sorting(struct Employee E[], int low, int high);
void bucket_sorting(struct Employee E[], int n);
void radix_sorting(struct Employee E[], int n);
void linear_search(struct Employee E[], int n, int key);
void binary_search(struct Employee E[], int n, int key);
void sentinel_search(struct Employee E[], int n, int key);

int main() {
    int n;
    printf("Enter the no. of employees: ");
    if(scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid");
        return 1;
    }

    struct Employee emp[n];
    printf("\n Enter employee details \n");
    accept(emp, n);
    printf("Employee List \n");
    display(emp, n);

    bubblesorting(emp, n);
    printf("Bubble Sorted Employee List \n");
    display(emp, n);

    selectionsorting(emp, n);
    printf("Selection Sorted Employee List \n");
    display(emp, n);

    insertion_sorting(emp, n);
    printf("Insertion Sorted Employee List \n");
    display(emp, n);

    shell_sorting(emp, n);
    printf("Shell Sorted Employee List \n");
    display(emp, n);

    quick_sorting(emp, 0, n - 1);
    printf("Quick Sorted Employee List \n");
    display(emp, n);

    merge_sorting(emp, 0, n - 1);
    printf("Merge Sorted Employee List \n");
    display(emp, n);

    bucket_sorting(emp, n);
    printf("Bucket Sorted Employee List \n");
    display(emp, n);

    radix_sorting(emp, n);
    printf("Radix Sorted Employee List \n");
    display(emp, n);

    linear_search(emp, n, 101);
    binary_search(emp, n, 102);
    sentinel_search(emp, n, 103);

    return 0;
}

void accept(struct Employee E[100], int n) {
    for(int i=0; i<n; i++) {
        printf("\nEmployee %d\n", i+1);
        printf("Employee id: ");
        scanf("%d", &E[i].id);

        printf("\nEmployee name: ");
        scanf("%s", E[i].name);

        printf("\nEmployee Post: ");
        scanf("%s", E[i].designation);
    }
}

void display(struct Employee E[100], int n) {
    for (int i=0; i < n; i++) {
        printf("%d \t %s\t %s \n", E[i].id, E[i].name, E[i].designation);
    }
}

void bubblesorting(struct Employee E[100], int n) {
    struct Employee temp;
    for(int i=0; i<n; i++) {
        for (int j=0; j<n-i-1; j++){
            if(E[j].id > E[j+1].id) {
                temp = E[j];
                E[j] = E[j+1];
                E[j+1] = temp;
            }
        }
    }
}

void selectionsorting(struct Employee E[100], int n) {
    struct Employee temp;
    for(int i=0; i<n-1; i++) {
        int min_index = i;
        for(int j=i+1; j<n; j++) {
            if(E[j].id < E[min_index].id) {
                min_index = j;
            }
        }
        if(min_index != i) {
            temp = E[i];
            E[i] = E[min_index];
            E[min_index] = temp;
        }
    }
}

void insertion_sorting(struct Employee E[100], int n) {
    struct Employee key;
    int j;
    for(int i=1; i<n; i++) {
        key = E[i];
        j = i - 1;
        while(j >= 0 && E[j].id > key.id) {
            E[j + 1] = E[j];
            j--;
        }
        E[j + 1] = key;
    }
}

void shell_sorting(struct Employee E[100], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            struct Employee temp = E[i];
            int j;
            for (j = i; j >= gap && E[j - gap].id > temp.id; j -= gap) {
                E[j] = E[j - gap];
            }
            E[j] = temp;
        }
    }
}

void quick_sorting(struct Employee E[100], int low, int high) {
    if (low < high) {
        struct Employee pivot = E[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (E[j].id < pivot.id) {
                i++;
                struct Employee temp = E[i];
                E[i] = E[j];
                E[j] = temp;
            }
        }
        struct Employee temp = E[i + 1];
        E[i + 1] = E[high];
        E[high] = temp;
        int pi = i + 1;

        quick_sorting(E, low, pi - 1);
        quick_sorting(E, pi + 1, high);
    }
}

void merge_sorting(struct Employee E[100], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        merge_sorting(E, low, mid);
        merge_sorting(E, mid + 1, high);

        struct Employee temp[100];
        int i = low, j = mid + 1, k = low;

        while (i <= mid && j <= high) {
            if (E[i].id <= E[j].id) {
                temp[k++] = E[i++];
            } else {
                temp[k++] = E[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = E[i++];
        }

        while (j <= high) {
            temp[k++] = E[j++];
        }

        for (i = low; i <= high; i++) {
            E[i] = temp[i];
        }
    }
}

void bucket_sorting(struct Employee E[100], int n) {
    int max_id = E[0].id;
    for (int i = 1; i < n; i++) {
        if (E[i].id > max_id) {
            max_id = E[i].id;
        }
    }

    int bucket_size = max_id + 1;
    struct Employee *buckets[bucket_size];
    for (int i = 0; i < bucket_size; i++) {
        buckets[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        int id = E[i].id;
        if (buckets[id] == NULL) {
            buckets[id] = &E[i];
        } else {
            struct Employee *temp = buckets[id];
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = &E[i];
        }
    }

    int index = 0;
    for (int i = 0; i < bucket_size; i++) {
        struct Employee *temp = buckets[i];
        while (temp != NULL) {
            E[index++] = *temp;
            temp = temp->next;
        }
    }
}

void radix_sorting(struct Employee E[100], int n) {
    int max_id = E[0].id;
    for (int i = 1; i < n; i++) {
        if (E[i].id > max_id) {
            max_id = E[i].id;
        }
    }

    for (int exp = 1; max_id / exp > 0; exp *= 10) {
        struct Employee output[n];
        int count[10] = {0};

        for (int i = 0; i < n; i++) {
            count[(E[i].id / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            output[count[(E[i].id / exp) % 10] - 1] = E[i];
            count[(E[i].id / exp) % 10]--;
        }

        for (int i = 0; i < n; i++) {
            E[i] = output[i];
        }
    }
}

void linear_search(struct Employee E[100], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (E[i].id == key) {
            printf("Employee found: %d %s %s\n", E[i].id, E[i].name, E[i].designation);
            return;
        }
    }
    printf("Employee with id %d not found.\n", key);
}

void binary_search(struct Employee E[100], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (E[mid].id == key) {
            printf("Employee found: %d %s %s\n", E[mid].id, E[mid].name, E[mid].designation);
            return;
        }
        if (E[mid].id < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Employee with id %d not found.\n", key);
}

void sentinel_search(struct Employee E[100], int n, int key) {
    struct Employee last = E[n - 1];
    E[n - 1].id = key;

    int i = 0;
    while (E[i].id != key) {
        i++;
    }

    E[n - 1] = last;

    if (i < n - 1 || E[n - 1].id == key) {
        printf("Employee found: %d %s %s\n", E[i].id, E[i].name, E[i].designation);
    } else {
        printf("Employee with id %d not found.\n", key);
    }
}