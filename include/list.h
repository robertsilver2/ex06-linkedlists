#include <cstdlib>
#include <utility>

namespace edu {
	namespace vcccd {
		namespace vc {
			namespace csv15 {
				template<class T>
				class LinkedList {
				private:
					struct Node {
						Node(T data, Node *next) : _data(data), _next(next) {}
						Node* _next;
						T _data;
					};
				public:
					class iterator {
					public:
						iterator(Node *node) : _node(node) {}
						iterator(const iterator &other) : _node(other._node) {}

					public:
						const T &operator*() { return _node->_data; }
						const T &operator*() const { return _node->_data; }
						iterator &operator++() { _node = _node->_next; return *this; }
						iterator operator++(int) { iterator before(*this); _node = _node->_next; return before; }
						bool operator==(const iterator &other) { return other._node == _node; }
						bool operator!=(const iterator &other) { return !operator==(other); }
						Node *node() { return _node; }
					private:
						Node *_node;
					};

				public:
					LinkedList() {
					    //default constructor
					    head = NULL;
					    tail = NULL;
					    _size = 0;
					    if((head && tail) == NULL) {
                            std::cout << "_size = " << _size << std::endl;
                        }
					}
					LinkedList(const LinkedList &other) : _size(0), head(nullptr), tail(nullptr) {
					    //copy constructor, copies list from one list to newly constructed;
					    head = other.head;
					    tail = other.tail;
					    _size = other._size;
					    //not sure if I did this right just a guess
					    std::cout << "copy created" << std::endl;
					}

					~LinkedList() {
					    //destructor. clears list, deletes (deallocate memory) all nodes
					    delete head;
					    delete tail;
					    std::cout << "head and tail deallocated" << std::endl;

					}

				public:
					bool empty() const {
					    //return true if list empty, false otherwise
					}
					T &front() {}
					const T &front() const {}
					T &back() {}
					const T &back() const {}
					size_t size() const {}

				public:
					iterator begin() {}
					const iterator begin() const {}
					iterator end() {}
					const iterator end() const {}

				public:
					void clear() {}
					iterator insert(iterator where, const T &value) {}
					iterator erase(iterator where) {}
					iterator erase(iterator first, iterator last) {}
					void push_back(const T &value) {}
					void pop_back() {}
					void push_front(const T &value) {}
					void pop_front() {}

				public:
					void swap(LinkedList &other) {}

				private:
					Node *head;
					Node *tail;
					size_t _size;
				};
			}
		}
	}
}