#pragma once
#include <vector>
#include <memory>
#include <iostream>


template <typename T> class TreeNode {
public:

    TreeNode() : value() {}
    TreeNode(const T& val) : value(val) {}

    T getValue() { return value; };

    TreeNode<T> * add_child(const T& val) {
        children.push_back(std::make_unique<TreeNode<T>>(val));
        return children.back().get();
    }

    T value;
    std::vector<std::unique_ptr<TreeNode<T>>> children;
};


template <typename T> class Tree {
public:
    Tree(const T& root_value) {
        root = std::make_unique<TreeNode<T>>(root_value);
    }
    Tree() {
        root = std::make_unique<TreeNode<T>>();
    }

    TreeNode<T>* get_root() {
        return root.get();
    }

    //recursively print the tree
    void print(TreeNode<T>* node, int depth = 0) {
        if(!node) return;
        std::cout << std::string(depth * 2, ' ') << node->value << "\n";
        for(auto& child : node->children) {
            print(child.get(), depth + 1);
        }
    }

private:
    std::unique_ptr<TreeNode<T>> root;
};