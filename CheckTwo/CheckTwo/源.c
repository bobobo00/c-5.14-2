#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>
void Check(int arr[], int len){
	int i = 0;
	int tmp = 0;
	int k = 0;
	int s = 0;
	//����ֻ����һ�����ֵ����Ľ��tmp
	for (i = 0; i < len; i++){
		tmp = tmp^arr[i];
	}
	//�ҳ�������ĵ�һ��Ϊ1��λ��count
	int count = 0;
	for (i =31; i >= 0; i--){
		if((tmp >> i) &1){
			count = i;
		}
	}
	//������ֳ����������飬ÿ������ֻ��һ������һ�ε�����
	for (i = 0; i < len; i++){
		if ((arr[i] >> count )& 1){
			k = k^arr[i];
		}
		else{
			s = s^arr[i];
		}
	}
	//�ֱ��������������������ҳ�ֻ����һ�ε����ִ�ӡ
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