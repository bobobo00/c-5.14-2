#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>
void Check(int arr[], int len){
	int i = 0;
	int tmp = 0;
	int k = 0;
	int s = 0;
	//两个只出现一次数字的异或的结果tmp
	for (i = 0; i < len; i++){
		tmp = tmp^arr[i];
	}
	//找出异或结果的第一个为1的位数count
	int count = 0;
	for (i =31; i >= 0; i--){
		if((tmp >> i) &1){
			count = i;
		}
	}
	//将数组分成两个子数组，每个数组只有一个出现一次的数字
	for (i = 0; i < len; i++){
		if ((arr[i] >> count )& 1){
			k = k^arr[i];
		}
		else{
			s = s^arr[i];
		}
	}
	//分别对两个数组采用异或操作找出只出现一次的数字打印
	printf("%d\n", k);
	printf("%d\n", s);

}
int main(){
	int arr[] = { 1, 2, 3, 4, 5, 1, 2, 3 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Check(arr,len);
	system("pause");
	return 0;
}