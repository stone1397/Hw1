#include<iostream>

int SaveInput();
void SelectMode();
void SumAverage(int array[], int length); // 함수 선언

void AscendingSort(int array[], int length);
void DescendingSort(int array[], int length);

int main() {
	SelectMode();

	return 0;
}

int SaveInput() {
	int num;
	std::cout << "숫자를 입력해주세요: ";
	std::cin >> num;
	return num;
}

void SelectMode() {
	// 숫자를 저장할 배열을 생성
	int array[5] = { 0, 0, 0, 0, 0 };
	int mode;

	std::cout << "**********Select Mode**********" << std::endl;
	std::cout << "Sum & Average: 0" << std::endl;
	std::cout << "Ascending Sort: 1" << std::endl;
	std::cout << "Descending Sort: 2" << std::endl;

	std::cin >> mode;



/*수정 전
	switch (mode) {
	case 0:
		// 사용자로부터 5개의 숫자를 입력 받아 배열에 저장
		for (int i = 0; i <= 4; i++) {
			std::cout << "숫자를 입력해주세요: " << std::endl;
			std::cin >> array[i];
		}
		SumAverage(array, 5);
		break; // break가 없으면 다음 case가 실행됨. 주의!

	case 1:
		AscendingSort(array, 5);
		break; 

	case 2:
		DescendingSort(array, 5);
		break;

	default:
		std::cout << "잘못 입력하셨습니다. 다시 플레이해주세요." << std::endl;
	}

}
*/

// 수정 후: 함수 포인터 배열 사용, 함수 포인터 배열에 각각의 함수의 주소를 저장
	void (*operations[])(int[], int) = { SumAverage, AscendingSort, DescendingSort };

	if (mode >= 0 && mode <= 2) {
		operations[mode](array, 5);
	}
	else {
		std::cout << "잘못된 입력입니다. 프로그램을 종료합니다." << std::endl;
	}
}
// 함수를 정의한다.
void SumAverage(int array[], int length) {
// 합계와 평균을 저장할 변수를 선언한다.
	float sum = 0;
	float average;
	
	for (int i = 0; i < length; i++) {
		array[i] = SaveInput();
		sum += array[i];
	}
	average = (sum / 5.0);

// 합계와 평균을 출력한다.
	std::cout << "Sum: " << sum << std::endl;
	std::cout << "Average: " << average << std::endl;

}

//삽입 정렬을 사용하여 구현한다.(데이터가 적을 때 매우 유용하므로)
void AscendingSort(int array[], int length) {	
	for (int i = 0; i < length; i++) {	
		int num = SaveInput();
		
		// 대소를 비교하여 배열의 빈 자리를 찾는다.
		// 1. 삽입된 것이 더 크다. 옆으로 이동하지 않음
		// 2. 기존의 것이 더 크다. 기존의 것이 옆으로 이동
		int j = i - 1;
		
		while(array[j] > num && j >= 0) {
			array[j + 1] = array[j];
			j--;
		}
		// 빈 자리에 삽입된 숫자가 들어간다.
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

		// 배열의 빈 자리를 찾기
		int j = i - 1;
		while (j >= 0 && array[j] < num) {
			array[j + 1] = array[j]; // 오른쪽으로 이동
			j--;
		}
		array[j + 1] = num; // 삽입
	}

	// 결과 출력
	std::cout << "Descending Sorted Array: ";
	for (int i = 0; i < length; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}