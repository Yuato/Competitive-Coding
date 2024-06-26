
#include <bits/stdc++.h>
using namespace std;

const int MAX_VAL = 1000001;

void update(int i, int add, vector<int>& BIT)
{
	while (i > 0 && i < BIT.size())
	{
		BIT[i] += add;
		i = i + (i & (-i));
	}
}

int sum(int i, vector<int>& BIT)
{
	int ans = 0;
	while (i > 0)
	{
		ans += BIT[i];
		i = i - (i & (-i));
	}

	return ans;
}

// Returns lower bound for k in BIT.
int findKthSmallest(int k, vector<int> &BIT)
{
	// Do binary search in BIT[] for given
	// value k.
	int l = 0;
	int h = BIT.size();
	while (l < h)
	{
		int mid = (l + h) / 2;
		if (k <= sum(mid, BIT))
			h = mid;
		else
			l = mid+1;
	}

	return l;
}

// Insert x into BIT. We basically increment
// rank of all elements greater than x.
void insert(int x, vector<int> &BIT)
{
	update(x, 1, BIT);
}

// Delete x from BIT. We basically decreases
// rank of all elements greater than x.
void deleteElement(int x, vector<int> &BIT)
{
	update(x, -1, BIT);
}

// Returns rank of element. We basically
// return sum of elements from start to
// index x.
int findRank(int x, vector<int> &BIT)
{
	return sum(x, BIT);
}

// Driver code
int main()
{
    vector<int>stuff;
	vector<int> BIT(MAX_VAL);
    int n, min;
    cin>>n>> min;
	if (n>0){
        char a, value;
        cin>>a>>value;
        if (a=='I'){
            insert(value, BIT);
            stuff.push_back
        }
        else if (a == 'A'){

        }
        n--;
    }
	vector<int> BIT(MAX_VAL);
	insertElement(20, BIT);
	insertElement(50, BIT);
	insertElement(30, BIT);
	insertElement(40, BIT);

	cout << "2nd Smallest element is "
	<< findKthSmallest(2, BIT) << endl;

	cout << "Rank of 40 is "
		<< findRank(40, BIT) << endl;

	deleteElement(40, BIT);

	cout << "Rank of 50 is "
		<< findRank(50, BIT) << endl;
    cout<<sum(50, BIT);

	return 0;
}
