#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

template <typename T>
class MiniDeque {
private:
    static const int BLOCK_SIZE = 4;   // 每个块的大小（简化）
    vector<T*> blocks;                 // map 指针数组
    int frontIndex;                   // 队首在第几个块上
    int backIndex;                    // 队尾在第几个块上
    int frontOffset;                  // 块内偏移
    int backOffset;                   // 块内偏移

    void allocateBlockFront() {
        T* newBlock = new T[BLOCK_SIZE];
        blocks.insert(blocks.begin(), newBlock);
        frontIndex++;
        backIndex++;
    }

    void allocateBlockBack() {
        T* newBlock = new T[BLOCK_SIZE];
        blocks.push_back(newBlock);
    }

public:
    MiniDeque() {
        T* block = new T[BLOCK_SIZE];
        blocks.push_back(block);
        frontIndex = backIndex = 0;
        frontOffset = BLOCK_SIZE / 2;
        backOffset = BLOCK_SIZE / 2 - 1;
    }

    ~MiniDeque() {
        for (T* block : blocks) {
            delete[] block;
        }
    }

    void push_back(T val) {
        if (backOffset + 1 >= BLOCK_SIZE) {
            allocateBlockBack();
            backIndex++;
            backOffset = 0;
        } else {
            backOffset++;
        }
        blocks[backIndex][backOffset] = val;
    }

    void push_front(T val) {
        if (frontOffset == 0) {
            allocateBlockFront();
            frontIndex--;
            frontOffset = BLOCK_SIZE - 1;
        } else {
            frontOffset--;
        }
        blocks[frontIndex][frontOffset] = val;
    }

    T pop_back() {
        if (empty()) throw out_of_range("empty");
        T val = blocks[backIndex][backOffset];
        if (backOffset == 0) {
            delete[] blocks[backIndex];
            blocks.pop_back();
            backIndex--;
            backOffset = BLOCK_SIZE - 1;
        } else {
            backOffset--;
        }
        return val;
    }

    T pop_front() {
        if (empty()) throw out_of_range("empty");
        T val = blocks[frontIndex][frontOffset];
        if (frontOffset + 1 >= BLOCK_SIZE) {
            delete[] blocks[frontIndex];
            blocks.erase(blocks.begin());
            frontOffset = 0;
        } else {
            frontOffset++;
        }
        return val;
    }

    bool empty() const {
        return (frontIndex == backIndex && frontOffset > backOffset);
    }

    int size() const {
        if (empty()) return 0;
        return (backIndex - frontIndex) * BLOCK_SIZE + (backOffset - frontOffset + 1);
    }

    T at(int index) const {
        if (index < 0 || index >= size()) throw out_of_range("index out of range");
        int totalOffset = frontOffset + index;
        int blockIdx = frontIndex + totalOffset / BLOCK_SIZE;
        int offset = totalOffset % BLOCK_SIZE;
        return blocks[blockIdx][offset];
    }
};

int main() {
    MiniDeque<int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5);
    dq.push_front(2);

    for (int i = 0; i < dq.size(); ++i) {
        cout << dq.at(i) << " ";
    }
    cout << endl;

    dq.pop_front();
    dq.pop_back();

    for (int i = 0; i < dq.size(); ++i) {
        cout << dq.at(i) << " ";
    }
    cout << endl;

    return 0;
}

