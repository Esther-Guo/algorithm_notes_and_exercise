// 2-路归并排序（递归）
const int maxn = 100;

// 将数组A的[L1,R1]和[L2,R2]区间合并为有序区间(L2 = R1+1)
void merge(int A[], int L1, int R1, int L2, int R2){
    int i=L1, j=L2; // i指向A[L1], j指向A[L2]
    int temp[maxn], index=0; // temp临时存放归并后的数组，index为其下标
    while (i<=R1 && j<=R2){
        if (A[i] <= A[j]) temp[index++] = A[i++];
        else temp[index++] = A[j++];
    }
    // 放入剩余元素
    while (i<=R1) temp[index++] = A[i++];
    while (j<=R2) temp[index++] = A[j++];
    // 合并后数组放回A
    for (int i=0;i<index;i++){
        A[L1+i] = temp[i];
    }
}

// 将A数组[left,right]区间递归排序
void mergeSort(int A[], int left, int right){
    if (left<right){
        int mid = (left+right)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid+1, right);
        merge(A, left, mid, mid+1, right);
    }
}