#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "get_next_line.h"

void test_file(const char *filename, const char *expected[]) {
    int fd;
    char *line;
    int i = 0;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error al abrir el archivo");
        return;
    }

    while ((line = get_next_line(fd)) != NULL) {
        if (expected != NULL && expected[i] != NULL) {
            // Si se proporciona un array expected, compara las líneas
            printf("Recibido: '%s', Esperado: '%s'\n", line, expected[i]);
            if (strcmp(line, expected[i]) != 0) {
                printf("Error: Línea inesperada.\n");
            }
            i++;
        } else {
            // Si no hay expected, solo imprime la línea obtenida
            printf("Recibido: '%s'\n", line);
        }
        free(line);
    }

    if (expected != NULL && expected[i] != NULL) {
        printf("Error: Se esperaba más líneas.\n");
    }

    close(fd);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <nombre_del_archivo>\n", argv[0]);
        fprintf(stderr, "Proporciona al menos un archivo para probar.\n");
        return EXIT_FAILURE;
    }

    // Prueba cada archivo proporcionado
    for (int i = 1; i < argc; i++) {
        printf("\nPrueba del archivo: %s\n", argv[i]);
        test_file(argv[i], NULL); // Se proporciona NULL porque no hay valores esperados específicos
    }
    return EXIT_SUCCESS;
}
