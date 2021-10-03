#include <stdio.h>
#include <stdlib.h>

struct Stack
{
  int top;
  int size;
  int *S;
};


//createStack fuction 
void createStack(struct Stack *st)
{
  printf("Enter The size : " );
  scanf("%d", &st->size);
  st->top=-1;
  st->S=(int*)malloc(st->size*sizeof(int));
}


// Displaying elements
void Display(struct Stack st)
{
  int i;
  for(i=st.top; i>=0; i--)
    printf("%d ", st.S[i]);
  printf(" \n");
}

// pushing elements to the Stack
void push(struct Stack *st, int x)
{
  if(st->top==st->size-1)
  {
    printf("StackOverflow");
  }
  else{
    st->top++;
    st->S[st->top]=x;
  }
}


// poping / deleting elements from the Stack
int pop(struct Stack *st)
{
  int x=-1;
  if(st->top==-1){
    printf("StackUnderflow");
  }
  else{
    x=st->S[st->top];
    st->top--;
  }
  return x;
}


// peeking the top element from the Stack
int peek(struct Stack st, int index)
{
  int x = -1;
  if(st.top-index+1<0){
    printf("Invalid Index\n");
  }
  else{
    x=st.S[st.top-index+1];
    printf("%d\n", x);
  }
  return x;
}


// checking if the Stack is empty
int isEmpty(struct Stack st)
{
 if(st.top==-1)
  return 1;
 return 0;
}


//checking if the Stack is full 
int isFull(struct Stack st)
{
 return st.top==st.size-1;
}

// checking the top element on the stack
int stackTop(struct Stack st)
{
 if(!isEmpty(st))
  return st.S[st.top];
 return -1;
}


// main fuction
int main(void) {
  struct Stack st;
  createStack(&st);

  push(&st, 20);
  push(&st, 40);

  peek(st, 1);
  //pop(&st);

  Display(st);


  return 0;
}
