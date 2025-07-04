#pragma once

template <typename T>
struct TreeNode
{
    T value;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode(T val) : value(val), left(nullptr), right(nullptr) {}
};

template <typename T>
class Tree
{
private:
    TreeNode<T> *root;
    int size;

    TreeNode<T>* insertRecursive(TreeNode<T> *node, T value);
    void removeRecursive(TreeNode<T> *node);
    TreeNode<T> *findRecursive(TreeNode<T> *node, const T& value);
    void printInOrder(TreeNode<T> *node) const;

public:
    Tree() : root(nullptr), size(0) {}
    ~Tree();

    void insert(const T &value);

    TreeNode<T> *find(const T &value);

    void print();

    int getSize() const {
        return size;
    }
};

template <typename T>
void Tree<T>::insert(const T &value)
{
    root = insertRecursive(root, value);
}

template <typename T>
TreeNode<T>* Tree<T>::find(const T& value) {
    return findRecursive(root, value);
}

template <typename T>
void Tree<T>::print() {
    printInOrder(root);
}

template <typename T>
TreeNode<T>* Tree<T>::insertRecursive(TreeNode<T> *node, T value)
{
    if (!node)
    {
        size++;
        return new TreeNode<T>(value);
    }

    if (value < node->value)
    {
        node->left = insertRecursive(node->left, value);
    }
    else if (value > node->value)
    {
        node->right = insertRecursive(node->right, value);
    }

    return node;
}

template <typename T>
void Tree<T>::removeRecursive(TreeNode<T> *node)
{
    if (!node)
    {
        return;
    }
    removeRecursive(node->left);
    removeRecursive(node->right);
    delete node;
}

template <typename T>
TreeNode<T> *Tree<T>::findRecursive(TreeNode<T> *node, const T &value)
{
    if (!node)
        return nullptr;
    if (node->value == value)
        return node;
    if (value < node->value)
        return findRecursive(node->left, value);
    else
        return findRecursive(node->right, value);
}

template <typename T>
void Tree<T>::printInOrder(TreeNode<T> *node) const
{
    if (!node)
        return;
    printInOrder(node->left);
    std::cout << node->value << " ";
    printInOrder(node->right);
}

template <typename T>
Tree<T>::~Tree()
{
    removeRecursive(root);
}
