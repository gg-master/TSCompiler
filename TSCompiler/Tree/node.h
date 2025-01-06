#pragma once
#include <string>
#include <vector>

struct Node
{
    const size_t id;

    Node() : id{nextId()} {}

    Node(const Node& other) = delete;

    Node(Node&& other) noexcept = delete;

    Node& operator=(const Node& other) = delete;

    Node& operator=(Node&& other) noexcept = delete;

    virtual ~Node() = default;

    virtual std::string toString() const noexcept = 0;

protected:
    static size_t nextId()
    {
        static size_t id = 0;
        return id++;
    }
};

template <typename TDerived, typename TNode>
struct NodeList : Node
{
    bool isEmpty() const noexcept { return _list.empty(); }

    static TDerived* makeEmpty() { return new TDerived; }

    void add(TNode* node) { _list.push_back(node); }

    void remove(TNode* node)
    {
        auto it = std::find(_list.begin(), _list.end(), node);
        if (it != _list.end())
        {
            _list.erase(it);
        }
    }

    void insertBefore(TNode* newNode, TNode* existingNode)
    {
        auto it = std::find(_list.begin(), _list.end(), existingNode);
        if (it != _list.end())
        {
            _list.insert(it, newNode);
        }
    }

    void moveBefore(TNode* nodeToMove, TNode* existingNode)
    {
        remove(nodeToMove);
        insertBefore(nodeToMove, existingNode);
    }

    void merge(TDerived* node)
    {
        auto& leftSeq = this->GetSeq();
        auto& rightSeq = node->GetSeq();
        leftSeq.insert(leftSeq.end(), rightSeq.begin(), rightSeq.end());
    }

    explicit NodeList(TNode* node) : Node() { _list.push_back(node); }

    std::vector<TNode*>& GetSeq() { return _list; }
    const std::vector<TNode*>& GetSeq() const { return _list; }

protected:
    std::vector<TNode*> _list{};

    NodeList() : Node() {}
};
