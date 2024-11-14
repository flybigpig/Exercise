#include <iostream>
#include <list>
#include <vector>
using namespace std;

// ��ϣ��ڵ���
template<typename K, typename V>
class HashNode {
public:
    K key;
    V value;
    HashNode* left;
    HashNode* right;
    
    HashNode(K k, V v) : key(k), value(v), left(nullptr), right(nullptr) {}
};

// ��ϣ��������
template<typename K, typename V>
class HashBinaryTree {
private:
    vector<HashNode<K,V>*> buckets;  // ��ϣͰ����
    int size;                        // ��ǰԪ�ظ���
    int capacity;                    // ��ϣ������
    
    // ��ϣ����
    int hashFunction(K key) {
        return hash<K>{}(key) % capacity;
    }
    
    // �ڶ������в���ڵ�
    HashNode<K,V>* insertInTree(HashNode<K,V>* root, K key, V value) {
        if (root == nullptr) {
            return new HashNode<K,V>(key, value);
        }
        
        if (key < root->key) {
            root->left = insertInTree(root->left, key, value);
        } else if (key > root->key) {
            root->right = insertInTree(root->right, key, value);
        } else {
            root->value = value;  // �����Ѵ��ڵ�key��ֵ
        }
        
        return root;
    }
    
    // �ڶ������в��ҽڵ�
    HashNode<K,V>* findInTree(HashNode<K,V>* root, K key) {
        if (root == nullptr || root->key == key) {
            return root;
        }
        
        if (key < root->key) {
            return findInTree(root->left, key);
        }
        return findInTree(root->right, key);
    }
    
    // ɾ��������
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
    
    // �����ֵ��
    void put(K key, V value) {
        int index = hashFunction(key);
        buckets[index] = insertInTree(buckets[index], key, value);
        size++;
    }
    
    // ��ȡֵ
    V* get(K key) {
        int index = hashFunction(key);
        HashNode<K,V>* node = findInTree(buckets[index], key);
        return node ? &(node->value) : nullptr;
    }
    
    // �ж��Ƿ������
    bool containsKey(K key) {
        return get(key) != nullptr;
    }
    
    // ��ȡ��С
    int getSize() {
        return size;
    }
    
    // �ж��Ƿ�Ϊ��
    bool isEmpty() {
        return size == 0;
    }
};

// ����������
int main() {
    HashBinaryTree<string, int> hashTree;
    
    // ���Բ���
    hashTree.put("apple", 1);
    hashTree.put("banana", 2);
    hashTree.put("orange", 3);
    
    // ���Բ���
    cout << "Value for 'apple': " << *hashTree.get("apple") << endl;
    cout << "Value for 'banana': " << *hashTree.get("banana") << endl;
    cout << "Value for 'orange': " << *hashTree.get("orange") << endl;
    
    // ����containsKey
    cout << "Contains 'apple': " << (hashTree.containsKey("apple") ? "true" : "false") << endl;
    cout << "Contains 'grape': " << (hashTree.containsKey("grape") ? "true" : "false") << endl;
    
    // ���Դ�С
    cout << "Size: " << hashTree.getSize() << endl;
    
    return 0;
}
