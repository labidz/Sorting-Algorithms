#include <conio.h>
#include <bits/stdc++.h>
#include "sort.h"

using namespace std;

int main(int argc, char** argv) {
	int x=1;
	while(x){
		system("cls");
		cout<<"Enter Size of the new Array: ";
		int n; cin>>n;
		cout<<"Enter the Array: ";
		vector<int> a(n);
		for(int i=0;i<n;++i){
			cin>>a[i];
		}
		cout<<"\n\nEnter the Sorting Algorithm you want to use: "<<endl;
		cout<<"1. Heap Short\n2. Hash Sort\n3. Selection Sort\n4. Insertion Sort\n5. Bubble Sort"<<endl;
		cin>>x;
		vector<int> arr;
		switch(x){
			case 1 : arr = heapSort(a);
			cout<<"After Heap Sort: ";
			break;
			case 2 : arr = hashSort(a);
			cout<<"After Hash Sort: ";
			break;
			case 3 : arr = selectionSort(a);
			cout<<"After Selection Sort: ";
			break;
			case 4 : arr = insertionSort(a);
			cout<<"After Insertion Sort: ";
			break;
			case 5 : arr = bubbleSort(a);
			cout<<"After Bubble Sort: ";
			break;
			default : cout<<"Invalid Input"<<endl;
		}
		for(int i=0;i<n;++i){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		cout<<"Press any key to return"<<endl;
		getch();
	}
	return 0;
}
