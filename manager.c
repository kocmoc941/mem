#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define EXIT_SUCCESS 0

#define SIZE 1024
static uint8_t PhysicalData[SIZE] = {0};

struct Header
{
	uint32_t free_bytes;
	uint8_t *data;
};

void init()
{
	struct Header *ptr = (struct Header *)&PhysicalData[0];
	ptr->free_bytes = SIZE - (sizeof(struct Header) - sizeof(uint8_t *));
	ptr->data = (uint8_t *)ptr;
}

void *mAlloc(uint32_t size)
{
	struct Header *ptr = (struct Header *)&PhysicalData[0];
	uint8_t *rawData = ptr->data;
	ptr->data += (size + sizeof(struct Header));
	ptr->free_bytes -= size;
	return rawData;
}

int main(int argc, char **argv)
{
	init();
	struct Header *ptr = (struct Header *)&PhysicalData[0];
	char *data = mAlloc(10);
	char *data2 = mAlloc(10);
	strcpy(data, "hello");
	strcpy(data2, "1h1e1");
	printf("free bytes %d\n", ptr->free_bytes);
	printf("data1:%s\n", data);
	printf("data2:%s", data2);
	return EXIT_SUCCESS;
}