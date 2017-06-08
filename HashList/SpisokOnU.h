#ifndef _SPISOK_ON_UKAZATEL_
#define _SPISOK_ON_UKAZATEL_

template <class T>
struct LinkNode
{
	LinkNode<T>* next; //указатель на следующую ноду
	T Dom; 
	LinkNode()
	{next=0;}
};
template <class T>
class Link
{
  private:
	  LinkNode<T>*node;
	  int size;
  public:
	  Link();
	  ~Link();
	  int GetSize();
	  void AddStart(T& a);
	  void AddEnd(T& a);
	  LinkNode<T>* GetStart();
	  LinkNode<T>* GetEnd();
	  T Get(LinkNode<T>* );
	  LinkNode<T>* GetNext(LinkNode<T>* );
	  void DeleteStart();
	  void DeleteEnd();
	  bool isEnd(LinkNode<T>*);
	  bool contains(T &a);
	  LinkNode<T>* indexOf(T &a);
	  Link<T>& operator=(Link<T> &a);
	  void Remove(LinkNode<T>* );

};
 
template <class T>
Link<T>::Link()
{
	size = 0;
	node = 0;
}

template <class T>
Link<T>::~Link()
{}

template <class T>
int Link<T>::GetSize()
{
	return size;
}

template <class T>
void Link<T>::AddStart(T& a)
{
	if(node==nullptr)
		{
			node = new LinkNode<T>;
			node->Dom = a;
		}
	else
	{
		LinkNode<T>* D = node;
		node= new LinkNode<T>;
		node->Dom = a;
		node->next = D;
	}
	size++;
}

template <class T>
void Link<T>::AddEnd(T& a)
{
	
	if(node==nullptr)
		{
			node = new LinkNode<T>;
			node->Dom = a;		
		}
	else
	{
		LinkNode<T>* D = node;
		while(!isEnd(D)) 
		{ 
			D = D->next;
		}
		D->next = new LinkNode<T>;
		D->next->Dom = a;
	}
	size++;
}

template <class T>
LinkNode<T>* Link<T>::GetStart()
{
	if(node==nullptr)
		throw 2;
	return node;
}

template <class T>
LinkNode<T>* Link<T>::GetEnd()
{
	if(node==nullptr)
		throw 2;
	LinkNode<T>* D = node;
		while(!isEnd(D)) 
		{ 
			D = D->next;
		}
	return D;
}

template <class T>
void Link<T>::DeleteStart()
{
	if(node==nullptr)
		throw 2;
	LinkNode<T>* Cat = node->next;
	delete node;
	node = Cat;
	size--;
}

template <class T>
void Link<T>::DeleteEnd()
{
	if(node==nullptr)
		throw 2;
	LinkNode<T>* Dog = node;
	LinkNode<T>* D = node;
		while(!isEnd(D)) 
		{ 
			Dog = D;
			D = D->next;
		}
	delete D;
	Dog->next = 0;
	size--;
}

template <class T>
T Link<T>::Get(LinkNode<T>* a)
{
	return a->Dom;
}

template <class T>
LinkNode<T>* Link<T>::GetNext(LinkNode<T>* a)
{
	return a->next;
}

template <class T>
bool Link<T>::isEnd(LinkNode<T>* a)
{
	if(a==nullptr)
		throw 1;
	if(a->next==nullptr)
		return true;
	return false;

}

template <class T>
bool Link<T>::contains(T &a)
{
	if(node==nullptr)
		return false;
	for( LinkNode<T>* i=this->GetStart(); i!=nullptr; i=GetNext(i))
	{
		if(Get(i)==a)
			return true;
	}
	return false;
}

template <class T>
LinkNode<T>* Link<T>::indexOf(T &a)
{
	for( LinkNode<T>* i=this->GetStart(); i!=nullptr; i=GetNext(i))
	{
		if(Get(i)==a)
			return i;
	}
	throw 3;
}

template <class T>
Link<T>& Link<T>::operator=(Link<T> &a)
{
	LinkNode<T> *tmp = node;
	while(node!=nullptr)
	{
		node=node->next;
		delete tmp;
	}
	tmp = nullptr;

	LinkNode<T>*i = a.GetStart();
	while(i=a.GetNext(i))
	{
		if(tmp!=nullptr)
		{
			tmp->next = new LinkNode<T>;
			tmp->next->Dom = a.Get(i);
			tmp = tmp->next;
		}
		else{
			tmp = new LinkNode<T>;
			tmp->Dom = a.Get(i);
			node = tmp;
		}
	}

	return *this;
}

template <class T>
void Link<T>::Remove(LinkNode<T>* a)
{
	if(a==nullptr)
		return;
	LinkNode<T>* D = node;
	while(D!=nullptr && D->next!=nullptr && D->next!=a)
		D=D->next;
	if(D->next==a)
	{
		D->next=a->next;
	    delete a;
	}
}

#endif