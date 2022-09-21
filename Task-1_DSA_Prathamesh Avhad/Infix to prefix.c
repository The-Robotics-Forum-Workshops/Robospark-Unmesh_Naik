Given are N ropes of different lengths, the task is to connect these ropes into one rope with minimum cost, such that the cost to connect two ropes is equal to the sum of their lengths?
Input: arr[] = {4,3,2,6} , N = 4
Output: 29
Explanation: 
1.	First, connect ropes of lengths 2 and 3. Now we have three ropes of lengths 4, 6, and 5. 
2.	Now connect ropes of lengths 4 and 5. Now we have two ropes of lengths 6 and 9. 
3.	Finally connect the two ropes and all ropes have connected.
Program
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Function to calculate the minimum cost to join `n` ropes into a single rope
int findMinCost(vector<int> const &prices)
{
	// create a min-heap from input elements
	priority_queue<int, vector<int>, greater<int>> pq(prices.begin(), prices.end());

	// keep track of the minimum cost so far
	int cost = 0;

	// repeat till heap size is reduced to one
	while (pq.size() > 1)
	{
		// Extract the top two elements from the min-heap
		int x = pq.top();
		pq.pop();

		int y = pq.top();
		pq.pop();

		// calculate the cost of the extracted values
		int sum = x + y;

		// insert the cost back to the min-heap
		pq.push(sum);

		// update the minimum cost
		cost += sum;
	}

	return cost;
}

int main()
{
	vector<int> prices = { 5, 4, 2, 8 };
	cout << "The minimum cost is " << findMinCost(prices);

	return 0;
}