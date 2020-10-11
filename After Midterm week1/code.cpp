#include<iostream>

using namespace std;

int array_output[100][100];
int array_loop[100], array_input[100], Count[100];

void print(int array_input[100], int array_output[100][100], int* count, int Count[100]) {
	cout << "\n\nOUTPUT";
	int sum;
	for (int i = 0; i < *count; i++) {
		sum = 0;
		cout << "\n" << array_input[i] << " = ";
		for (int j = Count[i] - 1; j >= 0; j--) {
			cout << array_output[i][j];
			sum += array_output[i][j];
		}
		if (Count[i] % 2 == 0 && sum % 2 == 0) {
			cout << "   Even";
		}
		else {
			cout << "   Odd";
		}
	}
}

int check_num_loop() {
	bool Pass = false;
	int base;
	while (Pass != true) {
		cout << "Base Number : ";
		cin >> base;
		if (base > 0 && base <= 10) {
			Pass = true;
		}
		else {
			if (base < 0) {
				cout << "Your Input Base Number is lower than 0 ";
			}
			else if (base > 10) {
				cout << "Your Input Base Number is greater than 10 ";
			}
			else {
				cout << "Your Input Base Number is 0 ";
			}
			Pass = false;
			cout << "\nPlease Input Base Number Again\n\n";
		}
	}
	return base;
}

void num_loop(int array_loop[100], int base, int* count) {
	cout << "Number Loop : ";

	int keep, number_loop, temp = *count;
	cin >> number_loop;
	keep = number_loop;
	while (number_loop != 0) {
		if (number_loop % base < 0) {
			array_loop[temp] = (number_loop % base) * -1;
		}
		else {
			array_loop[temp] = number_loop % base;
		}
		number_loop /= base;
		temp++;
	}
	*count = temp;
	cout << "\n = ";
	if (keep < 0) {
		cout << "-";
	}
	for (int i = *count - 1; i >= 0; i--) {
		cout << array_loop[i];
	}
}

void Input(int array_input[100], int array_output[100][100], int base, int* count, int Count[100]) {
	cout << "\n\nNumber of Input = " << *count << "\n\n";
	int temp, j = 0;
	for (int i = 0; i < *count; i++) {
		cout << "\nInput " << i + 1 << " : ";
		cin >> array_input[i];
		temp = array_input[i];
		j = 0;
		Count[i] = 0;
		while (temp != 0) {
			int num;
			num = temp % base;
			array_output[i][j] = num;
			temp /= base;
			j++;
			Count[i]++;
		}
	}
}

int main() {
	int count = 0;

	int base = check_num_loop();

	num_loop(array_loop, base, &count);

	Input(array_input, array_output, base, &count, Count);

	print(array_input, array_output, &count, Count);
	return 0;
}