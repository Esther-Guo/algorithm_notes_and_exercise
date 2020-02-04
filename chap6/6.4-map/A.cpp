// http://codeup.cn/problem.php?cid=100000598&pid=0 

/*
注意getline读入一行字符的方式，遇回车终止。
string类变量可以+=char 
*/

#include <cstdio>
#include <iostream> 
#include <map>
#include <string>

using namespace std;

// 判断是否为字母或数字 
bool isAlnum(char c){
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) return true;
	else return false;
}

int main() {
	string input;
	while(getline(cin, input)){
		map<string, int> words;
		string word;
		
		for (int i=0; i<input.length(); i++){
			// 首先处理该字符 
			if (isAlnum(input[i])) {
				// 大写转小写 
				if (input[i] >= 'A' && input[i] <= 'Z'){
					word += (input[i] + ('a'-'A'));
				}
				// 其余小写字母和数字的情况（不包含符号） 
				else if ((input[i] >= 'a' && input[i] <= 'z')||(input[i] >= '0' && input[i] <= '9'))
					word += input[i];
			}
			// 如果是最后一个字符（此时已经放入word），将该word放入words；
			// 或者遇到非字母数字的字符，也将此时的word放入words 
			if (i == input.length()-1 || !isAlnum(input[i])){
				if(word.length()) words[word]++;
				word = "";
			}
		}
		int max=0;
		string temp;
		for (map<string,int>::iterator it = words.begin(); it != words.end(); it++){
			//cout << it->first << it->second << endl;
			if (it->second > max) {
				max = it->second;
				temp = it->first;
			}
		}
		cout << temp << " " << max << endl;
	}
	
	
	
	return 0;
}