#include <stdio.h>
#define SIZE 100
int s[SIZE];
int top=-1;
void sort(){
    int pom;
    for(int i=0; i<=top; i++){
        for(int j=i+1; j<=top; j++){
            if(s[i]>s[j]){
                pom=s[i];
                s[i]=s[j];
                s[j]=pom;
            }
        }
    }
}
void push(int x) {
    if(top<SIZE){
    s[++top]=x;
    sort();}
    else printf("STACK OVERFLOW\n");
}

int pop(){
    int el;
    if(top==-1)printf("STACK UNDERFLOW");
    else{
        el=s[top];
        top--;
    }
    return el;
}
void display(){
    if(top==-1)printf("stek je prazan");
    else{
        printf("stek\n");
    for(int i=0; i<=top; i++)
    printf("%d \n", s[i]);
}}
int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    display();
    pop();
    pop();
    display();
    push(0);
    push(8);
    push(2);
    push(3);
    display();

}
