
struct T
{
  byte n;
  T* next, *previous;
  T(byte _n, T* _next, T* _previous)
  {
    n = _n;
    next = _next;
    previous = _previous;
  }
};

class Queue
{
  T* head, *tail;
  int size;
  
  public:
  Queue()
  {
    size = 0;
    head = NULL;
  }

  void add(byte n)
  {
    if(size == 0)
    {
      head = new T(n, NULL, NULL);
      tail = head;
    }
    else
    {
      tail->next = new T(n, NULL, tail);
      tail = tail->next;
    }
    size+=1;
  }

  byte get()
  {
    if(head == NULL)
      return NULL;
    T* h = head;
    h = head->next;
    byte n = head->n;
    delete head;
    size-=1;
    if(size)
      head = h;
    return n;
  }

  int get_size()
  {
    return size;
  }
  
};

