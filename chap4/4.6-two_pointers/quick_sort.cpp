// 快速排序

// 对[left,right]区间进行划分
int partition(int A[], int left, int right){
    int temp = A[left]; // 取第一个元素，把A[left]位置空出
    while (left < right){ // 只要left和right不相遇
        while (left < right && temp < A[right]) right--; // 反复左移right
        A[left] = A[right]; // 将第一个<=temp的元素移至左侧，空出A[right]
        while (left < right && temp >= A[left]) left++; // 反复右移left。注意等号！
        A[right] = A[left]; // 将第一个>=temp的元素移至右侧，空出A[left]
    }
    A[left] = temp; // 把temp放在left与right相遇的位置
    return left; // 返回相遇位置的下标
}

// 快速排序，left与right初值为首尾下标
void quickSort(int A[], int left, int right){
    if (left < right){
        int pos = partition(A, left, right); // 将[left, right]按A[left]一分为二
        quickSort(A, left, pos-1); // 两个区间不包括pos
        quickSort(A, pos+1, right);
    }
}