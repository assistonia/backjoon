#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int inorder[100000], postorder[100000];

//����Լ� �̿�
void makefreeorder(int in_l, int in_r, int post_l, int post_r)  //���������� ��ȯ���ִ� �Լ�  inord ���� �� postord ���� ��
{
	int i;
	if (post_l <= post_r) {
		int head = postorder[post_r];
		printf("%d ", head);
		for (i = in_l; inorder[i] != head; i++); 
		int l_num = i - in_l;
		int r_num = in_r - i;
		makefreeorder(in_l, in_l + l_num - 1, post_l, post_l + l_num - 1); //����
		makefreeorder(in_r - r_num + 1, in_r, post_r - r_num, post_r - 1); //������
	}
}


int main(void)
{
	int n;
	
	int i;


	

	scanf("%d", &n);//n�Է¹ޱ�

	for (i = 0; i < n; i++)//�ο��� �Է¹ޱ�
	{
		scanf("%d", &inorder[i]);

	}
	for (i = 0; i < n; i++)//����Ʈ���� �Է¹ޱ�
	{
		scanf("%d", &postorder[i]);
	}
	
	makefreeorder(0, n - 1, 0, n - 1);

	return 0;
}