/*
    算法思想：括号匹配问题是栈的一个应用，我们使用数组模拟栈的实现
    基本思想是遇到左括号进行压栈操作，遇到右括号将栈顶元素弹出进行
    匹配，不匹配直接返回false，匹配继续遍历，直至遍历完毕，最后判
    断栈是否为空，若不为空，则说明没有全部匹配，返回false；反之，
    匹配成功，返回true
*/
void Push(int *stack, int *top, int val)
{
    stack[(*top)++] = val;
}
char Pop(int *stack, int top)
{
    char pop = stack[top];
    return pop;
}
bool isValid(char* s) {
    if(s == "")
        return true;
    
    int stack[10000];
    int top = 0;
    int len =strlen(s);
    int i = 0;
    while(i < len)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            Push(stack,&top,s[i]);
        else if((s[i] == ')' && Pop(stack,--top) !='(')  ||
                (s[i] == ']' && Pop(stack,--top) !='[')  ||
                (s[i] == '}' && Pop(stack,--top) !='{'))
            return false;
        i++;
    }
    if(top != 0)
        return false;
    return true;
}