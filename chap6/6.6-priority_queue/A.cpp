// http://codeup.cn/problem.php?cid=100000601&pid=0

/*
并没有用到queue，可通过测试但不确定对。
*/

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;



int main() {
	int n;
	while (scanf("%d", &n) != EOF){
		string a;
		vector<string> tasks;
		for (int i=0; i<n; i++) {
			cin >> a;
            // 去掉 ( ) , 替换为空格
			if (a.find("(") != string::npos) a.replace(a.find("("), 1, " ");
			if (a.find(")") != string::npos) a.replace(a.find(")"), 1, " ");
			while (a.find(",") != string::npos) a.replace(a.find(","), 1, " ");
			string temp;
			int insert_pos=0;
			bool flag = false; // 标记是否插入
			for (int j=0; j<a.size(); j++){
				if (a[j]!=' ') temp += a[j]; // 根据空格取词
				else {
					if (temp == "NULL") continue; // NULL直接跳过
					if (i == 0) { // 第一组直接按顺序加入vector 
						tasks.push_back(temp);
						temp = ""; // 复原temp
						continue;
					}
                    // 遍历已有任务
					for (int k=insert_pos; k<tasks.size(); k++){
						if (temp == tasks[k]) { // temp已存在，无须再插入
							insert_pos = k; // 下次从此处开始遍历（后面的任务必须位于此任务之后）
							temp = "";
							break;
						}
						else if (temp < tasks[k]) { // 当前任务字典序小
							insert_pos = k; // 记录插入位置
							flag = true; // 标记可以插入
							break;	
						}
						if (k==tasks.size()-1) { // 遍历至末尾，说明字典序较大，插在最后
							flag = true;
							insert_pos = tasks.size();
						}
					}
					if (flag) { // 判断是否需要插入
						tasks.insert(tasks.begin()+insert_pos, temp);
						temp = ""; // 复原temp
						flag = false; // 重置flag
					}
					
				}
			}	
		}
        // 打印任务列表
		for (int i=0; i<tasks.size(); i++) {
			if (i==0) cout << tasks[i];
			else cout << " " << tasks[i];
		}
		cout << endl;
	}
	
    return 0;
}