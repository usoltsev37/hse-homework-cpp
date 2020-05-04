#ifndef HW_03_HUFFMAN_HPP
#define HW_03_HUFFMAN_HPP

#include <memory>
#include <map>
#include <queue>
#include <algorithm>
#include <string>

class HuffmanTree {
private:
    class HuffmanNode {
    public:
        HuffmanNode();

        HuffmanNode(uint8_t value, HuffmanNode *parent, HuffmanNode *left, HuffmanNode *right);

        std::string get_code() const noexcept;

        uint8_t get_value() const noexcept;

    private:
        friend class HuffmanTree;

        HuffmanNode *parent_;
        HuffmanNode *left_;
        HuffmanNode *right_;
        uint8_t value_;
        std::string code;
    };

public:

    explicit HuffmanTree(const std::map<uint8_t, int> &frequency);

    ~HuffmanTree();

    HuffmanNode *get_node_by_symbol(const uint8_t &symbol) noexcept;

    bool have_code_symbol(const std::string &code) const noexcept;

    uint8_t get_code_symbol(std::string &code) noexcept;

private:
    void set_backlinks_code_symbol_() noexcept;

    void del_nodes(HuffmanNode *node);

    void encrypt_tree();

    void encrypt_symbol(uint8_t &symbol, HuffmanNode *node, HuffmanNode *const start_nod);


    HuffmanNode *root_;
    std::map<uint8_t, HuffmanNode *> backlinks_symbol_node_;
    std::map<std::string, uint8_t> backlinks_code_symbol_;

};

#endif //HW_03_HUFFMAN_HPP
