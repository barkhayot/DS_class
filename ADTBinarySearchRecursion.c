stdio.h>

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

int BinarySearchRecursion(int a[],int l, int h, int key)
{
	int mid;

	if(l<=h)
	{
		mid =(l+h)/2;
		if(key == a[mid])
			return mid;
		else if(key<a[mid])
			return BinarySearchRecursion(a, l, mid-1, key);
		else 
			return BinarySearchRecursion(a, mid+1, h, key);
	}
	return -1;

		
}


int main() {
    struct Array arr = {{2,4,6,7,3}, 10, 5};

	printf("Binary Index Recursion is %d\n", BinarySearchRecursion(arr.A, 0, arr.length, 6));
	Display(arr);
    return 0;
}
