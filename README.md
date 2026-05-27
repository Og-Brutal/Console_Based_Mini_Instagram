# 📱 Console-Based Mini Instagram 

A comprehensive console-based social networking application built with C++ that replicates core Instagram functionality. Features user authentication, follow requests, messaging, posts, notifications, and advanced data structures for efficient user management.

## 📋 Project Overview

This is a **C++ console application** that simulates a mini version of Instagram. It demonstrates advanced Object-Oriented Programming, Data Structures & Algorithms (DSA), and software architecture design. The application uses multiple data structures including AVL trees, queues, stacks, and linked lists to manage user data, messaging, and relationships.

**Technology Stack:**
- C++ (STL, OOP) 
- Visual Studio Project Format
- Advanced Data Structures (AVL BST, Queue, Stack, Linked Lists) 
- Console-based User Interface

## ✨ Features

### 👤 User Management
- **User Registration (Sign Up)**: Create new accounts with username, password, and city
- **User Authentication (Log In)**: Secure login with credentials verification
- **User Profiles**: Store user information including username, password, city, and timestamps
- **Unique Username Validation**: Ensures no duplicate usernames in the system
- **Login Timestamp Tracking**: Records last login date and time

### 👥 Social Networking
- **Follow Requests**: Send follow requests to other users
- **Request Management**: Accept or reject incoming follow requests
- **Followers List**: View all followers with their last login information
- **Search Engine**: Find users by username using AVL BST search

### 📝 Posts & Feed
- **Create Posts**: Add posts with timestamp information
- **View Posts**: Display posts in chronological order (newest first)
- **Followers' Posts**: View feed of all followed users' posts
- **Personal Newsfeed**: Display your own posts

### 💬 Messaging System
- **Direct Messages**: Send messages to followers
- **Chat Box**: Maintain conversation history with multiple users
- **Recent Contacts**: Chat box shows recent conversations at the top
- **Message Queue**: Efficient message storage using queue data structure
- **Notifications**: Get notified of incoming messages

### 🔔 Notifications
- **Follow Request Notifications**: Alerts for incoming follow requests
- **Message Notifications**: Notifications for received messages
- **Acceptance/Rejection Notifications**: Feedback on follow request actions
- **Queue-based Storage**: Notifications stored in FIFO queue

## 📁 Project Structure

```
Console_Based_Mini_Instagram/
├── main.cpp                  # Entry point of application
├── INSTAGRAM.cpp             # Main application logic & menu system
├── User.h                    # User class with all user operations
├── Vertex.h                  # Vertex node for BST (AVL Tree)
├── Post.h                    # Post class with linked list implementation
├── MessageSection.h          # Chat box & messaging functionality
├── queue.h                   # Custom Queue data structure
├── stack.h                   # Custom Stack data structure
├── zorong.h                  # AVL BST (Self-balancing tree) implementation
├── sign_up.h                 # Sign-up related utilities
├── ErrorHandling.h           # Input validation & error handling
├── FileName.cpp              # Empty placeholder file
├── mini_instagram.exe        # Compiled executable
└── DSA PROJECT.vcxproj*      # Visual Studio project files
```

## 🏗️ Data Structures Used

### 1. **Vector<Vertex>** - User Storage
- Stores all registered user profiles
- Fast index-based access
- Maintains current user index

### 2. **AVL BST (Binary Search Tree)** - Search Engine
- Self-balancing tree for efficient user search
- O(log n) search complexity
- Implements left/right rotations for balancing

### 3. **Queue** - Requests & Notifications
```cpp
- Follow requests queue
- Notifications queue
- FIFO (First-In-First-Out) implementation
```

### 4. **Stack** - Message Management
```cpp
- Chat box stack (stores person names)
- Message queues (stores messages per contact)
- LIFO (Last-In-First-Out) with custom modifications
```

### 5. **Linked List** - Posts
- Post nodes with timestamp and content
- Traversable in chronological order
- Stack-based insertion (newest first)

## 🎯 Key Classes

### User.h
Manages all user-related operations:

```cpp
class Users {
  - vector<Vertex> user_profiles    // All registered users
  - int currentUser                 // Currently logged-in user index
  - BST searchEngine                // AVL tree for search
  
  // Key Methods:
  - signUp()                        // User registration
  - logIn()                         // User authentication
  - sendRequest()                   // Send follow request
  - acceptRequest() / rejectRequest() // Manage requests
  - addPost() / viewFollowersPost() // Post management
  - sendText()                      // Send messages
  - searchUser()                    // Search functionality
}
```

### Post.h
Handles post management:

```cpp
class Post {
  - string dateAndTime             // Timestamp
  - string postContext             // Post content
  - Post* next                      // Linked list pointer
}

class UserPost {
  - Post* posts                     // Head of linked list
  - pushPost()                      // Add new post
  - displayPost()                   // Show all posts
  - getCurrentTime()                // Get current timestamp
}
```

### MessageSection.h
Manages messaging system:

```cpp
class Cnode {
  - string person                   // Contact name
  - Queue<string> messages          // Messages with this person
  - Cnode* nextBox                  // Stack pointer
}

class MessageSection {
  - Cnode* chatBox                  // Stack of chat contacts
  - sendMessage()                   // Add message to queue
  - placeAtFront()                  // Move recent contact to top
  - printChatBox() / printSpecificChat()
}
```

### zorong.h (AVL BST)
Search engine implementation:

```cpp
class BST {
  - Node* root                      // Root of AVL tree
  - insertion()                     // Insert with balancing
  - binarySearch()                  // Search users
  - leftRotation() / rightRotation() // Balancing operations
  - checkBalance()                  // Height balance factor
}
```

## 💻 Algorithm Highlights

### 1. AVL Tree Balancing
```
Balance Factor = height(left) - height(right)
- If |BF| > 1: Perform rotations
- Left-Left Case: Right Rotation
- Right-Right Case: Left Rotation
- Left-Right Case: LR Rotation
- Right-Left Case: RL Rotation
```

### 2. Queue Operations
```
- Enqueue: Add to rear
- Dequeue: Remove from front
- FIFO principle for requests & notifications
```

### 3. Stack with Message Management
```
- Push: Add new contact to stack
- Pop: Remove contact
- placeAtFront(): Move recent chats to top
- searchStack(): Find contact in stack
```

## 🚀 Getting Started

### Prerequisites
- Visual Studio (2019 or later) with C++ support
- Windows OS (uses Windows-specific functions like `system("cls")`)
- Basic C++ knowledge

### Compilation & Execution

**Option 1: Using Visual Studio**
1. Open `DSA PROJECT.vcxproj` in Visual Studio
2. Build the project (Ctrl + Shift + B)
3. Run (Ctrl + F5)

**Option 2: Using Command Line**
```bash
# Navigate to project directory
cd Console_Based_Mini_Instagram

# Compile (requires g++ or cl.exe)
g++ -o mini_instagram main.cpp INSTAGRAM.cpp

# Run
mini_instagram.exe
```

## 📖 Usage Guide

### Sign Up
1. Launch application
2. Choose "Sign In" option
3. Enter username (must be unique)
4. Set password (validation applied)
5. Enter your city
6. Account created successfully

### Log In
1. Select "Log In" from main menu
2. Enter registered username
3. Enter correct password
4. Access main Instagram menu

### Main Features Menu

| Option | Functionality |
|--------|---------------|
| 1 | Send Follow Request |
| 2 | Handle Follow Requests (Accept/Reject) |
| 3 | View Notifications |
| 4 | Message Followers / Open Chat |
| 5 | Posts (Add/View Followers' Posts) |
| 6 | View Own Newsfeed |
| 7 | View Followers List |
| 8 | Search for Users |
| 9 | Logout / Return Home |

## 🔐 Security Features

- **Password Validation**: Checks for minimum requirements
- **Username Uniqueness**: Prevents duplicate accounts
- **Credential Verification**: Matches username and password on login
- **Input Validation**: Error handling for invalid inputs
- **One-way Follow**: Follow requests prevent self-following

## 📊 Time Complexity Analysis

| Operation | Time Complexity | Data Structure |
|-----------|-----------------|-----------------|
| User Search | O(log n) | AVL BST |
| Sign Up | O(1) amortized | Vector |
| Send Request | O(1) | Queue |
| View Posts | O(n) | Linked List |
| Message Sending | O(1) | Queue/Stack |
| Login | O(n) | Vector |

## 🐛 Known Limitations

1. **Windows-Specific**: Uses `system("cls")` and `system("pause")` (Windows-only)
2. **Console-Based**: No GUI, limited visual appeal
3. **Single Session**: Only one user can be logged in at a time
4. **No Persistence**: Data stored in memory; lost on program exit
5. **No Database**: Uses in-memory data structures only
6. **Limited Input Validation**: Some edge cases not handled

## 🔄 Data Flow

```
main()
  └── signInPage()
       ├── Sign Up Flow
       │    └── validationChecks → signUp()
       └── Log In Flow
            └── verification → instagram()
                 ├── Send Request
                 ├── Handle Requests
                 ├── View Notifications
                 ├── Messaging
                 ├── Posts Management
                 ├── Search Users
                 └── View Followers
```

## 🎓 Educational Value

This project demonstrates:
- **Object-Oriented Programming**: Class design and encapsulation
- **Data Structures**: AVL trees, queues, stacks, linked lists, vectors
- **Algorithms**: Tree balancing, searching, sorting
- **System Design**: Component-based architecture
- **Memory Management**: Dynamic allocation and deallocation
- **Error Handling**: Input validation and exception handling

## 🚧 Future Enhancements

Potential improvements:
- [ ] File-based persistence (save/load user data)
- [ ] Cross-platform compatibility (remove Windows-specific calls)
- [ ] GUI implementation (Qt/SFML)
- [ ] Real-time notifications
- [ ] Like/Comment system on posts
- [ ] User blocking functionality
- [ ] Private messaging (encryption)
- [ ] Profile pictures/avatars
- [ ] Post hashtags and trending
- [ ] User bio/profile information
- [ ] Admin dashboard
- [ ] Database integration (MySQL/SQLite)

## 📝 Code Quality

- **Modular Design**: Separate header files for different components
- **Object-Oriented**: Classes for users, posts, messages, vertices
- **Template Usage**: Generic queue and stack implementations
- **Error Handling**: Input validation and error messages
- **Comments**: Well-documented code sections

## 🤝 Contributing

This is a student/educational project. Contributions are welcome for:
- Bug fixes
- Cross-platform compatibility improvements
- Performance optimizations
- Feature additions
- Code refactoring

## 📄 License

This project is open source and available for educational and personal use.

## 👨‍💻 Author

**Og-Brutal**

## 📚 Resources & References

- **Data Structures**: Introduction to Algorithms (CLRS)
- **AVL Trees**: https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
- **C++ STL**: https://cplusplus.com/reference/
- **Queue & Stack**: https://www.cplusplus.com/reference/queue/

## 🎯 Learning Outcomes

After studying this project, you'll understand:
- How to build a social networking application
- AVL tree implementation and balancing
- Custom data structure creation (Queue, Stack)
- Managing complex user interactions
- Time complexity optimization
- Memory management in C++
- Real-world application architecture

---

**Last Updated**: March 2026  
**Status**: Educational Project - Complete

*A comprehensive demonstration of DSA concepts in a real-world application* 💻
