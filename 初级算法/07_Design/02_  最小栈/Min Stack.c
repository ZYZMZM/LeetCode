/*
    算法思想：首先定义结构体成员，栈数据元素，长度，栈顶指针(下标模拟)
    最小栈 共四个成员变量
    初始化两个栈，最小栈和数据栈，注意最小栈的Min为空，数据栈的Min为初始
    化的最小栈
*/
typedef struct MinStack{
    int *elem;
    int size;
    int top;
    struct MinStack *Min;
}MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    MinStack *minstack = (MinStack *)malloc(sizeof(MinStack));
    minstack->elem = (int *)malloc(sizeof(int) * maxSize);
    minstack->size = maxSize;
    minstack->top = -1;
    minstack->Min = NULL;
    
    MinStack *stack = (MinStack *)malloc(sizeof(MinStack));
    stack->elem = (int *)malloc(sizeof(int) * maxSize);
    stack->size = maxSize;
    stack->top = -1;
    stack->Min = minstack;
    
    return stack;
}

void minStackPush(MinStack* obj, int x) {
    int Curmin = 0;
    if(obj->top < 0)  
        Curmin = x;
    else
    {
        Curmin = minStackTop(obj->Min);
        if(x < Curmin)
            Curmin = x;
    }
    obj->top++;
    obj->Min->top++;
    obj->elem[obj->top] = x;
    obj->Min->elem[obj->Min->top] = Curmin;
}

void minStackPop(MinStack* obj) {
    obj->top--;
    obj->Min->top--;
}

int minStackTop(MinStack* obj) {
    return obj->elem[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return minStackTop(obj->Min);
}

void minStackFree(MinStack* obj) {
    free(obj->Min);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */