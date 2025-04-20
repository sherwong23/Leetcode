#include <iostream>
#include <stdexcept>

template<typename T>
class MyVector {
private:
    T* start;              // 起始指针，指向数据的开头
    T* finish;             // 当前数据的末尾（指向下一个空位置）
    T* end_of_storage;     // 容器的容量（指向已分配内存的末尾）
    size_t current_capacity; // 当前容量

    void reallocate() {
        size_t new_capacity = current_capacity == 0 ? 1 : current_capacity * 2; // 扩容
        T* new_start = new T[new_capacity];  // 分配新内存

        // 将旧数据复制到新内存中
        for (size_t i = 0; i < size(); ++i) {
            new_start[i] = start[i];
        }

        delete[] start; // 释放旧内存
        start = new_start;
        finish = start + size();
        end_of_storage = start + new_capacity;
        current_capacity = new_capacity;
    }

public:
    MyVector() : start(nullptr), finish(nullptr), end_of_storage(nullptr), current_capacity(0) {}

    ~MyVector() {
        delete[] start;
    }

    size_t size() const {
        return finish - start;  // 当前元素个数
    }

    size_t capacity() const {
        return current_capacity; // 当前容量
    }

    bool empty() const {
        return size() == 0;
    }

    void push_back(const T& value) {
        if (finish == end_of_storage) {
            reallocate(); // 扩容
        }
        *finish = value;  // 插入元素
        ++finish;         // 移动 finish 指针
    }

    T& operator[](size_t index) {
        if (index >= size()) {
            throw std::out_of_range("Index out of range");
        }
        return start[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size()) {
            throw std::out_of_range("Index out of range");
        }
        return start[index];
    }

    void clear() {
        finish = start; // 重置 finish 指针，相当于清空元素
    }

    void resize(size_t new_size, const T& value = T()) {
        if (new_size < size()) {
            finish = start + new_size; // 如果新尺寸小，直接调整 finish
        } else if (new_size > size()) {
            if (new_size > current_capacity) {
                while (new_size > current_capacity) {
                    reallocate(); // 需要扩容
                }
            }
            // 填充新增加的元素
            for (size_t i = size(); i < new_size; ++i) {
                start[i] = value;
            }
            finish = start + new_size;
        }
    }
};

int main() {
    MyVector<int> vec;

    // 添加元素
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    // 输出 vector 内容
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << "vec[" << i << "] = " << vec[i] << std::endl;
    }

    std::cout << "Size: " << vec.size() << std::endl;
    std::cout << "Capacity: " << vec.capacity() << std::endl;

    // 调整大小
    vec.resize(6, 50);
    std::cout << "After resizing to 6, new elements (50):" << std::endl;
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << "vec[" << i << "] = " << vec[i] << std::endl;
    }

    // 清空容器
    vec.clear();
    std::cout << "After clear, size: " << vec.size() << std::endl;

    return 0;
}

