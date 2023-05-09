#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void chkELF(unsigned char *ednt);
void prtMGC(unsigned char *ednt);
void prtCLS(unsigned char *ednt);
void prtDT(unsigned char *ednt);
void prtVRS(unsigned char *ednt);
void prtBI(unsigned char *ednt);
void prtSBI(unsigned char *ednt);
void prtTYP(unsigned int eTP, unsigned char *ednt);
void prtNTR(unsigned long int eNTR, unsigned char *ednt);
void clsELS(int elf);

/**
 * chkELF - Checks ELF file.
 * @ednt: ELF cntn MGC Num.
 *
 * Description: EXT with code 98.
 */
void chkELF(unsigned char *ednt)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (ednt[index] != 127 &&
		    ednt[index] != 'E' &&
		    ednt[index] != 'L' &&
		    ednt[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * prtMGC - Prnt MGC Num ELF.h.
 * @ednt: Pnt to ELF.
 *
 * Description: Mgc Spred spaces.
 */
void prtMGC(unsigned char *ednt)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", ednt[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * prtCLS - CLS of ELF.h.
 * @ednt: Pnt to ARRY.
 */
void prtCLS(unsigned char *ednt)
{
	printf("  Class:                             ");

	switch (ednt[EI_CLASS])
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
		printf("<unknown: %x>\n", ednt[EI_CLASS]);
	}
}

/**
 * prtDT - ELF Data.
 * @ednt: Pnt to ARRY.
 */
void prtDT(unsigned char *ednt)
{
	printf("  Data:                              ");

	switch (ednt[EI_DATA])
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
		printf("<unknown: %x>\n", ednt[EI_CLASS]);
	}
}

/**
 * prtVRS - VRSN of ELF.
 * @ednt: Pnt to ARRY.
 */
void prtVRS(unsigned char *ednt)
{
	printf("  Version:                           %d",
	       ednt[EI_VERSION]);

	switch (ednt[EI_VERSION])
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
 * prtSBI - Prnt ELF.h OS-ABI.
 * @ednt: Pnt to ARRY.
 */
void prtSBI(unsigned char *ednt)
{
	printf("  OS/ABI:                            ");

	switch (ednt[EI_OSABI])
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
		printf("<unknown: %x>\n", ednt[EI_OSABI]);
	}
}

/**
 * prtBI - ABI of ELF.
 * @ednt: Pnt to ARRY ABI.
 */
void prtBI(unsigned char *ednt)
{
	printf("  ABI Version:                       %d\n",
	       ednt[EI_ABIVERSION]);
}

/**
 * prtTYP - TYP EFL.h
 * @eTP: The ELF TYP.
 * @ednt: Pnt to ARRY.
 */
void prtTYP(unsigned int eTP, unsigned char *ednt)
{
	if (ednt[EI_DATA] == ELFDATA2MSB)
		eTP >>= 8;

	printf("  Type:                              ");

	switch (eTP)
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
		printf("<unknown: %x>\n", eTP);
	}
}

/**
 * prtNTR - ENTRY PNT ELF.
 * @eNTR: ENTRY PNT ELF.
 * @ednt: Pnt to ARRY.
 */
void prtNTR(unsigned long int eNTR, unsigned char *ednt)
{
	printf("  Entry point address:               ");

	if (ednt[EI_DATA] == ELFDATA2MSB)
	{
		eNTR = ((eNTR << 8) & 0xFF00FF00) |
			  ((eNTR >> 8) & 0xFF00FF);
		eNTR = (eNTR << 16) | (eNTR >> 16);
	}

	if (ednt[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)eNTR);

	else
		printf("%#lx\n", eNTR);
}

/**
 * clsELS - CLS ELF.
 * @elf: DSCRPT of ELF.
 *
 * Description: !CLS EXT with 98.
 */
void clsELS(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - DSP INFO ELF START.
 * @argc: Arguments SPLD To PRGM
 * @argv: ARRY to ARGM.
 *
 * Return: 0 on success.
 * Description: !ELF & !well_Fun - EXT 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		clsELS(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		clsELS(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	chkELF(header->ednt);
	printf("ELF Header:\n");
	prtMGC(header->ednt);
	prtCLS(header->ednt);
	prtDT(header->ednt);
	prtVRS(header->ednt);
	prtSBI(header->ednt);
	prtBI(header->ednt);
	prtTYP(header->eTP, header->ednt);
	prtNTR(header->eNTR, header->ednt);

	free(header);
	clsELS(o);
	return (0);
}
