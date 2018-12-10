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
					LinkedList(const LinkedList &other) {
					    //copy constructor, copies list from one list to newly constructed;
					    //deep copy
					    std::cout << "copy constructor entered" << std::endl;
                        if((other.head && other.tail) == NULL) {
                            std::cout << "param object NULL" << std::endl;
                            head=NULL;
                            tail=NULL;
                            _size = 0;

                        }else {
                            std::cout << "parm object not null, copying" << std::endl;
                            head = new Node(other.head->_data, other.head->_next);
                            tail = new Node(other.tail->_data, other.tail->_next);
                            head->_next = tail;
                            //above: is this the right thing to do? set head next to tail here?
                            size_t size = other._size;
                            //not sure if I did this right just a guess
                            std::cout << "copy created" << std::endl;
                        }
					}

					/*LinkedList(T data){
					    head = new Node;
					    head->_data = data;
					    std::cout << "head data = " << head->_data << std::endl;
					}*///practice constructor

					~LinkedList() {
					    //destructor. clears list, deletes (deallocate memory) all nodes
					    //while(head->_next != tail->_next){}//on right track?
					    /*if(head->_next != NULL) {
                            delete head->_next;
                            std::cout<< "next deleted" <<std::endl;
                        }*/
					    //above: should that be in there??
					    //NULL case:
                        if((head && tail) == NULL) {
                            delete head;
                            std::cout << "head deleted" << std::endl;
                            delete tail;
                            std::cout << "head and tail deallocated" << std::endl;
                        }

					}

				public:
					//i think i got these done

				    bool empty() const {
					    return(head==NULL);
					    //return true if list empty, false otherwise
					}
					T &front() {
					    return(head->_data);
					    //return a reference to the value at the front of the list
					    //is this right?

					}
					const T &front() const {
                        //return a constant reference to the value at the front of the list
					    return(head->_data);
					}
					T &back() {
					    //return a ref to val back of list
					    return(head->_data);
					}
					const T &back() const {
					    //return cons ref val back of list
                        return(head->_data);
					}
					size_t size() const {
					    return(_size)
					}

				public:
					iterator begin() {
						return(iterator(head));
					    //returns an iterator pointing to the first element of the list
					}
					const iterator begin() const {
                        return(iterator(head));
					}
					iterator end() {
					    return(iterator(tail));
					}
					const iterator end() const {}

				public:
					void clear() {}
					iterator insert(iterator where, const T &value) {}
					iterator erase(iterator where) {}
					iterator erase(iterator first, iterator last) {}
					void push_back(const T &value) {
					    if(head == NULL){
					        head = new Node(NULL, tail);
					    }

					    Node *newFront = new Node(value, head);
					    head = newFront;
					    _size+=1;
					}
					void pop_back() {}
					void push_front(const T &value) {
					    //insert new node to back of list
					    if(tail==NULL) {
                            std::cout << "tail is null, function returned no mods" << std::endl;
                        }else {
                            Node myBack = new Node(value, NULL);
                            tail->_next = myBack;
                            _size += 1;
                        }
					}
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