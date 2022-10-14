#ifndef _operations_hpp_
#define _operations_hpp_

#include <forward_list>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "book.hpp"

//
// INSERT OPERATIONS
//

struct insert_at_back_of_vector {
  // Function takes a constant Book as a parameter, inserts that book at the
  // back of a vector, and returns nothing.
  void operator()(const Book& book) {

    // Write the lines of code to insert "book" at the back of "my_vector".
    my_vector.push_back(book);
  }

  std::vector<Book>& my_vector;
};

struct insert_at_back_of_dll {
  // Function takes a constant Book as a parameter, inserts that book at the
  // back of a doubly linked list, and returns nothing.
  void operator()(const Book& book) {

    // Write the lines of code to insert "book" at the back of "my_dll".
    my_dll.push_back(book);
  }

  std::list<Book>& my_dll;
};

struct insert_at_back_of_sll {
  // Function takes a constant Book as a parameter, inserts that book at the
  // back of a singly linked list, and returns nothing.
  void operator()(const Book& book) {

    // Write the lines of code to insert "book" at the back of "my_sll". Since
    // the SLL has no size() function and no tail pointer, you must walk the
    // list looking for the last node.
    //
    // HINT:  Do not attempt to insert after "my_sll.end()".
    
    // Creates an iterator of type std::forward_list <Book> to point before 
    // the beginning of my_sll.
    std::forward_list<Book>::iterator iter = my_sll.before_begin();

    // while the next iterator of the current iterator does not point to my_sll.end()...
    while (std::next(iter) != my_sll.end()) {
      // ...mutate iter by incrementing it.
      iter++;
    }
    // Insert book to the back of my_sll.
    my_sll.insert_after(iter, book);
  }

  std::forward_list<Book>& my_sll;
};

struct insert_at_front_of_vector {
  // Function takes a constant Book as a parameter, inserts that book at the
  // front of a vector, and returns nothing.
  void operator()(const Book& book) {

    // Write the lines of code to insert "book" at the front of "my_vector".

    // std::vector::insert's arguments are an iterator pointing to the beginning of 
    // my_vector and book to insert. 
    my_vector.insert(my_vector.begin(), book);
  }

  std::vector<Book>& my_vector;
};

struct insert_at_front_of_dll {
  // Function takes a constant Book as a parameter, inserts that book at the
  // front of a doubly linked list, and returns nothing.
  void operator()(const Book& book) {

    // Write the lines of code to insert "book" at the front of "my_dll".

    // Use std::list::push_front() to insert book at the front of my_dll
    my_dll.push_front(book);
  }

  std::list<Book>& my_dll;
};

struct insert_at_front_of_sll{
  // Function takes a constant Book as a parameter, inserts that book at the
  // front of a singly linked list, and returns nothing.
  void operator()(const Book& book) {

    // Write the lines of code to insert "book" at the front of "my_sll"

    // Use std::forward_list::push_front() to insert book at the front.
    my_sll.push_front(book);
  }

  std::forward_list<Book>& my_sll;
};

struct insert_into_bst {
  // Function takes a constant Book as a parameter, inserts that book indexed by
  // the book's ISBN into a binary search tree, and returns nothing.
  void operator()(const Book& book) {

    // Write the lines of code to insert the key (book's ISBN) and value
    // ("book") pair into "my_bst".
    
    // Use std::map::insert() to insert a key-value pair into the BST. 
    // The key is book's isbn and the value is book. 
    my_bst.insert(std::make_pair(book.isbn(), book));
  }

  std::map<std::string, Book>& my_bst;
};

struct insert_into_hash_table {
  // Function takes a constant Book as a parameter, inserts that book indexed by
  // the book's ISBN into a hash table, and returns nothing.
  void operator()(const Book& book) {

    // Write the lines of code to insert the key (book's ISBN) and value
    // ("book") pair into "my_hash_table".

     
    // Use std::unordered_map::insert() to insert a key-value pair into hash table. 
    // The key is book's isbn and the value is book. 
    my_hash_table.insert(std::make_pair(book.isbn(), book));
  }

  std::unordered_map<std::string, Book>& my_hash_table;
};

//
// REMOVE OPERATIONS
//

struct remove_from_back_of_vector {
  // Function takes no parameters, removes the book at the back of a vector, and
  // returns nothing.
  void operator()(const Book& unused) {

    // Write the lines of code to remove the book at the back of "my_vector".
    //
    // Remember, attempting to remove an element from an empty data structure is
    // a logic error. Include code to avoid that.
    
    // If the size of my_vector is 0...
    if (my_vector.size() == 0) {
      // ...throw an std::out_of_range error.
      throw std::out_of_range("Cannot remove an element from an empty vector.");
    }

    // Call my_vector's pop_back function to remove the book from the back. 
    my_vector.pop_back();
  }

  std::vector<Book>& my_vector;
};

struct remove_from_back_of_dll {
  // Function takes no parameters, removes the book at the back of a doubly
  // linked list, and returns nothing.
  void operator()(const Book& unused) {

    // Write the lines of code to remove the book at the back of "my_dll".
    //
    // Remember, attempting to remove an element from an empty data structure is
    // a logic error. Include code to avoid that.

    // If the size of my_dll is 0...
    if (my_dll.size() == 0) {
      // ...throw an std::out_of_range error.
      throw std::out_of_range("Cannot remove an element from an empty DLL.");
    }

    // Call my_dll's pop_back function to remove the book from the back. 
    my_dll.pop_back();
  }

  std::list<Book>& my_dll;
};

struct remove_from_back_of_sll {
  // Function takes no parameters, removes the book at the back of a singly
  // linked list, and returns nothing.
  void operator()(const Book& unused) {

    // Write the lines of code to remove the book at the back of "my_sll".
    //
    // Remember, attempting to remove an element from an empty data structure is
    // a logic error. Include code to avoid that.
    //
    // Since the SLL has no size() function and no tail pointer, you must walk
    // the list looking for the last node.
    //
    // HINT:  If "my_sll" is empty, simply return. 
    //        Otherwise:
    //        o) Define two iterators called predecessor and current.
    //           Initialize predecessor to the node before the beginning, and
    //           current to the node at the beginning.
    //        o) Advance current to the next node.
    //        o) Walk the list until current is equal to end(), advancing both
    //           predecessor and current each time through the loop.
    //        o) Once current is equal to end(), then remove the node after
    //           predecessor

    // If my_sll is empty...
    if (my_sll.empty()) {
      // ...throw std::out_of_range argument.
      throw std::out_of_range("SLL is empty.");
    }

    // Create the predecessor iterator.
    std::forward_list<Book>::iterator predecessor = my_sll.before_begin();

    // Create the current iterator.
    std::forward_list<Book>::iterator current = my_sll.begin();

    // While the next iterator of current does not equal to end()...
    while (std::next(current) != my_sll.end()){
      // ...advance to the next node by incrementing both iterators.
      predecessor++;
      current++;
    }
  
    // Use std::forward_list::erase_after() to remove the node after predecessor.
    my_sll.erase_after(predecessor);
  }

  std::forward_list<Book>& my_sll;
};

struct remove_from_front_of_vector {
  // Function takes no parameters, removes the book at the front of a vector,
  // and returns nothing.
  void operator()(const Book& unused) {

    // Write the lines of code to remove the book at the front of "my_vector".
    //
    // Remember, attempting to remove an element from an empty data structure is
    // a logic error. Include code to avoid that.

    // If the size of my_vector is 0...
    if (my_vector.size() == 0) {
      // ...throw an std::out_of_range error.
      throw std::out_of_range("Cannot remove an element from an empty vector.");
    }

    // Use std::vector::erase() to remove the book from the front of my_vector.
    // The argument of erase() is an iterator pointing to the beginning of my_vector.
    my_vector.erase(my_vector.begin());
  }

  std::vector<Book>& my_vector;
};

struct remove_from_front_of_dll {
  // Function takes no parameters, removes the book at the front of a doubly
  // linked list, and returns nothing.
  void operator()(const Book& unused) {

    // Write the lines of code to remove the book at the front of "my_dll".
    //
    // Remember, attempting to remove an element from an empty data structure is
    // a logic error. Include code to avoid that.

    // If the size of my_dll is 0...
    if (my_dll.size() == 0) {
      // ...throw an std::out_of_range error.
      throw std::out_of_range("Cannot remove an element from an empty DLL.");
    }

    // Use std::list::pop_front() to remove the front book. 
    my_dll.pop_front();
  }

  std::list<Book>& my_dll;
};

struct remove_from_front_of_sll {
  // Function takes no parameters, removes the book at the front of a singly
  // linked list, and returns nothing.
  void operator()(const Book& unused) {

    // Write the lines of code to remove the book at the front of "my_sll".
    //
    // Remember, attempting to remove an element from an empty data structure is
    // a logic error. Include code to avoid that.

     // If my_sll is empty...
    if (my_sll.empty()) {
      // ...throw an std::out_of_range error.
      throw std::out_of_range("Cannot remove an element from an empty SLL.");
    }

    // Use std::forward_list::pop_front() to remove the front book. 
    my_sll.pop_front();
  }

  std::forward_list<Book>& my_sll;
};

struct remove_from_bst {
  // Function takes a constant Book as a parameter, finds and removes from the
  // binary search tree the book with a matching ISBN (if any), and returns
  // nothing. If no Book matches the ISBN, the method does nothing.
  void operator()(const Book& book) {

    // Write the lines of code to remove the book from "my_bst" that has an ISBN
    // matching "book".

    // Use std::map::erase() to remove a book.
    // erase()'s argument is an ISBN.
    my_bst.erase(book.isbn());
  }

  std::map<std::string, Book>& my_bst;
};

struct remove_from_hash_table {
  // Function takes a constant Book as a parameter, finds and removes from the
  // hash table the book with a matching ISBN (if any), and returns nothing. If 
  // no Book matches the ISBN, the method does nothing.
  void operator()(const Book& book) {

    // Write the lines of code to remove the book from "my_hash_table" that has
    // an ISBN matching "book".

    // Use std::unordered_map::erase() to remove a book.
    // erase()'s argument is an ISBN.
    my_hash_table.erase(book.isbn());

  }

  std::unordered_map<std::string, Book>& my_hash_table;
};

//
// SEARCH OPERATIONS
//

struct search_within_vector {
  // Function takes no parameters, searches a vector for a book with an ISBN
  // matching the target ISBN, and returns a pointer to that found book if such
  // a book is found, nullptr otherwise.
  Book* operator()(const Book& unused) {

    // Write the lines of code to search for the Book within "my_vector" with an
    // ISBN matching "target_isbn". Return a pointer to that book immediately
    // upon finding it, or a null pointer when you know the book is not in the
    // container.

    // Create an iterator that points to the beginning of my_vector.
    std::vector<Book>::iterator iter = my_vector.begin();

    // While iter does not equal end()...
    while (iter != my_vector.end()) {
      // ...if iter's isbn is equal to target_isbn...
      if ((*iter).isbn() == target_isbn) {
        // ... create a pointer to the book.
        Book* ptr = &(*iter);
        // Return the pointer.
        return ptr;
      }
      // Advance iter to the next element.
      iter++;
    }

    // Return nullptr because a book with target_isbn was not found. 
    return nullptr;
  }

  std::vector<Book>& my_vector;
  const std::string target_isbn;
};

struct search_within_dll {
  // Function takes no parameters, searches a doubly linked list for a book with
  // an ISBN matching the target ISBN, and returns a pointer to that found book
  // if such a book is found, nullptr otherwise.
  Book* operator()(const Book& unused) {

    // Write the lines of code to search for the Book within "my_dll" with an
    // ISBN matching "target_isbn". Return a pointer to that book immediately
    // upon finding it, or a null pointer when you know the book is not in the
    // container.

    // Create an iterator that points to the beginning of my_dll.
    std::list<Book>::iterator iter = my_dll.begin();

    // While iter does not equal end()...
    while (iter != my_dll.end()) {
      // ...if iter's isbn is equal to target_isbn...
      if ((*iter).isbn() == target_isbn) {
        // ... create a pointer to the book.
        Book* ptr = &(*iter);
        // Return the pointer.
        return ptr;
      }
      // Advance iter to the next node.
      iter++;
    }

    // Return nullptr because a book with target_isbn was not found. 
    return nullptr;
  }

  std::list<Book>& my_dll;
  const std::string target_isbn;
};

struct search_within_sll {
  // Function takes no parameters, searches a singly linked list for a book with
  // an ISBN matching the target ISBN, and returns a pointer to that found book
  // if such a book is found, nullptr otherwise.
  Book* operator()(const Book& unused) {

    // Write the lines of code to search for the Book within "my_sll" with an
    // ISBN matching "target_isbn". Return a pointer to that book immediately
    // upon finding it, or a null pointer when you know the book is not in the
    // container.

    // Create an iterator that points to the beginning of my_sll.
    std::forward_list<Book>::iterator iter = my_sll.begin();

    // While iter does not equal end()...
    while (iter != my_sll.end()) {
      // ...if iter's isbn is equal to target_isbn...
      if ((*iter).isbn() == target_isbn) {
        // ...create a pointer to the book.
        Book* ptr = &(*iter);
        // Return the pointer.
        return ptr;
      }
      // Advance iter to the next node.
      iter++;
    }

    // Return nullptr because a book with target_isbn was not found. 
    return nullptr;
  }

  std::forward_list<Book>& my_sll;
  const std::string target_isbn;
};

struct search_within_bst {
  // Function takes no parameters, searches a binary search tree for a book with
  // an ISBN matching the target ISBN, and returns a pointer to that found book
  // if such a book is found, nullptr otherwise.
  Book* operator()(const Book& unused) {

    // Write the lines of code to search for the Book within "my_bst" with an
    // ISBN matching "target_isbn". Return a pointer to that book immediately
    // upon finding it, or a null pointer when you know the book is not in the
    // container.
    //
    // NOTE: Do not implement a linear search, i.e., do not loop from beginning
    // to end.

    // Create an iterator that points to the iterator that std::map::find() returns.
    std::map<std::string, Book>::iterator search = my_bst.find(target_isbn);

    // If search does not equal end()...
    if (search != my_bst.end()) {
      //...create a pointer to book.
      Book* ptr = &((*search).second);
      //Return the pointer. 
      return ptr;
    }

    // Return nullptr because a book with target_isbn was not found.
    return nullptr;
  }

  std::map<std::string, Book>& my_bst;
  const std::string target_isbn;
};

struct search_within_hash_table {
  // Function takes no parameters, searches a hash table for a book with an ISBN
  // matching the target ISBN, and returns a pointer to that found book if such
  // a book is found, nullptr otherwise.
  Book* operator()(const Book& unused) {

    // Write the lines of code to search for the Book within "my_hash_table"
    // with an ISBN matching "target_isbn". Return a pointer to that book
    // immediately upon finding it, or a null pointer when you know the book is
    // not in the container.
    //
    // NOTE: Do not implement a linear search, i.e., do not loop from beginning
    // to end.

    // Since std::unordered_map uses chaining to resolve collisions, target_isbn's
    // hash can be used to figure out which bucket it is stored in. 

    // An int that stores the bucket number that calling 
    // std::unordered_map::bucket() returns. 
    int bucket = my_hash_table.bucket(target_isbn);

    // Uses auto to create an iterator that points to the beginning of the bucket. 
    auto iter = my_hash_table.begin(bucket);

    // Uses auto to create an iterator that points to the end() of bucket.
    auto end = my_hash_table.end(bucket);

    // While iter does not equal to the bucket's end...
    while (iter != end) {
      // .. if iter's isbn is equal to target_isbn...
      if (iter->first == target_isbn) {
        // ...return a pointer to the book.
        return &(iter->second);
      }
      // Increment iter to advance to the next key-value pair in the bucket. 
      iter++;
    }
    
    // Return nullptr because a book with target_isbn was not found.
    return nullptr;
  }

  std::unordered_map<std::string, Book>& my_hash_table;
  const std::string target_isbn;
};

#endif
