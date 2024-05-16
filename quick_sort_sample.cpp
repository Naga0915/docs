#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ARY_LEN 10
#define ARY_NUM_MAX 10
#define ARY_NUM_MIN -10

//数字入れ替え
void swap(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

//クイックソート
void quickSort(int* data, int left, int right) {
	int pivot;
	int i, j;

	//探索範囲がない場合終了
	if (left >= right) {
		return;
	}

	//pivot選択
	//一番左の要素をpivotに設定
	pivot = data[left];

	i = left;
	j = right;

	//配列をpivot以上と未満に分ける
	while (true) {
		//pivot以上を左から探索
		while (data[i] < pivot) {
			i++;
		}

		//pivot未満を右から探索
		while (data[j] > pivot) {
			j--;
		}

		//探索範囲が被っていれば分割終了
		if (i >= j) break;

		//探索した２つの値を交換
		swap(&data[i], &data[j]);

		//交換後の数字の次から探索再開
		i++;
		j--;
	}

	//再帰的に呼び出す
	//pivot未満のグループをソート
	quickSort(data, left, i - 1);

	//pivot以上のグループをソート
	quickSort(data, j + 1, right);
}

//配列にランダム値を格納
void arrayRnd(int* data, int max, int min) {
	int range = max - min + 1;
	for (int i = 0; i < ARY_LEN; i++) {
		data[i] = min + (rand() % range);
	}
}

//配列の中身を表示
void printArray(int a[], int num) {
	int i;
	for (i = 0; i < num; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main(void) {
	int data[ARY_LEN];

	//乱数シード設定
	srand((unsigned int)time(NULL));

	arrayRnd(data, ARY_NUM_MAX, ARY_NUM_MIN);

	printf("ソート前:");
	printArray(data, ARY_LEN);

	//クイックソート
	//leftは0、rightは(配列の長さ - 1)を引数として渡す
	quickSort(data, 0, ARY_LEN - 1);

	printf("ソート後:");
	printArray(data, ARY_LEN);

	return 0;
}
