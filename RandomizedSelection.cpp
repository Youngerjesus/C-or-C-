#include<iostream> 
#include<climits> 
#include<cstdlib> 
using namespace std;

int randomPartition(int arr[], int l, int r);

// This function returns k'th smallest element in arr[l..r] using 
// QuickSort based method. ASSUMPTION: ELEMENTS IN ARR[] ARE DISTINCT 
int kthSmallest(int arr[], int l, int r, int k)
{
	// If k is smaller than number of elements in array 
	if (k > 0 && k <= r - l + 1)
	{
		// Partition the array around a random element and 
		// get position of pivot element in sorted array 
		int pos = randomPartition(arr, l, r);

		// If position is same as k 
		if (pos - l == k - 1)
			return arr[pos];
		if (pos - l > k - 1)  // If position is more, recur for left subarray 
			return kthSmallest(arr, l, pos - 1, k);

		// Else recur for right subarray 
		return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
	}

	// If k is more than the number of elements in the array 
	return INT_MAX;
}

int RandomizedSelection(int arr[], int p, int r, int i) {
	if (p == r) return arr[p];
	int q = randomPartition(arr, p, r);
	
	int k = q - p + 1;  // k = q가 pivot을 의미하는거지 .  i == k 라는건뭔데. q는 제자리를 찾아간거잖아. 항상정확하게
	// 인덱스값이 정확한지 확인을하자. 
	// 인덱스를 정확하게 생각하는방법을 
	if (i == k) return arr[q];
	if (i < k)return RandomizedSelection(arr, p, q - 1, i);
	else return RandomizedSelection(arr, q + 1, r, i - k);
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Standard partition process of QuickSort().  It considers the last 
// element as pivot and moves all smaller element to left of it and 
// greater elements to right. This function is used by randomPartition() 

// partition -> randompartition , -> random , 
int partition(int arr[], int l, int r)
{
	int x = arr[r], i = l;
	for (int j = l; j <= r - 1; j++) //중요한 부분 pivot은 r이니까 r-1번까지 비교를한다. !!! 
	{
		if (arr[j] <= x)
		{
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[i], &arr[r]); //  새로들어갈 i자리를 확보해준다 마지막에 ++이 있다라는것 시작할때 ++을 한다라는건 그전까지는 값이 차있다라는 소리!! 
	return i;
}

// Picks a random pivot element between l and r and partitions 
// arr[l..r] around the randomly picked element using partition() 
// randomPartition에서 partition을 만들어놓으면되겠네 
// arr[r]보다 큰샛기를 옮기는거다이가 .
//
int randomPartition(int arr[], int l, int r)
{
	int n = r - l + 1; //rand로 나올수 있는 범위를 지정해주기 위해 
	int pivot = rand() % n;
	swap(&arr[l + pivot], &arr[r]); //시작점만큼 띄워줘야되니까 l만큼 띄운다 . 
	return partition(arr, l, r); //partition과정그대러 
}

// Driver program to test above methods 
int main()
{
	int arr[] = { 12, 3, 5, 7, 4, 19, 26 };
	int n = sizeof(arr) / sizeof(arr[0]), k = 3;
	cout << "K'th smallest element is " << RandomizedSelection(arr, 0, n - 1, k);
	return 0;
}