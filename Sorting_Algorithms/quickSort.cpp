#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int>& v, int start, int end);
int partition(vector<int>& v, int start, int end);
void printVector(const vector<int>& v);

void quickSort(vector<int>& v, int start, int end){
    if(start >= end) {
        return;
    }
    int mid = partition(v, start, end);
    quickSort(v, start, mid-1);
    quickSort(v, mid, end);
}

int partition(vector<int>& v, int start, int end){
    int pivot = v[end];
    int mid = start;
    for(int i = start; i < end; i++){
        if(v[i] < pivot){
            if (mid != i){
                int temp = v[i];
                v[i] = v[mid];
                v[mid] = temp;
            }
            mid++;
        }
    }
    v[end] = v[mid];
    v[mid] = pivot;
    return mid;
}

void printVector(const vector<int>& v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){

    vector<int> values = {87, 23, 5, 12, 48, 39, 64};
    quickSort(values, 0, values.size()-1);
    printVector(values);

    return 0;
}