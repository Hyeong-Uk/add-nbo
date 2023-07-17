#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc != 3) {
		fprintf(stderr, "Please run this program with this form: ./add-nbo <file1> <file2>\n");
		exit(0);
	}

	FILE *fp1 = fopen(argv[1], "r");
	FILE *fp2 = fopen(argv[2], "r");

	if (fp1 == NULL) {
		fprintf(stderr, "%s open error\n", argv[1]);
		exit(0);
	}
	if (fp2 == NULL) {
                fprintf(stderr, "%s open error\n", argv[2]);
		exit(0);
	}

	uint32_t *buff1 = malloc(sizeof(uint32_t));
	uint32_t *buff2 = malloc(sizeof(uint32_t));
	size_t ret1 = fread(buff1, 4, 1, fp1);
	size_t ret2 = fread(buff2, 4, 1, fp2);
	
	if (ret1 == 0 || ret2 == 0) {
		printf("0..0\n");
		return 0;
	}
	uint32_t n1 = ntohl(*buff1);
	uint32_t n2 = ntohl(*buff2);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", n1, n1, n2, n2, n1+n2, n1+n2);

	return 0;
}
