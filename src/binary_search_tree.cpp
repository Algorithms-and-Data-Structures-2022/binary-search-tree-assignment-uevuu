#include "assignment/binary_search_tree.hpp"

namespace assignment {

  BinarySearchTree::~BinarySearchTree() {
    BinarySearchTree::Clear();
  }

  void BinarySearchTree::Insert(int key, int value) {
    // Write your code here...
    insert(key, value, root_);
  }

  bool BinarySearchTree::Remove(int key) {
    // Write your code here...
    return remove(key, root_);
  }

  void BinarySearchTree::Clear() {
    // Write your code here...
    clear(root_);
  }

  std::optional<int> BinarySearchTree::Find(int key) const {
    // Write your code here...
    Node* node = find(key, root_);
    if (node != nullptr) {
      return node->value;
    }
    return std::nullopt;
  }

  bool BinarySearchTree::Contains(int key) const {
    auto value = Find(key);
    return value != std ::nullopt;
  }

  bool BinarySearchTree::IsEmpty() const {
    return root_ == nullptr;
  }

  std::optional<int> BinarySearchTree::FindMin() const {
    // Write your code here...
    Node* node = find_min(root_);
    if (node != nullptr) {
      return node->value;
    }
    return std::nullopt;
  }

  std::optional<int> BinarySearchTree::FindMax() const {
    // Write your code here...
    Node* node = find_max(root_);
    if (node != nullptr) {
      return node->value;
    }
    return std::nullopt;
  }

  Node* BinarySearchTree::root() const {
    return root_;
  }

  // вспомогательные методы

  void BinarySearchTree::insert(int key, int value, Node*& node) {
    // Write your code here ...
    if (node == nullptr) {
      node = new Node(key, value);
    } else {
      if (key == node->key) {
        node->value = value;
      }
      if (key < node->key) {
        insert(key, value, node->left);
      }
      if (key > node->key) {
        insert(key, value, node->right);
      }
    }
  }

  bool BinarySearchTree::remove(int key, Node*& node) {
    // Write your code here...
    if (node != nullptr) {
      if (key < node->key) {
        return remove(key, node->left);
      }
      if (key > node->key) {
        return remove(key, node->right);
      }
      if (node->left == nullptr and node->right == nullptr) {
        node = nullptr;
        return true;
      }
      if (node->left == nullptr and node->right != nullptr) {
        node = node->right;
        node->right = nullptr;
        return true;
      }
      if (node->left != nullptr and node->right == nullptr) {
        node = node->left;
        node->left = nullptr;
        return true;
      }
      if (node->left != nullptr and node->right != nullptr) {
        Node* min_node = find_min(node->right);
        node->key = min_node->key;
        node->value = min_node->value;
        return remove(min_node->key, node->right);
      }
    }
    return false;
  }

  void BinarySearchTree::clear(Node* node) {
    // Write your code here...
    if (node != nullptr) {
      clear(node->left);
      clear(node->right);
      delete node;
      root_ = nullptr;
    }
  }

  Node* BinarySearchTree::find(int key, Node* node) const {
    // Write your code here...
    if (node != nullptr) {
      if (key == node->key) {
        return node;
      }
      if (key < node->key) {
        return find(key, node->left);
      }
      if (key > node->key) {
        return find(key, node->right);
      }
    }
    return nullptr;
  }

  Node* BinarySearchTree::find_min(Node* node) const {
    // Write your code here...
    Node* min_node = node;
    if (node != nullptr) {
      for (Node* now_node = node; now_node != nullptr; now_node = now_node->left) {
        min_node = now_node;
      }
    }
    return min_node;
  }

  Node* BinarySearchTree::find_max(Node* node) const {
    // Write your code here...
    Node* max_node = node;
    if (node != nullptr) {
      for (Node* now_node = node; now_node != nullptr; now_node = now_node->right) {
        max_node = now_node;
      }
    }
    return max_node;
  }

}  // namespace assignment