#include "graphedge.h"
#include "graphnode.h"
#include <memory>

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    // Task 0 Solution
    // delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    // Task 3: convert to unique pointer, move ownership
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{   // Task 5: move chatbot to node
    // ref: https://knowledge.udacity.com/questions/142110
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{   
    // Task 5: https://knowledge.udacity.com/questions/77646
    newNode->MoveChatbotHere(std::move(_chatBot)); 
    // _chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    // Task 3: return raw pointer
    return _childEdges[index].get(); 

    ////
    //// EOF STUDENT CODE
}