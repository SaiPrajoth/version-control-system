#include "Branch.h"
#include "LinkedList.h"
#include <iostream>
#include <string>
#include <sstream>

Branch *masterBranch = nullptr; // No branch initially
LinkedList<Branch> branchList;
Branch *currentBranch = nullptr;

void help() {
    std::cout << "\nAvailable Commands:\n";
    std::cout << "1. vcsInit: Initialize the VCS system.\n";
    std::cout << "2. createBranch <branchName> : Create a new branch.\n";
    std::cout << "3. switchBranch <branchName> : Switch to an existing branch.\n";
    std::cout << "4. makeCommit : you need to enter the message and datafile: Make a commit with a message and file data.\n";
    std::cout << "5. viewCommits : View the commit log for the current branch.\n";
    std::cout << "6. revertCommit <commitNumber>: Revert a specific commit by its number.\n";
    std::cout << "7. help: Display this help menu.\n";
    std::cout << "8. exit: Exit the program.\n";
}

Branch *findBranch(const std::string &branchName) {
    Node<Branch> *current = branchList.pStart;
    while (current != nullptr) {
        if (current->pData->aBranchName == branchName) {
            return current->pData;
        }
        current = current->pNext;
    }
    return nullptr;
}

void vcsInit() {
    if (masterBranch == nullptr) {
        masterBranch = new Branch();
        masterBranch->aBranchName = "master";
        branchList.InsertAtFront(masterBranch);
        currentBranch = masterBranch;
        std::cout << "VCS initialized with default branch: master.\n";
    } else {
        std::cout << "VCS is already initialized.\n";
    }
}

int main() {
    std::string input;

    std::cout << "Welcome to the Version Control System. Type `help()` for a list of commands.\n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);

        std::istringstream iss(input);
        std::string command;
        iss >> command;

        if (command == "vcsInit") {
            vcsInit();
        } else if (command == "createBranch") {
            if (!masterBranch) {
                std::cout << "Please initialize the VCS with `vcsInit()` first.\n";
                continue;
            }
            std::string branchName;
            iss >> branchName;
            Branch *newBranch = new Branch();
            newBranch->aBranchName = branchName;
            branchList.InsertAtEnd(newBranch);
            std::cout << "Branch created: " << branchName << "\n";
        } else if (command == "switchBranch") {
            if (!masterBranch) {
                std::cout << "Please initialize the VCS with `vcsInit()` first.\n";
                continue;
            }
            std::string branchName;
            iss >> branchName;
            Branch *branch = findBranch(branchName);
            if (branch) {
                currentBranch = branch;
                std::cout << "Switched to branch: " << branchName << "\n";
            } else {
                std::cout << "Branch not found.\n";
            }
        } else if (command == "makeCommit") {
            if (!currentBranch) {
                std::cout << "No branch selected. Please switch to a branch first.\n";
                continue;
            }
            std::string message, data;
            std::cout << "Enter commit message: ";
            std::getline(std::cin, message);
            std::cout << "Enter file data: ";
            std::getline(std::cin, data);
            currentBranch->MakeCommit(message, data);
            std::cout << "Commit added.\n";
        } else if (command == "viewCommits") {
            if (!currentBranch) {
                std::cout << "No branch selected. Please switch to a branch first.\n";
                continue;
            }
            std::cout << "Commit log for branch '" << currentBranch->aBranchName << "':\n";
            currentBranch->CommitLog();
        } else if (command == "revertCommit") {
            if (!currentBranch) {
                std::cout << "No branch selected. Please switch to a branch first.\n";
                continue;
            }
            size_t commitNumber;
            iss >> commitNumber;
            if (currentBranch->RevertCommit(commitNumber)) {
                std::cout << "Commit " << commitNumber << " reverted.\n";
            } else {
                std::cout << "Invalid commit number.\n";
            }
        } else if (command == "help") {
            help();
        } else if (command == "exit") {
            std::cout << "Exiting...\n";
            break;
        } else {
            std::cout << "Unknown command. Type `help()` for a list of commands.\n";
        }
    }

    return 0;
}
