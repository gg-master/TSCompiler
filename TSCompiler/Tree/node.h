#pragma once
#include <string_view>
#include <vector>

struct Node
{
    const int id;

    Node() : id{ nextId() }
    {
    }

    Node(const Node& other) = delete;

    Node(Node&& other) noexcept = delete;

    Node& operator=(const Node& other) = delete;

    Node& operator=(Node&& other) noexcept = delete;

    virtual ~Node() = default;

    virtual std::string_view name() const noexcept = 0;

protected:
    static int nextId()
    {
        static int id = 0;
        return id++;
    }
};

template <typename TDerived, typename TNode>
struct NodeList : Node
{
    bool isEmpty() const noexcept { return _list.empty(); }

    static TDerived* makeEmpty() { return new TDerived; }

    void add(TNode* node) { _list.push_back(node); }

    explicit NodeList(TNode* node) : Node() { _list.push_back(node); }

    std::vector<TNode*>& GetSeq() { return _list; }
    const std::vector<TNode*>& GetSeq() const { return _list; }
protected:
    std::vector<TNode*> _list{};

    NodeList() : Node()
    {
    }
};
