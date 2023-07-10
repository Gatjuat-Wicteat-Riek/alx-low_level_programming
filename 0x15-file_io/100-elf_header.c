#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>

void print_data(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);
void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);


/**
 * check_elf - This Checks if a file is an ELF file hear
 * @e_ident: this a pointer to an elf file.
 * Description:  exits code 98 if not elf files.
 */
void check_elf(unsigned char *e_ident)
{
	int in;

	for (in = 0; in < 4; in++)
	{
		if (e_ident[in] != 127 &&
		    e_ident[in] != 'E' &&
		    e_ident[in] != 'L' &&
		    e_ident[in] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - This prints the magic number of ELF file
 * @e_ident: This is a pointer to the Array of a magic
 * Description: This indicates that magic number are separeted by spaces
 */
void print_magic(unsigned char *e_ident)
{
	int in;

	printf("  Magic:   ");

	for (in = 0; in < EI_NIDENT; in++)
	{
		printf("%02x", e_ident[in]);

		if (in == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - This prints a class of an ELF class
 * @e_ident: This is a pointer to an array
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:        ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_data - This prints a data of a header of an ELF..
 * @e_ident: This is a pointer to an array..
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_version - this prints a version of a header.
 * @e_ident: this is a pointer to an array containing 
 * the ELF version.
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:                           %d",
	       e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_osabi - This prints osabi of a header file..
 * @e_ident: this a  pointer to program of the ELF version.
 */
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_abi - this prints the osabi of an header file..
 * @e_ident: this is a pointer to an array containing the
 * ELF ABI version.
 */
void print_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

/**
 * print_type - This prints the type of ELF header file..
 * @e_type: The type of ELF file.
 * @e_ident: This is a pointer to an array containing the
 * ELF class.
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - This an entry of value to an ElF file.
 * @sle_entry: This is a adress to an entry of a file.
 * @e_ident: This is a pointer to an array contening a entry.
 */
void print_entry(unsigned long int sle_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		sle_entry = ((sle_entry << 8) & 0xFF00FF00) |
			  ((sle_entry >> 8) & 0xFF00FF);
		sle_entry = (sle_entry << 16) | (sle_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)sle_entry);

	else
		printf("%#lx\n", sle_entry);
}

/**
 * close_elf - this Closes an ELF file.
 * @sl: This is a  file descriptor of the ELF file in a
 * program entered
 * Description: exits code 98 if code fails.
 */
void close_elf(int sl)
{
	if (close(sl) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", sl);
		exit(98);
	}
}

/**
 * main - This displays the information in an ELF header file.
 * @argment: The number of arguments supplied to the program.
 * @argv: this is a pointer to an array
 * Return: 0 is return on success.
 * Description:  exits code 98 if file is not ELF file or fails.
 */
int main(int __attribute__((__unused__)) argment, char *argv[])
{
	Elf64_Ehdr *header;
	int ro, or;

	ro = open(argv[1], O_RDONLY);
	if (ro == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(ro);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	or = read(ro, header, sizeof(Elf64_Ehdr));
	if (or == -1)
	{
		free(header);
		close_elf(ro);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(ro);
	return (0);
}
