#pragma once
//Реализация класса List.
namespace mylist
{
	template <typename T>
	class List
	{
	public:
		List();
		~List();
		int size() { return Size; }
		void push_front(T data);
		void push_back(T data);
		void pop_front();
		void pop_back();
		T &operator[](const int index);
		void insert(T data, const int index);
		void removeAt(const int index);
		void clear();

	private:
		template <typename T>
		class Node
		{
		public:
			T data;
			Node<T> *pNext;
			Node<T> *pPrev;
			Node(T data = T(), Node<T> *pNext = nullptr, Node<T> *pPrev = nullptr)
			{
				this->data = data;
				this->pNext = pNext;
				this->pPrev = pPrev;
			}
		};
		int Size;
		Node<T> *head;
		Node<T> *tail;
	};

	template <typename T>
	List<T>::List()
	{
		this->Size = 0;
		this->head = nullptr;
		this->tail = nullptr;
	}

	template <typename T>
	void List<T>::push_front(T data)
	{
		if (this->tail != nullptr)
			this->tail = this->tail->pNext = new Node<T>(data, nullptr, this->tail);
		else
			this->head = this->tail = new Node<T>(data);
		Size++;
	}

	template <typename T>
	void List<T>::push_back(T data)
	{
		if (this->head != nullptr)
			this->head = this->head->pPrev = new Node<T>(data, this->head);
		else
			this->head = this->tail = new Node<T>(data);
		Size++;
	}

	template <typename T>
	void List<T>::pop_front()
	{
		if (this->tail != nullptr)
		{
			Node<T> *toDelete = this->tail;
			this->tail = this->tail->pPrev;
			delete toDelete;
			toDelete = nullptr;
			Size--;
		}
	}

	template <typename T>
	void List<T>::pop_back()
	{
		if (this->head != nullptr)
		{
			Node<T> *toDelete = this->head;
			this->head = this->head->pNext;
			delete toDelete;
			toDelete = nullptr;
			Size--;
		}
	}

	template <typename T>
	void List<T>::clear()
	{
		while (Size)
			pop_back();
	}

	template <typename T>
	List<T>::~List()
	{
		clear();
	}

	template <typename T>
	T &List<T>::operator[](const int index)
	{
		if (index > (Size / 2))
		{
			Node<T> *temp = this->tail;
			for (int i = (Size - 1); temp != nullptr; i--, temp = temp->pPrev)
				if (index == i)
					return temp->data;
		}
		else
		{
			Node<T> *temp = this->head;
			for (int i = 0; temp != nullptr; i++, temp = temp->pNext)
				if (index == i)
					return temp->data;
		}
		throw;
	}

	template <typename T>
	void List<T>::insert(T data, const int index)
	{
		if (index > (Size / 2))
		{
			Node<T> *temp = this->tail;
			for (int i = (Size - 1); temp != nullptr; i--, temp = temp->pPrev)
				if (index == i)
				{
					temp->pPrev = (temp->pPrev)->pNext = new Node<T>(data, temp, temp->pPrev);
					Size++;
					break;
				}
		}
		else
		{
			Node<T> *temp = this->head;
			for (int i = 0; temp != nullptr; i++, temp = temp->pNext)
				if (index == i)
				{
					if ((temp->pPrev) != nullptr)
						temp->pPrev = (temp->pPrev)->pNext = new Node<T>(data, temp, temp->pPrev);
					else
						push_back(data);
					Size++;
					break;
				}
		}
	}

	template <typename T>
	void List<T>::removeAt(const int index)
	{
		if (this->Size != 0)
		{
			Node<T> *toDelete = nullptr;
			if (index > (Size / 2))
			{
				toDelete = this->tail;
				for (int i = (Size - 1); toDelete != nullptr; i--, toDelete = toDelete->pPrev)
					if (index == i)
					{
						if (toDelete->pNext != nullptr)
						{
							(toDelete->pPrev)->pNext = toDelete->pNext;
							(toDelete->pNext)->pPrev = toDelete->pPrev;
						}
						else
							this->tail = toDelete->pPrev;
						delete toDelete;
						toDelete = nullptr;
						Size--;
						break;
					}
			}
			else
			{
				toDelete = this->head;
				for (int i = 0; toDelete != nullptr; i++, toDelete = toDelete->pNext)
					if (index == i)
					{
						if (toDelete->pPrev != nullptr)
						{
							if (toDelete->pNext != nullptr)
							{
								(toDelete->pPrev)->pNext = toDelete->pNext;
								(toDelete->pNext)->pPrev = toDelete->pPrev;
							}
							else
								this->tail = toDelete->pPrev;
						}
						else
							this->head = toDelete->pNext;
						delete toDelete;
						toDelete = nullptr;
						Size--;
						break;
					}
			}
		}
	}
}
