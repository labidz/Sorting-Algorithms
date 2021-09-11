#include <bits/stdc++.h>
using namespace std;

const int N = 1e7+10;
int phs[N];
int mhs[N];

int parent(int i){
	return (i-1)/2;
}
int left(int i){
	return (2*i)+1;
}
int right(int i){
	return (2*i)+2;
}
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
void heapify(int i, vector<int> &v){
	int l = left(i);
	int r = right(i);
	int min = i;
	if(l < v.size() and v[min] > v[l]){
		min = l;
	}
	if(r < v.size() and v[min] > v[r]){
		min = r;
	}
	if(min != i){
		swap(v[min],v[i]);
		heapify(min, v);
	}
}
vector<int> heapSort(vector<int> &v){
	vector<int> a,sorted;
	for(int i=0;i<v.size();++i){
		a.push_back(v[i]);
		int j = a.size()-1;
		while(j!=0 and a[parent(j)]>a[j]){
			swap(a[parent(j)],a[j]);
			j = parent(j);
		}
	}
	while(a.size() != 0){
		sorted.push_back(a[0]);
		swap(a[0],a[a.size()-1]);
		a.pop_back();
		heapify(0,a);
	}
	return sorted;
}

vector<int> hashSort(vector<int> arr){

	for(int i=0;i<arr.size();++i){
		if(arr[i]<0){
			mhs[(-arr[i])] = 1;
		}else{
			phs[arr[i]] = 1;
		}
	}

	vector<int> sorted;
	for(int i=N-1;i>=0;--i){
		if(mhs[i] == 1){
			sorted.push_back(-i);
		}
	}

	for(int i=0;i<N;++i){
		if(phs[i] == 1){
			sorted.push_back(i);
		}
	}
	
	return sorted;
}

vector<int> bubbleSort(vector<int> a){
	
	for(int i=0;i<a.size()-1;i++){
		
		for(int j=0;j<a.size()-i-1;j++){
			if(a[j]>a[j+1]){
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	return a;
}

vector<int> insertionSort(vector<int> a){
	
	for(int i=1;i<a.size();++i){
		int j = i-1,key = a[i];
		while(j>-1 and a[j]>key){
			a[j+1] = a[j];
			j=j-1;
		}
		a[j+1] = key;
	}
	
	return a;
}

vector<int> selectionSort(vector<int> a){
	
	for(int i=0;i<a.size();i++){
		int min = i;
		for(int j = i+1;j<a.size();j++){
			if(a[min] > a[j]){
				min = j;
			}
		}
		int temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
	
	return a;
}

