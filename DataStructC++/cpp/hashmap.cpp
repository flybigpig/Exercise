#include <iostream>
#include <list>
#include <vector>
using namespace std;

// 哈希表节点类
template<typename K, typename V>
class HashNode {
public:
    K key;
    V value;
    HashNode* left;
    HashNode* right;
    
    HashNode(K k, V v) : key(k), value(v), left(nullptr), right(nullptr) {}
};

// 哈希二叉树类
template<typename K, typename V>
class HashBinaryTree {
private:
    vector<HashNode<K,V>*> buckets;  // 哈希桶数组
    int size;                        // 当前元素个数
    int capacity;                    // 哈希表容量
    
    // 哈希函数
    int hashFunction(K key) {
        return hash<K>{}(key) % capacity;
    }
    
    // 在二叉树中插入节点
    HashNode<K,V>* insertInTree(HashNode<K,V>* root, K key, V value) {
        if (root == nullptr) {
            return new HashNode<K,V>(key, value);
        }
        
        if (key < root->key) {
            root->left = insertInTree(root->left, key, value);
        } else if (key > root->key) {
            root->right = insertInTree(root->right, key, value);
        } else {
            root->value = value;  // 更新已存在的key的值
        }
        
        return root;
    }
    
    // 在二叉树中查找节点
    HashNode<K,V>* findInTree(HashNode<K,V>* root, K key) {
        if (root == nullptr || root->key == key) {
            return root;
        }
        
        if (key < root->key) {
            return findInTree(root->left, key);
        }
        return findInTree(root->right, key);
    }
    
    // 删除二叉树
    void deleteTree(HashNode<K,V>* root) {
        if (root == nullptr) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }

public:
    HashBinaryTree(int initialCapacity = 16) {
        capacity = initialCapacity;
        size = 0;
        buckets.resize(capacity, nullptr);
    }
    
    ~HashBinaryTree() {
        for (auto root : buckets) {
            deleteTree(root);
        }
    }
    
    // 插入键值对
    void put(K key, V value) {
        int index = hashFunction(key);
        buckets[index] = insertInTree(buckets[index], key, value);
        size++;
    }
    
    // 获取值
    V* get(K key) {
        int index = hashFunction(key);
        HashNode<K,V>* node = findInTree(buckets[index], key);
        return node ? &(node->value) : nullptr;
    }
    
    // 判断是否包含键
    bool containsKey(K key) {
        return get(key) != nullptr;
    }
    
    // 获取大小
    int getSize() {
        return size;
    }
    
    // 判断是否为空
    bool isEmpty() {
        return size == 0;
    }
};

// 测试主函数
int main() {
    HashBinaryTree<string, int> hashTree;
    
    // 测试插入
    hashTree.put("apple", 1);
    hashTree.put("banana", 2);
    hashTree.put("orange", 3);
    
    // 测试查找
    cout << "Value for 'apple': " << *hashTree.get("apple") << endl;
    cout << "Value for 'banana': " << *hashTree.get("banana") << endl;
    cout << "Value for 'orange': " << *hashTree.get("orange") << endl;
    
    // 测试containsKey
    cout << "Contains 'apple': " << (hashTree.containsKey("apple") ? "true" : "false") << endl;
    cout << "Contains 'grape': " << (hashTree.containsKey("grape") ? "true" : "false") << endl;
    
    // 测试大小
    cout << "Size: " << hashTree.getSize() << endl;
    
    return 0;
}
