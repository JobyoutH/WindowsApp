# include<stdio.h>
# include"stack.h"
#include <malloc.h>
#pragma warning( disable : 4996)

/*选择法对int数组排序*/
void sort(int *a){
	int temp;
	for (int i = 0; a[i + 1] != -1; i++){
		int min_index = i;
		for (int j = i; a[j] != -1; j++){
			if (a[min_index] > a[j]){
				min_index = j;
			}
		}
		temp = a[i];
		a[i] = a[min_index];
		a[min_index] = temp;
	}
}

/*按行读取txt文件中的字符串信息，返回一个二维的字符串数组*/
char(*read())[20]{
	FILE *pFile = fopen("E:\\Documents\\Visual Studio 2013\\Projects\\FA-C\\Debug\\nfa.txt", "r");
	char *pBuf;  //定义文件指针
	fseek(pFile, 0, SEEK_END); //把指针移动到文件的结尾 ，获取文件长度
	int len = ftell(pFile); //获取文件长度
	pBuf = new char[len + 1]; //定义数组长度
	rewind(pFile); //把指针移动到文件开头 因为我们一开始把指针移动到结尾，如果不移动回来 会出错
	fgets(pBuf, len, pFile); //读文件
	int num = 0;
	for (int i = 0; pBuf[i] != ','; i++){
		num = num * 10 + pBuf[i] - '0';
	}
	char(*NFA)[20] = new char[num + 2][20];
	for (int i = 0; pBuf[i - 1] != 0; i++)
		NFA[0][i] = pBuf[i];
	for (int i = 1; i < num + 1; i++){
		fgets(NFA[i], len, pFile);
	}
	NFA[num + 1][0] = NULL;
	fclose(pFile); // 关闭文件
	return NFA;
}


/*根据读得的信息生成一个便于操作的三维int数组*/
int ***nfa(){
	char(*T)[20] = read();
	int num = 0;
	for (int i = 0; T[0][i] != ','; i++){
		num = num * 10 + T[0][i] - '0';
	}
	int state = 0;
	for (int i = 1; T[0][i] != 0; i++){
		if (T[0][i] == ','){
			state++;
		}
	}

	int ***nfa = new int **[num + 1];
	for (int i = 0; i < num; i++){
		nfa[i] = new int*[state + 1];
		nfa[i][state] = NULL;
	}
	nfa[num] = NULL;

	for (int i = 1; nfa[i - 1] != NULL; i++){
		int t = 0;
		nfa[i - 1][t] = (int*)calloc(2, sizeof(int));
		nfa[i - 1][t][0] = -1;
		nfa[i - 1][t][1] = -2;
		int x = 0;

		for (int j = 0; T[i][j] != 0; j++){
			if (T[i][j] == ';'){
				t++;
				x = 0;
				nfa[i - 1][t] = (int*)calloc(2, sizeof(int));
				nfa[i - 1][t][0] = -1;
				nfa[i - 1][t][1] = -2;
			}
			if (T[i][j] == ','){
				x++;
				nfa[i - 1][t] = (int*)realloc(nfa[i - 1][t], sizeof(int)*(x + 2));
			}
			if (T[i][j]<'0' || T[i][j]>'9'){
				if (T[i][j] == '\n')
					break;
				continue;
			}
			else{
				nfa[i - 1][t][x] = T[i][j] - '0';
				nfa[i - 1][t][x + 1] = -2;
			}
		}
	}

	return nfa;
}

static int State = 0;					//输入符号数

/*求e_closure(T)*/
int  *e_closure(int ***nfa, int *T){
	Stack *stack = InitStack();

	int top;
	int num = 0;
	for (int i = 0; T[i] != -1; i++){
		Push(stack, T[i]);
		num++;
	}

	while (!IsEmpty(stack)){
		Pop(stack, &top);
		for (int i = 0; nfa[i] != NULL; i++){
			for (int j = 0; nfa[top][State - 1][j] != -2; j++){
				if (i == nfa[top][State - 1][j]){
					int flag = 0;
					for (int t = 0; t < num; t++){
						if (i == T[t]){
							flag = 1;
							break;
						}
					}
					if (flag == 0){
						num++;
						T = (int*)realloc(T, sizeof(int)*(num + 1));
						T[num - 1] = i;
						T[num] = -1;
						Push(stack, i);
					}
				}
			}
		}
	}

	sort(T);
	return T;
}

/*move(T,a)操作*/
int *move(int ***nfa, int *T, int a){
	int *result = new int[1]{-1};
	int num = 0;
	for (int i = 0; T[i] != -1; i++){
		if (nfa[T[i]][a - 1][0] == -1){
			continue;
		}
		for (int j = 0; nfa[T[i]][a - 1][j] != -2; j++){
			int flag = 0;
			for (int t = 0; result[t] != -1; t++){
				if (result[t] == nfa[T[i]][a - 1][j]){
					flag = 1;
					break;
				}
			}
			if (flag == 0){
				num++;
				result = (int *)realloc(result, sizeof(int)*(num + 1));
				result[num - 1] = nfa[T[i]][a - 1][j];
				result[num] = -1;
			}
		}
	}
	sort(result);
	return result;
}

/*主函数，但是生成Dtran的操作是在主函数中完成的*/
int main(){
	int*** NFA = nfa();
	while (NFA[0][++State] != NULL){
	}
	int dsnum = 0;
	int dsflag = 0;
	int *s0 = new int[2]{ 0, -1 };
	int **Dstate = new int*[2];
	Dstate[1] = NULL;
	Dstate[dsnum] = e_closure(NFA, s0);	//Dtran状态集合Dstate
	dsnum++;							//Dtran中状态数，初始为1
	char **Dtran = new char*[1];
	Dtran[0] = (char*)calloc(4, sizeof(char));
	Dtran[0][0] = 'A';

	/*生成Dtran*/
	while (dsflag < dsnum){
		for (int i = 1; i < State; i++){
			int flag = 0;
			int*u = e_closure(NFA, move(NFA, Dstate[dsflag], i));
			for (int j = 0; j < dsnum; j++){
				for (int t = 0; Dstate[j][t] != -1; t++){
					if (Dstate[j][t] != u[t]){
						break;
					}
					if (Dstate[j][t + 1] == -1 && u[t + 1] == -1){
						flag = 1;
						Dtran[dsflag][i] = 'A' + j;
					}
				}
				if (flag == 1)
					break;
				Dtran[dsflag][i] = 'A' + j + 1;
			}
			if (flag == 0){
				dsnum++;
				Dstate = (int**)realloc(Dstate, sizeof(int*)*(dsnum + 1));
				Dstate[dsnum - 1] = u;
				Dstate[dsnum] = NULL;
				Dtran = (char**)realloc(Dtran, sizeof(char*)*dsnum);
				Dtran[dsnum - 1] = (char*)calloc(4, sizeof(char));
				Dtran[dsnum - 1][0] = 'A' + dsnum - 1;
			}
		}
		dsflag++;
	}

	/*输出状态集合*/
	for (int i = 0; i < dsnum; i++){
		printf("%c:{", 'A' + i);
		for (int j = 0; Dstate[i][j] != -1; j++){
			printf("%d", Dstate[i][j]);
			if (Dstate[i][j + 1] != -1)
				printf(",");
			else
				printf("}");
		}
		printf("\n");
	}

	/*输出状态转换表*/
	printf("\ns ");
	for (int i = 0; i < State - 1; i++){
		printf("%c ", 'a' + i);
	}
	printf("\n-----\n");

	for (int i = 0; i < dsnum; i++){
		for (int j = 0; j < State; j++){
			printf("%c ", Dtran[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	/*释放动态数组*/
	for (int i = 0; NFA[i] != NULL; i++){
		for (int j = 0; NFA[i][j] != NULL; j++){
			free(NFA[i][j]);
		}
		free(NFA[i]);
	}
	for (int i = 0; i < State; i++){
		free(Dtran[i]);
	}
	free(Dtran);
	free(NFA);

	return 0;
}