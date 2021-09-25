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

BinarySearch(struct Array arr, int key)
{
	int l = 0;
	int h = arr.length-1;
	int mid;

	while(l<=h)
		{
			mid = (l+h)/2;
			if(key == arr.A[mid])
				return mid;
			else if (key<arr.A[mid])
				h=mid-1;
			else
				l=mid+1;
		}
	return -1;
}



int main() {
    struct Array arr = {{2,4,6,7,3}, 10, 5};

	printf("Binary Index is %d\n", BinarySearch(arr, 6));
	Display(arr);
    return 0;
}
