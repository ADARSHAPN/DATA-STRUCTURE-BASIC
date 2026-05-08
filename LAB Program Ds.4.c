#include<stdio.h>
#define MAX 5

int stack[MAX],
top = -1;

//Push
void push(int value) {
    if (top == MAX-1){
        printf("Stack overflow\n");
        return;
    }
    else{
        top++;
        stack[top] = value;
    printf("Pushed %d\n", value);
}
}
//Pop   
void pop() {
    if (top == -1)
        printf("Stack underflow\n");
    
    else{
        printf("Popped %d\n", stack[top]);
        top--;
    }
}
//Display
void display() {
    if (top == -1)
        printf("Stack is empty\n");
    else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}
int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60); // This will cause stack overflow

    display();

    pop();
    pop();
    pop();
    pop();
    pop();
    pop(); // This will cause stack underflow

    display();

    return 0;
}

OUTPUT
Pushed 10
Pushed 20
Pushed 30
Pushed 40
Pushed 50
Stack overflow
Stack elements: 50 40 30 20 10 
Popped 50
Popped 40
Popped 30
Popped 20
Popped 10
Stack underflow
Stack is empty
