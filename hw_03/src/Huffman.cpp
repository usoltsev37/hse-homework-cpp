#include "Huffman.hpp"


HuffmanTree::HuffmanTree(const std::map<uint8_t, int> &frequency) {
    auto cmp = [](const std::pair<int, HuffmanNode *> c1, const std::pair<int, HuffmanNode *> c2) {
        return c1.first > c2.first;
    };

    std::priority_queue<std::pair<int, HuffmanNode *>,
            std::vector<std::pair<int, HuffmanNode *>>,
            decltype(cmp)> buffer_tree(cmp);

    for (auto &symbol : frequency) {
        auto *node = new HuffmanNode(symbol.first, nullptr, nullptr, nullptr);
        backlinks_symbol_node_[symbol.first] = node;
        buffer_tree.push({symbol.second, node});
    }


    if (buffer_tree.size() <= 1) {
        if (buffer_tree.empty())
            root_ = new HuffmanNode();
        else
            root_ = new HuffmanNode(' ', nullptr, buffer_tree.top().second,
                                    nullptr);
        return;
    } else {
        while (buffer_tree.size() > 1) {
            auto left = buffer_tree.top();
            buffer_tree.pop();
            auto right = buffer_tree.top();
            buffer_tree.pop();
            auto parent = new HuffmanNode(' ', nullptr, left.second, right.second);
            left.second->parent_ = right.second->parent_ = parent;
            buffer_tree.push({left.first + right.first, parent});
        }
        root_ = buffer_tree.top().second;
    }

    encrypt_tree();

    set_backlinks_code_symbol_();
}


void HuffmanTree::del_nodes(HuffmanTree::HuffmanNode *node) {
    if (!node) return;
    del_nodes(node->left_);
    del_nodes(node->right_);
    delete node;
}

HuffmanTree::HuffmanNode::HuffmanNode() { code = ""; }

HuffmanTree::HuffmanNode::HuffmanNode(uint8_t value, HuffmanTree::HuffmanNode *parent, HuffmanTree::HuffmanNode *left,
                                      HuffmanTree::HuffmanNode *right) : value_(value), parent_(parent), left_(left),
                                                                         right_(right) {
    if (left) left_->parent_ = this;
    if (right) right_->parent_ = this;
    code = "";
}

std::string HuffmanTree::HuffmanNode::get_code() const noexcept {
    return code;
}

uint8_t HuffmanTree::HuffmanNode::get_value() const noexcept {
    return value_;
}

HuffmanTree::HuffmanTree::~HuffmanTree() {
    del_nodes(root_);
}

HuffmanTree::HuffmanNode *HuffmanTree::get_node_by_symbol(const uint8_t &symbol) noexcept {
    return backlinks_symbol_node_[symbol];
}

void HuffmanTree::encrypt_tree() {
    for (auto &i : backlinks_symbol_node_) {
        uint8_t symbol = i.first;
        HuffmanNode *node = i.second;
        encrypt_symbol(symbol, node, node);
    }
}

void HuffmanTree::encrypt_symbol(uint8_t &symbol, HuffmanNode *node, HuffmanNode *const start_node) {
    if (!node->parent_) return;
    encrypt_symbol(symbol, node->parent_, start_node);
    if (node->parent_->left_ == node)
        start_node->code += "0";
    else if (node->parent_->right_ == node)
        start_node->code += "1";
}

bool HuffmanTree::have_code_symbol(const std::string &code) const noexcept {
    return backlinks_code_symbol_.count(code);
}

uint8_t HuffmanTree::get_code_symbol(std::string &code) noexcept {
    return backlinks_code_symbol_[code];
}

void HuffmanTree::set_backlinks_code_symbol_() noexcept {
    for (auto i : backlinks_symbol_node_)
        backlinks_code_symbol_[i.second->get_code()] = i.first;
}



