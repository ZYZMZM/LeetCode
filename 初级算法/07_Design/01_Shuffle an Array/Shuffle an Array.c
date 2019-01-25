/*
    算法思想：首先定义结构体元素，数组长度，原始数组和打乱数组
    初始化结构体成员，使用memcpy函数将原始数组初始化
    返回原始数组，首先将长度存入*returnSize，然后直接返回数组
    打乱数组：生成数组下标的随机值，然后与对应位置元素互换即可
*/
typedef struct {
    int size;
    int *original;
    int *array;
} Solution;

Solution* solutionCreate(int* nums, int size) {
    Solution *solu = (Solution *)malloc(sizeof(Solution));
    solu->original = (int *)malloc(sizeof(int) *size);
    solu->size = size;
    memcpy(solu->original, nums, sizeof(int) *size);
    solu->array = nums;
    return solu;
}

/** Resets the array to its original configuration and return it. */
int* solutionReset(Solution* obj, int *returnSize) {
    *returnSize = obj->size;
    return obj->original;
}

/** Returns a random shuffling of the array. */
int* solutionShuffle(Solution* obj, int *returnSize) {
    
    int randNum = 0;
    for(int i = 0; i < obj->size; i++)
    { 
        randNum = rand()%(obj->size);  // 生成数组下标的随机值
        
        int temp = obj->array[i];
        obj->array[i] = obj->array[randNum];
        obj->array[randNum] = temp;
    }
    *returnSize = obj->size;
    return obj->array;
}

void solutionFree(Solution* obj) {
  //  free(obj->size); 
    free(obj->original);
    free(obj->array);
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * struct Solution* obj = solutionCreate(nums, size);
 * int* param_1 = solutionReset(obj);
 * int* param_2 = solutionShuffle(obj);
 * solutionFree(obj);
 */