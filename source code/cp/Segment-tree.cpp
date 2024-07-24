#include <iostream>
#include <vector>
using namespace std;

// chat gpt

// Hàm xây dựng cây phân đoạn
void buildTree(vector<int>& arr, vector<int>& tree, int start, int end, int treeNode) {
    if (start == end) {
        tree[treeNode] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, 2 * treeNode);
    buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);
    tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}

// Hàm truy vấn tổng trong đoạn [left, right]
int query(vector<int>& tree, int start, int end, int treeNode, int left, int right) {
    if (left > end || right < start)
        return 0;
    if (left <= start && right >= end)
        return tree[treeNode];
    int mid = (start + end) / 2;
    int leftSum = query(tree, start, mid, 2 * treeNode, left, right);
    int rightSum = query(tree, mid + 1, end, 2 * treeNode + 1, left, right);
    return leftSum + rightSum;
}

// Hàm cập nhật giá trị của phần tử tại vị trí index
void update(vector<int>& tree, int start, int end, int treeNode, int index, int value) {
    if (start == end) {
        tree[treeNode] = value;
        return;
    }
    int mid = (start + end) / 2;
    if (index <= mid)
        update(tree, start, mid, 2 * treeNode, index, value);
    else
        update(tree, mid + 1, end, 2 * treeNode + 1, index, value);
    tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9};
    int n = arr.size();
    vector<int> tree(4 * n);

    // Xây dựng cây phân đoạn
    buildTree(arr, tree, 0, n - 1, 1);

    // Truy vấn tổng từ vị trí 1 đến 3
    int result = query(tree, 0, n - 1, 1, 1, 3);
    cout << "Tổng từ vị trí 1 đến 3: " << result << endl;

    // Cập nhật giá trị tại vị trí 2 thành 6
    update(tree, 0, n - 1, 1, 2, 6);

    // Truy vấn tổng từ vị trí 1 đến 5
    result = query(tree, 0, n - 1, 1, 1, 4);
    cout << "Tổng từ vị trí 1 đến 5 sau khi cập nhật: " << result << endl;

    return 0;
}
