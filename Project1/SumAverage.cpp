#include<iostream>

int SaveInput();
void SelectMode();
void SumAverage(int array[], int length); // �Լ� ����

void AscendingSort(int array[], int length);
void DescendingSort(int array[], int length);

int main() {
	SelectMode();

	return 0;
}

int SaveInput() {
	int num;
	std::cout << "���ڸ� �Է����ּ���: ";
	std::cin >> num;
	return num;
}

void SelectMode() {
	// ���ڸ� ������ �迭�� ����
	int array[5] = { 0, 0, 0, 0, 0 };
	int mode;

	std::cout << "**********Select Mode**********" << std::endl;
	std::cout << "Sum & Average: 0" << std::endl;
	std::cout << "Ascending Sort: 1" << std::endl;
	std::cout << "Descending Sort: 2" << std::endl;

	std::cin >> mode;



/*���� ��
	switch (mode) {
	case 0:
		// ����ڷκ��� 5���� ���ڸ� �Է� �޾� �迭�� ����
		for (int i = 0; i <= 4; i++) {
			std::cout << "���ڸ� �Է����ּ���: " << std::endl;
			std::cin >> array[i];
		}
		SumAverage(array, 5);
		break; // break�� ������ ���� case�� �����. ����!

	case 1:
		AscendingSort(array, 5);
		break; 

	case 2:
		DescendingSort(array, 5);
		break;

	default:
		std::cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �÷������ּ���." << std::endl;
	}

}
*/

// ���� ��: �Լ� ������ �迭 ���, �Լ� ������ �迭�� ������ �Լ��� �ּҸ� ����
	void (*operations[])(int[], int) = { SumAverage, AscendingSort, DescendingSort };

	if (mode >= 0 && mode <= 2) {
		operations[mode](array, 5);
	}
	else {
		std::cout << "�߸��� �Է��Դϴ�. ���α׷��� �����մϴ�." << std::endl;
	}
}
// �Լ��� �����Ѵ�.
void SumAverage(int array[], int length) {
// �հ�� ����� ������ ������ �����Ѵ�.
	float sum = 0;
	float average;
	
	for (int i = 0; i < length; i++) {
		array[i] = SaveInput();
		sum += array[i];
	}
	average = (sum / 5.0);

// �հ�� ����� ����Ѵ�.
	std::cout << "Sum: " << sum << std::endl;
	std::cout << "Average: " << average << std::endl;

}

//���� ������ ����Ͽ� �����Ѵ�.(�����Ͱ� ���� �� �ſ� �����ϹǷ�)
void AscendingSort(int array[], int length) {	
	for (int i = 0; i < length; i++) {	
		int num = SaveInput();
		
		// ��Ҹ� ���Ͽ� �迭�� �� �ڸ��� ã�´�.
		// 1. ���Ե� ���� �� ũ��. ������ �̵����� ����
		// 2. ������ ���� �� ũ��. ������ ���� ������ �̵�
		int j = i - 1;
		
		while(array[j] > num && j >= 0) {
			array[j + 1] = array[j];
			j--;
		}
		// �� �ڸ��� ���Ե� ���ڰ� ����.
		array[j + 1] = num; 
	}
	std::cout << "Ascending Sorted Array: ";
	for (int i = 0; i < length; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

void DescendingSort(int array[], int length) {
	for (int i = 0; i < length; i++) {
		int num = SaveInput();

		// �迭�� �� �ڸ��� ã��
		int j = i - 1;
		while (j >= 0 && array[j] < num) {
			array[j + 1] = array[j]; // ���������� �̵�
			j--;
		}
		array[j + 1] = num; // ����
	}

	// ��� ���
	std::cout << "Descending Sorted Array: ";
	for (int i = 0; i < length; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}