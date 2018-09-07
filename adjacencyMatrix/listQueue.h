#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

template <class Item>
class Queue
{
private:
	struct node{
		Item item;
		node *next;
		node(Item x) : item(x), next(0) {}
	};
	typedef node *link;
	link head, tail;
public:
	Queue();
	~Queue();
	bool isEmpty() const;
	void enqueue(Item);
	Item dequeue();
};

template <class Item>
Queue<Item>::Queue()
{
	head = 0;
	tail = 0;
}

template <class Item>
Queue<Item>::~Queue()
{
	delete head;
}

template <class Item>
bool Queue<Item>::isEmpty() const
{
	return head == 0;
}

template <class Item>
void Queue<Item>::enqueue(Item x)
{
	link t = tail;
	tail = new node(x);
	if (head == 0)
		head = tail;
	else t->next = tail;
}

template <class Item>
Item Queue<Item>::dequeue()
{
	Item v = head->item;
	link t = head->next;
	delete head;
	head = t;
	return v;
}

#endif // QUEUE_H_INCLUDED