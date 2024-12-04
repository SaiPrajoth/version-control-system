# Version Control System (VCS)

## Introduction

This project is a lightweight, custom-built Version Control System (VCS) that replicates basic Git-like features. It enables users to manage branches, create commits, view commit logs, and revert changes. The system is entirely built using C++ and employs core programming concepts such as linked lists and object-oriented design.

The project demonstrates the inner workings of a version control system, providing users and developers a stepping stone for deeper exploration into more complex version control frameworks.

## Architecture

### Overview

The VCS framework has three core components:

1. **Branch Management:**
   - this file tracks individual branches, each with its own set of commits.

2. **Commit Management:**
   - this file records changes and their descriptions as commits associated with a branch.

3. **Linked List Storage:**
   - this uses a linked list to store and manage branches.

## What Each File Does

### Branch.h

This file defines how a branch works and how commits are stored and managed.

**Key Elements:**
- **Commit:** A small structure to hold a commit's message and its associated data.
- **Branch:** A class to manage:
  - Branch name
  - List of commits
  - Actions like making a commit, viewing commit logs, and reverting commits

### LinkedList.h

This file implements a simple linked list to hold all branches.

**Key Elements:**
- **Node:** A single unit in the linked list holding a branch and a pointer to the next node.
- **LinkedList:** A class to manage:
  - Inserting nodes at the front or end
  - Traversing and managing branch nodes

### main.cpp

This is the core file where all the logic comes together. It handles:
- Command-line inputs
- Core functionality like initializing the VCS, creating/switching branches, making/reverting commits, and displaying commit logs
- Acts as the interface between the user and the underlying system

## File Structure

```bash
project/
├── Branch.h        # Contains the Branch class and Commit struct.
├── LinkedList.h    # Defines a generic LinkedList template class.
├── main.cpp        # Entry point for the program and user interface logic.
├── README.md       # Documentation for the project.
```

## How to Run the Project

### Prerequisites
- A C++ compiler (e.g., g++, clang++)
- Familiarity with running terminal commands

### Steps

1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd project
   ```

2. Compile the project:
   ```bash
   g++-std=c++11 -o vcs main.cpp
   ```

3. Run the executable:
   ```bash
   ./vcs
   ```

4. Use the on-screen prompts to explore commands and features.

## Testing and Example Usage

### Scenario 1: Initializing and Making a Commit
```
> vcsInit
VCS initialized with default branch: master.

> makeCommit
Enter commit message: Initial commit
Enter file data: Added README and project setup.
Commit added.
```

### Scenario 2: Creating and Switching Branches
```
> createBranch featureX
Branch created: featureX.

> switchBranch featureX
Switched to branch: featureX.
```

### Scenario 3: Viewing and Reverting a Commit
```
> viewCommits
Commit log for branch 'featureX':
1. Initial commit: Added README and project setup.

> revertCommit 1
Commit 1 reverted.
```

## Future Directions

### 1. Push and Pull Functionalities
- **Task:** Adding commands to push and pull changes using a database and server setup.
- **Failed Attempt:** Tried deploying the server with Cloudflare, but issues like synchronization and latency prevented stable operations.

### 2. Packaging as an NPM Library
- **Task:** Converting the project into an npm package for wider adoption by users.
- **Roadblocks:** Compatibility issues between C++ backend logic and JavaScript.

### 3. Docker Integration
- **ToDo:** Containerize the VCS system using Docker for platform independence.
- **+:** Enables the project to run seamlessly on any machine with Docker installed.

### 4. AI Agentic Framework
**ToDo:** we can use AI agentic framework to provide:
- Suggestions for commit messages
- Automatic detection of errors in commits
- Resolution of PR (Pull Request) conflicts
- can further optimize this to other tasks, if needed

**Failed Attempt:** we have implemented a reAct agentic framework architecture in C++ (with minimal Python), but debugging complexities led to delays.
