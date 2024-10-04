#include "get_next_line_bonus.h" // Para la parte bonus
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdarg.h>

void testGnlBonus(int file_count, char *test_name, ...)
{
    int *fds;
    char **lines;
    int i = 0, files_remaining = file_count;

    printf("----------------------------------------------------------\n");
    printf("-> TEST BONUS %s\n", test_name);					
    printf("----------------------------------------------------------\n");

    // Inicializamos arrays para los fd y las líneas actuales
    fds = malloc(file_count * sizeof(int));
    lines = malloc(file_count * sizeof(char*));

    // Abrimos los archivos pasados como argumentos
    va_list args;
    va_start(args, test_name);
    for (int j = 0; j < file_count; j++) {
        char *file_path = va_arg(args, char*);
        fds[j] = open(file_path, O_RDONLY);
        if (fds[j] < 0) {
            perror("Error opening file");
            va_end(args);
            free(fds);
            free(lines);
            return;
        }
        lines[j] = get_next_line(fds[j]);  // Leemos la primera línea de cada archivo
    }
    va_end(args);

    // Mientras queden archivos por leer
    while (files_remaining > 0) {
        for (int j = 0; j < file_count; j++) {
            if (lines[j] != NULL) {
                printf("File %d - Line %d: '%s'\n", j + 1, i, lines[j]);
                free(lines[j]);  // Liberamos la línea después de imprimirla
                lines[j] = get_next_line(fds[j]);  // Leemos la siguiente línea del archivo
                if (lines[j] == NULL) {
                    files_remaining--;  // Si el archivo se ha leído completamente, lo descontamos
                }
            }
        }
        i++;
    }

    // Cerramos todos los archivos
    for (int j = 0; j < file_count; j++) {
        close(fds[j]);
    }

    // Liberamos memoria
    free(fds);
    free(lines);

    printf("\n");
    printf("\n");
}

int main(void)
{
    testGnlBonus(4, "GNL Bonus Example", "./example.txt", "./file1.txt", "./file2.txt", "./file3.txt");
}
