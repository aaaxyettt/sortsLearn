#include "sorts.hpp"
#include <cstring>

void swap(int &a,int  &b){
	int temp = a;
	a = b;
	b = temp;
}

//какое отношение эта функция имеет к сортировкам??? --она используется в сортировке выбором(
int search(int *ar, int size, int i){
        int min = ar[i];
        int index = 0;
        for(int j = i; j < size; j++){
                  if(ar[j] <= min){
                          min = ar[j];
                          index = j;
                  }
        }
        return index;
}


void bubbleSort(int *ar, int size){
        for(int i = 0; i < size - 1; i++){
                for(int j = 0; j < size - i - 1; j++){
                        if(ar[j] > ar[j + 1]){
                                swap(ar[j], ar[j + 1]);
                        }
                }
        }
}


void insertionSort(int *ar, int size){
        for (int i = 1; i< size; i++){
                 for (int j = i; j > 0 && ar[j-1] > ar[j]; j--){
                        swap(ar[j-1], ar[j]);
                 }
	}
}


void selectionSort(int *ar, int size){
        for(int i = 0; i < size; i++){
                swap(ar[i], ar[search(ar, size, i)]);
        }
}


void quickSort_up(int* ar, int size) {
	int left = 0;
	int right = size - 1;
	int pivot = ar[size >> 1];

	while(left <= right) {
		while(ar[left] < pivot) {
			left++;
		}

		while (ar[right] > pivot) {
			right--;
		}

		if (left <= right) {
			swap(ar[right], ar[left]);
			right--;
			left++;
		}
	}
	if (right > 0) {
		quickSort_up(&ar[0], right + 1);
	}

	if (left < size) {
		quickSort_up(&ar[left], size - left);
	}
}


void quickSort_down(int* ar, int size) {
        int left = 0;
        int right = size - 1;
        int pivot = ar[size >> 1];

        while(left <= right) {
                while(ar[left] > pivot) {
                        left++;
                }

                while (ar[right] < pivot) {
                        right--;
                }

                if (left <= right) {
                        swap(ar[right], ar[left]);
                        right--;
                        left++;
                }
        }
        if (right > 0) {
                quickSort_down(&ar[0], right + 1);
        }

        if (left < size) {
                quickSort_down(&ar[left], size - left);
        }
}



static void merge_up(int* ar, int size, int central) {
    int left = 0;
    int right = central;
    int* arTemp = new int [size];
    int indexTemp = 0;

    while (left < central && right < size) {
        while(ar[left] <= ar[right] && left < central) {
            arTemp[indexTemp++] = ar[left++];
//            left++;
//            indexTemp++;
        }
        while(ar[left] > ar[right] && right < size) {
            arTemp[indexTemp] = ar[right];
            indexTemp++;
            right++;
        }
    }

    while (left < central) {
        arTemp[indexTemp++] = ar[left++];
    }
    while (right < size) {
        arTemp[indexTemp++] = ar[right++];
    }

    memcpy(ar, arTemp, size * sizeof(int));

    delete [] arTemp;
}


void mergeSort_up(int* ar, int size) {
    if (size <= 1) {
        return;
    }
    mergeSort_up(&ar[0], size >> 1);
    mergeSort_up(&ar[size >> 1], size - (size >> 1));

    merge_up(ar, size, size >> 1);
}

static void merge_down(int* ar, int size, int central) {
    int left = 0;
    int right = central;
    int* arTemp = new int [size];
    int indexTemp = 0;

    while (left < central && right < size) {
        while(ar[left] >= ar[right] && left < central) {
            arTemp[indexTemp++] = ar[left++];
//            left++;
//            indexTemp++;
        }
        while(ar[left] < ar[right] && right < size) {
            arTemp[indexTemp] = ar[right];
            indexTemp++;
            right++;
        }
    }

    while (left < central) {
        arTemp[indexTemp++] = ar[left++];
    }
    while (right < size) {
        arTemp[indexTemp++] = ar[right++];
    }

    memcpy(ar, arTemp, size * sizeof(int));

    delete [] arTemp;
}


void mergeSort_down(int* ar, int size) {
    if (size <= 1) {
        return;
    }
    mergeSort_down(&ar[0], size >> 1);
    mergeSort_down(&ar[size >> 1], size - (size >> 1));

    merge_down(ar, size, size >> 1);
}


void countSort(int *bigAr,int size){
	int smallAr[getMax(bigAr, size) + 1];
	
	for(int i = 0; i < getMax(bigAr, size) + 1; i++){
		smallAr[i] = 0;
	}

	for(int i = 0; i < size; i++){
		smallAr[bigAr[i]]++;	
	}
	
	for(int i = 0, j = 0; i < size;){
		if(smallAr[j] > 0){
			bigAr[i] = j;
			--smallAr[j];
			++i;
		}
		else if(smallAr[j] == 0){
			++j;
		}

	}
}
