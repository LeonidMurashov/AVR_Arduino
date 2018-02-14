
namespace s
{
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
}
class Vector
{
  T* head, *tail;
  int size;
  
  public:
  Vector()
  {
    size = 0;
    head = NULL;
  }

  void push_back(byte n)
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

  void push_front(byte n)
  {
    if(size == 0)
    {
      head = new T(n, NULL, NULL);
      tail = head;
    }
    else
    {
      head->previous = new T(n, head, NULL);
      head = head->previous;
    }
    size+=1;
  }

  byte get(int n)
  {
    if(n >= size)
      return NULL;
    T *h = head;
    for(int i = 0; i < n; i++)
      h = h->next;
    return h->n;
  }

  byte operator[](int i)
  {
    return get(i);
  }

  int get_size()
  {
    return size;
  }
  
};

