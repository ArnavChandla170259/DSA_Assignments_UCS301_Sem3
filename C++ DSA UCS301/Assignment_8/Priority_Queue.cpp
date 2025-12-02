#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Max Heap implementation for Priority Queue
class PriorityQueue {
    vector<int> heap;

    void heapify(int i) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < heap.size() && heap[l] > heap[largest])
            largest = l;
        if (r < heap.size() && heap[r] > heap[largest])
            largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

public:
    void enqueue(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;

        // Fix the min heap property if it is violated
        while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int dequeue() {
        if (heap.size() == 0) return -1;
        if (heap.size() == 1) {
            int root = heap[0];
            heap.pop_back();
            return root;
        }

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);

        return root;
    }

    void display() {
        for (int i : heap) cout << i << " ";
        cout << "\n";
    }
};

int main() {
    PriorityQueue pq;

    pq.enqueue(100);
    pq.enqueue(200);
    pq.enqueue(150);
    pq.enqueue(300);

    cout << "Priority Queue: ";
    pq.display();

    cout << "Dequeue: " << pq.dequeue() << "\n";

    cout << "After Dequeue: ";
    pq.display();

    return 0;
}

/*Name: Arnav Chandla
Roll No. :1024170259*/
