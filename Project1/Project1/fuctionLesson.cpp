#include<iostream>
#include<math.h>

using namespace std;

template<class T> T test(T a, T b) {
	return a + b;
}

int square(int num) {
	return num * num;
}

int cube(int num) {
	return num * num * num;
}

double square_root(int num) {
	return sqrt(num);
}

double sum(int arr[], int len, int(*pfuc)(int)) {
	int summary = 0;
	//for (int i : arr); ????
	return summary;
}

int length(int arr[]) {
	return sizeof(arr) / sizeof(arr[0]);
}

int main() {
	char* a;
	int arr[] = { 1, 2, 3, 4, 5 };
	cout << test(1,1) << endl;
	cout << test<int>(1.5, 1.3) << endl;
	cout << test<int>(1.5, 1.3) << endl;
	cout << sum(arr, length(arr), cube) << endl;
	for (int i : arr);
	cin.getline(a, 1);
}


// 함수 포인터 > 어떤 함수에서 같은 장소에서 다양한 함수를 써야할때, 
//		코드를 여러번 작성할 필요없이 함수의 주소를 전달하여 포인터를 이용해 사용한다.

