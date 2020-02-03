// http://codeup.cn/problem.php?cid=100000596&pid=0 

/*
本题的数据结构需要思考后敲定，最终采用哈希映射。
大数组尽量定义在主函数外。本题如定义在主函数内则本地编译器提示栈溢出，OJ编译正常
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX=26*26*26*10;

int hashFunc(char s[]){
	int id = 0;
	for (int i=0; i<3; i++){
		id = id*26+(s[i]-'A');
	}
	id = id*10+(s[3]-'0');
	return id;
}

vector<int> stu[MAX];
int main() {
	int n, k;
	while(scanf("%d %d", &n, &k) != EOF){
		while (k--){
			int classNum, stuNum;
			scanf("%d %d", &classNum, &stuNum);
			while (stuNum--){
				char stuName[10];
				scanf("%s", stuName);
				int id = hashFunc(stuName);
				stu[id].push_back(classNum);
			}
		}
		while(n--){
			char stuName[10];
			scanf("%s", stuName);
			int id = hashFunc(stuName);
			sort(stu[id].begin(), stu[id].end());
			printf("%s %d", stuName, stu[id].size());
			for (int i=0; i<stu[id].size(); i++){
				printf("% d", stu[id][i]); 
			}
			printf("\n");
		}
	}
	return 0;
}