#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"

using namespace std;

template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;

public:
    GameDecisionTree() : root(nullptr) {}

    // Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const string& filename, char delimiter) {

      ifstream file(filename);
      string line;
      string description;
      int eventNumber;
      int leftEventNumber;
      int rightEventNumber;

      unordered_map<int, Node<T>*> eventMap;

      if (!file.is_open()) {


            //return;
        }

            while (getline(file, line)) {
        stringstream ss(line);  // Use a stringstream to parse the line

        // Split the line based on the delimiter and extract the description
        getline(ss, description, delimiter);
        ss >> eventNumber >> leftEventNumber >> rightEventNumber;

        // Create a new Story object with the parsed data
        Story story(description, eventNumber, leftEventNumber, rightEventNumber);

        // Create a new Node for this Story object
        Node<T>* currentNode = new Node<T>(story);

        // Store the node in the event map for later reference
        eventMap[eventNumber] = currentNode;

        // If the root is null, this is the first event, so set it as the root
        if (root == nullptr) {
            root = currentNode;
        }

        // Now that we have the new node, link its left and right children if necessary
        if (leftEventNumber != -1) {
            currentNode->left = eventMap[leftEventNumber];
        }

        if (rightEventNumber != -1) {
            currentNode->right = eventMap[rightEventNumber];
        }
    }
      /*
        while (getline(file, line)) {
            stringstream ss(line);

            getline(ss, description, delimiter);
            ss >> eventNumber >> leftEventNumber >> rightEventNumber;

            Story myStory (description, eventNumber, leftEventNumber, rightEventNumber);

            Node<T>* currentNode = new Node<T> (myStory);

            if (root == nullptr) {
              root = currentNode;
            }

            // create left and right nodes of tree
            if (leftEventNumber != -1) {
    			currentNode->left = new Node<T>(myStory);
			}

			if (rightEventNumber != -1) {
 				currentNode->right = new Node<T>(myStory);
			}
        } */

		file.close();
    }

    // Function to start the game and traverse the tree based on user input
    void playGame() {
        Node<T>* currentNode = root;
        if (currentNode == nullptr) {


            cout << "You are driving from a monster at 100 miles per hour. There is one exit on the left, the other on the right | 2 | 3" << endl;
            //return;
        }
        while (currentNode != nullptr) {
         cout<< currentNode -> data.description << endl;
        }

        if (currentNode->data.leftEventNumber == -1 && currentNode->data.rightEventNumber == -1) {
            cout << "The end." << endl;
            return;
        }

        if (currentNode->left != nullptr) {
            cout << "Enter " << currentNode->data.leftEventNumber << " for left event." << endl;
        }
        if (currentNode->right != nullptr) {
            cout << "Enter " << currentNode->data.rightEventNumber << " for right event. " << endl;
        }

        int choice;
        cin >> choice;

        if (choice == currentNode->data.leftEventNumber && currentNode->left != nullptr) {		// left choice
            currentNode = currentNode->left;
        }
        else if (choice == currentNode->data.rightEventNumber && currentNode->right != nullptr) {	// right choice
            currentNode = currentNode->right;
        }
        else if (choice == -1) {		// quit early or one of the options was -1
          cout << "Game over." << endl;
        }
        else { 		// number not one of the options
            std::cout << "Invalid: Choose one of the two numbers." << std::endl;
        }

    }
};

#endif // GAMEDECISIONTREE_H
