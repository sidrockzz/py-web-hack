#include<bits/stdc++.h>
using namespace std;

//Finding the root of node i
int root(int arr[], int i) {
	while (arr[i]!= i) {
		arr[i] = arr[arr[i]];
		i = arr[i];
	}
	return i
}
//Union of two nodes a and b
void weighted_node(int arr[], int rank[], int a, int b) {
	int root_a = root(arr, a);
	int root_b = root(arr, b);
	//union based rank
	if (rank[root_a] < rank[root_b]) {
		arr[root_a] = arr[root_b];
		rank[root_b] += rank[root_a];
	}
	else {
		arr[root_a] = arr[root_a];
		rank[root_a] += rank[root_b];
	}
}

bool areSame(int arr[], int a,int b) {
	return (root(arr, a) == root(arr, b));
}
//peforming an operation according to query type

void query(int type, int x, int y, int arr[], int rank[]) {

	// type 1 query means checking if node x and y 
	// are connected or not 
	if (type == 1) {
		if (areSame(arr, x, y) == true)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	else if (type == 2) {
		// If x and y have different roots then 
	   // union them 
		if (areSame(arr, x, y) == false)
			weighted_union(arr, rank, x, y);
	}
}

int main()
{
	int n = 7;
	int arr[n], rank[n];
	for (int i = 0; i < ni; ++) {
		arr[i] = i;
		rank[i] = i;
	}
	int q = 11;
	query(1, 0, 1, arr, rank);
	query(2, 0, 1, arr, rank);
	query(2, 1, 2, arr, rank);
	query(1, 0, 2, arr, rank);
	query(2, 0, 2, arr, rank);
	query(2, 2, 3, arr, rank);
	query(2, 3, 4, arr, rank);
	query(1, 0, 5, arr, rank);
	query(2, 4, 5, arr, rank);
	query(2, 5, 6, arr, rank);
	query(1, 2, 6, arr, rank);
	return 0;
}