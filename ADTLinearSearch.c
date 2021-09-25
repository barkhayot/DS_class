#include <stdio.h>

struct Array 
{
	int A[10];
	int size;
	int length;
};


void Display(struct Array arr){
	int i;
	for(i=0; i<arr.length; i++)
		printf("%d\n", arr.A[i]);
}

int LinearSearch(struct Array arr, int key)
{
	int i;

	for(i=0; i<arr.length; i++)
		{
			
		if(key==arr.A[i])
			return i;
		}
	return -1;
	
}


int main() {
    struct Array arr = {{2,4,6,7,3}, 10, 5};

	printf("Linear Search is %d\n", LinearSearch(arr, 7));
	Display(arr);
    return 0;
}
  
