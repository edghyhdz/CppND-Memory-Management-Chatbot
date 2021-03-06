#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <string>
#include <wx/bitmap.h>
#include <memory>
#include <iostream>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot {
private:
  // data handles (owned) -> Should be properly handled by class destructor
  wxBitmap *_image; // avatar image
  std::string _filename; // for copy constructor

  // data handles (not owned)
  GraphNode *_currentNode;
  GraphNode *_rootNode;
  ChatLogic *_chatLogic;

  // proprietary functions
  int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
  // constructors / destructors
  ChatBot();                     // constructor WITHOUT memory allocation
  ChatBot(std::string filename); // constructor WITH memory allocation
  ~ChatBot();

  // TODO: Task 2: Rule of 5
  //// STUDENT CODE
  ////
  // Rereference from knowledge.udacity
  // https://knowledge.udacity.com/questions/131653 -> to find out error with move constructor and move assignment operator 
  // Move constructor and move assignment constructor
  // and copy assignment constructors
  ChatBot &operator=(const ChatBot &source); // Copy assignment operator
  ChatBot(const ChatBot &source); // Copy constructor 
  ChatBot(ChatBot &&source); // Move constructor
  ChatBot &operator=(ChatBot &&source); // Move assignment operator
  ////
  //// EOF STUDENT CODE

  // getters / setters
  // void SetCurrentNode(std::unique_ptr<GraphNode> node);
 //  void SetRootNode(std::unique_ptr<GraphNode> rootNode){ _rootNode = rootNode.get(); }


  void SetCurrentNode(GraphNode *node);
  void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
  void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
  wxBitmap *GetImageHandle() { return _image; }

  // communication
  void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */