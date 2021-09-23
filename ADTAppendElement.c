#include <stdio.h>

struct Array 
{
	int A[10];
	int size;
	int length;
};

void Append(struct Array *arr, int x){
	if(arr->length<arr->size)
		arr->A[arr->length++]=x;
}

void Display(struct Array arr){
	int i;
	for(i=0; i<arr.length; i++)
		printf("%d\n", arr.A[i]);
}

int main() {
    struct Array arr = {{2,4,6,7,3}, 10, 5};

	Append(&arr, 30);
	Display(arr);
    return 0;
}
