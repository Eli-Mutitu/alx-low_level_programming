#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <elf.h>

void print_error(const char *message) {
    fprintf(stderr, "%s\n", message);
    exit(98);
}

void print_elf_header(const char *filename) {
    int fd;
    Elf64_Ehdr header;
    ssize_t bytes_read;

    /* Open the ELF file */
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        print_error("Error opening file");
    }

    /* Read ELF header */
    bytes_read = read(fd, &header, sizeof(header));
    if (bytes_read != sizeof(header)) {
        print_error("Error reading ELF header");
    }

    /* Check ELF magic number */
    if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0) {
        print_error("Not an ELF file");
    }

    /* Print ELF header information */
    printf("ELF Header:\n");
    printf("  Magic:   ");
    int i;
    for (i = 0; i < SELFMAG; i++) {
        printf("%02x ", header.e_ident[i]);
    }
    printf("\n");

    printf("  Class:                             %s\n", (header.e_ident[EI_CLASS] == ELFCLASS64) ? "ELF64" : "ELF32");
    printf("  Data:                              %s\n", (header.e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" : "2's complement, big endian");
    printf("  Version:                           %d (current)\n", header.e_ident[EI_VERSION]);
    printf("  OS/ABI:                            ");
    switch (header.e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
        case ELFOSABI_HPUX: printf("UNIX - HP-UX\n"); break;
        case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
        case ELFOSABI_LINUX: printf("UNIX - Linux\n"); break;
        case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
        case ELFOSABI_IRIX: printf("UNIX - IRIX\n"); break;
        case ELFOSABI_FREEBSD: printf("UNIX - FreeBSD\n"); break;
        case ELFOSABI_TRU64: printf("UNIX - TRU64\n"); break;
        case ELFOSABI_ARM: printf("ARM\n"); break;
        case ELFOSABI_STANDALONE: printf("Standalone (embedded) application\n"); break;
        default: printf("<unknown: %d>\n", header.e_ident[EI_OSABI]); break;
    }
    printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);
    printf("  Type:                              ");
    switch (header.e_type) {
        case ET_NONE: printf("NONE (No file type)\n"); break;
        case ET_REL: printf("REL (Relocatable file)\n"); break;
        case ET_EXEC: printf("EXEC (Executable file)\n"); break;
        case ET_DYN: printf("DYN (Shared object file)\n"); break;
        case ET_CORE: printf("CORE (Core file)\n"); break;
        default: printf("<unknown: %d>\n", header.e_type); break;
    }
    printf("  Entry point address:               0x%lx\n", (unsigned long) header.e_entry);

    /* Close the file descriptor */
    close(fd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_error("Usage: elf_header elf_filename");
    }

    print_elf_header(argv[1]);

    return 0;
}

