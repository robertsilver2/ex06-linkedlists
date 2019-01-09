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
					    if((head || tail) == NULL) {
                            std::cout << "_size = " << _size << std::endl;
                        }
					}
					LinkedList(const LinkedList &other) {
					    //copy constructor, copies list from one list to newly constructed;
					    //deep copy
					    std::cout << "copy constructor entered" << std::endl;
					    //std::cout << "other.head NULL? other.head->data = " << other.front() << std::endl;
					    std::cout << "other empty?" << other.empty() <<std::endl;
                        /*if(other.empty()) {
                            std::cout << "param object NULL" << std::endl;
                            head=NULL;
                            tail=NULL;
                            _size = 0;

                        }else {
                            std::cout << "parm object not null, copying" << std::endl;
                            head = other.head;
                            tail = NULL;
                            _size = 0;
                            for(iterator i = other.begin(); i.node() != other.tail; i++  ) {
                                    push_back(*i);
                                    std::cout << "i data = " << *i << std::endl;

                            }*/


                            //head->_next = tail;
                            //above: is this the right thing to do? set head next to tail here?
                            std::cout << (this->begin()==nullptr) <<std::endl;
                            for(iterator i = other.begin(); i.node() != other.tail; i++) {
                                std::cout << "i data = " << *i << std::endl;
                                if(head==NULL){
                                    push_back(*i);
                                    std::cout<< "head copied" << std::endl;
                                }else{
                                    push_back(*i);
                                }
                                //not sure if I did this right just a guess
                            }
                            push_back(*other.end());
                            std::cout << "copy created" << std::endl;

					}

					~LinkedList() {
					    //destructor. clears list, deletes (deallocate memory) all nodes
                        clear();

					}

				public:
					//i think i got these done

				    bool empty() const {
					    return(head==NULL);
					    //return true if list empty, false otherwise
					}
					T &front() {
                        std::cout << "front entered" <<std::endl;
					    return head->_data;

					    //return a reference to the value at the front of the list
					    //is this right?

					}
					const T &front() const {
                        //return a constant reference to the value at the front of the list
                        std::cout << "const front entered" <<std::endl;
                        return head->_data;
					}
					T &back() {
					    //return a ref to val back of list
					    return tail->_data;
					}
					const T &back() const {
					    //return cons ref val back of list
                        return tail->_data;
					}
					size_t size() const {
					    return _size;
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
					const iterator end() const {
					    return(iterator(tail));
					}

				public:
					void clear() {
					   // Node *
                        erase(head, tail);
                        delete head;
                        delete tail;
                        _size-=2;
					}
					iterator insert(iterator where, const T &value) {
					    return(nullptr);
					}
					iterator erase(iterator where) {
					    return(nullptr);
					}
					iterator erase(iterator first, iterator last) {
						//std::cout << "get here? line erase else statement" << std::endl;
                        iterator i = first.node();
                        while (head != tail){
                            std::cout << "enter loop? " << std::endl;
                            Node * temp = i.node();
                            i++;
                            head = i.node();
                            delete temp;
                            _size -=1;
                            std::cout << "temp deleted" << std::endl;
                        }
                        return head;
					}
					void push_back(const T &value) {
					    if(head == NULL){
                            std::cout << "pushback null if entered" << std::endl;
					        head = new Node(value, tail);
					        //head->_data = value;
					        std::cout << "head->_data = " << head->_data << std::endl;
                            //head->_next = tail;
					        _size+=1;

					    }else {
					        std::cout << "pushback non null entered" << std::endl;
                            Node *newFront = new Node(value, head);
                            head = newFront;
                            _size+=1;
                        }

					}
					void pop_back() {}
					void push_front(const T &value) {
					    //insert new node to back of list
					    if(tail==NULL) {
					        tail->_next=NULL;
					        tail->_data = value;
                            std::cout << "tail is null, function returned no mods" << std::endl;
                        }else {
                            Node * myBack = new Node(value, nullptr);
                            tail->_next = myBack;
                            tail = myback;
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