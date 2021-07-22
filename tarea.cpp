#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Particion:    int arr 
//              int l
//              int r
//              Return:
int particion(int arr[], int l, int r)
{
	int x = arr[r], i = l;
	for (int j = l; j <= r - 1; j++) {
		if (arr[j] <= x) {
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i], arr[r]);
	return i;
}


//QuickSelect:  int arr
//              int l
//              int r
//              int k
//              Return: 
int quickselect(int arr[], int l, int r, int k)
{

	if (k > 0 && k <= r - l + 1) {

		int pos = particion(arr, l, r);

		if (pos - l == k - 1) return arr[pos];

		if (pos - l > k - 1) return quickselect(arr, l, pos - 1, k);

		return quickselect(arr, pos + 1, r, k - pos + l - 1);
	}

	return -1;
}

int main(){
    int left;
    int right;
    while (cin >> left >> right){ // left cantidad de casos y right salidas requeridas
        int numeros[left];
        string nombres[left];
        int buffer[left];
        for (int i = 0; i < left; i++){
            cin >> numeros[i] >> nombres[i];
        }
        for (int i = 0; i < left; i++){
            buffer[i] = numeros[i];
        }
        for(int i = 0; i < right; i++){

            int retorno = quickselect(numeros, 0, left, left-i);
            for(int i = 0; i < left; i++){
                if (buffer[i] == retorno){
                    cout << buffer[i] << " " << nombres[i] << endl;
                }
            }
            // cout << numeros[pos] << endl << nombres[pos] << endl;
        }
        cout << endl;
    }
    return 0;
}

