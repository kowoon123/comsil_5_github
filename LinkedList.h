#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
using namespace std;

//LinkedList Node
template <class t>
class Node{
	public:
		//데이터를 저장할 변수
		t data;
		//노드구조체 이용; 다음노드의 주소를 저장할 포인터
		Node *link;

		Node(t element){
		  data = element;
		  link = 0;
		}
	};

//LinkedList Class
template <class t>
class LinkedList{
	protected:
		//첫번째 노드의 주소를 저장할 포인터
		Node<t> *first;
		int current_size;
	public:
		//생성자, 초기화 
		LinkedList(){
			first = 0;
			current_size = 0;
		};

		//노드 개수를 리턴
		int GetSize(){
			return current_size;
		};

		//맨 앞에 원소를 삽입, LinkedList와 Stack 둘다 같다
		void Insert(t element){
			Node<t> *newnode = new Node<t>(element);
			newnode->link = first;
			first = newnode;
			current_size++;
		};
			
		
		//맨 뒤의 원소를 삭제, 제일 나중에 들어온 원소 삭제  - LinkedList
		virtual bool Delete(t& element){
			if(first ==0)
				return false;
			Node<t> *current = first;
			Node<t> *previous = NULL;
			while (1){
				if(current->link == 0){
					if(previous)previous->link = current->link;
					else first=first->link;
					break;
				}
				previous = current;
				current = current->link;
			}
			element = current->data;
			delete current;
			current_size--;
			return true;
		};
		//리스트 출력
		void Print(){
			int i;
			Node<t> *current = first;
			for(i=1;i<=current_size;i++){
				cout << "["<<i<<"|"<<current->data<<"]";
				current = current->link;
				if(current !=0) cout <<"->";
				else break;
			}
			if(current_size != 0)
				cout << endl;
		};
};
#endif
