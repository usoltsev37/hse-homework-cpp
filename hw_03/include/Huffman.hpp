#ifndef HW_03_HUFFMAN_HPP
#define HW_03_HUFFMAN_HPP

#include <memory>
#include <map>
#include <queue>
#include <algorithm>

#include <vector>

class HuffmanTree {
private:
    class HuffmanNode {
    public:
        HuffmanNode();
        HuffmanNode(uint8_t value, HuffmanNode *parent, HuffmanNode *left, HuffmanNode *right);
        std::string get_code() const noexcept;
    private:
        friend class HuffmanTree;
        HuffmanNode* parent_;
        HuffmanNode* left_;
        HuffmanNode* right_;
        uint8_t value_;
        std::string code;
    };
public:

    HuffmanTree(const std::map<uint8_t, int> &frequency);
    ~HuffmanTree();

    HuffmanNode* get_NodeBySymbol(const uint8_t &symbol) noexcept;

    // DEBUG
    void printCODE() noexcept {
        std::cout << "==============printCODE()==============\n";
        for(auto i : backlinks_) {
            //std::cout << std::bitset<8>(i.first) << ' ' << i.first << ' ' << i.second->get_code() << std::endl;
            std::cout  << "{\""<< i.second->get_code() << "\", \'" << i.first << "\'}" << std::endl;
            std::string code = i.second->get_code();
            //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
            code_sumbol_[i.second->get_code()] = i.first;
        }
        std::cout << "==============printCODE()==============\n";
    }

    bool have_code_sumbol(std::string code) const {
        return code_sumbol_.count(code);
    }

    uint8_t get_code_sumbol(std::string code) {
        return code_sumbol_[code];
    }

private:
    void del_nodes(HuffmanNode *node);
    void encrypt_tree();
    void encrypt_symbol(uint8_t &symbol, HuffmanNode *node, HuffmanNode *const start_nod);


    HuffmanNode *root_;
    std::map<uint8_t, HuffmanNode*> backlinks_;
    std::map<std::string, uint8_t> code_sumbol_;

};

#endif //HW_03_HUFFMAN_HPP
