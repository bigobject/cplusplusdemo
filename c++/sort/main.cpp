#include <iostream>
#include<string.h>
#include <functional>

void printarr(int* input, int len) {
	std::cout << "intput:";
	for (int i=0; i<len;i++) {
	std::cout << input[i] << " ";
	}
	std::cout << std::endl;
}
void insertsort(int* input, int len);
void quicksort(int* input, int len);
void cmbsort(int* input, int len);
int main(void)
{
	int input[] = {10,4,35,25,3,6,4,4,2,5};
	auto len = sizeof(input)/sizeof(int);
	printarr(input, len);

	int *forinsert = new int[len];
	memcpy(forinsert, input, sizeof(input));
	insertsort(forinsert, len);
	printarr(forinsert, len);
	delete []forinsert;

	
	int *forquick = new int[len];
	memcpy(forquick, input, sizeof(input));
	quicksort(forquick, len);
	printarr(forquick, len);
	delete []forquick;

	int *forcmb= new int[len];
	memcpy(forcmb, input, sizeof(input));
	cmbsort(forcmb, len);
	printarr(forcmb, len);
	delete []forcmb;

}

void insertsort(int* input, int len){
	if (nullptr == input) {
		return;
	}

	for (int i=1; i<len;i++) {
		auto target = input[i];
		auto j=i-1;
		while(j>=0 && target<input[j]) {
			auto tmp = input[j];
			input[j] = input[j+1];
			input[j+1] = tmp;
			
			j--;
		}
	}
}

void quicksort(int* input, int len){

}
void cmbsort(int* input, int len){
	std::function<void(int*, int,int)>cmb;

	cmb = [&cmb](int* input, int start,int end) {
		if (start >= end) {
			return;
		}
		auto mid = (start+end)/2;
		cmb(input, start, mid);
		cmb(input, mid+1, end);

		auto l = start;
		auto r = mid+1;
		int* sorted = new int[end-start+1];
		auto i=0;

		while (l <= mid||r <=end) {
			int *k = nullptr;
			if (l >mid) {
				k = &r;
			}else if (r > end) {
				k = &l;
			}else if (input[l] <= input[r]) {
				k = &l;
			}else {
				k = &r;
			}
			sorted[i++] = input[*k];
			(*k)++;
		}
		for (auto j=0; j<end-start+1;j++) {
			input[start+j] = sorted[j];
		}
		delete[] sorted;

	};
	cmb(input, 0, len-1);
}