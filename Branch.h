#pragma once
#include <iostream>
#include <string>
#include <vector>

struct Commit {
    std::string message;
    std::string data;
};

class Branch {
public:
    std::string aBranchName;
    std::vector<Commit> commits;

    void MakeCommit(const std::string &message, const std::string &data) {
        commits.push_back({message, data});
    }

    void CommitLog() {
        if (commits.empty()) {
            std::cout << "No commits yet.\n";
        } else {
            for (size_t i = 0; i < commits.size(); ++i) {
                std::cout << i + 1 << ". " << commits[i].message << ": " << commits[i].data << "\n";
            }
        }
    }

    bool RevertCommit(size_t commitIndex) {
        if (commitIndex > 0 && commitIndex <= commits.size()) {
            commits.erase(commits.begin() + (commitIndex - 1));
            return true;
        }
        return false;
    }
};
