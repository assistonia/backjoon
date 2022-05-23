#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int inorder[100000], postorder[100000];

//재귀함수 이용
void makefreeorder(int in_l, int in_r, int post_l, int post_r)  //프리오더로 변환해주는 함수  inord 시작 끝 postord 시작 끝
{
	int i;
	if (post_l <= post_r) {
		int head = postorder[post_r];
		printf("%d ", head);
		for (i = in_l; inorder[i] != head; i++); 
		int l_num = i - in_l;
		int r_num = in_r - i;
		makefreeorder(in_l, in_l + l_num - 1, post_l, post_l + l_num - 1); //왼쪽
		makefreeorder(in_r - r_num + 1, in_r, post_r - r_num, post_r - 1); //오른쪽
	}
}


int main(void)
{
	int n;
	
	int i;


	

	scanf("%d", &n);//n입력받기

	for (i = 0; i < n; i++)//인오더 입력받기
	{
		scanf("%d", &inorder[i]);

	}
	for (i = 0; i < n; i++)//포스트오더 입력받기
	{
		scanf("%d", &postorder[i]);
	}
	
	makefreeorder(0, n - 1, 0, n - 1);

	return 0;
}